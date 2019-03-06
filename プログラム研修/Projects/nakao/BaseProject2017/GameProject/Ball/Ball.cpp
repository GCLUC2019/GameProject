#include "Ball.h"
#include "../Global.h"
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos;
	int i = Utility::Rand(-10, 10);
	int j = Utility::Rand(-50, -20);
	m_vec = CVector2D(i, j);
}

CVector2D point_data[] = {
	CVector2D(100,100),
	CVector2D(200,70),
	CVector2D(500,60),
	CVector2D(52,30),
	CVector2D(1220,50)
};

Ball::Ball() :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	m_pos = point_data[Utility::Rand(0, 5)];
	//m_pos = CVector2D(Utility::Rand(0, 1280), Utility::Rand(0, 520));
	/*int i = Utility::Rand(-10, 10);
	int j = Utility::Rand(-50, -20);
	m_vec = CVector2D(i, j);*/
	m_vec = CVector2D(20, -20);
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
