#ifndef CPLAYER2_H
#define CPLAYER2_H

#include "CCharacter.h"
#include "CSound.h"
#include "CTexture.h"

/*
プレイヤークラス
*/
class CPlayer : public CCharacter {
private:
	int mGravityV; //重力速度
	int mStartX; //スタートX座標
	CSound mSound;
public:
	static CPlayer *spInstance; //インスタンスのポインタ
	CPlayer(CTexture *t, int x, int y, int w, int h, int u0, int u1, int v0, int v1);
	//更新処理
	void Update();
	//衝突処理
	bool Collision(CCharacter *m, CCharacter *y);
};


#endif
