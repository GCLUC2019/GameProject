/*
　　　　　　　　　　　　製作者　釜田正輝
			近距離　敵
			*/

#include "CEnemy1.h"
#include "CPlayerTank.h"
#include "CBullet.h"
#include "CExplosion.h"
#include "CSceneGame.h"
#include "CMain.h"
#include "CItem.h"

#define FIREINTERVER_E 60
#define ATTACKINTERVAR_E 58
#define CBULLET_LIFE 8

extern CPlayerTank*Tank;

CTexture CEnemy1::mTexImage;
CTexture CEnemy1::mTexImage2;


void CEnemy1::Init(){
	mTexImage.Load("enemy1.tga");
	mTexImage2.Load("enemy1-2.tga");

	mFireIntervar = FIREINTERVER_E;
	mAttackIntervar = ATTACKINTERVAR_E;
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
	mTaskTag = EENEMY1;
	mHpBar.SetHpBar(this, CVector2(0.0f, -50.0f), CVector2(50.0f, 8.0f), mColor, 100, 100);
}

void CEnemy1::Update(){

	//if (mAttackIntervar == 50){
	//	EForward();
	//}
	CTank::Update();
	mHpBar.Update();

	CVector2 rightSide = mHead.mMatrix*CVector2(1.0f, 0.0f) - mHead.mMatrix*CVector2(0.0f, 0.0f);
	CVector2 UpSide = mHead.mMatrix*CVector2(0.0f, 1.0f) - mHead.mMatrix*CVector2(0.0f, 0.0f);

	CVector2 dirPlayer = mpTarget->mPosition - mHead.mMatrix*CVector2(0.0f, 0.0f);

	float dot = rightSide.dot(dirPlayer);
	float dot2 = UpSide.dot2(dirPlayer);
	if (mAttackIntervar == 58){
		if (dot > 0.0f){
			EnemyDown();
			CRectangle::SetTexture(&mTexImage2, 0, 500, 500, 0);
		}
		else if (dot < 0.0f){
			EnemyUp();
			CRectangle::SetTexture(&mTexImage, 0, 500, 500, 0);
		}
		if (dot2<0.0f){
			EnemyDown2();
			CRectangle::SetTexture(&mTexImage, 0, 500, 500, 0);
		}
		else if (dot2>0.0f){
			EnemyUp2();
			CRectangle::SetTexture(&mTexImage2, 0, 500, 500, 0);
		}
	}
	CCollisionManager::Get()->Collision(mCollider);

	if (mFireIntervar>0){
		mFireIntervar--;
	}
	if (mAttackIntervar < 58){
		mAttackIntervar--;
	}
	//if (-0.1 < dot&&dot < 0.1){
	if (mAttackIntervar <= 0){
		if (mFireIntervar <= 0){
			mAttackIntervar = ATTACKINTERVAR_E;
			mFireIntervar = FIREINTERVER_E;
			CBullet*bullet = new CBullet();
			bullet->mTaskTag = EENEMYBULLET;
			bullet->mLife = CBULLET_LIFE;
			if (dot2 < 0.0f){
				bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, -25.0f);
				bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, -24.0f);
			}
			if (dot2 > 0.0f){
				bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 25.0f);
				bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
			}
			bullet->SetColor(mColor[0], mColor[0], mColor[0], mColor[0]);
			CTaskManager::Get()->Add(bullet);
		}
	}


	//if (EnemyTank->mPosition.x >= 425.0f){
	//	EnemyTank->mPosition.y = 150.0f;
	//	EnemyTank->mRotation = 90.0f;
	//}

	//if (EnemyTank->mPosition.x <= -425.0f){
	//	EnemyTank->mPosition.y = 250.0f;
	//	EnemyTank->mRotation = 270.0f;
	//}
}

void CEnemy1::OnCollision(CCollider*p){
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
	if (p->mpTask->mTaskTag == EPLAYERTANK){
		CExplosion*p = new CExplosion();
		if (mAttackIntervar == 58){
			mAttackIntervar -= 1;
		}
	}
	printf("CEnemyTank::OnCollision\n");
	mPosition = mPosition + mCollider->mAdjust;
}

void CEnemy1::OnCollision(CBoxCollider*p){
	if (p->mpTask->mTaskTag == EPLAYERTANK){
		mPosition = mPosition + mCollider->mAdjust;
		printf("CBullet::OnCollision\n");
	}
}


void CEnemy1::Render(){
	//CTank::Render();
	CRectangle::Render();
	mHpBar.Render();
}