#ifndef CPLAYERTANK_H
#define CPLAYERTANK_H

#include"CTank.h"
#include"CHpBar.h"
#include"CSound.h"

class CPlayerTank :public CTank{
private:
	int mGravityV; //重力速度
	int mStartX; //スタートX座標
	CSound mSound;
	//CRectangle mPlayer;
public:
	float p_max_hp;	//ステータス類追加	宮原
	float p_max_sp;
	float p_min_sp;


	void Init();
	void Update();
	void OnCollision(CCollider*p);
	CBoxCollider*mpBoxCollider;
	CRectangle mPlayer;
	CTexture mTexture;
	static CTexture mTexImage;
	int mFireInterval;
	CHpBar mHpBar;

	void Render();

};
#endif