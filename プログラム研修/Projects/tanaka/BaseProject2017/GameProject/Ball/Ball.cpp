#include "Ball.h"
#include "../Global.h"

CVector2D point_data[] = {
    CVector2D(64,64),
    CVector2D(128,64),
    CVector2D(64,128),
    CVector2D(512,256),
    CVector2D(256,512),
};
const int point_data_size = ARRAY_SIZE(point_data);
Ball::Ball(const CVector2D& pos):Task(eId_Ball,eUp_Ball,eRd_Ball)
{
    //int point_data_num = sizeof(point_data) / sizeof(point_data[0]);
    int r = rand() % POINT_MAX;
    //確認デバッグ用
    static_assert(POINT_MAX == point_data_size, "要素数オーバー");//警告を出せる
    assert(r < POINT_MAX);
	m_pos = point_data[r];
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

void Ball::SetVector(const CVector2D &vec)
{
    m_vec = vec;
}
