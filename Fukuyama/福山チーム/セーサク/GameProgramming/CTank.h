#ifndef CTANK_H
#define CTANK_H

#include"CRectangle.h"
#include"CCollider.h"
#include<stdio.h>


class CTank :public CRectangle{
public:
	void Init();
	void Update();
	void LeftTurn();
	void RightTurn();
	void HeadLeftTurn();
	void HeadRightTurn();

	CVector2 mForward;
	CVector2 mBackward;

	void Forward();
	void Backward();

	CRectangle mHead;
	void Render();

	CRectangle mCanon;
	CBoxCollider mBoxCollider;

	CCollider mCollider;
	void OnCollision(CCollider*p);
	void OnCollision(CBoxCollider*p);
};

#endif