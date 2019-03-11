#pragma once
#include "../EnemyBase.h"
/*
“c’†@
*/
class Enemy01: public EnemyBase{
private:
    CVector2D m_vec;
    bool m_search_flg;
public:
	Enemy01();
	void Update();
	void Draw();
    void Move();
    void Search();
};