#pragma once
/*Å@íSìñ
	çëå©Å@class Enemy05
*/
#include "../EnemyBase.h"

class Enemy05 : public EnemyBase {
private:
	enum {
		eMove,
		eSearch,
		eAttack,
		eDamage,
	};
private:
	int m_cnt;
public:
	Enemy05();
	void Move();
	void Attack();
	void Damage();
	void Update();
	void Draw();
	
};