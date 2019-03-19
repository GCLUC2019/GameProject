#include "CCharacter.h"

//コンストラクタ
CCharacter::CCharacter(CTexture *t, int ax, int ay, int aw, int ah, int u0, int u1, int v0, int v1)
: mState(ERUN) //移動状態
, mEnabled(true)
{
	x = ax; //X座標
	y = ay; //Y座標
	w = aw; //幅
	h = ah; //高さ
	mpTexture = t;
	mU[0] = u0; //UV左
	mU[1] = u1; //UV右
	mV[0] = v0; //UV下
	mV[1] = v1; //UV上
}


//テクスチャマッピングの設定
void CCharacter::SetUv(int u0, int u1, int v0, int v1) {
	mU[0] = u0;
	mU[1] = u1;
	mV[0] = v0;
	mV[1] = v1;
}
