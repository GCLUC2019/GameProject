#include"CPlayerTank.h"
#include"CBullet.h"
#include"windows.h"
#include"CExplosion.h"
#include"CMain.h"
#include"CScene.h"
#include"CKey.h"

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
#define P_VELOCITY 4
//ジャンプ初速
#define P_VELOCITY_JUMP 300
//重力加速度
#define GRAVITY 1
//間隔
#define P_FIREINTERVAL 60

#define CBLLET_LIFE 80

#define JUMP_COUNT 44
#define P_JUMP 1

#define EFFECT_COUNT 10
#define EFFECT_COUNT2 20
#define EFFECT_COUNT3 30

//extern CTexture mTexture;	//TextureからmTextureに変更
CTexture CPlayerTank::mTexImage;
CTexture CPlayerTank::mTexImage2;
CTexture CPlayerTank::mTexImage3;
CTexture CPlayerTank::mPlayerface;		//HP
CTexture CPlayerTank::mPlayerfaceD;		//HP ダメージ

CRectangle Rect;
CRectangle Rect2;

CPlayerTank *CPlayerTank::spInstance = 0;

void CPlayerTank::Init(){
	mGravityV = 0;
	AttackSide = 1;
	mTexImage.Load("Player-2.tga");
	mTexImage2.Load("P-ya.tga");
	mTexImage3.Load("P-hissatu-yumi.tga");
	mPlayerface.Load("playerface1.tga");	//HPバープレイヤー画像		追加　宮原
	mPlayerfaceD.Load("playerfaceD.tga");	//HPバープレイヤーダメージ画像
	CRectangle::SetTexture(&mTexImage, 4, 95, -238, -152);

	j_Prev = 0;
	j_Temp = 0;
	JumpCount = 0;
	EffectCount = 0;
	EffectCount2 = 0;
	EffectCount3 = 0;
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

	//プレイヤーHPバー横画像用四角形	追加宮原
	Rect.x = 115;
	Rect.y = 250;
	Rect.w = 30;
	Rect.h = 30;
	//プレイヤーHPバー横画像用四角形　ダメージ用　追加宮原
	Rect2.x = 115;
	Rect2.y = 250;
	Rect2.w = 30;
	Rect2.h = 30;

	SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	/*mHead.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mCanon.SetColor(1.0f, 1.0f, 0.8f, 1.0f);*/


	mItem.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mItem.mPosition.x = 30.0f;
	mItem.mPosition.y = 68.0f;
	mItem.SetVertex(-40.0f, -20.0f, -44.0f, 24.0f);

	mFireInterval = 0;

	mpBoxCollider = new CBoxCollider();

	mpBoxCollider->mSize.x = 20.0f;
	mpBoxCollider->mSize.y = 24.0f;
	SetVertex(-70.0f, 70.0f, -60.0f, 60.0f);
	mRotation = -90.0f;
	mpBoxCollider->mpTask = this;

	//mPlayer.SetVertex(0, 576, 384, 0);
	//mPlayer.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	CCollisionManager::Get()->Add(mpBoxCollider);
	mTaskTag = EPLAYERTANK;

	//SPバー追加カラー変更　宮原
	mHpBar.SetHpBar(this, CVector2(270.0f, 250.0f), CVector2(250.0f, 30.0f), mColor, 100, 100);
	mSpBar.SetHpBar(this, CVector2(270.0f, 220.0f), CVector2(250.0f, 30.0f), mColor, 100, 0);
	mHpBar.mBar.SetColor(0.0f, 2.0f, 0.0f, 0.0f);
	mSpBar.mBar.SetColor(0.0f, 0.0f, 2.0f, 2.0f);

	strengthen = 0;
	Invincible = 0;
	if (strengthen > 0){
		strengthen--;
	}

	spInstance = this;
}

