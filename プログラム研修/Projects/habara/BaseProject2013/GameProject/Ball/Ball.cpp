#include "Ball.h"
#include "../Global.h"
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos;
	m_vec = CVector2D(0, -20);

}
//�o���ʒu
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
	m_pos = point_date[r];
	m_vec = CVector2D(0, -20);

}

Ball::~Ball(){
}

void Ball::Update(float delta_time)
{
	DEBUG_PRINT("�f�o�b�O���イ");
	//���x�̐ݒ�
	m_vec.y += GRAVITY*SPF;
	m_pos += m_vec;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}

