#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
’S“–
”ÔŠ@Boss.cppp,h
*/
class BossHead :public EnemyBase {
private:
	enum {
		eIdle,
		eMove,
		eAttack
	};
	CImage m_img2; //‰¡ƒuƒŒƒXUŒ‚img

	CVector2D m_center;

	float m_rot;
	float m_r;
	int m_state;
protected:


public:
	BossHead();

	void Update();

	void Idle();

	void Attack();

	void Draw();

};
