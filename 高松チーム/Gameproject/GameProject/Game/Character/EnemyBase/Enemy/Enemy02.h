#pragma once
#include "../EnemyBase.h"
#include "../../Player.h"
#include "../GameProject/stdafx.h"
/*
�S��
�c��  class Enemy02�@
*/

class Enemy02 : public EnemyBase {
private:
    enum Enemy02State{
        eMove,
        eSearch,
        eAttack,
        eDamage,
    };
    CVector2D m_dir;
    float m_hight;//����
    bool m_search_flg;//�v���C���[�����������ǂ����̃t���O
    bool m_jump_flg;//�W�����v�t���O

    int cnt;
public:
    Enemy02();
    Enemy02(CVector2D _pos);
    void Update();
    void Draw();
    void Move();//�v���C���[�������̓���
    void Search();//�T�����̓���
    void Attack();//�U��
    void Damage();//�_���[�W
    void MoveControl();
    //bool PlayerCheck(Player*p, Task*e, float _l);//�v���C���[�����m����
};