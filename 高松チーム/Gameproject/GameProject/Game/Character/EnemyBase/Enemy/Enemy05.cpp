#include "Enemy05.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../../CharacterBase.h"
#include "../../Player.h"
#include "../GameProject/Game/CollitionBase.h"
#include "../GameProject/Game/GameData/GameData.h"
#define MOVE_ 360

#define GRAVITY -4//重力
#define DEP_N 540//奥行重石
#define JUMP_SPD 50
#define SAIZE_SD 110

Enemy05::Enemy05(CVector2D& _pos) : EnemyBase(CharacterData::eEnemy05),
m_move_cnt(0)
{
	//初期化
	m_img = COPY_RESOURCE("Enemy05", CAnimImage*);
	m_shadow = COPY_RESOURCE("Shadow", CImage*);
	m_pos = _pos;
	m_vec = CVector2D(0, 0);
	m_hp = 100;
	m_img.SetFlipH(m_flip);
	m_move_cnt = 0;
	m_rect = CRect(-IMAGE_SIZE / 3.0f, -IMAGE_SIZE / 5.0f, IMAGE_SIZE / 3.5f, IMAGE_SIZE / 2.5f);
	m_depth = (m_pos.y - DEP_N) / 3.5;
	m_state = Enemy05State::eMove;
}

void Enemy05::Move()
{
	MoveManagement(0);
	m_img.ChangeAnimation(Enemy05Anim ::eEMove05);
}

void Enemy05::MoveManagement(int _type)
{
	switch (_type) {
	case 0:
		//仮移動
		++m_move_cnt;
		if (m_move_cnt <= MOVE_ / 2) {
			m_vec.x = 2.0f;
			//m_pos.y += 0.2f;
			//m_depth = (m_pos.y - DEP_N) / 3.5;
			m_flip = true;
		}
		else if (m_move_cnt >= MOVE_/2) {
			m_vec.x = -2.0f;
			m_flip = false;
		}
		if (m_move_cnt >= MOVE_) {
			m_vec.x = 0;
			m_move_cnt = 0;
			m_state = Enemy05State::eAttack;
			
		}
		break;

	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
}

void Enemy05::Attack()
{
	m_img.ChangeAnimation(Enemy05Anim ::eEAttack05,false);
	if (m_img.CheckAnimationEnd())
		m_state = Enemy05State::eMove;
	
}

void Enemy05::Damage()
{
	m_vec.x = 0;
	if (m_hp <= 0){
		g_game_data.m_dead_cnt++;
		m_img.ChangeAnimation(Enemy05Anim ::eEDeath05, false);
		if (m_img.CheckAnimationEnd())
			SetKill();
	
	}
	else {
		m_img.ChangeAnimation(Enemy05Anim::eEDamage05, false);
		if (m_img.CheckAnimationEnd())
			m_state = Enemy05State::eMove;
	}
}

void Enemy05::Update()
{
	switch (m_state) {
	case Enemy05State::eMove:
		Move();
		break;
	case Enemy05State::eSearch:
		//Search();
		break;
	case Enemy05State::eAttack:
		Attack();
		break;
	case Enemy05State::eDamage:
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

void Enemy05::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE/* - IMAGE_SIZE / 2*/);
	m_img.SetPos(CVector2D(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3));
	m_img.SetRect(-IMAGE_SIZE / 2.7f, -IMAGE_SIZE / 4.0f - g_game_data.m_scroll.y / 3,
					IMAGE_SIZE / 3.0f, IMAGE_SIZE / 2.3f - g_game_data.m_scroll.y / 3);
	m_img.SetFlipH(m_flip);

	m_shadow.SetSize(SAIZE_SD + m_depth / 5, 50);
	m_shadow.SetCenter((SAIZE_SD + m_depth / 5) / 2, 50 / 2);
	m_shadow.SetPos(CVector2D(m_pos.x,m_pos.y - g_game_data.m_scroll.y / 3));
	m_rect = CRect(-IMAGE_SIZE / 3.0f, -IMAGE_SIZE / 5.0f - g_game_data.m_scroll.y / 3, 
					IMAGE_SIZE / 3.5f, IMAGE_SIZE / 2.5f - g_game_data.m_scroll.y / 3);

	m_shadow.Draw();
	m_img.Draw();
	
}

void Enemy05::HitCheck()
{	

	if (CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack01) ||
		CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack02) ||
		CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack03) ||
		CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectLongAttack))
	{
		m_hp -= 1;
		m_state = Enemy05State::eDamage;
	}
}
