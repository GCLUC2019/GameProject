#include "Ball.h"
#include "../Global.h"

//出現位置の数
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

#ifdef _DEBUG
#define DEBUG_PRINT(s) printf(s)
#else
#define DEBUG_PRINT(s)
#endif 


#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define POINT_MAX 5

CVector2D point_data[5] = {
	CVector2D(64,64),
	CVector2D(128,64),
	CVector2D(64,128),
	CVector2D(512,256),
	CVector2D(256,512),
};



const int point_data_size = ARRAY_SIZE(point_data);

Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	int r = rand() % point_data_size;
	static_assert(POINT_MAX == point_data_size,"要素数オーバー");
	m_pos = point_data[r];
	/*m_vec = CVector2D(0, -20);*/

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

void Ball::SetVector(const CVector2D & _vec)
{
	m_vec = _vec;
}
