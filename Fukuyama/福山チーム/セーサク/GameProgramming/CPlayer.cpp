#include "CPlayer.h"
#include "CKey.h"
//#include "CBlock.h"

//プレイヤー移動速度
#define VELOCITY_P 2
//ジャンプ初速
#define VELOCITY_JUMP 15
//重力加速度
#define GRAVITY 1
//重力加速度
#define GRAV0ITY GRAVITY

//UVマッピング プレイヤーの歩き
#define UVPLAYERWALK1 136, 156, 158, 130
#define UVPLAYERWALK2 168, 188, 158, 130
#define UVPLAYERWALK1L 156, 136, 158, 130
#define UVPLAYERWALK2L 188, 168, 158, 130
//プレイヤー泣き
#define UVPLAYERCRY 196, 216, 158, 130

//プレイヤーのインスタンス
CPlayer *CPlayer::spInstance = 0;
//float Gravity = 0.5;
float Gravity = (GRAV0ITY);
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
	if (CKey::Push('D')) {
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
	if (CKey::Push('A')) {
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
	if (CKey::Once(' ') && mState == ERUN) {
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
	mGravityV -= GRAVITY;
}

/*
プレイヤーの衝突処理
*/
bool CPlayer::Collision(CCharacter *m, CCharacter *yo) {
	//int dx, dy;
	////相手と衝突しているか判定
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
	//	case EBLOCK: //相手がブロック
	//		//ブロッククラスへキャスト
	//		CBlock *b = (CBlock*)yo;
	//		//左へ調整の時
	//		if (dx < 0) {
	//			//左が空いているか判定
	//			if ((b->mType & 0x08) == 0) {
	//				//空いていない場合
	//				dx = w*2;//大きい値を代入
	//			}
	//		}
	//		//右へ調整の時
	//		else if (dx > 0) {
	//			//右が空いているか判定
	//			if ((b->mType & 0x02) == 0) {
	//				//空いていない場合
	//				dx = w * 2;//大きい値を代入
	//			}
	//		}
	//		//下へ調整の場合
	//		if (dy < 0) {
	//			//下が空いているか判定
	//			if ((b->mType & 0x04) == 0) {
	//				dy = h*2;
	//			}
	//		}
	//		//上へ調整の場合
	//		else if (dy > 0) {
	//			//上が空いているか判定
	//			if ((b->mType & 0x01) == 0) {
	//				dy = h*2;
	//			}
	//		}
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
	////衝突していない
	return false;
}
