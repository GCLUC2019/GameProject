#include "UI.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../GameProject/Game/CollitionBase.h"
#include "../Character/Player.h"

UI::UI() : Task(CharacterData::eUI)
{
	TaskManager::GetInstance()->AddTask(new PlayerLogoUI());
	TaskManager::GetInstance()->AddTask(new SpecialGageUI());
	TaskManager::GetInstance()->AddTask(new GageBaseUI());
	TaskManager::GetInstance()->AddTask(new PlayerGageUI());
}

UI::UI(int _type) : Task(CharacterData::eUI)
{
}

void UI::Update()
{
}

void UI::Draw()
{
}

void UI::HitCheck()
{
}



PlayerLogoUI::PlayerLogoUI() : UI(UIData::ePlayerLogoUI)
{
	m_img = COPY_RESOURCE("RogoUI", CImage*);
	m_pos = CVector2D(100, 10);
}

void PlayerLogoUI::Update()
{
}

void PlayerLogoUI::Draw()
{
	m_img.SetSize(CVector2D(95, 95));
	m_img.SetPos(m_pos);
	m_img.Draw();
}


SpecialGageUI::SpecialGageUI() : UI(UIData::eSpecialGageUI)
{
	m_img = COPY_RESOURCE("SpecialGageUI", CAnimImage*);
	m_img.ChangeAnimation(SpecialGage::eGage00);

	m_special_gage_img = COPY_RESOURCE("SpecialGageEffect", CAnimImage*);
	m_pos = CVector2D(10, 20);
}

void SpecialGageUI::Update()
{
	Task* p = TaskManager::FindObject(ePlayer);
	Player* n = dynamic_cast<Player*>(p);
	m_special_gage = n->GetSpecial();

	switch (m_special_gage)
	{
	case 0:
		m_img.ChangeAnimation(SpecialGage::eGage00);
		break;
	case 10:
		m_img.ChangeAnimation(SpecialGage::eGage01);
		break;
	case 20:
		m_img.ChangeAnimation(SpecialGage::eGage02);
		break;
	case 30:
		m_img.ChangeAnimation(SpecialGage::eGage03);
		break;
	case 40:
		m_img.ChangeAnimation(SpecialGage::eGage04);
		break;
	case 50:
		m_img.ChangeAnimation(SpecialGage::eGage05);
		break;
	case 60:
		m_img.ChangeAnimation(SpecialGage::eGage06);
		break;
	case 70:
		m_img.ChangeAnimation(SpecialGage::eGage07);
		break;
	case 80:
		m_img.ChangeAnimation(SpecialGage::eGage08);
		break;
	case 90:
		m_img.ChangeAnimation(SpecialGage::eGage09);
		break;
	case 100:
		m_img.ChangeAnimation(SpecialGage::eGage10);
		break;
	default:
		break;
	}
	if (m_special_gage >= 100)
		m_special_gage_img.ChangeAnimation(SpecialGageEffect::eGageEffect);

	m_img.UpdateAnimation();
	m_special_gage_img.UpdateAnimation();
}

void SpecialGageUI::Draw()
{
	m_special_gage_img.SetSize(CVector2D(180, 180));
	m_special_gage_img.SetPos(CVector2D(-31,-20));
	if (m_special_gage >= 100)
	m_special_gage_img.Draw();

	m_img.SetSize(CVector2D(100, 100));
	m_img.SetPos(m_pos);
	m_img.Draw();
}



GageBaseUI::GageBaseUI() : UI(eGageBaseUI)
{
	m_img = COPY_RESOURCE("GageBaseUI", CImage*);
	m_pos = CVector2D(100, 100);
}

void GageBaseUI::Update()
{
}

void GageBaseUI::Draw()
{
	m_img.SetSize(CVector2D(200, 15));
	m_img.SetPos(m_pos);
	m_img.Draw();
}


PlayerGageUI::PlayerGageUI() : UI(ePlayerGageUI)
{
	m_img = COPY_RESOURCE("PlayerGageUI", CImage*);
	m_pos = CVector2D(100, 102);
	hp_width = 200;
	m_player_hp_max = 100;
}

void PlayerGageUI::Update()
{
	Task* p = TaskManager::FindObject(ePlayer);
	Player* n = dynamic_cast<Player*>(p);
	m_player_hp_now = n->GetHP();

	m_player_hp_now = m_player_hp_now / m_player_hp_max;
}

void PlayerGageUI::Draw()
{

	m_img.SetSize(CVector2D(m_player_hp_now * hp_width , 10));
	m_img.SetPos(m_pos);
	m_img.Draw();
}
