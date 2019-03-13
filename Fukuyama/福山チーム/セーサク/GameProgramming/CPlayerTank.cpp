#include "CPlayerTank.h"
#include "windows.h"
#include "CBullet.h"
#include "CExplosion.h"
#include "CMain.h"

#define FIREINTERVER_P 30

extern CTexture Texture;

void CPlayerTank::Init(){
	CTank::Init();
	SetColor(0.0f, 0.0f, 0.6f, 1.0f);
	mHead.SetColor(0.0f, 0.0f, 1.0f, 1.0f);
	mCanon.SetColor(0.0f, 0.0f, 0.8f, 1.0f);
	mpBoxCollider = new CBoxCollider();
	mpBoxCollider->mSize.x = 20.0f;
	mpBoxCollider->mSize.y = 24.0f;
	mpBoxCollider->mpTask = this;
	CCollisionManager::Get()->Add(mpBoxCollider);
	mTaskTag = EPLAYERTANK;
	mFireInterver = FIREINTERVER_P;
	mHpBar.SetHpBar(this, CVector2(0.0f, -35.0f), CVector2(50.0f, 8.0f), mColor, 100, 100);
}

void CPlayerTank::Update(){
	mHpBar.Update();

	CTank::Update();

	if (GetKeyState('W') & 0x8000){
		Forward();
	}

	if (GetKeyState('S') & 0x8000){
		Backward();
	}

	if (GetKeyState('A') & 0x8000){
		LeftTurn();
	}

	if (GetKeyState('D') & 0x8000){
		RightTurn();
	}

	if (GetKeyState('J') & 0x8000){
		HeadLeftTurn();
	}

	if (GetKeyState('L') & 0x8000){
		HeadRightTurn();
	}

	if (mFireInterver > 0){
		mFireInterver--;
	}

	if (GetKeyState(' ') & 0x8000){
		if (mFireInterver <= 0){
			mFireInterver = FIREINTERVER_P;
			CBullet*bullet = new CBullet();
			bullet->mTaskTag = EPLAYERBULLET;
			bullet->mLife = CBULLET_LIFE;
			bullet->mPosition =
				mCanon.mMatrix*CVector2(0.0f, 25.0f);
			bullet->mForward = bullet->mPosition -
				mCanon.mMatrix*CVector2(0.0f, 24.0f);
			bullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
			CTaskManager::Get()->Add(bullet);
		}
	}
}

void CPlayerTank::OnCollision(CCollider*p){
	if (p->mpTask->mTaskTag == EENEMYBULLET){
		CExplosion*p = new CExplosion();
		p->SetTexture(&Texture, 0, 64, 64, 0);
		p->mPosition = mPosition;
		CTaskManager::Get()->Add(p);
		mHpBar.mHp -= 40.0f;
		if (mHpBar.mHp <= 0.0f){
			mEnabled = false;
			CMain::mSceneTag = CScene::ELOSE;
		}
	}
}

void CPlayerTank::Render(){
	CTank::Render();
	mHpBar.Render();
}