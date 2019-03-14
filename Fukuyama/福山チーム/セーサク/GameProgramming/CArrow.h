//è¨êÏ

#ifndef CARROW_H
#define CARROW_H

#include "CRectangle.h"
#include "CCollider.h"

#define CARROW_VELOCITY 2.0f
#define CARROW_LIFE 180

class CArrow :public CRectangle{
public:
	CVector2 mForward;
	float mVelocity;
	int mLife;

	CArrow()
		:mForward(1.0f, 0.0f)
		, mVelocity(CARROW_VELOCITY)
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