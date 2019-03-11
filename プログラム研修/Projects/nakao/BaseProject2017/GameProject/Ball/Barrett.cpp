#include "Barrett.h"
Barrett::Barrett(const CVector2D& _pos) :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	m_pos = _pos;
}

void Barrett::Update(float delta_time)
{
}

void Barrett::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f, 32.0f), CVector4D(1.0f, 1, 0, 1));
}
