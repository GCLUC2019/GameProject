#include "Enemy02.h"
#include "../GameProject/Game/Character/Player.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Global.h"
#include "../GameProject/Game/GameData/GameData.h"
#define MOVE_SPEED 2.5f
#define DEP_N 1200
#define JUMP_SPD -20.0f
#define GRAVITY 10.0f
Enemy02::Enemy02() : EnemyBase(eEnemy02),
m_hight(0.0f),
m_search_flg(false),
m_move_dir_flg(true),
m_jump_flg(false)
{
    m_img = COPY_RESOURCE("Enemy02", CAnimImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.ChangeAnimation(eEMove02);
    m_img.SetFlipH(m_move_dir_flg);
    m_pos = CVector2D(200, 200);
    m_vec = CVector2D(0, 0);
    m_dir = CVector2D(0, 0);
    m_state = eSearch;
    m_depth = m_pos.y / DEP_N;

    cnt = 0;
}

Enemy02::Enemy02(CVector2D _pos) : EnemyBase(eEnemy02),
m_hight(0.0f),
m_search_flg(false),
m_move_dir_flg(true),
m_jump_flg(false)
{
    m_img = COPY_RESOURCE("Enemy02", CAnimImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.ChangeAnimation(eEMove02);
    m_img.SetFlipH(m_move_dir_flg);
    m_pos = _pos;
    m_vec = CVector2D(0, 0);
    m_dir = CVector2D(0, 0);
    m_state = eSearch;
    m_depth = m_pos.y / DEP_N;

    cnt = 0;
}

void Enemy02::Update()
{
    if(m_jump_flg==false)
    cnt++;
    if (cnt > 300) {
        m_state = eAttack;
        m_jump_flg = true;
        cnt = 0;
    }
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
    
    m_pos += m_vec;
    MoveControl();
    m_img.UpdateAnimation();
}

void Enemy02::Draw()
{
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.SetPos(CVector2D(m_pos.x - g_game_data.m_scroll.x, m_pos.y + m_hight - g_game_data.m_scroll.y));
    m_img.SetFlipH(m_move_dir_flg);
    m_img.Draw();
}

void Enemy02::Move()
{
    m_img.ChangeAnimation(eEMove02);
    /* CVector2D vec = p->GetPos() - m_pos;
    float length = sqrt(vec.x*vec.x + vec.y*vec.y);
    if (length < IMAGE_SIZE / 2)
    m_state = eAttack;*/
    m_jump_flg = true;
}

void Enemy02::Search()
{
    m_img.ChangeAnimation(eEMove02);
    if (m_move_dir_flg == true) {
        m_vec.x += MOVE_SPEED;
        if (m_pos.x > 1280 - IMAGE_SIZE / 2)
            m_move_dir_flg = false;
    }
    else {
        m_vec.x -= MOVE_SPEED;
        if (m_pos.x < IMAGE_SIZE / 2)
            m_move_dir_flg = true;
    }
    
    /*Player*p ;
    if (PlayerCheck(p, this,300.0f)) {
    m_dir=GetNormalize(playerpos-m_pos);
    m_state = eMove;
    }*/
}

void Enemy02::Attack()
{
    m_img.ChangeAnimation(eEAttack02, false);
    float bound = false;
    if (m_jump_flg) {
        cnt++;
        m_hight = 0 + JUMP_SPD * cnt + GRAVITY / 10 * (cnt*cnt) / 2;
        if (m_hight > 0) {
            m_hight = 0;
            cnt = 1;
            m_jump_flg = false;
        }
    }
    if (m_img.CheckAnimationEnd()) {
        m_state = eSearch;
    }
}

void Enemy02::Damage()
{
    m_img.ChangeAnimation(eEDamage02);
}

void Enemy02::MoveControl()
{
}
