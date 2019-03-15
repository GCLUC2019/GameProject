#ifndef CSPEEDENEMY_H
#define CSPEEDENEMY_H
#include "CTank.h"
#include"CCollider.h"
#include"CHpBar.h"

class CSpeedEnemy :public CTank{
public:
	CCircleCollider*mCollider;
	void Init();
	void Update();
	CTank*mpTarget;
	void OnCollision(CCollider*p);
	void OnCollision(CBoxCollider*p);
	int mFireInterval;
	int mForward;
	CHpBar mHpBar;
	void Render();

};
extern CSpeedEnemy*SpeedEnemy;
#endif