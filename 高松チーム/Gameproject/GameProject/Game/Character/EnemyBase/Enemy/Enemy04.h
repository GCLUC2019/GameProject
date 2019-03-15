#pragma once
/*
	�S��		
	����	Enemy04
*/

#include"../EnemyBase.h"
class Enemy04 : public EnemyBase {
private:
	enum Enemy04State {
		eMove,
		eSearch,
		eAttack,
		eDamage,
	};
	CVector2D m_dir;
	float m_hight;//����
	bool m_search_flg;//�v���C���[�����������ǂ����̃t���O

	int cnt;
	void Update();
	void Draw();
	void Move();//�v���C���[�������̓���
	void Search();//�T�����̓���
	void Attack();//�U��
	void Damage();//�_���[�W
	void MoveControl();
public:
	Enemy04();
	Enemy04(CVector2D _pos);

};