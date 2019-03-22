#pragma once
#include "../EnemyBase.h"
#include "../../Player.h"
#include "../GameProject/stdafx.h"
/*
�S��
�c��  class Enemy03�@
*/

class Enemy03 : public EnemyBase {
private:
    enum Enemy03State {
        eMove,
        eSearch,
        eAttack,
        eDamage,
    };
    CVector2D m_dir;
    int m_state;//���
    float m_hover;//���V��\�����邽�߂̕ϐ�
    bool m_search_flg;//�v���C���[�����������ǂ����̃t���O


public:
    Enemy03(const CVector2D &_pos);
    void Update();
    void Draw();
    void Move();//�v���C���[�������̓���
    void Search();//�T�����̓���
    void Attack();//�U��
    void Damage();//�_���[�W
    void MoveControl();
    void HitCheck();
    bool PlayerCheck(Player*p, Task*e, float _l);//�v���C���[�����m����
};