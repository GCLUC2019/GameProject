#include "CPlayer.h"



//プレイヤー移動速度
#define VELOCITY_P 2
//ジャンプ初速
#define VELOCITY_JUMP 15
//重力加速度
#define GRAVITY 1
#define GRAVITY2 0

//UVマッピング プレイヤーの歩き
#define UVPLAYERWALK1 136, 156, 158, 130
#define UVPLAYERWALK2 168, 188, 158, 130
#define UVPLAYERWALK1L 156, 136, 158, 130
#define UVPLAYERWALK2L 188, 168, 158, 130
//プレイヤー泣き
#define UVPLAYERCRY 196, 216, 158, 130

int NotAttack = 0;  //追加　釜田　　

//プレイヤーのインスタンス
CPlayer *CPlayer::spInstance = 0;

CPlayer::CPlayer(CTexture *t, int x, int y, int w, int h, int u0, int u1, int v0, int v1)
: CCharacter(t, x, y, w, h, u0, u1, v0, v1)
, mGravityV(0)
, mStartX(x)
{
	mTag = CCharacter::EPLAYER;
	//インスタンスポインタに設定
	spInstance = this;
	//サウンドロード
	mSound.Load("jump.mp3");
}

/*
プレイヤーの更新処理
*/
void CPlayer::Update() {
	//右へ移動
	if (GetKeyState('D') & 0x8000) {
		x += VELOCITY_P;
		//X座標によって画像を変える
		if (x % 30 < 15) {
			//右画像1
			SetUv(UVPLAYERWALK1);
		}
		else {
			//右画像2
			SetUv(UVPLAYERWALK2);
		}
	}
	//左へ移動
	if (GetKeyState('A') & 0x8000) {
		//開始位置より左へ行かせない
		if (mStartX < x)
			x -= VELOCITY_P;
		//X座標によって画像を変える
		if (x % 30 < 15) {
			//左画像1
			SetUv(UVPLAYERWALK1L);
		}
		else {
			//左画像2
			SetUv(UVPLAYERWALK2L);
		}
	}
	//ジャンプする
	if (GetKeyState(' ') & 0x8000 && mState == ERUN) {
		mGravityV = VELOCITY_JUMP;
		//ジャンプ上
		mState = EJUMPUP;
		//1回再生
		mSound.Play();
	}
	if (mGravityV < -GRAVITY)
		//ジャンプ下
		mState = EJUMPDOWN;
	//重力速度分移動
	y += mGravityV;
	//重力速度更新
	mGravityV -= GRAVITY2;
}

/*
プレイヤーの衝突処理
*/
bool CPlayer::Collision(CCharacter *m, CCharacter *yo) {
	//int dx, dy;
	//相手と衝突しているか判定
	//if (CRectangle::Collision(yo, &dx, &dy)) {
	//	switch (yo->mTag) {
	//	case EENEMY: //相手が敵の時
	//		switch (yo->mState) {
	//		case ERUN:
	//			if (mState == ERUN) {
	//				mState = ECRY;
	//				SetUv(UVPLAYERCRY);
	//			}
	//			break;
	//		case ECRY:
	//			//戻りが小さい方へ戻す
	//			if (abs(dx) < abs(dy)) {
	//				x += dx;
	//			}
	//			else {
	//				y += dy;
	//				//重力初期化
	//				mGravityV = 0;
	//				//歩く
	//				mState = ERUN;
	//			}
	//			break;
	//		}
	//		break;
	//		//戻りが小さい方へ戻す
	//		if (abs(dx) < abs(dy)) {
	//			x += dx;
	//		}
	//		else {
	//			y += dy;
	//			//重力初期化
	//			mGravityV = 0;
	//			//歩く
	//			mState = ERUN;
	//		}
	//		break;
	//	}
	//	//衝突している
	//	return true;
	//}
	//衝突していない
	return false;
}
