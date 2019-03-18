#ifndef CTANK_H
#define CTANK_H
#include"CRectangle.h"
#include"CCOllider.h"

class CTank :public CRectangle{
public:

	CVector2 mForward;
	CVector2 mBackward;
	CVector2 mPForward;     //追加　釜田　
	CVector2 mEForward;

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
	void PHeadLeftTurn();
	void PHeadRightTurn();
	void EnemyUp();         //追加　釜田
	void EnemyDown();
	void PForward();
	void EForward();
	void EnemyUp2();         //追加　釜田
	void EnemyDown2();
};
#endif