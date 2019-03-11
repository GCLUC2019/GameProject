#include "Boss.h"

BossHead::BossHead():EnemyBase(eBossHead)
{
	m_img = COPY_RESOURCE("Boss", CImage*);
	m_pos = CVector2D(1280-768/3,768-768/3);
}

void BossHead::Update()
{

}

void BossHead::Draw()
{
	m_img.SetSize(768/3,768/3);
	m_img.SetRect(768,768*4,768*2,768*5);
	m_img.SetPos(m_pos);
	m_img.Draw();
}
