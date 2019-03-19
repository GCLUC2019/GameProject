#include"CPlayerTank.h"
#include"CBullet.h"
#include"windows.h"
#include"CExplosion.h"
#include"CMain.h"
#include"CScene.h"

/*
制作者　宮原
*/

/*
プレイヤステータス,攻撃,移動速度,
ジャンプ初速,重力加速度追加　03/18
*/

//プレイヤステータス
#define P_MAX_HP 100
#define P_MAX_SP 100
#define P_MIN_SP 0
//攻撃
#define P_ATTACK_D 20
#define P_ARROW_D 10
#define P_SKILL_D 30
#define P_SKILL2_D 50

//プレイヤー移動速度
#define P_VELOCITY 2
//ジャンプ初速
#define P_VELOCITY_JUMP 15
//重力加速度
#define GRAVITY 1
//間隔
#define P_FIREINTERVAL 30

//extern CTexture mTexture;	//TextureからmTextureに変更
CTexture CPlayerTank::mTexImage;

void CPlayerTank::Init(){
	mTexture.Load("player1.tga");
	CRectangle::SetTexture(&mTexture, 56, 10, 63, 50);

	/*
	mTexture.Load("Player1.tga");
	mPlayer.SetVertex(0, 576, 384, 0);
	mPlayer.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mPlayer.SetTexture(&mTexture, 56, 10, 63, 0);
	*/

	CTank::Init();

	p_max_hp = 100.0f;
	p_max_sp = 100.0f;
	p_min_sp = 0.0f;

	SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	/*mHead.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mCanon.SetColor(1.0f, 1.0f, 0.8f, 1.0f);*/


	mItem.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mItem.mPosition.x = 30.0f;
	mItem.mPosition.y = 68.0f;
	mItem.SetVertex(-40.0f, -20.0f, -44.0f, 24.0f);

	mFireInterval = P_FIREINTERVAL;

	mpBoxCollider = new CBoxCollider();

	mpBoxCollider->mSize.x = 20.0f;
	mpBoxCollider->mSize.y = 24.0f;
	mpBoxCollider->mpTask = this;
	//mPlayer.SetVertex(0, 576, 384, 0);
	//mPlayer.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	CCollisionManager::Get()->Add(mpBoxCollider);
	mTaskTag = EPLAYERTANK;
	mHpBar.SetHpBar(this, CVector2(0.0f, -35.0f), CVector2(50.0f, 8.0f), mColor, 100, 100);
}

void CPlayerTank::Update(){
	mItem.Update();

	if (mPosition.x > 390){
		mPosition.x = 390;
	}
	if (mPosition.x <-390){
		mPosition.x = -390;
	}
	if (mFireInterval > 0){
		mFireInterval--;
	}

	CTank::Update();
	
	if (GetKeyState('W') & 0x8000){
		mPosition.y += P_VELOCITY;
	}
	if (GetKeyState('S') & 0x8000){
		mPosition.y -= P_VELOCITY;
	}
	if (GetKeyState('A') & 0x8000){
		mPosition.x -= P_VELOCITY;
	}
	if (GetKeyState('D') & 0x8000){
		mPosition.x += P_VELOCITY;
	}
	if (GetKeyState('J') & 0x8000){
		PHeadLeftTurn();
	}
	if (GetKeyState('L') & 0x8000){
		PHeadRightTurn();
	}

	if (GetKeyState(' ') & 0x8000){
			mGravityV = P_VELOCITY_JUMP;
		
		if (mGravityV < -GRAVITY)

		////重力速度分移動
		mPosition.y += mGravityV;
		////重力速度更新
		mGravityV -= GRAVITY;
		if (mFireInterval <= 0){
			mFireInterval = P_FIREINTERVAL;
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
		mHpBar.mHp -= 5.0f;
		if (mHpBar.mHp <= 0.0f){
			mEnabled = false;
			CMain::mSceneTag = CScene::ELOSE;
		}
	}
	if (p->mpTask->mTaskTag == ESPEEDENEMY){
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
		mHpBar.mHp -= 5.0f;
		if (mHpBar.mHp <= 0.0f){
			mEnabled = false;
			CMain::mSceneTag = CScene::ELOSE;
		}
	}

}
void CPlayerTank::Render(){
	//CTank::Render();
	CRectangle::Render();
	mHpBar.Render();
	//mItem.Render();
}