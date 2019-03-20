#ifndef CHPBAR_H
#define CHPBAR_H
#include "CRectangle.h"

class CHpBar :public CRectangle{
public:
	CVector2 mSize;
	float mMax;
	float mHp;
	float mColor[4];
	CRectangle mBar;
	CRectangle*mpTask;
	void SetHpBar(CRectangle*task, const CVector2 &pos, const CVector2 &size, float*color, float max, float hp);
	void Update();
	void Render();
};

#endif