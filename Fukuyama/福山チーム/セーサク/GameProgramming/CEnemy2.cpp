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

#define FIREINTERVER_E 140
#define CBULLET_LIFE 400

#define EFFECT_COUNT 140

#define DELETE_COUNT 210

extern CPlayerTank*Tank;

extern int NotAttack;

CTexture CEnemy2::mTexImage;
CTexture CEnemy2::mTexImage2;


void CEnemy2::Init(){
	mTexImage.Load("EE.tga");
	mTexImage2.Load("EE-ya.tga");
	CRectangle::SetTexture(&mTexImage, 0, 65, -296, -250);

	mFireIntervar = FIREINTERVER_E;
	EffectCount = 0;
	DeleteCount = DELETE_COUNT;

	//CTank::Init();
	SetVertex(-53.0f, 53.0f, -40.0f, 40.0f);
	mBoxCollider.mSize.x = 40.0f;
	mBoxCollider.mSize.y = 53.0f;
	mBoxCollider.mpTask = this;

	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mHead.SetColor(0.6f, 1.0f, 1.0f, 1.0f);
	mCanon.SetColor(0.6f, 1.0f, 1.0f, 1.0f);
	mCollider = new CCircleCollider();
	mCollider->mRadius = 30.0f;
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
	if (mFireIntervar>50){
		if (mHpBar.mHp >= 1){
			if (dot > 0.0f){
				EnemyDown();
			}
			else if (dot < 0.0f){
				EnemyUp();
			}
		}
	}
	CCollisionManager::Get()->Collision(mCollider);


	if (mFireIntervar>0){
		mFireIntervar--;
	}

	if (EffectCount > 0){
		EffectCount--;
	}

	if (EffectCount <= 70){
		CRectangle::SetTexture(&mTexImage, 116, 178, -294, -247);
	}
	if (EffectCount >= 71){
		CRectangle::SetTexture(&mTexImage, 0, 65, -296, -250);
	}

	//if (-0.1 < dot&&dot < 0.1)
	//if (NotAttack > 0){
	if (mHpBar.mHp >= 1){
		if (EffectCount == 0){
			EffectCount = EFFECT_COUNT;
		}
		if (mFireIntervar <= 0){
			mFireIntervar = FIREINTERVER_E;
			CBullet*bullet = new CBullet();
			bullet->SetVertex(-30.0f, 30.0f, -8.0f, 8.0f);
			bullet->CRectangle::SetTexture(&mTexImage2, 191, 0, 0, 23);
			bullet->mTaskTag = EENEMYBULLET2;
			bullet->mLife = CBULLET_LIFE;
			bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, -30.0f);
			bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, -24.0f);
			bullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
			CTaskManager::Get()->Add(bullet);
		}
	}
	if (Enemy2->mPosition.y >= -20.0f){
		Enemy2->mPosition.y = -21.0f;
	}
	if (Enemy2->mPosition.y <= -220.0f){
		Enemy2->mPosition.y = -219.0f;
	}
	if (Enemy2->mPosition.x >= 370.0f){
		Enemy2->mPosition.x = 369.0f;
	}
	if (Enemy2->mPosition.x <= -370.0f){
		Enemy2->mPosition.x = -369.0f;
	}
	if (mHpBar.mHp <= 0){
		SetVertex(-30.0f, 30.0f, -60.0f, 60.0f);
		CRectangle::SetTexture(&mTexImage, 262, 302, -178, -102);
		DeleteCount--;
	}
	if (DeleteCount <= 0){
		mEnabled = false;
	}
}

void CEnemy2::OnCollision(CCollider*p){
	if (mHpBar.mHp >= 1){
		if (p->mpTask->mTaskTag == EPLAYERBULLET){
			CExplosion*p = new CExplosion();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 20.0f;
			if (mHpBar.mHp <= 0.0f){
				CItem*Item = new CItem();   //小川
				Item->mTaskTag = EITEM;
				Item->mPosition = mPosition;
				CTaskManager::Get()->Add(Item);
				//	mEnabled = false;
				//	CMain::mSceneTag = CScene::EWIN;
			}
		}
		if (p->mpTask->mTaskTag == EPLAYERBULLET2){
			CExplosion*p = new CExplosion();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 10.0f;
			if (mHpBar.mHp <= 0.0f){
				CItem*Item = new CItem();   //小川
				Item->mTaskTag = EITEM;
				Item->mPosition = mPosition;
				CTaskManager::Get()->Add(Item);
				//	mEnabled = false;
				//	CMain::mSceneTag = CScene::EWIN;
			}
		}
		if (p->mpTask->mTaskTag == EPLAYERBULLET3){
			CExplosion*p = new CExplosion();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 5.0f;
			if (mHpBar.mHp <= 0.0f){
				CItem*Item = new CItem();   //小川
				Item->mTaskTag = EITEM;
				Item->mPosition = mPosition;
				CTaskManager::Get()->Add(Item);
				//	mEnabled = false;
				//	CMain::mSceneTag = CScene::EWIN;
			}
		}

		if (p->mpTask->mTaskTag == EPLAYERTANK){
			//CExplosion*p = new CExplosion();
			//mPosition = mPosition + mCollider->mAdjust;
			p->mPosition = mPosition;
		}
		//printf("CEnemyTank::OnCollision\n");
	}
}

void CEnemy2::OnCollision(CBoxCollider*p){
	if (mHpBar.mHp >= 1){
		if (p->mpTask->mTaskTag == EPLAYERTANK){
			//mPosition = mPosition + mCollider->mAdjust;
			p->mPosition = mPosition;
		}
	}
}
void CEnemy2::Render(){
	CTank::Render();
	mHpBar.Render();
}