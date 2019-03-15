#pragma once
#include "../EnemyBase.h"
#include "../../Player.h"
#include "../GameProject/stdafx.h"
/*
	担当
	国見　class TutorialEnemy 
*/

class TutorialEnemy : public EnemyBase {
private:
	enum TutorialEnemyState {
		eMove,
		eDamage,
	};

	bool m_jump_flg;//ジャンプフラグ

public:
	TutorialEnemy(CVector2D _pos);
	void Move();
	void Damage();
	void Update();
	void Draw();
	void HitCheck();
	virtual int GetType() { return m_type; }
};