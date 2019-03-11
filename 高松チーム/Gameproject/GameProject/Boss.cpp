#include "Boss.h"

#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

#define FIRE_X_SIZE 1280
#define FIRE_Y_SIZE 960

BossHead::BossHead():EnemyBase(eBossHead)
{
	m_img = COPY_RESOURCE("Boss", CImage*);
	m_img2 = COPY_RESOURCE("BossFire", CImage*);
	m_pos = CVector2D(1280- BOSS_X_SIZE /3, BOSS_Y_SIZE - BOSS_Y_SIZE /3);
	m_pos2 = CVector2D(0, FIRE_Y_SIZE / 3 + FIRE_Y_SIZE / 3 / 2);
}

void BossHead::Update()
{
	/*m_rot += 0.1;
	if (m_rot >= 6.28)m_rot = 0;
	m_pos = m_center + CVector2D(sin(m_rot), cos(m_rot))*r;*/
}

void BossHead::Draw()
{
	m_img.SetSize(BOSS_X_SIZE /3, BOSS_X_SIZE / 3);
	m_img2.SetSize(1280 - BOSS_X_SIZE/3, FIRE_Y_SIZE / 3);
	m_img.SetRect(BOSS_X_SIZE, BOSS_X_SIZE * 4, BOSS_X_SIZE * 2, BOSS_X_SIZE * 5);
	m_img2.SetRect(0,FIRE_Y_SIZE, FIRE_X_SIZE, FIRE_Y_SIZE * 2);
	m_img.SetPos(m_pos);
	m_img2.SetPos(m_pos2);
	m_img2.Draw();
	m_img.Draw();
	
}
