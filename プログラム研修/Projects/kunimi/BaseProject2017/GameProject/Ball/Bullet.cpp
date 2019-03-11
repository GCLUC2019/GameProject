#include "Bullet.h"

Bullet::Bullet(const CVector2D & pos) : 
{
	m_pos = pos;
}

void Bullet::Update(float delta_time)
{
}

void Bullet::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f, 32.0f), CVector4D(0, 1.0f, 0, 1));
}
