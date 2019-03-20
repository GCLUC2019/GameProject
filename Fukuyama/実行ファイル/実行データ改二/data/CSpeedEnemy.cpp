#include"CSpeedEnemy.h"
#include"CPlayerTank.h"
#include <stdio.h>
#include"CBullet.h"
#include"CExplosion.h"
#include"CMain.h"
#include"CScene.h"
#include"CHpBar.h"
#define FIREINTERVAL_E 60
#define SPEED_E 60

extern CPlayerTank *Tank;
extern CTexture Texture;
CTexture CSpeedEnemy::mTextImage2;

void CSpeedEnemy::Init(){
	mTextImage2.Load("data/Enemy-s.tga");
	CRectangle::SetTexture(&mTextImage2, 1341, 1644, 969, 660);
	mFireInterval = FIREINTERVAL_E;
	CTank::Init();
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mHead.SetColor(1.0f, 0.0f, 0.0f, 1.0f);
	mCanon.SetColor(0.8f, 0.0f, 0.0f, 1.0f);
	mCollider = new CCircleCollider();
	mCollider->mRadius = 20.0f;
	mCollider->mpTask = this;
	mpTarget = Tank;
	CCollisionManager::Get()->Add(mCollider);
	mTaskTag = ESPEEDENEMY;
	mHpBar.SetHpBar(this, CVector2(0.0f, -35.0f), CVector2(50.0f, 8.0f), mColor, 500, 500);
}

void CSpeedEnemy::Update(){
	if (mFireInterval > 0){
		mFireInterval--;
	}
	Forward();
	Forward();
	Forward();
	Forward();
	Forward();
	

	CTank::Update();
	mHpBar.Update();

	/*if (mPosition.x > 400){
		mPosition = CVector2(400.0f, 150.0f);
		mRotation = 90.0f;
	}*/
	if (mPosition.x <-400){
		mPosition = CVector2(400.0f, -200.0f);
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

	/*if (-0.1 < dot&&dot < 0.1){
	if (mFireInterval <= 0){
	mFireInterval = FIREINTERVAL_E;
	CBullet*bullet = new CBullet();
	bullet->mTaskTag = EENEMYBULLET;
	bullet->mLife = CBULLET_LIFE;
	bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 25.0f);
	bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
	bullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
	CTaskManager::Get()->Add(bullet);*/
}
//}

//}

void CSpeedEnemy::OnCollision(CCollider*p){
	if (p->mpTask->mTaskTag == EPLAYERBULLET){
		CExplosion*p = new CExplosion();
		p->SetTexture(&Texture, 0, 64, 64, 0);
		p->mPosition = mPosition;
		CTaskManager::Get()->Add(p);
		mHpBar.mHp -= 500.0f;
		if (mHpBar.mHp <= 0.0f){
			mEnabled = false;
			/*CMain::mSceneTag = CScene::EWIN;*/
		}

	}

	//mPosition = mPosition + mCollider->mAdjust;

}
void CSpeedEnemy::OnCollision(CBoxCollider*p){

	mPosition = mPosition + mCollider->mAdjust;

}
void CSpeedEnemy::Render(){
	//CTank::Render();
	//mHpBar.Render();
	CRectangle::Render();
}