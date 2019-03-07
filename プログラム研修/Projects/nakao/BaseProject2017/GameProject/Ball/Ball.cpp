#include "Ball.h"
#include "../Global.h"
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos;
	/*int i = Utility::Rand(-10, 10);
	int j = Utility::Rand(-50, -20);
	m_vec = CVector2D(i, j);*/
}

CVector2D point_data[] = {
	CVector2D(100,100),
	CVector2D(200,60),
	CVector2D(500,250),
	CVector2D(52,300),
	CVector2D(1220,100)
};

#define P_MAX 5
const int point_data_size = ARRAY_SIZE(point_data);
Ball::Ball() :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	int n;
	// n = Utility::Rand(0, 4);
	n = rand() % point_data_size;
	static_assert(P_MAX == point_data_size/*条件式　満たされなければエラーが出る*/, "要素数オーバー");
	assert(n < point_data_size);
	m_pos = point_data[n];
	//m_pos = CVector2D(Utility::Rand(0, 1280), Utility::Rand(0, 520));
	/*int i = Utility::Rand(-10, 10);
	int j = Utility::Rand(-50, -20);
	m_vec = CVector2D(i, j);*/
	m_vec = CVector2D(0, -20);
}
Ball::~Ball()
{
	DEBUG_PRINT("破棄\n");
}

void Ball::Update(float delta_time)
{
	DEBUG_PRINT("334\n");


	m_vec.y += GRAVITY * delta_time;
	m_pos += m_vec * delta_time;

	
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}

