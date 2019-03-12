//����

#ifndef CITEM_H
#define CITEM_H

#include "CRectangle.h"
#include "CCollider.h"
#include <stdlib.h>

class CItem :public CRectangle{
public:
	int mType;
	CItem()
		:mType(rand() % 3 + 1)
		//1=�� 2=���� 3=���G
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