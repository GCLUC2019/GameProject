#pragma once

#ifndef CBOSS_H
#define CBOSS_H
#include "CTank.h"
#include "CCollider.h"
#include<stdio.h>
#include "CHpBar.h"

<<<<<<< HEAD
class CBoss :public CTank {
public:
=======
//extern CBoss*Boss;

class CBoss :public CTank {
public:

>>>>>>> e044c4de01d59b26e4f73edc2316a38152d1e39e
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
