#ifndef CBOSSBULLET_H
#define CBOSSBULLET_H
#include "CRectangle.h"
#define CBOSSBULLET_VELOCITY 2.0f
#define CBOSSBULLET_LIFE 200
#include"CCollider.h"


class CBossBullet :public CRectangle{
public:
	CVector2 mForward;
	float mVelocity;
	int mLife;
	CCircleCollider*mCollider;

	CBossBullet()
		:mForward(0.0f, 1.0f)
		, mVelocity(CBOSSBULLET_VELOCITY)
		, mLife(0){
		Init();
	}

	static CTexture mTextImage5;

	void Init();
	void Update();
	void Render();
	void OnCollision(CCollider*p);


};


#endif