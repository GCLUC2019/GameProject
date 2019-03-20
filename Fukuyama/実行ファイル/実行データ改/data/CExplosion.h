#ifndef CEXPLOSION_H
#define CEXPLOSION_H
#include "CRectangle.h"

class CExplosion:public CRectangle{
public:
	float mSize;
	float mAlpha;
	int mLife;
	CExplosion()
	{
		Init();
	}
	void Init();
	void Update();

};

#endif