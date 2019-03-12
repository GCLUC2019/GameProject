#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
íSìñ
î‘ûäÅ@Boss.cppp,h
*/
class BossHead :public EnemyBase {
private:
	CVector2D m_center;

	float m_rot;//â~é¸ó¶
	float m_r;  //îºåa
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

