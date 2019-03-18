#include "EnemyBase.h"

EnemyBase::EnemyBase(int _type) : Task(CharacterData::eEnemyBase)
{
}

void EnemyBase::Move()
{
}

void EnemyBase::Attack()
{
}

void EnemyBase::Damage()
{
}

void EnemyBase::Update()
{
	m_pos_old = m_pos;
}

void EnemyBase::Draw()
{
}

void EnemyBase::HitCheck(Task * _t)
{
}

bool EnemyBase::CollisionCheckRect(EnemyBase * b1, EnemyBase * b2)
{
	CRect r1 = CRect(
		b1->m_pos.x + b1->m_rect.m_left,
		b1->m_pos.y + b1->m_rect.m_top,
		b1->m_pos.x + b1->m_rect.m_right,
		b1->m_pos.y + b1->m_rect.m_bottom);

	CRect r2 = CRect(
		b2->m_pos.x + b2->m_rect.m_left,
		b2->m_pos.y + b2->m_rect.m_top,
		b2->m_pos.x + b2->m_rect.m_right,
		b2->m_pos.y + b2->m_rect.m_bottom);
	return CCollision::CollisionRect(r1, r2);

}

bool EnemyBase::CollitionCheckflip(int fliptype, EnemyBase * b1, EnemyBase * b2)
{
	/*
	Ž©‹@‚ÌŒü‚«
	0=‰E,1=¶,2=ã,3=‰º
	*/
	switch (fliptype)
	{
	case 0:
		if (b1->m_pos.x < b2->m_pos.x) return true;
		else return false;
		break;

	case 1:
		if (b1->m_pos.x > b2->m_pos.x) return true;
		else return false;
		break;

	case 2:
		if (b1->m_pos.y > b2->m_pos.y) return true;
		else return false;
		break;

	case 3:
		if (b1->m_pos.y < b2->m_pos.y) return true;
		else return false;
		break;

	default:
		break;
	}

	return false;
}

void EnemyBase::MoveControl()
{

	if (m_pos.x < SCREEN_MIN_SIZE_X || m_pos.y > SCREEN_MAX_SIZE_X)
		m_pos.x = m_pos_old.x;
	if (m_pos.y < SCREEN_MIN_SIZE_Y || m_pos.y > SCREEN_MAX_SIZE_Y)
		m_pos.y = m_pos_old.y;
}
