/*
　　　　　　　　　　　　製作者　釜田正輝
			遠距離　敵
			*/

#include "CEnemy2.h"
#include "CPlayerTank.h"
#include "CBullet.h"
#include "CExplosion.h"
#include "CSceneGame.h"
#include "CMain.h"
#include "CItem.h"

#define FIREINTERVER_E 120

extern CPlayerTank*Tank;

extern int NotAttack;

CTexture CEnemy2::mTexImage;

void CEnemy2::Init(){
	mTexImage.Load("enemy1-2.tga");
	CRectangle::SetTexture(&mTexImage, 0, 500, 500, 0);

	mFireIntervar = FIREINTERVER_E;
	//CTank::Init();
	SetVertex(-38.0f, 38.0f, -25.0f, 25.0f);
	mBoxCollider.mSize.x = 25.0f;
	mBoxCollider.mSize.y = 38.0f;
	mBoxCollider.mpTask = this;

	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mHead.SetColor(0.6f, 1.0f, 1.0f, 1.0f);
	mCanon.SetColor(0.6f, 1.0f, 1.0f, 1.0f);
	mCollider = new CCircleCollider();
	mCollider->mRadius = 20.0f;
	mCollider->mpTask = this;
	mpTarget = Tank;
	CCollisionManager::Get()->Add(mCollider);
	mTaskTag = EENEMY2;
	mHpBar.SetHpBar(this, CVector2(0.0f, -50.0f), CVector2(50.0f, 8.0f), mColor, 100, 100);
}

void CEnemy2::Update(){

	//Forward();
	CTank::Update();
	mHpBar.Update();

	CVector2 rightSide = mHead.mMatrix*CVector2(1.0f, 0.0f) - mHead.mMatrix*CVector2(0.0f, 0.0f);

	CVector2 dirPlayer = mpTarget->mPosition - mHead.mMatrix*CVector2(0.0f, 0.0f);

	float dot = rightSide.dot(dirPlayer);
	if (dot > 0.0f){
		EnemyDown();
	}
	else if (dot < 0.0f){
		EnemyUp();
	}
	CCollisionManager::Get()->Collision(mCollider);

	if (mFireIntervar>0){
		mFireIntervar--;
	}

	//if (-0.1 < dot&&dot < 0.1)
	//if (NotAttack > 0){
	if (mFireIntervar <= 0){
		mFireIntervar = FIREINTERVER_E;
		CBullet*bullet = new CBullet();
		bullet->mTaskTag = EENEMYBULLET;
		bullet->mLife = CBULLET_LIFE;
		bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 25.0f);
		bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
		bullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
		CTaskManager::Get()->Add(bullet);
	}
	//}


	//	if (EnemyTank->mPosition.x >= 425.0f){
	//		EnemyTank->mPosition.y = 150.0f;
	//		EnemyTank->mRotation = 90.0f;
	//	}
	//
	//	if (EnemyTank->mPosition.x <= -425.0f){
	//		EnemyTank->mPosition.y = 250.0f;
	//		EnemyTank->mRotation = 270.0f;
	//	}
}

void CEnemy2::OnCollision(CCollider*p){
	if (p->mpTask->mTaskTag == EPLAYERBULLET){
		CExplosion*p = new CExplosion();
		p->SetTexture(&Texture, 0, 64, 64, 0);
		p->mPosition = mPosition;
		CTaskManager::Get()->Add(p);
		mHpBar.mHp -= 20.0f;
		if (mHpBar.mHp <= 0.0f){
			//小川
			CItem*Item = new CItem();
			Item->mTaskTag = EITEM;
			Item->mPosition = mCanon.mMatrix*CVector2(0.0f, 0.0f);
			CTaskManager::Get()->Add(Item);
			//小川
			mEnabled = false;
			CMain::mSceneTag = CScene::EWIN;
		}
	}
	printf("CEnemyTank::OnCollision\n");
	mPosition = mPosition + mCollider->mAdjust;
}

void CEnemy2::OnCollision(CBoxCollider*p){
	if (p->mpTask->mTaskTag == EPLAYERTANK){
		mPosition = mPosition + mCollider->mAdjust;
	}
}
void CEnemy2::Render(){
	CTank::Render();
	mHpBar.Render();
}