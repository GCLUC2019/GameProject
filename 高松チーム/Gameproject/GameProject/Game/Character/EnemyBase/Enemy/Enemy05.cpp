#include "Enemy05.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Game/Resource/Resource.h"

Enemy05::Enemy05() : EnemyBase(eEnemy05)
{
	//初期化
	m_img = COPY_RESOURCE("Enemy05", CAnimImage*);
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);

	m_pos = CVector2D(100, 100);
	m_vec = CVector2D(0, 0);
	m_hp = 100;
	m_cnt = 0;
	m_state = eMove;
}

void Enemy05::Move()
{
	m_img.ChangeAnimation(eEMove05);
	if(m_img.CheckAnimationEnd())
	m_state = eMove;
}

void Enemy05::Attack()
{
	m_cnt = 0;
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

	//仮攻撃
	++m_cnt;
	if (m_cnt >= 300) {
		m_state = eAttack;
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
	m_img.Draw();
}
