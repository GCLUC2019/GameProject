#ifndef CPLAYERTANK_H
#define CPLAYERTANK_H
#include "CTank.h"
#include "CHpBar.h"

extern CTexture Texture;

class CPlayerTank :public CTank{
public:
	void Init();
	void Update();
	void Render();
	CBoxCollider*mpBoxCollider;
	int mFireInterver;
	void OnCollision(CCollider*p);
	CHpBar mHpBar;
};

#endif