#include "BossEffect.h"
#include "../GameProject/Game/Resource/Resource.h"

#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768
#define FIRE_X_SIZE 1280
#define FIRE_Y_SIZE 960

BossEffect::BossEffect(CVector2D& pos)
{
	m_img = COPY_RESOURCE("BossFire", CImage*);
	m_pos.x = 0;
	//512
	m_pos.y = pos.y;
}


void BossEffect::Update()
{
	
}

void BossEffect::Draw()
{
	m_img.SetSize(FIRE_X_SIZE - BOSS_X_SIZE / 3, FIRE_Y_SIZE / 4);
	m_img.SetRect(FIRE_X_SIZE,0, FIRE_X_SIZE * 2, FIRE_Y_SIZE);
	m_img.SetPos(m_pos);
	m_img.Draw();
}
