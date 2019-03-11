#include "Ball.h"
#include "../Global.h"
const float default_speed = -20.0f;
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos + CVector2D(-50.0f,0.0f);
	m_vec = CVector2D(0, default_speed);

}
//出現位置
#define POINT_MAX 5

CVector2D point_date[POINT_MAX] = {
	CVector2D(100, 100),
	CVector2D(200, 200),
	CVector2D(300,300),
	CVector2D(-400, 400),
	CVector2D(500, -400),

};

Ball::Ball():Task(eId_Ball, eUp_Ball, eRd_Ball){
	
	int r = rand() % POINT_MAX;
	//0 1 2 3 4 5
	
	static_assert(POINT_MAX, "要素数");
	assert(r <POINT_MAX);
	m_pos = point_date[r];
	m_vec = CVector2D(0, -20);

}

Ball::~Ball(){
}

void Ball::Update(float delta_time)
{
	DEBUG_PRINT("あやややややややや");

	//速度の設定
	m_vec.y += GRAVITY*delta_time;
	m_pos += m_vec*delta_time;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}

