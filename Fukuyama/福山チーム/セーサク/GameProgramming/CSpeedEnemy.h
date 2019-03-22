#ifndef CSPEEDENEMY_H
#define CSPEEDENEMY_H
#include "CTank.h"
#include"CCollider.h"
#include"CHpBar.h"

class CSpeedEnemy :public CTank{
public:
	static CSpeedEnemy *spInstance;
	CCircleCollider*mCollider;
	void Init();
	void Update();
	CTank*mpTarget;
	void OnCollision(CCollider*p);
	void OnCollision(CBoxCollider*p);
	int mFireInterval;
	int mForward;
	CHpBar mHpBar;
	void Render();

	CTexture*mTexture2;
	static CTexture mTextImage2;

};
extern CSpeedEnemy*SpeedEnemy;
#endif