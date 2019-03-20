/*
�@�@�@�@�@�@�@�@�@�@�@�@����ҁ@���c���P
			�ߋ����@�G
			*/

#include "CEnemy1.h"
#include "CPlayerTank.h"
#include "CBullet.h"
#include "CExplosion.h"
#include "CSceneGame.h"
#include "CMain.h"
#include "CItem.h"

#define FIREINTERVER_E 20
#define ATTACKINTERVAR_E 28
#define CBULLET_LIFE 25

#define EFFECT_COUNT 28

extern CPlayerTank*Tank;

CTexture CEnemy1::mTexImage;
CTexture CEnemy1::mTexImage2;


void CEnemy1::Init(){
	mTexImage.Load("EK.tga");
	mTexImage2.Load("enemy1-2.tga");

	EffectCount = 0;
	AttackSide = 1;

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
			CRectangle::SetTexture(&mTexImage, 147, 218, -73, -1);
			EffectCount--;
		}
		if (EffectCount == 0){
			CRectangle::SetTexture(&mTexImage, 132, 209, -291, -231);
		}
	}

	if (AttackSide == 1){
		if (EffectCount > 0){
			CRectangle::SetTexture(&mTexImage, 147, 218, -1, -73);
			EffectCount--;
		}
		if (EffectCount == 0){
			CRectangle::SetTexture(&mTexImage, 132, 209, -231, -291);
		}
	}

	if (EffectCount == 0){
		if (mAttackIntervar == 28){
			if (mHpBar.mHp >= 1){
				if (dot > 0.0f){
					EnemyDown2();
					CRectangle::SetTexture(&mTexImage, 132, 209, -231, -291);
				}
				if (dot < 0.0f){
					EnemyUp2();
					CRectangle::SetTexture(&mTexImage, 132, 209, -291, -231);
				}
				if (dot2<0.0f){
					EnemyLeft();
					CRectangle::SetTexture(&mTexImage, 132, 209, -291, -231);
					AttackSide = 0;
				}
				if (dot2>0.0f){
					EnemyRight();
					CRectangle::SetTexture(&mTexImage, 132, 209, -231, -291);
					AttackSide = 1;
				}
			}
		}
	}
	CCollisionManager::Get()->Collision(mCollider);

	if (mFireIntervar>0){
		mFireIntervar--;
	}
	if (mAttackIntervar < 28){
		mAttackIntervar--;
	}
	if (mHpBar.mHp >= 1){
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
	if (mHpBar.mHp == 0){
		SetVertex(-45.0f, 45.0f, -70.0f, 70.0f);
		CRectangle::SetTexture(&mTexImage, 300, 359, -200, -100);
	}
}

void CEnemy1::OnCollision(CCollider*p){
	if (mHpBar.mHp > 0){
		if (p->mpTask->mTaskTag == EPLAYERBULLET){
			CExplosion*p = new CExplosion();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 20.0f;
			if (mHpBar.mHp <= 0.0f){
				CItem*Item = new CItem();   //����
				Item->mTaskTag = EITEM;
				Item->mPosition = mCanon.mMatrix*CVector2(0.0f, 0.0f);
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
				CItem*Item = new CItem();   //����
				Item->mTaskTag = EITEM;
				Item->mPosition = mCanon.mMatrix*CVector2(0.0f, 0.0f);
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
			if (mAttackIntervar == 28){
				mAttackIntervar -= 1;
			}
			if (EffectCount == 0){
				EffectCount = EFFECT_COUNT;
			}
		}
		printf("CEnemyTank::OnCollision\n");
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