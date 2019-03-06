#include "Ball.h"
#include "../Global.h"
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos;
	m_vec = CVector2D(0, -20);
}

//出現位置の数
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

#ifdef _DEBUG
	#define DEBUG_PRINT(s) printf(s)
#else
	#define DEBUG_PRINT(s)
#endif 

CVector2D point_data[] = {
	CVector2D(123,456),
	CVector2D(23,45),
	CVector2D(542,98),
	CVector2D(323,356),
	CVector2D(823,656)
};

int point_data_size = ARRAY_SIZE(point_data);
Ball::Ball() :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	DEBUG_PRINT("デバッグ中です");

	int i = rand() % point_data_size;
#ifdef _DEBUG
	printf("%d番目にボールを出現させました\n", i+1);
#endif // _DEBUG

	m_pos = point_data[i];
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
