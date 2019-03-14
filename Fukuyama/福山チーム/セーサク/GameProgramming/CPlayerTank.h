#ifndef CPLAYERTANK_H
#define CPLAYERTANK_H
#include"CTank.h"
#include"CHpBar.h"

class CPlayerTank :public CTank{
public:
	void Init();
	void Update();
	void OnCollision(CCollider*p);
	CBoxCollider*mpBoxCollider;
	int mFireInterval;
	CHpBar mHpBar;

	void Render();

};
#endif