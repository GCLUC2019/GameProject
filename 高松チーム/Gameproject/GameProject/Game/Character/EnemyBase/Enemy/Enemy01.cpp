#include "Enemy01.h"
#include "../GameProject/Game/Character/Player.h"
#include "../../Anim/AnimData.h"

#define MOVE_SPEED 2.0f
Enemy01::Enemy01() : EnemyBase(eEnemy01),
m_state(eSearch),
m_hover(0.0f),
m_search_flg (false),
m_move_dir_flg(false)
{
    m_img = COPY_RESOURCE("Enemy01", CAnimImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.ChangeAnimation(eEMove01);
    m_pos = CVector2D(200, 200);
    m_vec = CVector2D(0, 0);
}

void Enemy01::Update()
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

void Enemy01::Draw()
{
    m_hover += 0.1f;//リセットしたほうがいい？
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.SetPos(CVector2D(m_pos.x, m_pos.y + sin(m_hover)*5.0f));
	m_img.Draw();
}

void Enemy01::Move()
{
    m_img.ChangeAnimation(eEMove01);
}

void Enemy01::Search()
{
    m_img.ChangeAnimation(eEMove01);
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
    /*Player*p = nullptr;
    if (PlayerCheck(p, this,300.0f)) {
        m_state = eMove;
    }*/
}

void Enemy01::Attack()
{
    m_img.ChangeAnimation(eEAttack01,false);
    if (m_img.CheckAnimationEnd())
        m_state = eSearch;
}
void Enemy01::Damage()
{
    m_img.ChangeAnimation(eEDamage01);
}
void Enemy01::MoveControl()
{
}
//2019/3/11タスクの探索処理ができ次第実装可能　田中
bool Enemy01::PlayerCheck(Player*p, Task*e, float _l)
{
    /*CVector2D vec= p->GetPos() - m_pos;
    float length = sqrt(vec.x*vec.x + vec.y*vec.y);
    if (length <= _l)
        return true;
    else
        return false;*/
    return false;
}
