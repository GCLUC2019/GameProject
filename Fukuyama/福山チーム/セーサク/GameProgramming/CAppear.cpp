#include "Utility.h"
#include "CAppear.h"
#include "CGlobal.h"

//#define POINT_MAX (5)

const int point_size = 6;
CVector2 point_data[point_size] = {
	CVector2(64, 64),
	CVector2(128, 64),
	CVector2(64, 128),
	CVector2(512, 256),
	CVector2(256, 512),
	CVector2(256, 512),
};

const float default_speed = -20.0f;

CAppear::CAppear() : Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	DEBUG_PRINT("デバッグ中です。\n");
	const int point_data_num = sizeof(point_data) / sizeof(point_data[0]);
	int r = Utility::Rand(0, 10);
	m_pos = point_data[r];

	m_vec = CVector2(0, default_speed);
}

CAppear::CAppear(const CVector2& pos) :Task(eId_Ball, eUp_Ball, eRd_Ball)
{
	m_pos = pos;
	m_vec = CVector2(0, -20);
}

CAppear::~CAppear()
{
}

void CAppear::Update(float delta_time)
{
	m_vec.y += GRAVITY * SPF;
	m_pos = m_pos + m_vec;
	if (m_pos.y > SCREEN_HEIGHT) SetKill();
}

void CAppear::Render()
{
	//Utility::DrawQuad(m_pos, CVector2D(32.0f, 32.0f), CVector4D(1.0f, 0, 0, 1));
}
