#include "Enemy02.h"
#include "../GameProject/Game/Character/Player.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Global.h"
#include "../GameProject/Game/GameData/GameData.h"
#include "../GameProject/Game/CollitionBase.h"
#include "../GameProject/Game/Character/Effect/EnemyEffect.h"
#define MOVE_SPEED 2.5f
#define DEP_N 1200
#define JUMP_SPD -20.0f
#define GRAVITY 10.0f
Enemy02::Enemy02() : EnemyBase(CharacterData::eEnemy02),
m_hight(0.0f),
m_search_flg(false),
m_jump_flg(false)
{
    m_img = COPY_RESOURCE("Enemy02", CAnimImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.ChangeAnimation(eEMove02);
    m_img.SetFlipH(m_flip);
    m_pos = CVector2D(200, 200);
    m_vec = CVector2D(0, 0);
    m_dir = CVector2D(0, 0);
    m_state = eSearch;
	m_rect = CRect(-IMAGE_SIZE / 3.5f, -IMAGE_SIZE / 5.0f, IMAGE_SIZE / 3.5f, IMAGE_SIZE / 5.0f);
    m_depth = (m_pos.y - DEP_N) / 3.5;
	m_hp = 100;
    cnt = 0;
}

Enemy02::Enemy02(CVector2D _pos) : EnemyBase(CharacterData::eEnemy02),
m_hight(0.0f),
m_search_flg(false),
m_jump_flg(false)
{
    m_img = COPY_RESOURCE("Enemy02", CAnimImage*);
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
    m_img.ChangeAnimation(eEMove02);
    m_img.SetFlipH(m_flip);
    m_pos = _pos;
    m_vec = CVector2D(0, 0);
    m_dir = CVector2D(0, 0);
    m_state = eSearch;
    m_depth = (m_pos.y - DEP_N) / 3.5;
	m_hp = 100;
	m_rect = CRect( - 47.0f, -120.0f - g_game_data.m_scroll.y/3, 54.0f, -20.0f - g_game_data.m_scroll.y / 3);
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
        m_depth = (m_pos.y - DEP_N) / 3.5;
    m_pos += m_vec;
    MoveControl();
    m_img.UpdateAnimation();
}

void Enemy02::Draw()
{
    m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
    m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE);
    m_img.SetPos(CVector2D(m_pos.x , m_pos.y + m_hight - g_game_data.m_scroll.y/3));
    m_img.SetFlipH(m_flip);
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
    if (m_flip == true) {
        m_vec.x += MOVE_SPEED;
        if (m_pos.x > 1280 - IMAGE_SIZE / 2)
            m_flip = false;
    }
    else {
        m_vec.x -= MOVE_SPEED;
        if (m_pos.x < IMAGE_SIZE / 2)
            m_flip = true;
    }
    
    Task*t = TaskManager::FindObject(ePlayer);
    Player*p = dynamic_cast<Player*>(t);
    if (p!=nullptr&&PlayerCheck(p,50.0f)) {
        Move();
    }
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
            TaskManager::AddTask(new E2Effect(CVector2D(m_pos.x,m_pos.y-IMAGE_SIZE/3)));
        }
    }
    if (m_img.CheckAnimationEnd()) {
        m_state = eSearch;
    }
}

void Enemy02::Damage()
{
	m_vec.x = 0;
	if (m_hp <= 0) {
		m_img.ChangeAnimation(Enemy02Anim::eEDeath02, false);
		if (m_img.CheckAnimationEnd())
			SetKill();
	}
	else {
		m_img.ChangeAnimation(Enemy02Anim::eEDamage02, false);
		if (m_img.CheckAnimationEnd())
			m_state = Enemy02State::eSearch;
	}
}

void Enemy02::MoveControl()
{
}

void Enemy02::HitCheck()
{
	if (CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack01) ||
		CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack02) ||
		CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack03))
	{
		SOUND("punch-middle2")->Play();
		m_hp -= 1;
		m_state = Enemy02State::eDamage;
	}
}

bool Enemy02::PlayerCheck(Player * p, float _l)
{
    CollisionLine l1, l2;
    l1.s = m_pos; l1.e = m_pos + CVector2D(1, 1)*_l;
    return false;
}
