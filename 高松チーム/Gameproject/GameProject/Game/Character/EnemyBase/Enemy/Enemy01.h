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
    int m_state;//状態
    float m_hover;//浮遊を表現するための変数
    bool m_search_flg;//プレイヤーを見つけたかどうかのフラグ
    bool m_move_dir_flg;//方向：false右、true左

public:
	Enemy01();
	void Update();
	void Draw();
    void Move();//プレイヤー発見時の動き
    void Search();//探索中の動き
    void Attack();//攻撃
    void Damage();//ダメージ
    void MoveControl();
    bool PlayerCheck(Player*p, Task*e,float _l);//プレイヤーを検知する
};