#ifndef CBOSS_H
#define CBOSS_H
#include "CTank.h"
#include"CCollider.h"
#include"CHpBar.h"
#include"CBullet.h"

//#define CBOSSTEXTURE_LIFE 100

class CBoss :public CTank{
public:

	CCircleCollider*mCollider;
	CTexture*mTexture;
	static CTexture mTextImage;
	static CTexture mTextImage3;
	/*static CTexture mTextImage4;
	static CTexture mTextImage6;
	*/
	void Init();
	void Update();
	CTank*mpTarget;
	void OnCollision(CCollider*p);
	void OnCollision(CBoxCollider*p);
	int mFireInterval;
	//int mTextureInterval;

	int mBossLife;


	CHpBar mHpBar;
	void Render();
};
extern CBoss*Boss;
#endif