#include "Enemy02.h"
#include "../GameProject/Game/Character/Player.h"
#include "../../Anim/AnimData.h"
#define MOVE_SPEED 2.5f
Enemy02::Enemy02() : EnemyBase(eEnemy02),
m_state(eSearch),
m_hover(0.0f),
m_search_flg(false),
m_move_dir_flg(false)
{
    m_img = COPY_RESOURCE("Enemy02", CAnimImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.ChangeAnimation(eEMove02);
    m_pos = CVector2D(200, 200);
    m_vec = CVector2D(0, 0);
}

void Enemy02::Update()
{
    m_vec = CVector2D(0, 0);
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
    MoveControl();
    m_img.UpdateAnimation();
}

void Enemy02::Draw()
{
    m_hover += 0.1f;//リセットしたほうがいい？
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.SetPos(CVector2D(m_pos.x, m_pos.y + sin(m_hover)*5.0f));
    m_img.Draw();
}

void Enemy02::Move()
{
    m_img.ChangeAnimation(eEMove02);
}

void Enemy02::Search()
{
    m_img.ChangeAnimation(eEMove02);
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

void Enemy02::Attack()
{
    m_img.ChangeAnimation(eEAttack02,false);
    if (m_img.CheckAnimationEnd())
        m_state = eSearch;
}

void Enemy02::Damage()
{
    m_img.ChangeAnimation(eEDamage02);
}

void Enemy02::MoveControl()
{
}
