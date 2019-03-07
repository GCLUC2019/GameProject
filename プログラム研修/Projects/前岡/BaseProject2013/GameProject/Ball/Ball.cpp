#include "Ball.h"
#include "../Global.h"
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos;
	m_vec = CVector2D(0, -20);
}

Ball::~Ball()
{
}
#define POINT_MAX 5
CVector2D point_deta[POINT_MAX] = {
	CVector2D(64, 64),
	CVector2D(128, 64),
	CVector2D(64, 128),
	CVector2D(512, 256),
	CVector2D(256, 512)
};

Ball::Ball():Task(eId_Ball,eUp_Ball,eRd_Ball)
{

	int r=rand() % POINT_MAX;
	m_pos = point_deta[r];
	m_vec = CVector2D(0, -20);
}

void Ball::Update(float delta_time)
{
	DEBUG_PRINT("デバッグ中");

	m_vec.y += GRAVITY*SPF;
	m_pos += m_vec;
	if (m_pos.y > SCREEN_HEIGHT)SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}


