#include "EnemyBase.h"

EnemyBase::EnemyBase(int _type)
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

void EnemyBase::MoveControl()
{

	if (m_pos.x < SCREEN_MIN_SIZE_X || m_pos.y > SCREEN_MAX_SIZE_X)
		m_pos.x = m_pos_old.x;
	if (m_pos.y < SCREEN_MIN_SIZE_Y || m_pos.y > SCREEN_MAX_SIZE_Y)
		m_pos.y = m_pos_old.y;
}
