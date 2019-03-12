#pragma once
/*�@�S��
	�����@class Enemy05
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
	int m_move_cnt;	//���U���J�E���g�ϐ�
	int mp_hp;
public:
	Enemy05(CVector2D& _pos);
	void Move();
	/*
	@brief�@�ړ��Ǘ�
	@param�@_type	[in]�@�ړ��^�C�v
	*/
	void MoveManagement(int _type);
	void Attack();
	void Damage();
	void Update();
	void Draw();
	void HitCheck(Task* _t);
	
};