#include "Enemy01.h"
#include "../GameProject/Game/Character/Player.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Game/GameData/GameData.h"

#define MOVE_SPEED 2.0f
#define DEP_N 1200

Enemy01::Enemy01() : EnemyBase(CharacterData::eEnemy01),
m_state(eSearch),
m_hover(0.0f),
m_search_flg (false)
{
    m_img = COPY_RESOURCE("Enemy01", CAnimImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.SetFlipH(m_flip);
    m_img.ChangeAnimation(eEMove01);
    m_pos = CVector2D(200, 200);
    m_vec = CVector2D(0, 0);
    m_dir = CVector2D(0, 0);
    m_depth = m_pos.y / DEP_N;
}

Enemy01::Enemy01(CVector2D & _pos) : EnemyBase(eEnemy01),
m_state(eSearch),
m_hover(0.0f),
m_search_flg(false)
{
    m_img = COPY_RESOURCE("Enemy01", CAnimImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.SetFlipH(m_flip);
    m_img.ChangeAnimation(eEMove01);
    m_pos = _pos;
    m_vec = CVector2D(0, 0);
    m_dir = CVector2D(0, 0);
    m_depth = m_pos.y / DEP_N;
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
        Attack();
        break;
    case eDamage:
        Damage();
        break;
    default:
        break;
    }
    m_depth = m_pos.y / DEP_N;
    m_pos += m_vec;
    MoveControl();
    m_img.UpdateAnimation();
}

void Enemy01::Draw()
{
    
    m_hover += 0.1f;//リセットしたほうがいい？
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.SetPos(CVector2D(m_pos.x, m_pos.y + sin(m_hover)*10.0f));
    m_img.SetFlipH(m_flip);
	m_img.Draw();
}

void Enemy01::Move()
{
    m_img.ChangeAnimation(eEMove01);
    m_vec = m_dir;
   /* CVector2D vec = p->GetPos() - m_pos;
    float length = sqrt(vec.x*vec.x + vec.y*vec.y);
    if (length < IMAGE_SIZE / 2)
        m_state = eAttack;*/
}

void Enemy01::Search()
{
    m_img.ChangeAnimation(eEMove01);
    if (m_flip == true) {
        m_vec.x = MOVE_SPEED;
        if (m_pos.x > 1280 - IMAGE_SIZE / 2)
            m_flip = false;
    }
    else {
        m_vec.x = -MOVE_SPEED;
        if (m_pos.x < IMAGE_SIZE / 2)
            m_flip = true;
    }
    /*Player*p = nullptr;
    if (PlayerCheck(p, this,300.0f)) {
    m_dir=GetNormalize(playerpos-m_pos);
        m_state = eMove;
    }*/
}

void Enemy01::Attack()
{
    m_img.ChangeAnimation(eEAttack01, false);
    if (m_img.CheckAnimationEnd()) {
        m_state = eSearch;
        SetKill();
    }
       
}
void Enemy01::Damage()
{
    m_img.ChangeAnimation(eEDamage01, false);
    if (m_img.CheckAnimationEnd())
        m_state = eSearch;
}
void Enemy01::MoveControl()
{
}
void Enemy01::HitCheck(Task * _t)
{
    Task*t = TaskManager::FindObject(ePlayer);
    if (t) {
        printf("Player発見\n");
    }
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
