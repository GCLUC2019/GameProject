#include "UI.h"
#include "../GameProject/Game/Resource/Resource.h"

UI::UI() : Task(CharacterData::eUI)
{
	TaskManager::GetInstance()->AddTask(new PlayerLogoUI());
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



PlayerLogoUI::PlayerLogoUI() : UI(UIData::ePlayerLogoUI)
{
	m_img = COPY_RESOURCE("RogoUI", CImage*);
	m_pos = CVector2D(100, 20);
}

void PlayerLogoUI::Update()
{
}

void PlayerLogoUI::Draw()
{
	m_img.SetSize(CVector2D(80, 80));
	m_img.SetPos(m_pos);
	m_img.Draw();
}


SpecialGageUI::SpecialGageUI() : UI(eSpecialGageUI)
{
	
}

void SpecialGageUI::Update()
{
}

void SpecialGageUI::Draw()
{
}
