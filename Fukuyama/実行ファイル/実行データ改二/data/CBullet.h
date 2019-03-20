#ifndef CBULLET_H
#define CBULLET_H

#include "CRectangle.h"
#include "CCollider.h"

#define CBULLET_VELOCITY 2.0f
#define CBULLET_LIFE 120

class CBullet :public CRectangle{
public:
	CVector2 mForward;
	float mVelocity;
	int mLife;

	CBullet()
		:mForward(0.0f, 1.0f)
		, mVelocity(CBULLET_VELOCITY)
		, mLife(0)
	{
		Init();
	}

	void Init();
	void Update();
	void Render();

	CCircleCollider*mCollider;

	void OnCollision(CCircleCollider*p);

	void OnCollision(CCollider*p);
};

#endif