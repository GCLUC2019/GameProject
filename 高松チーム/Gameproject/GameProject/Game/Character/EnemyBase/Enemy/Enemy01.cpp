#include "Enemy01.h"

Enemy::Enemy() : EnemyBase(eEnemy01)
{
	m_pos = CVector2D(200, 200);
	m_img = COPY_RESOURCE("Player", CImage*);
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	m_img.SetSize(400, 200);
	m_img.SetPos(m_pos);
	m_img.Draw();
}
