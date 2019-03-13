//小川

#include "CAppear.h"
#include "CGlobal.h"
CAppear::CAppear(const CVector2& pos) :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	m_pos = pos;
	m_vec = CVector2(0, -20);
}

CAppear::~CAppear()
{
}
#define POINT_MAX 5
CVector2 point_deta[POINT_MAX] = {
	CVector2(64, 64),
	CVector2(128, 64),
	CVector2(64, 128),
	CVector2(512, 256),
	CVector2(256, 512)
};

CAppear::CAppear() :Task(eId_Ball, eUp_Ball, eRd_Ball)
{

	int r = rand() % POINT_MAX;
	const int a = 9;
	static_assert(POINT_MAX == 5, "要素数オーバー");
	assert(r < POINT_MAX);
	m_pos = point_deta[r];
	m_vec = CVector2(0, -20);
}

void CAppear::Update(float delta_time)
{
	DEBUG_PRINT("デバッグ中");

	m_vec.y += GRAVITY*delta_time;
//	m_pos += m_vec*delta_time;
	if (m_pos.y > SCREEN_HEIGHT)SetKill();
}

void CAppear::Render()
{
//	Utility::DrawQuad(m_pos, CVector2(32.0f, 32.0f), CVector4D(1.0f, 0, 0, 1));
}
