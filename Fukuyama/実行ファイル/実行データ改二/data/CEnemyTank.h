#ifndef CENEMYTANK_H
#define CENEMYTANK_H
#include "CTank.h"
#include "CCollider.h"
#include<stdio.h>
#include "CHpBar.h"

class CEnemyTank :public CTank{
public:
	int mFireIntervar;	
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