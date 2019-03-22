#pragma once
#include "CObject.h"

class  CDamageEfect :public CObject
{
private:
	CImage * m_damage_p;
	double m_delete_cnt = 0;
public:
	CDamageEfect(CVector3D _pos);
	~CDamageEfect();
	void Update();
	void Draw();
};

