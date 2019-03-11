#include "Bullet.h"

Bullet::Bullet(const CVector2D & pos) :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	m_pos = pos;
}

void Bullet::Update()
{
}

void Bullet::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f, 32.0f), CVector4D(0, 1.0f, 0, 1));
}
