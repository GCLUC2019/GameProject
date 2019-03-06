#include "Ball.h"
#include "../Global.h"
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos;
	m_vec = CVector2D(0, -20);
}


CVector2D point_data[] = {
	CVector2D(123,456),
	CVector2D(23,45),
	CVector2D(542,98),
	CVector2D(323,356),
	CVector2D(823,656)
};
Ball::Ball() :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	int i = rand() % 5 + 0;
	m_pos = point_data[i];
	m_vec = CVector2D(0, -20);
}

Ball::~Ball()
{
}

void Ball::Update(float delta_time)
{

	m_vec.y += GRAVITY * SPF;
	m_pos += m_vec;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}
