#include "Ball.h"
#include "../Global.h"


//#define POINT_MAX (5)

const int point_size = 6;
CVector2D point_data[point_size] = {
	CVector2D(64,64),
	CVector2D(128,64),
	CVector2D(64,128),
	CVector2D(512,256),
	CVector2D(256,512),
	CVector2D(256,512),
};

const float default_speed = -20.0f;

Ball::Ball() : Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	DEBUG_PRINT("デバッグ中です。\n");
	const int point_data_num = sizeof(point_data) / sizeof(point_data[0]);
	int r = Utility::Rand(0, 10);
	//static_assert(POINT_MAX == point_data_num,"要素数オーバー");
	//assert(r < point_data_num);
	m_pos = point_data[r];
	
	m_vec = CVector2D(0, default_speed);
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
