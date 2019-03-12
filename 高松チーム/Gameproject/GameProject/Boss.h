#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
�S��
�Ԟ��@Boss.cppp,h
*/
class BossHead :public EnemyBase {
private:
	enum {
		eIdle,
		eMove,
		eAttack
	};
	CImage m_img2; //���u���X�U��img

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
