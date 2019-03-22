#include"CBoss.h"
#include"CPlayerTank.h"
#include <stdio.h>
#include"CBullet.h"
#include"CExplosion.h"
#include"CMain.h"
#include"CScene.h"
#include"CBossBullet.h"
#define FIREINTERVAL_E 60
#define BOSSLIFE_B 50


extern CPlayerTank *Tank;
extern CTexture Texture;

CTexture CBoss::mTextImage;
CTexture CBoss::mTextImage3;


void CBoss::Init(){
	mTextImage.Load("Boss.ikaku.tga");
	mTextImage3.Load("Boss.tga");


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
	mTaskTag = EBOSS;
	mHpBar.SetHpBar(this, CVector2(0.0f, -120.0f), CVector2(200.0f, 8.0f), mColor, 200, 200);
}



void CBoss::Update(){

	if (mFireInterval > 0){
		mFireInterval--;
	}
	if (mHpBar.mHp > 0){

		Forward();

	}



	CTank::Update();

	if (mPosition.x <-400){
		mPosition = CVector2(250.0f, -150.0f);
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


	if (-0.1 < dot&&dot < 0.1){
		if (mFireInterval <= 0 && mHpBar.mHp > 0){
			mFireInterval = FIREINTERVAL_E;
			CBossBullet*cbullet = new CBossBullet();
			CRectangle::SetTexture(&mTextImage3, 24, 162, -150, -32);

			cbullet->mTaskTag = EBOSSBULLET;
			cbullet->mLife = CBULLET_LIFE;
			cbullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 30.0f);
			cbullet->mForward = cbullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
			cbullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
			CTaskManager::Get()->Add(cbullet);
		}
	}



	mHpBar.Update();
}



void CBoss::OnCollision(CCollider*p){
	if (mHpBar.mHp >= 1){
		if (p->mpTask->mTaskTag == EPLAYERBULLET){
			CRectangle::SetTexture(&mTextImage3, 200, 338, -520, -416);
			CExplosion*p = new CExplosion();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 8.0f;

			if (mHpBar.mHp <= 0.0f){

				CExplosion*p = new CExplosion();
				p->SetTexture(&Texture, 0, 64, 64, 0);
				p->mPosition = mPosition;
				CTaskManager::Get()->Add(p);
				mEnabled = false;
				//CRectangle::SetTexture(&mTextImage3, -17, 160, -380, -191);
			}

		}

		//if (p->mpTask->mTaskTag == EPLAYERTANK){
		//	CRectangle::SetTexture(&mTextImage3, 394, 552, -521, -426);
		//	CExplosion*p = new CExplosion();
		//	p->SetTexture(&Texture, 0, 64, 64, 0);
		//	p->mPosition = mPosition;
		//	CTaskManager::Get()->Add(p);
		//	mHpBar.mHp -= 1.0f;

		//	if (mHpBar.mHp <= 0.0f){
		//		CRectangle::SetTexture(&mTextImage3, -17, 160, -380, -191);

		//	}
		//}
		if (p->mpTask->mTaskTag == EPLAYERBULLET2){
			CRectangle::SetTexture(&mTextImage3, 394, 552, -521, -426);
			CExplosion*p = new CExplosion();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 5.0f;

			if (mHpBar.mHp <= 0.0f){
				CRectangle::SetTexture(&mTextImage3, -17, 160, -380, -191);
				CExplosion*p = new CExplosion();
				p->SetTexture(&Texture, 0, 64, 64, 0);
				p->mPosition = mPosition;
				CTaskManager::Get()->Add(p);
				mEnabled = false;

			}
		}
	}
}
void CBoss::OnCollision(CBoxCollider*p){
	//if (p->mpTask->mTaskTag == EPLAYERTANK){
	//	mPosition = mPosition + mCollider->mAdjust;
	//}
}
void CBoss::Render(){
	mHpBar.Render();
	CRectangle::Render();
}