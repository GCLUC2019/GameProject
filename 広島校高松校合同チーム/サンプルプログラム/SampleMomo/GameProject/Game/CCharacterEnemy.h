#pragma once
#include "CCharacter.h"
#include "../Global.h"

class CCharacterEnemy : public CCharacter {
private:
	enum {
		eEnemyStateIdle,
		eEnemyStateAttack,
		eEnemyStateDamage
	};
	CImage m_enemy_img;
	int m_enemy_state;
	CVector3D m_enemy_vec;
	CVector3D m_enemy_pos;
public:
	CCharacterEnemy();
	~CCharacterEnemy();
	void Update();
	void Draw();

	void Gravity() {
		m_enemy_vec.y += GRAVITY * SPF;
		m_enemy_pos += m_enemy_vec;
		if (m_enemy_pos.y > SCREEN_HEIGHT - 100) {
			m_enemy_vec.y = 0;
			m_enemy_pos.y = SCREEN_HEIGHT - 100;
		}
	}
};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
*/
