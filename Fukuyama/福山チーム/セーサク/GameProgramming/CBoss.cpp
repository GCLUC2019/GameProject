
#include"CBoss.h"
#include"CPlayerTank.h"
#include <stdio.h>
#include"CBullet.h"
#include"CExplosion.h"
#include"CMain.h"
#include"CScene.h"
#include"CBossBullet.h"
//#include"CRectangle.h"
#define FIREINTERVAL_E 60


extern CPlayerTank *Tank;
extern CTexture Texture;

CTexture CBoss::mTextImage;

void CBoss::Init(){
	mTextImage.Load("Boss.ikaku.tga");
	CRectangle::SetTexture(&mTextImage, 0, 1299, 992, 0);

	mFireInterval = FIREINTERVAL_E;
	CTank::Init();
	SetVertex(-100.0f, 100.0f, -100.0f, 100.0f);
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mHead.SetColor(1.0f, 0.6f, 0.0f, 1.0f);
	mHead.SetVertex(-50.0f, 50.0f, -50.0f, 50.0f);
	mCanon.SetColor(1.0f, 0.6f, 0.0f, 1.0f);
	mCanon.SetVertex(-20.0f, 20.0f, -70.0f, 70.0f);
	mCanon.mPosition.y = 40.0f;





	mCollider = new CCircleCollider();
	mCollider->mRadius = 20.0f;
	mCollider->mpTask = this;
	mpTarget = Tank;
	CCollisionManager::Get()->Add(mCollider);
	mTaskTag = EENEMYTANK;
	mHpBar.SetHpBar(this, CVector2(0.0f, -120.0f), CVector2(200.0f, 8.0f), mColor, 200, 200);
}

int Counter = 1;

void CBoss::Update(){
	if (mFireInterval > 0){
		mFireInterval--;
	}

	Forward();


	CTank::Update();

	/*if (mPosition.x > 400){
	mPosition = CVector2(400.0f, 150.0f);
	mRotation = 90.0f;
	}*/
	if (mPosition.x <-400){
		mPosition = CVector2(400.0f, -150.0f);
		mRotation = 90.0f;
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


	//if (-0.1 < dot&&dot < 0.1){
	//	if (mFireInterval <= 0){
	//		mFireInterval = FIREINTERVAL_E;
	//		CBossBullet*cbullet = new CBossBullet();
	//		cbullet->mTaskTag = EBOSSBULLET;
	//		cbullet->mLife = CBULLET_LIFE;
	//		cbullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 30.0f);
	//		cbullet->mForward = cbullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
	//		cbullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
	//		CTaskManager::Get()->Add(cbullet);
	//	}
	//}



	mHpBar.Update();
}

void CBoss::OnCollision(CCollider*p){
	if (p->mpTask->mTaskTag == EPLAYERBULLET){
		CExplosion*p = new CExplosion();
		p->SetTexture(&Texture, 0, 64, 64, 0);
		p->mPosition = mPosition;
		CTaskManager::Get()->Add(p);
		mHpBar.mHp -= 40.0f;
		//Counter -= 1;
		if (mHpBar.mHp <= 0.0f){
			mEnabled = false;
			CMain::mSceneTag = CScene::EWIN;
		}
	}

	/*if (p->mpTask->mTaskTag == EPLAYERTANK){
	mPosition = mPosition + mCollider->mAdjust;
	}*/
}
void CBoss::OnCollision(CBoxCollider*p){
	if (p->mpTask->mTaskTag == EPLAYERTANK){
		mPosition = mPosition + mCollider->mAdjust;
	}
}
void CBoss::Render(){
	//CTank::Render();
	//mHpBar.Render();
	CRectangle::Render();
}