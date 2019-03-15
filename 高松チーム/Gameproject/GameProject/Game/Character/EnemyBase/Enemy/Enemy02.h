#pragma once
#include "../EnemyBase.h"
#include "../../Player.h"
#include "../GameProject/stdafx.h"
/*
担当
田中  class Enemy02　
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
    float m_hight;//高さ
    bool m_search_flg;//プレイヤーを見つけたかどうかのフラグ
    bool m_jump_flg;//ジャンプフラグ

    int cnt;
public:
    Enemy02();
    Enemy02(CVector2D _pos);
    void Update();
    void Draw();
    void Move();//プレイヤー発見時の動き
    void Search();//探索中の動き
    void Attack();//攻撃
    void Damage();//ダメージ
    void MoveControl();
    //bool PlayerCheck(Player*p, Task*e, float _l);//プレイヤーを検知する
};