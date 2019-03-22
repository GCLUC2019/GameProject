#ifndef CBOSS_H
#define CBOSS_H
#include "CTank.h"
#include"CCollider.h"
#include"CHpBar.h"
#include"CBullet.h"


class CBoss :public CTank{
public:
	static CBoss *spInstance;

	CCircleCollider*mCollider;
	CTexture*mTexture;
	static CTexture mTextImage;
	static CTexture mTextImage3;
	
	void Init();
	void Update();
	CTank*mpTarget;
	void OnCollision(CCollider*p);
	void OnCollision(CBoxCollider*p);
	int mFireInterval;


	CHpBar mHpBar;
	void Render();
};
extern CBoss*Boss;
#endif