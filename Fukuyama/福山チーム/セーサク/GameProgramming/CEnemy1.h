/*
　　　　　　　　　　　　製作者　釜田正輝
			近距離　敵
			*/

#ifndef CENEMY1_H
#define CENEMY1_H
#include "CTank.h"
#include "CCollider.h"
#include<stdio.h>
#include "CHpBar.h"


class CEnemy1 :public CTank{
public:
	static CEnemy1 *spInstance;
	int mFireIntervar;
	int mAttackIntervar;
	int AttackSide;
	int EffectCount;
	int DeleteCount;

	static CTexture mTexImage;
	static CTexture mTexImage2;

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