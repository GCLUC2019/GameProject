/*
　　　　　　　　　　　　製作者　釜田正輝
			遠距離　敵
			*/

#ifndef CENEMY2_H
#define CENEMY2_H
#include "CTank.h"
#include "CCollider.h"
#include<stdio.h>
#include "CHpBar.h"

class CEnemy2 :public CTank{
public:
	static CEnemy2 *spInstance;

	static CTexture mTexImage;
	static CTexture mTexImage2;

	int mFireIntervar;
	int EffectCount;
	int DeleteCount;

	void Init();
	void Update();
	void Render();
	CTank*mpTarget;
	CCircleCollider*mCollider;
	void OnCollision(CCollider*p);
	void OnCollision(CBoxCollider*p);
	CHpBar mHpBar;
};

#endif