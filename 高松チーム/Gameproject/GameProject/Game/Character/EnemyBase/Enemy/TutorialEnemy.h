#pragma once
#include "../EnemyBase.h"
#include "../../Player.h"
#include "../GameProject/stdafx.h"
/*
	�S��
	�����@class TutorialEnemy 
*/

class TutorialEnemy : public EnemyBase {
private:
	enum TutorialEnemyState {
		eMove,
		eDamage,
	};

	float m_hight;	//����
	bool m_flip;	//���]
	bool m_jump_flg;//�W�����v�t���O

public:
	TutorialEnemy(CVector2D _pos);
	void Move();
	void Damage();
	void Update();
	void Draw();
	void HitCheck();
};