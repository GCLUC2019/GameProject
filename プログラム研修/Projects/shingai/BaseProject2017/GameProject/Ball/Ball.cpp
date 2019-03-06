#include "Ball.h"
#include "../Global.h"

CVector2D point_data[] = {
	CVector2D(64,64),
	CVector2D(128,64),
	CVector2D(64,128),
	CVector2D(512,256),
	CVector2D(256,512),
};

Ball::Ball() : Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	m_pos = point_data[Utility::Rand(0, 4)];
	m_vec = CVector2D(0, -20);
}

Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos;
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
