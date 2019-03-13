#pragma once

#ifndef CBOSS_H
#define CBOSS_H
#include "CTank.h"
#include "CCollider.h"
#include<stdio.h>
#include "CHpBar.h"

//extern CBoss*Boss;

class CBoss :public CTank {
public:

	int mFireIntervar;
	void Init();
	void Update();
	void Render();
	CTank*mpTarget;
	CCircleCollider*mCollider;
	void OnCollision(CCollider*p);
	void OnCollision(CBoxCollider*p);
	CHpBar mHpBar;

	
	};



#endif
