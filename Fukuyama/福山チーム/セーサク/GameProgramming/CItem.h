//è¨êÏ

#ifndef CITEM_H
#define CITEM_H

#include "Task.h"
#include "CCollider.h"
#include "CStdafx.h"

class CItem :public CRectangle{
public:
	static CItem *spInstance;
	int mType;
	CItem()
		:mType(rand() % 3 + 1)
		//1=âÒïú 2=ã≠âª 3=ñ≥ìG
	{
		Init();
	}
	void Init();
	void Update();
	void Render();

	static CTexture mTexImage;

	CCircleCollider*mCollider;

	void OnCollision(CCircleCollider*p);

	void OnCollision(CCollider*p);

};

#endif