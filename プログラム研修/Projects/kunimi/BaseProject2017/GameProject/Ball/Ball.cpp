#include "Ball.h"
#include "../Global.h"
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos;
	m_vec = CVector2D(0, -20);

}

CVector2D point_data[] = {
	CVector2D(64,64),
	CVector2D(80,64),
	CVector2D(90,64),
	CVector2D(100,64),
	CVector2D(110,64)
};
Ball::Ball() :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	int r = rand() % 5;
	m_pos = point_data[r];
	m_vec = CVector2D(0, -20);
}

Ball::~Ball()
{
}

void Ball::Update(float delta_time)
{
	//Global.hŽQÆ
	m_vec.y += GRAVITY * SPF;
	m_pos += m_vec;

	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}
