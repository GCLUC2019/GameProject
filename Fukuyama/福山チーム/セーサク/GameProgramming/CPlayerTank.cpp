#include"CPlayerTank.h"
#include"CBullet.h"
#include"windows.h"
#include"CExplosion.h"
#include"CMain.h"
#include"CScene.h"
#define FIREINTERVAL_P 30

extern CTexture Texture;
void CPlayerTank::Init(){
	CTank::Init();
	SetColor(0.0f, 0.0f, 0.6f, 1.0f);

	mHead.SetColor(0.0f, 0.0f, 1.0f, 1.0f);
	mCanon.SetColor(0.0f, 0.0f, 0.8f, 1.0f);


	mItem.SetColor(0.0f, 0.0f, 1.0f, 1.0f);
	mItem.mPosition.x = 30.0f;
	mItem.mPosition.y = 68.0f;
	mItem.SetVertex(-40.0f, -20.0f, -44.0f, 24.0f);

	mFireInterval = FIREINTERVAL_P;

	mpBoxCollider = new CBoxCollider();
	mpBoxCollider->mSize.x = 20.0f;
	mpBoxCollider->mSize.y = 24.0f;
	mpBoxCollider->mpTask = this;
	CCollisionManager::Get()->Add(mpBoxCollider);
	mTaskTag = EPLAYERTANK;
	mHpBar.SetHpBar(this, CVector2(0.0f, -35.0f), CVector2(50.0f, 8.0f), mColor, 100, 100);
}
void CPlayerTank::Update(){
	mItem.Update();

	if (mFireInterval > 0){
		mFireInterval--;
	}
	CTank::Update();
	if (GetKeyState('W') & 0x8000){
		Forward();
		Forward();
		Forward();
	}
	if (GetKeyState('S') & 0x8000){
		Backward();
		Backward();
		Backward();
	}
	if (GetKeyState('A') & 0x8000){
		LeftTurn();
	}
	if (GetKeyState('D') & 0x8000){
		RightTurn();
	}
	if (GetKeyState('J') & 0x8000){
		PHeadLeftTurn();
	}
	if (GetKeyState('L') & 0x8000){
		PHeadRightTurn();
	}

	if (GetKeyState(' ') & 0x8000){
		if (mFireInterval <= 0){
			mFireInterval = FIREINTERVAL_P;
			CBullet*bullet = new CBullet();
			bullet->mTaskTag = EPLAYERBULLET;
			bullet->mLife = CBULLET_LIFE;
			bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 25.0f);
			bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
			bullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
			CTaskManager::Get()->Add(bullet);
		}
	}
	mHpBar.Update();
	mItem.mMatrix = mHead.mMatrix*mItem.mMatrix;

}
void CPlayerTank::OnCollision(CCollider*p){
	if (p->mpTask->mTaskTag == EENEMYBULLET){
		CExplosion*p = new CExplosion();
		HeadRightTurn();
		HeadRightTurn();
		HeadRightTurn();
		HeadRightTurn();
		HeadRightTurn();
		HeadRightTurn();
		HeadRightTurn();
		HeadRightTurn();
		p->SetTexture(&Texture, 0, 64, 64, 0);
		p->mPosition = mPosition;
		CTaskManager::Get()->Add(p);
		mHpBar.mHp -= 1.0f;
		if (mHpBar.mHp <= 0.0f){
			mEnabled = false;
			CMain::mSceneTag = CScene::ELOSE;
		}
	}
	if (p->mpTask->mTaskTag == EBOSSBULLET){
		CExplosion*p = new CExplosion();
		p->SetTexture(&Texture, 0, 64, 64, 0);
		p->mPosition = mPosition;
		CTaskManager::Get()->Add(p);
		mHpBar.mHp -= 5.0f;
		if (mHpBar.mHp <= 0.0f){
			mEnabled = false;
			CMain::mSceneTag = CScene::ELOSE;
		}
	}
	if (p->mpTask->mTaskTag == ESPEEDENEMY){
		CExplosion*p = new CExplosion();
		p->SetTexture(&Texture, 0, 64, 64, 0);
		p->mPosition = mPosition;
		CTaskManager::Get()->Add(p);
		mHpBar.mHp -= 1.0f;
		if (mHpBar.mHp <= 0.0f){
			mEnabled = false;
			CMain::mSceneTag = CScene::ELOSE;
		}
	}

}
void CPlayerTank::Render(){
	CTank::Render();
	mHpBar.Render();
	mItem.Render();

}