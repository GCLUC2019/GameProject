#include "Enemy05.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../../CharacterBase.h"
#include "../../Player.h"
#define MOVE_ 360

#define MOVE_ 360

Enemy05::Enemy05(CVector2D& _pos) : EnemyBase(eEnemy05),
m_move_cnt(0)
{
	//初期化
	m_img = COPY_RESOURCE("Enemy05", CAnimImage*);
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);

	//m_rect = 
	m_pos = _pos;
	m_vec = CVector2D(0, 0);
	m_hp = 100;
	m_img.SetFlipH(m_flip);
	m_move_cnt = 0;
	m_state = eMove;
}

void Enemy05::Move()
{
	MoveManagement(0);
	m_img.ChangeAnimation(eEMove05);
}

void Enemy05::MoveManagement(int _type)
{
	switch (_type) {
	case 0:
		//仮移動
		++m_move_cnt;
		if (m_move_cnt <= MOVE_ / 2) {
			m_vec.x = 2.0f;
			m_flip = true;
		}
		else if (m_move_cnt >= MOVE_/2) {
			m_vec.x = -2.0f;
			m_flip = false;
		}
		if (m_move_cnt >= MOVE_) {
			m_vec.x = 0;
			m_move_cnt = 0;
			m_state = eAttack;
			
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
	m_img.ChangeAnimation(eEAttack05,false);
	if (m_img.CheckAnimationEnd())
		m_state = eMove;
	
}

void Enemy05::Damage()
{
	m_img.ChangeAnimation(eEDamage05,false);
	if (m_hp <= 0)
		m_img.ChangeAnimation(eEDeath05,false);
	if (m_img.CheckAnimationEnd())
	m_state = eMove;
}

void Enemy05::Update()
{
	switch (m_state) {
	case eMove:
		Move();
		break;
	case eSearch:
		//Search();
		break;
	case eAttack:
		Attack();
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

void Enemy05::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_img.SetPos(m_pos);
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}

void Enemy05::HitCheck(Task * _t)
{
	switch (_t->GetType()) {
	case ePlayer:
		printf("playerを取得");
		break;
	default:
		break;
	}
}
