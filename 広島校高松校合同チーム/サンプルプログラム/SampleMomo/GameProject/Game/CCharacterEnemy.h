#pragma once
#include "CCharacter.h"
#include "../Global.h"



enum {
	eEnemyAnimIdIdle,
	eEnemyAnimIdMove,
	eEnemyAnimIdAttack,
	eEnemyAnimIdDamage,
	eEnemyAnimIdMax,
};

enum {
	eEnemyAnimIdle0,
	eEnemyAnimMove0,
	eEnemyAnimAttack0,
	eEnemyAnimDamage0,
	eEnemyAnimMax,
};


class CCharacterEnemy : public CCharacter {
private:
	enum {
		eEnemyStateIdle,
		eEnemyStateMove,
		eEnemyStateAttack,
		eEnemyStateDamage
	};
	int m_enemy_state;
	int m_enemy_hp;
	int m_AI_cnt;
	bool is_damage;
public:
	CCharacterEnemy();
	~CCharacterEnemy();
	void CharacterUpdate();
	void CharacterDraw();

	void LoadAnimImage();
	void Idle();
	void Move();
	void Attack();
	void Damage();
	void MovePos();

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