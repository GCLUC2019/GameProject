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

#define FIREINTERVER_E 40
#define ATTACKINTERVAR_E 10
#define CBULLET_LIFE 1

#define EFFECT_COUNT 40
#define DELETE_COUNT 210

extern CPlayerTank*Tank;

CTexture CEnemy1::mTexImage;
CTexture CEnemy1::mTexImage2;


void CEnemy1::Init(){
	mTexImage.Load("EK.tga");
	mTexImage2.Load("enemy1-2.tga");

	EffectCount = 0;
	AttackSide = 1;
	DeleteCount = DELETE_COUNT;


	mFireIntervar = FIREINTERVER_E;
	mAttackIntervar = ATTACKINTERVAR_E;
	//CTank::Init();
	SetVertex(-53.0f, 53.0f, -40.0f, 40.0f);
	mBoxCollider.mSize.x = 40.0f;
	mBoxCollider.mSize.y = 53.0f;
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
	mHpBar.SetHpBar(this, CVector2(0.0f, -65.0f), CVector2(50.0f, 8.0f), mColor, 100, 100);
}

void CEnemy1::Update(){

	//if (mAttackIntervar == 50){
	//	EForward();
	//}
	CTank::Update();
	mHpBar.Update();

	Enemy1->mRotation = 270.0f;

	CVector2 rightSide = mHead.mMatrix*CVector2(1.0f, 0.0f) - mHead.mMatrix*CVector2(0.0f, 0.0f);
	CVector2 UpSide = mHead.mMatrix*CVector2(0.0f, 1.0f) - mHead.mMatrix*CVector2(0.0f, 0.0f);

	CVector2 dirPlayer = mpTarget->mPosition - mHead.mMatrix*CVector2(0.0f, 0.0f);

	float dot = rightSide.dot(dirPlayer);
	float dot2 = UpSide.dot2(dirPlayer);

	if (AttackSide == 0){

		if (EffectCount > 0){
			SetVertex(-48.0f, 48.0f, -55.0f, 55.0f);
			CRectangle::SetTexture(&mTexImage, 147, 207, -69, -1);
			EffectCount--;
		}
		if (EffectCount == 0){
			SetVertex(-53.0f, 53.0f, -40.0f, 40.0f);
			CRectangle::SetTexture(&mTexImage, 139, 207, -175, -120);
		}
	}

	if (AttackSide == 1){
		if (EffectCount > 0){
			SetVertex(-48.0f, 48.0f, -55.0f, 55.0f);
			CRectangle::SetTexture(&mTexImage, 147, 207, -1, -69);
			EffectCount--;
		}
		if (EffectCount == 0){
			SetVertex(-53.0f, 53.0f, -40.0f, 40.0f);
			CRectangle::SetTexture(&mTexImage, 139, 207, -120, -175);
		}
	}

	if (EffectCount == 0){
		//if (mAttackIntervar == ATTACKINTERVAR_E){
		if (mHpBar.mHp >= 1){
			if (dot > 0.0f){
				EnemyDown2();
			}
			if (dot < 0.0f){
				EnemyUp2();
			}
			if (dot2<0.0f){
				EnemyLeft();
				AttackSide = 0;
			}
			if (dot2>0.0f){
				EnemyRight();
				AttackSide = 1;
			}
		}
	}
	CCollisionManager::Get()->Collision(mCollider);

	if (mFireIntervar>0){
		mFireIntervar--;
	}
	if (mAttackIntervar < ATTACKINTERVAR_E){
		mAttackIntervar--;
	}
	if (EffectCount>20){
		if (mHpBar.mHp >= 1){
			if (mAttackIntervar <= 0){
				if (mFireIntervar <= 0){
					mAttackIntervar = ATTACKINTERVAR_E;
					mFireIntervar = FIREINTERVER_E;
					CBullet*bullet = new CBullet();
					bullet->mTaskTag = EENEMYBULLET;
					bullet->mLife = CBULLET_LIFE;
					if (dot2 < 0.0f){
						bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, -24.0f);
						bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, -24.0f);
					}
					if (dot2 > 0.0f){
						bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 24.0f);
						bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
					}
					bullet->SetColor(mColor[0], mColor[0], mColor[0], mColor[0]);
					CTaskManager::Get()->Add(bullet);
				}
			}
		}
	}


	if (Enemy1->mPosition.y >= -20.0f){
		Enemy1->mPosition.y = -21.0f;
	}
	if (Enemy1->mPosition.y <= -220.0f){
		Enemy1->mPosition.y = -219.0f;
	}
	if (Enemy1->mPosition.x >= 370.0f){
		Enemy1->mPosition.x = 369.0f;
	}
	if (Enemy1->mPosition.x <= -370.0f){
		Enemy1->mPosition.x = -369.0f;
	}
	if (mHpBar.mHp <= 0){
		SetVertex(-45.0f, 45.0f, -70.0f, 70.0f);
		     
		DeleteCount--;
	}
	if (DeleteCount <= 0){
		mEnabled = false;
	}
}

void CEnemy1::OnCollision(CCollider*p){
	if (mHpBar.mHp >= 1){
		if (p->mpTask->mTaskTag == EPLAYERBULLET){
			CExplosion*p = new CExplosion();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 25.0f;
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
		if (p->mpTask->mTaskTag == EPLAYERTANK){
			//CExplosion*p = new CExplosion();
			//p->SetTexture(&Texture, 0, 64, 64, 0);
			//p->mPosition = mPosition;
			//CTaskManager::Get()->Add(p);

			//p->mPosition = mPosition;
			//mPosition = mPosition + mCollider->mAdjust;
			p->mPosition = mPosition;
			if (mAttackIntervar == ATTACKINTERVAR_E){
				mAttackIntervar -= 1;
			}
			if (EffectCount == 0){
				EffectCount = EFFECT_COUNT;
			}
		}
		//printf("CEnemyTank::OnCollision\n");
	}
}

void CEnemy1::OnCollision(CBoxCollider*p){
	if (mHpBar.mHp >= 1){
		if (p->mpTask->mTaskTag == EPLAYERTANK){
			//mPosition = mPosition + mCollider->mAdjust;
			printf("CBullet::OnCollision\n");
			p->mPosition = mPosition;
		}
	}
}


void CEnemy1::Render(){
	//CTank::Render();
	CRectangle::Render();
	mHpBar.Render();
}