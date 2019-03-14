#ifndef CTANK_H
#define CTANK_H
#include"CRectangle.h"
#include"CCOllider.h"

class CTank :public CRectangle{
public:

	CVector2 mForward;
	CVector2 mBackward;
	CRectangle mHead;
	CRectangle mCanon;
	CRectangle mItem;

	CBoxCollider mBoxCollider;
	void OnCollision(CCollider*p);

	void Init();
	void Update();
	void LeftTurn();
	void RightTurn();
	void Forward();
	void Backward();
	void Render();
	void HeadLeftTurn();
	void HeadRightTurn();

};
#endif