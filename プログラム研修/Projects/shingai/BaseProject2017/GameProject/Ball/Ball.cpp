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
	DEBUG_PRINT("float %d\n", sizeof(float));
	DEBUG_PRINT("bool %d\n", sizeof(bool));
	DEBUG_PRINT("size %d\n", sizeof(point_data));
	int point_data_num = sizeof(point_data) / sizeof(point_data[0]);
	DEBUG_PRINT("array_size %d\n", ARRAY_SIZE(point_data));

	//int point_data_num = POINT_MAX;
	int r = Utility::Rand(0, point_data_num);
	DEBUG_PRINT("r %d\n", r);
	m_pos = point_data[r];
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
