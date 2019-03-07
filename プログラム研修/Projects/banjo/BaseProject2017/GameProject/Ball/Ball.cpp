#include "Ball.h"
#include "../Global.h"

//出現位置の数
#define POINT_MAX 5

CVector2D point_data[] = {
	CVector2D(64,64),
	CVector2D(64*3,64),
	CVector2D(64*5,64),
	CVector2D(64*7,64),
	CVector2D(64*9,64)
};
Ball::Ball() :Task(eId_Ball, eUp_Ball, eRd_Ball)
{

	int r = rand() % POINT_MAX;
	//int a = Utility::Rand(0, 5);
	m_pos = point_data[r];
	DEBUG_DATA_NUM("%d番目の要素が選ばれました\n",r);
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
	//重力の落下速度
	m_vec.y += GRAVITY * SPF;
	m_pos += m_vec;
	//if (m_pos.y > 660)m_vec = m_vec * -1;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}
