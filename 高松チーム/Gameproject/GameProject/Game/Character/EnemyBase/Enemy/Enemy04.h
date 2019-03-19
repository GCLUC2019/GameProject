#pragma once
/*
	�S��		
	����	Enemy04
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
	
	CVector2D m_distance; //�v���C���[�Ƃ̋���

	float m_hight;//����
		
	int m_cnt;
	int m_attack_cnt;
	int m_state_old;

	bool m_interval_flg;
	bool m_attack_flg;
	bool m_movetyp_flg;
		
	void Update();
	void Draw();
	void EXAttack();//����U��
	void LAttack();//�������U��
	void SAttack();//�ߐڍU��
	void Damage();//�_���[�W
	void Move();
	void AttackControl();//�U���Ǘ�
	void Alignment_y();//y�����킹
public:
	Enemy04();
	Enemy04(CVector2D _pos);

};