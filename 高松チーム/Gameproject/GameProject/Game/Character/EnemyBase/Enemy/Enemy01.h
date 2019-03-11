#pragma once
#include "../EnemyBase.h"
#include "../../Player.h"
#include "../GameProject/stdafx.h"
/*
担当
田中  class Enemy01　
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
    void Move();//プレイヤー発見時の動き
    void Search();//探索中の動き
    void Attack();//攻撃
    bool PlayerCheck(Player*p, Task*e,float _l);//プレイヤーを検知する
};