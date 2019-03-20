//è¨êÏ

#ifndef CITEM_H
#define CITEM_H

#include "Task.h"
#include "CCollider.h"
#include "CStdafx.h"

class CItem :public CRectangle, Task{
public:
	static CItem *spInstance;
	int mType;
	CItem()
		:mType(rand() % 3 + 1)
		//1=âÒïú 2=ã≠âª 3=ñ≥ìG
	{
		Init();
	}

	static CTexture mTexImage;
	static CTexture mTexImage2;
	static CTexture mTexImage3;

	void Init();
	void Update();
	void Render();

	CCircleCollider*mCollider;

	void OnCollision(CCircleCollider*p);

	void OnCollision(CCollider*p);

};

#endif