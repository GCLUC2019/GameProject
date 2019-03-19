#pragma once
/*
	’S“–		
	’†”ö	Enemy04
*/

#include"../EnemyBase.h"
class Enemy04 : public EnemyBase {
private:
	enum Enemy04State {
		eIdle,
		eMove,
		eEXAttack,
		eLAttack,
		eSAttack,
		eDamage,
		eDeath,
	};
	
	CVector2D m_distance; //ƒvƒŒƒCƒ„[‚Æ‚Ì‹——£

	float m_hight;//‚‚³
		
	int m_cnt;
	int m_damage_cnt;
	int m_attack_cnt;
	int m_state_old;

	bool m_interval_flg;
	bool m_attack_flg;
	bool m_lattack_flg;
	bool m_sattack_flg;
	bool m_exattack_flg;
	bool m_movetyp_flg;
	bool m_movexy_flg;
	bool m_damage_flg;
		
	void Update();
	void Draw();
	void EXAttack();//“ÁêUŒ‚
	void LAttack();//‰“‹——£UŒ‚
	void SAttack();//‹ßÚUŒ‚
	void Move();
	void AttackControl();//UŒ‚ŠÇ—
	void Alignment_y();//y²‡‚í‚¹
	void DamageState();
public:
	Enemy04();
	Enemy04(CVector2D _pos);
	void Damage(const float& _damage);

};