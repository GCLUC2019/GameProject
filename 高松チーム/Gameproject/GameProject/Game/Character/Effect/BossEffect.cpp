#include "BossEffect.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../GameProject/Game/GameData/GameData.h"

#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

#define FIRE_X_SIZE 1280
#define FIRE_Y_SIZE 960

#define LAZER_X_SIZE 640
#define LAZER_Y_SIZE 480

#define SLASH_SIZE 200


BossFireEffect::BossFireEffect(const CVector2D& pos) : Task(eBossFireEffectc)
{
	m_img = COPY_RESOURCE("BossFire", CAnimImage*);

	m_img.SetCenter((FIRE_X_SIZE - BOSS_X_SIZE / 3)/2, FIRE_Y_SIZE / 8);

	m_pos.x = FIRE_X_SIZE - pos.x + 300;
	m_pos.y = pos.y + 100;
}


void BossFireEffect::Update()
{
	m_img.ChangeAnimation(eBossFireEffect, false);
	m_img.UpdateAnimation();
	m_img.CheckAnimationEnd();
	if (m_img.CheckAnimationEnd())SetKill();
}

void BossFireEffect::Draw()
{
	m_img.SetSize(FIRE_X_SIZE - BOSS_X_SIZE / 3, FIRE_Y_SIZE / 4);
	m_img.SetPos(m_pos/* - g_game_data.m_scroll*/);
	m_img.Draw();
}


///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////ボスのレーザー攻撃////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
BossLazerEffect::BossLazerEffect(const CVector2D& pos) : Task(eBossLazerEffectc)
{
	m_img = COPY_RESOURCE("BossLazer", CAnimImage*);

	m_img.SetCenter((LAZER_X_SIZE + 640) / 2, (LAZER_Y_SIZE + 528) / 2);

	m_pos.x = pos.x - LAZER_X_SIZE / 6.5;

	m_pos.y = pos.y + LAZER_Y_SIZE / 6;
	
	
}


void BossLazerEffect::Update()
{
	m_img.ChangeAnimation(eBossLazerEffect, false);
	m_img.UpdateAnimation();
	m_img.CheckAnimationEnd();
	if (m_img.CheckAnimationEnd())SetKill();
}

void BossLazerEffect::Draw()
{
	m_img.SetSize(LAZER_X_SIZE + 640, LAZER_Y_SIZE + 528);
	m_img.SetPos(m_pos/* - g_game_data.m_scroll*/);
	m_img.Draw();
}

BossSlashEffect::BossSlashEffect(const CVector2D & pos) : Task(eBossLazerEffectc)
{
	m_img = COPY_RESOURCE("PEGetDamage", CAnimImage*);

	m_img.SetCenter(SLASH_SIZE * 2 / 2, SLASH_SIZE * 2 / 2);

	m_pos.x = pos.x;

	m_pos.y = pos.y;
}

void BossSlashEffect::Update()
{
	m_img.ChangeAnimation(eBossSlashEffect, false);
	m_img.UpdateAnimation();
	m_img.CheckAnimationEnd();
	if (m_img.CheckAnimationEnd())SetKill();
}

void BossSlashEffect::Draw()
{
	m_img.SetSize(SLASH_SIZE * 2, SLASH_SIZE * 2);
	m_img.SetPos(m_pos/* - g_game_data.m_scroll*/);
	m_img.Draw();
}
