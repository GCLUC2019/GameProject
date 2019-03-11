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
    int m_state;
    bool m_search_flg;
    bool m_move_dir_flg;

public:
	Enemy01();
	void Update();
	void Draw();
    void Move();//�v���C���[�������̓���
    void Search();//�T�����̓���
    void Attack();//�U��
    bool PlayerCheck(Player*p, Task*e,float _l);//�v���C���[�����m����
};