#include "Enemy01.h"
#define MOVE_SPEED 5.0f
Enemy01::Enemy01() : EnemyBase(eEnemy01)
{
    m_img = COPY_RESOURCE("Player", CImage*);
    m_pos = CVector2D(200, 200);
    m_vec = CVector2D(0, 0);
    m_search_flg = false;

}

void Enemy01::Update()
{
    if (m_search_flg == false)
        Search();
    else
        Move();
    m_pos += m_vec;
}

void Enemy01::Draw()
{
	m_img.SetSize(400, 200);
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Enemy01::Move()
{
    m_vec.x = MOVE_SPEED;
}

void Enemy01::Search()
{
}
