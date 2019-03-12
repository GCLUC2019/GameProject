#include "BossEffect.h"
#include "../GameProject/Game/Resource/Resource.h"

#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768
#define FIRE_X_SIZE 1280
#define FIRE_Y_SIZE 960

BossFireEffect::BossFireEffect(const CVector2D& pos)
{
	m_img = COPY_RESOURCE("BossFire", CAnimImage*);
	m_pos.x = 0;
	//512
	m_pos.y = pos.y;
}


void BossFireEffect::Update()
{
	m_img.ChangeAnimation(eBossFireEffect, false);
	m_img.UpdateAnimation();
	m_img.CheckAnimationEnd();
}

void BossFireEffect::Draw()
{
	m_img.SetSize(FIRE_X_SIZE - BOSS_X_SIZE / 3, FIRE_Y_SIZE / 4);
	m_img.SetRect(0, 0, FIRE_X_SIZE, FIRE_Y_SIZE);
	m_img.SetPos(m_pos);
	m_img.Draw();
}


///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////�{�X�̃��[�U�[�U��////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//BossLazerEffect::BossLazerEffect(const CVector2D& pos)
//{
//	m_img = COPY_RESOURCE("BossLazer", CAnimImage*);
//	m_pos.x = 0;
//	//512
//	m_pos.y = pos.y;
//}
//
//
//void BossLazerEffect::Update()
//{
//	/*m_img.ChangeAnimation(eBossFireEffect, false);
//	m_img.UpdateAnimation();
//	m_img.CheckAnimationEnd();*/
//}
//
//void BossLazerEffect::Draw()
//{
//	m_img.SetSize(FIRE_X_SIZE - BOSS_X_SIZE / 3, FIRE_Y_SIZE / 4);
//	m_img.SetRect(FIRE_X_SIZE, 0, FIRE_X_SIZE * 2, FIRE_Y_SIZE);
//	m_img.SetPos(m_pos);
//	m_img.Draw();
//}