void CPlayerTank::Update(){
	Rect.Draw(mPlayerface, 0, 144, 0, 144);			//HPバー横プレイヤー画像追加　宮原

	mItem.Update();
	if (mPosition.x > 380){
		mPosition.x = 380;
	}
	if (mPosition.x <-380){
		mPosition.x = -380;
	}
	if (JumpCount == 0){
		if (mPosition.y > -10){
			mPosition.y = -10;
		}
	}
	if (mPosition.y <-270){
		mPosition.y = -270;
	}
	if (mFireInterval > 0){
		mFireInterval--;
	}

	//if (p_Jump == 1){
	//	if (JumpCount > 0){
	//		if (JumpCount >= 20){
	//			JumpCount--;
	//			mPosition.y += 12.0f;
	//		}
	//	}
	//	if (JumpCount <= 20){
	//		JumpCount--;
	//		mPosition.y -= 14.4f;
	//	}
	//}
	//if (JumpCount == 0){
	//	p_Jump = 0;
	//}

	if (AttackSide == 0){
		if (EffectCount > 0){
			CRectangle::SetTexture(&mTexImage, 312, 413, -391, -303);
			EffectCount--;
		}
		if (EffectCount2 > 0){
			CRectangle::SetTexture(&mTexImage, 454, 549, -231, -150);
			EffectCount2--;
		}
		if (EffectCount3 > 0){
			CRectangle::SetTexture(&mTexImage, 144, 230, -526, -439);
			EffectCount3--;
		}
		if (EffectCount == 0){
			if (EffectCount2 == 0){
				if (EffectCount3 == 0){
					CRectangle::SetTexture(&mTexImage, 4, 95, -238, -152);
				}
			}
		}
	}

	if (AttackSide == 1){
		if (EffectCount > 0){
			CRectangle::SetTexture(&mTexImage, 312, 413, -303, -391);
			EffectCount--;
		}
		if (EffectCount2 > 0){
			CRectangle::SetTexture(&mTexImage, 454, 549, -150, -231);
			EffectCount2--;
		}
		if (EffectCount3 > 0){
			CRectangle::SetTexture(&mTexImage, 144, 230, -439, -526);
			EffectCount3--;
		}
		if (EffectCount == 0){
			if (EffectCount2 == 0){
				if (EffectCount3 == 0){
					CRectangle::SetTexture(&mTexImage, 4, 95, -152, -238);
				}
			}
		}
	}

	CTank::Update();

	if (EffectCount == 0){
		if (EffectCount2 == 0){
			if (EffectCount3 == 0){
				if (JumpCount == 0){
					if (GetKeyState('W') & 0x8000){
						mPosition.y += P_VELOCITY;
					}
				}
				if (JumpCount == 0){
					if (GetKeyState('S') & 0x8000){
						mPosition.y -= P_VELOCITY;
					}
				}
				if (GetKeyState('A') & 0x8000){
					mPosition.x -= P_VELOCITY;
					AttackSide = 0;
					//if (x % 30 < 15) {
					//左画像1
					CRectangle::SetTexture(&mTexImage, 4, 95, -238, -152);
					//}
				}
				if (GetKeyState('D') & 0x8000){
					mPosition.x += P_VELOCITY;
					AttackSide = 1;
					//if (x % 30 < 15) {
					//左画像1
					CRectangle::SetTexture(&mTexImage, 4, 95, -152, -238);
					//}
				}
				//if (p_Jump == 0){

				if (JumpCount == 1){
					j_Temp = mPosition.y;
					mPosition.y -= (j_Prev - mPosition.y) + 1.0f;
					j_Prev = j_Temp;
					if (mPosition.y == p_Jump){
						JumpCount = 0;
					}
				}
				if (CKey::Once(' ') && JumpCount == 0){
					JumpCount = 1;
					j_Prev = mPosition.y;
					mPosition.y += 22.0f;
					p_Jump = j_Prev;
					//mGravityV = P_VELOCITY_JUMP;

					//if (mGravityV < -GRAVITY)

					////重力速度分移動
					//mPosition.y += mGravityV;
					////重力速度更新
					//mGravityV -= GRAVITY;
					//	JumpCount = JUMP_COUNT;
					//	p_Jump = P_JUMP;
					//}

				}
				if (GetKeyState('J') & 0x8000){
					if (mFireInterval <= 0){
						mFireInterval = 30;
						if (EffectCount == 0){
							EffectCount = EFFECT_COUNT;
						}
						CBullet*bullet = new CBullet();
						bullet->mTaskTag = EPLAYERBULLET;
						bullet->mLife = 1;
						if (AttackSide == 1){
							bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 35.0f);
							bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
						}
						if (AttackSide == 0){
							bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, -35.0f);
							bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, -24.0f);
						}
						bullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
						CTaskManager::Get()->Add(bullet);
						mSpBar.mHp += 10;
					}
				}
				if (GetKeyState('K') & 0x8000){
					if (mFireInterval <= 0){
						mFireInterval = P_FIREINTERVAL;
						if (EffectCount2 == 0){
							EffectCount2 = EFFECT_COUNT2;
						}
						CBullet*bullet = new CBullet();
						bullet->SetVertex(-30.0f, 30.0f, -8.0f, 8.0f);
						bullet->mTaskTag = EPLAYERBULLET2;
						bullet->mLife = CBULLET_LIFE;
						if (AttackSide == 1){
							bullet->CRectangle::SetTexture(&mTexImage2, 0, 551, 0, 46);
							bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 28.0f);
							bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
						}
						if (AttackSide == 0){
							bullet->CRectangle::SetTexture(&mTexImage2, 551, 0, 0, 46);
							bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, -28.0f);
							bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, -24.0f);
						}
						bullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
						CTaskManager::Get()->Add(bullet);
						mSpBar.mHp += 5;
					}
				}
				if (GetKeyState('H') & 0x8000){
					if (mSpBar.mHp >= 100){
						if (EffectCount3 == 0){
							EffectCount3 = EFFECT_COUNT3;
						}
						CBullet*bullet = new CBullet();
						bullet->SetVertex(-30.0f, 30.0f, -70.0f, 70.0f);
						bullet->mTaskTag = EPLAYERBULLET3;
						bullet->mLife = 50;
						bullet->mCollider->mRadius = 30.0f;
						if (AttackSide == 1){
							bullet->CRectangle::SetTexture(&mTexImage3, 0, 466, 0, 239);
							bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, 28.0f);
							bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, 24.0f);
						}
						if (AttackSide == 0){
							bullet->CRectangle::SetTexture(&mTexImage3, 466, 0, 0, 239);
							bullet->mPosition = mCanon.mMatrix*CVector2(0.0f, -28.0f);
							bullet->mForward = bullet->mPosition - mCanon.mMatrix*CVector2(0.0f, -24.0f);
						}
						bullet->SetColor(mColor[0], mColor[1], mColor[2], mColor[3]);
						CTaskManager::Get()->Add(bullet);
						mSpBar.mHp -= 100;
					}
				}
				mHpBar.PUpdate();
				mSpBar.PUpdate();		//SP追加　宮原
				mItem.mMatrix = mHead.mMatrix*mItem.mMatrix;
			}
		}
	}
}
void CPlayerTank::OnCollision(CCollider*p){
	if (Invincible == 0){
		if (p->mpTask->mTaskTag == EENEMYBULLET){
			CExplosion*p = new CExplosion();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			Rect2.Draw(mPlayerfaceD, 0, 144, 0, 144);	//ダメージ画像追加　宮原

			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 5.0f;
			if (mHpBar.mHp <= 0.0f){
				mEnabled = false;
				CMain::mSceneTag = CScene::ELOSE;
			}
		}
		if (p->mpTask->mTaskTag == EENEMYBULLET2){
			CExplosion*p = new CExplosion();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			Rect2.Draw(mPlayerfaceD, 0, 144, 0, 144);	//ダメージ画像追加　宮原

			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 10.0f;
			if (mHpBar.mHp <= 0.0f){
				mEnabled = false;
				CMain::mSceneTag = CScene::ELOSE;
			}
		}
		if (p->mpTask->mTaskTag == EBOSSBULLET){
			CExplosion*p = new CExplosion();
			/*HeadRightTurn();
			HeadRightTurn();
			HeadRightTurn();
			HeadRightTurn();
			HeadRightTurn();
			HeadRightTurn();
			HeadRightTurn();
			HeadRightTurn();*/
			p->SetTexture(&Texture, 0, 64, 64, 0);
			Rect2.Draw(mPlayerfaceD, 0, 144, 0, 144);	//ダメージ画像追加　宮原
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
			//HeadRightTurn();
			//HeadRightTurn();
			//HeadRightTurn();
			//HeadRightTurn();
			//HeadRightTurn();
			//HeadRightTurn();
			//HeadRightTurn();
			//HeadRightTurn();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			Rect2.Draw(mPlayerfaceD, 0, 144, 0, 144);	//ダメージ画像追加　宮原

			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 1.0f;
			if (mHpBar.mHp <= 0.0f){
				mEnabled = false;
				CMain::mSceneTag = CScene::ELOSE;
			}
		}
		if (p->mpTask->mTaskTag == EBOSS){
			CExplosion*p = new CExplosion();
			p->SetTexture(&Texture, 0, 64, 64, 0);
			Rect2.Draw(mPlayerfaceD, 0, 144, 0, 144);	//ダメージ画像追加　宮原

			p->mPosition = mPosition;
			CTaskManager::Get()->Add(p);
			mHpBar.mHp -= 1.0f;
			if (mHpBar.mHp <= 0.0f){
				mEnabled = false;
				CMain::mSceneTag = CScene::ELOSE;
			}
		}
	}
	if (p->mpTask->mTaskTag == EENEMY1){
		CExplosion*p = new CExplosion();
		//mPosition = mPosition + mpBoxCollider->mAdjust;
		p->mPosition = mPosition;
	}

	if (p->mpTask->mTaskTag == EENEMY2){
		CExplosion*p = new CExplosion();
		//mPosition = mPosition + mpBoxCollider->mAdjust;
		p->mPosition = mPosition;
	}
<<<<<<< HEAD
	if (p->mpTask->mTaskTag == EITEM){
		mHpBar.mHp += 10.0f;
		printf("CItem1::OnCollision\n");
=======
	if (p->mpTask->mTaskTag == EENEMYBULLET || EENEMYBULLET2){
		if (Invincible > 0){ //無敵
			Invincible -= 1;
		}
>>>>>>> 732e224df6889b848af53c88280d2fdff8efd54d
	}
}


void CPlayerTank::OnCollision(CBoxCollider*p){
	if (p->mpTask->mTaskTag == EENEMY1){
		//mPosition = mPosition + mpBoxCollider->mAdjust;
		printf("CBullet::OnCollision\n");
		p->mPosition = mPosition;
	}
	if (p->mpTask->mTaskTag == EENEMY2){
		//mPosition = mPosition + mpBoxCollider->mAdjust;
		printf("CBullet::OnCollision\n");
		p->mPosition = mPosition;
	}

}

void CPlayerTank::Render(){
	//CTank::Render();
	CRectangle::Render();
	mHpBar.Render();
	mSpBar.Render();	//SP追加　宮原
	//mItem.Render();
}