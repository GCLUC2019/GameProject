#pragma once
#include "CGameSceneObject.h"

class  CDamageEfect :public CGameSceneObject
{
private:
	CImage * m_damage_p;
	CVector3D* m_target_p;
	double m_delete_cnt = 0;
public:
	CDamageEfect(CVector3D * _pos_p);
	~CDamageEfect();
	void Update();
	void Draw();
	void LoadAnimImage();
};

