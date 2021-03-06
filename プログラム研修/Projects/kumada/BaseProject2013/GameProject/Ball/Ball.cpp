#include "Ball.h"
#include "../Global.h"


Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos;
	m_vec = CVector2D(0, -20);

}

#define POINT_MAX 5 //出現位置の数

//const int point_data_size = ARRAY_SIZE(point_data);

CVector2D point_data[POINT_MAX] = {
	CVector2D(64,64),
	CVector2D(128,64),
	CVector2D(64,128),
	CVector2D(512,256),
	CVector2D(256,512),

};
//int point_data_size = ARRAY_SIZE(point_data);
Ball::Ball() : Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	
	//int r = rand() % point_data_size;
	int r = rand() % POINT_MAX;
	const int a= 9;
	static_assert(a == 9, "要素数オーバー");
	assert(r <POINT_MAX);
	m_pos = point_data[r];
	m_vec = CVector2D(0, -20);

}

Ball::~Ball()/*:Task(eId_Ball,eUp_Ball,eRd_Ball)*/
{
}

void Ball::Update(float delta_time)
{
	DEBUG_PRINT("デバッグ");
	m_vec.y += GRAVITY * delta_time;
	m_pos += m_vec * delta_time;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}

void Ball::SetVector(const CVector2D& vec) {

	m_vec = vec;
}


