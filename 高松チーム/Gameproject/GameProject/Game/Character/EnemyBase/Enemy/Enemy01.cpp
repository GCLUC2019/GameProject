#include "Enemy01.h"
#include "../GameProject/Game/Character/Player.h"
#define MOVE_SPEED 3.0f
#define IMAGE_SIZE 100
Enemy01::Enemy01() : EnemyBase(eEnemy01)
{
    m_img = COPY_RESOURCE("Player", CImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_pos = CVector2D(200, 200);
    m_vec = CVector2D(0, 0);
    m_state = eSearch;
    m_search_flg = false;
    m_move_dir_flg = false;
}

void Enemy01::Update()
{
    switch (m_state) {
    case eMove:
        Move();
        break;
    case eSearch:
        Search();
        break;
    case eAttack:
        break;
    case eDamage:
        break;
    default:
        break;
    }
    m_pos += m_vec;
}

void Enemy01::Draw()
{
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Enemy01::Move()
{
   
}

void Enemy01::Search()
{
    if (m_move_dir_flg == false) {
        m_vec.x = MOVE_SPEED;
        if (m_pos.x > 1280 - IMAGE_SIZE / 2)
            m_move_dir_flg = true;
    }
    else {
        m_vec.x = -MOVE_SPEED;
        if (m_pos.x < IMAGE_SIZE / 2)
            m_move_dir_flg = false;
    }
}

void Enemy01::PlayerCheck()
{
}
