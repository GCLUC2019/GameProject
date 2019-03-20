#ifndef CCOLLIDER_H
#define CCOLLIDER_H
#include "CRectangle.h"

class CBoxCollider;
class CCircleCollider;

class CCollider{
public:
	CRectangle*mpTask;
	CVector2 mPosition;
	//float mRadius;
	static bool Collision(CCircleCollider*p1, CCircleCollider*p2);
	static bool Collision(CCircleCollider*p1, CBoxCollider*p2);
	CVector2 mAdjust;
	CCollider*mpNext;
	virtual bool Collision(CCircleCollider*p){ return false;};
	virtual bool Collision(CBoxCollider*p){ return false; };
};

class CBoxCollider :public CCollider{
public:
	CVector2 mSize;
	bool Collision(CCircleCollider*p);
};

class CCircleCollider :public CCollider{
public:
	float mRadius;
	bool Collision(CCircleCollider*p);
};

class CCollisionManager{
private:
	static CCollisionManager*mpInstance;
	CCollider*mpHead;
	CCollider*mpTail;
	CCollisionManager()
		:mpHead(0)
		, mpTail(0)
	{}
public:
	static CCollisionManager*Get();
	void Add(CCollider*p);
	void Collision(CCircleCollider*p);
	void Collision(CBoxCollider*p);
	void Destroy();
	void Remove();
};



#endif