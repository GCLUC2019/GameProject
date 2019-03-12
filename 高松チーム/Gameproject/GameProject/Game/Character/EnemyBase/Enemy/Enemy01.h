#pragma once
#include "../EnemyBase.h"
#include "../../Player.h"
#include "../GameProject/stdafx.h"
/*
�S��
�c��  class Enemy01�@
*/

class Enemy01: public EnemyBase{
private:
    enum {
        eMove,
        eSearch,
        eAttack,
        eDamage,
    };
    CVector2D m_dir;
    int m_state;//���
    float m_hover;//���V��\�����邽�߂̕ϐ�
    bool m_search_flg;//�v���C���[�����������ǂ����̃t���O
    bool m_move_dir_flg;//�����Ffalse�E�Atrue��

public:
	Enemy01();
    Enemy01(CVector2D &_pos);
	void Update();
	void Draw();
    void Move();//�v���C���[�������̓���
    void Search();//�T�����̓���
    void Attack();//�U��
    void Damage();//�_���[�W
    void MoveControl();
    void HitCheck(Task*_t);
    bool PlayerCheck(Player*p, Task*e,float _l);//�v���C���[�����m����
};