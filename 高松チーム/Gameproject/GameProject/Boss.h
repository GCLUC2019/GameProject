#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
�S��
�Ԟ��@Boss.cppp,h
*/
class BossHead :public EnemyBase {
private:
	CVector2D m_center;

	float m_rot;//�~����
	float m_r;  //���a
protected:


public:
	BossHead();

	void Update();

	void Draw();

};


class BossHand :public EnemyBase {
private:

	CVector2D m_center;

	float m_rot;
	float m_r;
protected:


public:
	BossHand();

	void Update();

	void Draw();

};

