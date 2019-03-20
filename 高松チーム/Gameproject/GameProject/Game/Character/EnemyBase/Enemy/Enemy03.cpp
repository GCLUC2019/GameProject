#include "Enemy03.h"
#include "../../Anim/AnimData.h"
#include "../../../GameData/GameData.h"
#include "../../../CollitionBase.h"
#define MOVE_SPEED 2.0f
#define DEP_N 1200

Enemy03::Enemy03() :EnemyBase(eEnemy03),
m_state(eSearch),
m_hover(0.0f),
m_search_flg(false)
{
    m_img = COPY_RESOURCE("Enemy03", CAnimImage*);
    m_pos = CVector2D(200, 200);
    m_vec = CVector2D(0, 0);
    m_dir = CVector2D(0, 0);
    m_depth = (m_pos.y - DEP_N) / 3.5;
}

Enemy03::Enemy03(CVector2D & _pos) : EnemyBase(eEnemy03),
m_state(eSearch),
m_hover(0.0f),
m_search_flg(false)
{
    m_img = COPY_RESOURCE("Enemy03", CImage*);
    m_pos = _pos;
    m_vec = CVector2D(0, 0);
    m_dir = CVector2D(0, 0);
    m_depth = (m_pos.y - DEP_N) / 3.5;
}

void Enemy03::Update()
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
    m_depth = (m_pos.y - DEP_N) / 3.5;
    m_pos += m_vec;
    MoveControl();
    m_img.UpdateAnimation();
#ifdef _DEBUG
    if (CInput::GetState(0, CInput::ePush, CInput::eMouseL)) {
        CVector2D mouse_pos = CInput::GetMousePoint();
        printf("%f,%f,%f,%f\n", mouse_pos.x - g_game_data.m_scroll.x, mouse_pos.y - g_game_data.m_scroll.y, g_game_data.m_scroll.x, g_game_data.m_scroll.y);

    }

#endif
}

void Enemy03::Draw()
{
    m_hover += 0.1f;//リセットしたほうがいい？
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.SetRect(-IMAGE_SIZE, -IMAGE_SIZE - g_game_data.m_scroll.y / 3, IMAGE_SIZE, IMAGE_SIZE - g_game_data.m_scroll.y / 3);
    m_img.SetPos(CVector2D(m_pos.x, m_pos.y + sin(m_hover)*10.0f - g_game_data.m_scroll.y / 3));
    m_img.SetFlipH(m_flip);
    m_rect = CRect(-IMAGE_SIZE / 3.5f, -IMAGE_SIZE / 5.0f - g_game_data.m_scroll.y / 3,
        IMAGE_SIZE / 3.5f, IMAGE_SIZE / 5.0f - g_game_data.m_scroll.y / 3);
    m_img.Draw();
}

void Enemy03::Move()
{
    m_img.ChangeAnimation(Enemy03State::eMove);
    m_vec = m_dir;
    /* CVector2D vec = p->GetPos() - m_pos;
    float length = sqrt(vec.x*vec.x + vec.y*vec.y);
    if (length < IMAGE_SIZE / 2)
    m_state = eAttack;*/
}

void Enemy03::Search()
{
    m_img.ChangeAnimation(Enemy03State::eMove);
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

void Enemy03::Attack()
{
    m_img.ChangeAnimation(Enemy03State::eAttack, false);
    if (m_img.CheckAnimationEnd()) {
        m_state = eSearch;
        SetKill();
    }
}

void Enemy03::Damage()
{
    m_vec.x = 0;
    if (m_hp <= 0) {
        g_game_data.m_dead_cnt++;
        m_img.ChangeAnimation(Enemy03Anim::eEDeath03, false);
        if (m_img.CheckAnimationEnd())
            SetKill();
    }
    else {
        m_img.ChangeAnimation(Enemy03Anim::eEDamage03, false);
        if (m_img.CheckAnimationEnd())
            m_state = Enemy03State::eSearch;
    }
}

void Enemy03::MoveControl()
{
}

void Enemy03::HitCheck()
{
    if (CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectLongAttack)) {
        SOUND("punch-middle2")->Play();
        m_hp -= 1;
        m_state = Enemy03State::eDamage;
    }
}
