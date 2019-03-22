#include "BossEffect.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../GameProject/Game/GameData/GameData.h"
#include "../GameProject/Game/CollitionBase.h"
#include "../GameProject/Game/Character/Player.h"

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

	m_img.SetCenter((FIRE_X_SIZE - BOSS_X_SIZE / 3) / 2, FIRE_Y_SIZE / 8);

	m_rect = CRect(-450, -120, 500, 120);

	m_pos.x = FIRE_X_SIZE - pos.x + 300;
	m_pos.y = pos.y;
}


void BossFireEffect::Update()
{
	m_img.ChangeAnimation(eBossFireEffect, false);
	m_img.UpdateAnimation();
	m_img.CheckAnimationEnd();
	if (m_img.CheckAnimationEnd())SetKill();
}

void BossFireEffect::HitCheck()
{
	Task*t = CollitionBase::GetCollisionCheckRectANDY(this, CharacterData::ePlayer, 50.0f);
	Player*p = dynamic_cast<Player*>(t);

	if (p != nullptr) {
		p->Damage(20);
	}
}

void BossFireEffect::Draw()
{
#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif

	m_img.SetSize(FIRE_X_SIZE - BOSS_X_SIZE / 3, FIRE_Y_SIZE / 4);
	m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
	m_img.Draw();
}


///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////ボスのレーザー攻撃////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
BossLazerEffect::BossLazerEffect(const CVector2D& pos) : Task(eBossLazerEffectc)
{
	m_img = COPY_RESOURCE("SkyRed", CImage*);
	m_img2 = COPY_RESOURCE("BossLazer", CAnimImage*);//矩形確認しやすくするために作った。表示はしていない
	
	m_img.SetCenter(LAZER_X_SIZE / 4, LAZER_Y_SIZE / 4);
	m_img2.SetCenter((LAZER_X_SIZE + 640) / 2, (LAZER_Y_SIZE + 528) / 2);

	m_pos = CVector2D(100, 625);

	m_pos2.x = pos.x - LAZER_X_SIZE / 6.5 + 50;

	m_pos2.y = pos.y + LAZER_Y_SIZE / 6.5 + 1;

	m_rect_pos = 0;

	m_rect = CRect(-50, -200, 50, 75);


}


void BossLazerEffect::Update()
{
	if (m_img2.CheckAnimationEnd() == false) m_pos.x += 15;
	m_img2.ChangeAnimation(eBossLazerEffect, false);
	m_img2.UpdateAnimation();
	m_img2.CheckAnimationEnd();
	if (m_img2.CheckAnimationEnd())SetKill();
}

void BossLazerEffect::HitCheck()
{
	Task*t = CollitionBase::GetCollisionCheckRectANDY(this, CharacterData::ePlayer, 100.0f);
	Player*p = dynamic_cast<Player*>(t);

	if (p != nullptr) {
		p->Damage(20);
	}
}

void BossLazerEffect::Draw()
{
#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif
	m_img.SetRect(0, 0, LAZER_X_SIZE, LAZER_Y_SIZE);
	m_img2.SetSize(LAZER_X_SIZE + 640, LAZER_Y_SIZE + 528);
	m_img.SetSize(LAZER_X_SIZE / 2, LAZER_Y_SIZE / 2);
	m_img2.SetPos(m_pos2.x, m_pos2.y - g_game_data.m_scroll.y / 3);
	m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
	//m_img.Draw();
	m_img2.Draw();
}

BossSlashEffect::BossSlashEffect(const CVector2D &pos) : Task(eBossLazerEffectc)
{
	m_img = COPY_RESOURCE("BossSlash", CAnimImage*);

	m_img.SetCenter(SLASH_SIZE * 2 / 2, SLASH_SIZE * 2 / 2);

	Task * p = TaskManager::GetInstance()->FindObject(ePlayer);
	if (p == nullptr)return;
	m_player_pos = p->GetPos();

	//m_pos = pos;

	m_pos = CVector2D(pos.x, m_player_pos.y);

	m_flip = false;

	m_rect = CRect(-150, -100, 50, 100);


}

void BossSlashEffect::Update()
{
	printf("Effect     %f             %f\n", m_pos.x, m_pos.y);
	m_img.ChangeAnimation(eBossSlashEffect, false);
	m_img.UpdateAnimation();
	m_img.CheckAnimationEnd();
	if (m_img.CheckAnimationEnd())SetKill();
}

void BossSlashEffect::HitCheck()
{
	Task*t = CollitionBase::GetCollisionCheckRectANDY(this, CharacterData::ePlayer, 50.0f);
	Player*p = dynamic_cast<Player*>(t);

	if (p != nullptr) {
		p->Damage(20);
	}
}

void BossSlashEffect::Draw()
{
#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif

	m_img.SetFlipH(m_flip);
	m_img.SetSize(SLASH_SIZE * 2, SLASH_SIZE * 2);
	m_img.SetPos(m_pos.x - 80, m_pos.y + 1 - g_game_data.m_scroll.y / 3);
	m_img.SetFlipH(false);
	m_img.Draw();

}
