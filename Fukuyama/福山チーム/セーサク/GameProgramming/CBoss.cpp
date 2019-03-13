#include"CBoss.h"
#include"CPlayerTank.h"
#include <stdio.h>
#include"CBullet.h"
#include"CExplosion.h"
#include"CMain.h"
#include"CScene.h"
#define FIREINTERVAL_E 60


extern CPlayerTank *Tank;
extern CTexture Texture;


void CBoss::Init(){
	mFireInterval = FIREINTERVAL_E;
	

	CTank::Init();
	SetVertex(-100.0f, 100.0f, -100.0f, 100.0f);
	SetColor(0.6f, 0.0f, 1.0f, 1.0f);
	mHead.SetColor(0.6f, 1.0f, 1.0f, 1.0f);
	mHead.SetVertex(-50.0f, 50.0f, -50.0f, 50.0f);
	mCanon.SetColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	mCollider = new CCircleCollider();
	mCollider->mRadius = 20.0f;
	mCollider->mpTask = this;
	mpTarget = Tank;
	CCollisionManager::Get()->Add(mCollider);
	mTaskTag = EENEMYTANK;
	mHpBar.SetHpBar(this, CVector2(0.0f, -35.0f), CVector2(50.0f, 8.0f), mColor, 100, 100);
}

void CBoss::Update(){
	if (mFireInterval > 0){
		mFireInterval--;
	}
	 Forward();
	CTank::Update();

	if (mPosition.x > 400){
		mPosition = CVector2(400.0f, 150.0f);
		mRotation = 90.0f;
	}
	if (mPosition.x <-400){
		mPosition = CVector2(-400.0f, 250.0f);
		mRotation = 270.0f;
	}

	CVector2 rightSide = mHead.mMatrix*CVector2(1.0f, 0.0f) - mHead.mMatrix*CVector2(0.0f, 0.0f);

	CVector2 dirPlayer = mpTarget->mPosition - mPosition;

	float dot = rightSide.dot(dirPlayer);
	if (dot>0.0f){
		HeadRightTurn();
	}
	else if (dot < 0.0f){
		HeadLeftTurn();
	}
	CCollisionManager::Get()->Collision(mCollider);

	if (-0.1 < dot&&dot < 0.1){
		if (mFireInterval <= 0){
			mFireInterval = FIREINTERVAL_E;
			CBullet*bullet = new CBullet();
			bullet->mTaskTag = EENEMYBULLET;
			bullet->mLife = CBULLET_LIFE;
			bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 25.0f);
			bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
			bullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
			CTaskManager::Get()->Add(bullet);
		}
	}
	mHpBar.Update();
}

void CBoss::OnCollision(CCollider*p){
	if (p->mpTask->mTaskTag == EPLAYERBULLET){
		CExplosion*p = new CExplosion();
		p->SetTexture(&Texture, 0, 64, 64, 0);
		p->mPosition = mPosition;
		CTaskManager::Get()->Add(p);
		mHpBar.mHp -= 40.0f;

		if (mHpBar.mHp <= 0.0f){
			mEnabled = false;
			CMain::mSceneTag = CScene::EWIN;
		}
	}
	mPosition = mPosition + mCollider->mAdjust;

}
void CBoss::OnCollision(CBoxCollider*p){
	mPosition = mPosition + mCollider->mAdjust;
}
void CBoss::Render(){
	CTank::Render();
	mHpBar.Render();
}