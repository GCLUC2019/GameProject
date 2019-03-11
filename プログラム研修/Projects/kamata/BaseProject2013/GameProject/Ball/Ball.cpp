#include "Ball.h"
#include "../Global.h"
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos+CVector2D(50,0);
	m_vec = CVector2D(0, -120);
}
//出現位置の数
#define POINT_MAX 5
//const int point_data_size=5;

CVector2D point_data[POINT_MAX] = {
	CVector2D(64, 64),
	CVector2D(128, 64),
	CVector2D(64, 128),
	CVector2D(512, 256),
	CVector2D(256, 512),
};

const int point_data_size = ARRAY_SIZE(point_data);
const float default_speed = -20.0f;
Ball::Ball():Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	int r = rand() % point_data_size;
	//01234   5 
	//static_assert(POINT_MAX == point_data_size, "要素数オーバー");
	assert(r < point_data_size);
	m_pos = point_data[r];
	m_vec = CVector2D(0, default_speed);
}

//int GetSize(const CVector2D*array){
//	return (sizeof(CVector2D*) / sizeof(CVector2D*));
//}
//int size = GetSize(point_data);

Ball::~Ball()
{
}


void Ball::Update(float delta_time)
{
	DEBUG_PRINT("デバック中");
	m_vec.y += GRAVITY * delta_time;
	m_pos += m_vec*delta_time;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::SetVector(const CVector2D&vec){
	m_vec = vec;
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}
