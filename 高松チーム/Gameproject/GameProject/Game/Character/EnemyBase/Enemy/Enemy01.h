#pragma once
#include "../EnemyBase.h"
#include "../../Player.h"
/*
ìcíÜÅ@
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
    void Move();
    void Search();
    void Attack();
    bool PlayerCheck(Task*p, Task*e);
};