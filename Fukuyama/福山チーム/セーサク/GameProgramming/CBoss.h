#ifndef CBOSS_H
#define CBOSS_H
#include "CTank.h"
#include"CCollider.h"
#include"CHpBar.h"

//êªçÏé“ åGìc

class CBoss :public CTank{
public:
	CCircleCollider*mCollider;
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