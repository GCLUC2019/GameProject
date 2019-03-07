#include "Ball.h"
#include "../Global.h"

//出現位置の数
#define POINT_MAX 5

CVector2D point_data[] = {
	CVector2D(100,360),
	CVector2D(100*3,360),
	CVector2D(100*5,360),
	CVector2D(100*7,360),
	CVector2D(100*9,360),
};

const int point_data_size = ARRAY_SIZE(point_data);

Ball::Ball() :Task(eId_Ball, eUp_Ball, eRd_Ball)
/*
初期化子リスト
ここに書いたやつは初期化される
*/
{
	int r = rand() % point_data_size;
	/*static_assert(POINT_MAX == point_data_size, "要素数オーバー");
	assert(r < point_data_size);*/
	//デバッグの時だけ有効
	m_pos = point_data[r];
	//DEBUG_DATA_NUM("%d番目の要素が選ばれました\n",r);
	m_vec = CVector2D(0, -20);
}
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
	m_pos = pos+CVector2D(50,0);
	m_vec = CVector2D(0, -20);
}

Ball::~Ball()
{
}

void Ball::Update(float delta_time)
{
	//重力の落下速度
	m_vec.y += GRAVITY * delta_time;
	m_pos += m_vec * delta_time;
	//if (m_pos.y > 660)m_vec = m_vec * -1;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void Ball::Render()
{
	Utility::DrawQuad(m_pos, CVector2D(32.0f,32.0f), CVector4D(1.0f, 0, 0, 1));
}