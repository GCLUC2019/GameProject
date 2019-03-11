#pragma once
#include "CCharacter.h"
#include "../Global.h"

class CCharacterEnemy : public CCharacter {
private:
	enum {
		eEnemyStateIdle,
		eEnemyStateMove,
		eEnemyStateAttack,
		eEnemyStateDamage
	};
	CImage m_enemy_img;
	int m_enemy_state;
	int m_enemy_hp;
	CVector3D m_enemy_vec;
	CVector3D m_enemy_pos;
	int m_AI_cnt;
	bool is_damage;
public:
	CCharacterEnemy();
	~CCharacterEnemy();
	void Update();
	void Draw();

	void Idle();
	void Move();
	void Attack();
	void Damage();


	void Gravity() {
		m_enemy_vec.y += GRAVITY * SPF;
		m_enemy_pos += m_enemy_vec;
		if (m_enemy_pos.y > SCREEN_HEIGHT - 150) {
			m_enemy_vec.y = 0;
			m_enemy_pos.y = SCREEN_HEIGHT - 150;
		}
	}
	void AiChange() {
		if (m_AI_cnt > 200) {
			m_AI_cnt = 0;
			m_enemy_state++;
			if (m_enemy_state > eEnemyStateDamage) m_enemy_state = eEnemyStateIdle;
		}
	}
};
/*
2019/03/06 クラス定義。 by shingai
*/