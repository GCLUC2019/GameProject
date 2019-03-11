#include "Ball.h"
#include "../Global.h"

Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos+CVector2D(50,0);
	m_vec = CVector2D(0, -20);

}
//出現位置の数
#define POINT_MAX 5
CVector2D point_data[] = {
	CVector2D(64,64),
	CVector2D(128, 64),
	CVector2D(64, 128),
	CVector2D(512, 256),
	CVector2D(256, 512),
};
const int point_data_size = ARRAYSIZE(point_data);
const float default_speed = -20.0f;
Ball::Ball() :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	int r = rand() % 10;
	const int a = 9;
	static_assert(a == 9, "要素数オーバー");
	assert(r < point_data_size);
	m_pos = point_data[r];
	m_vec = CVector2D(0, default_speed);

}

Ball::~Ball()
{
}

void Ball::Update(float delta_time)
{
	printf("デバッグ中");
	m_vec.y += GRAVITY* delta_time;
	m_pos += m_vec*delta_time;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}
