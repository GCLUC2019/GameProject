#include "CGameSceneBossUI.h"
#include "CCharacterBoss.h"

#include "CBar.h"
#include "CGameScene.h"

CGameSceneBossUI::CGameSceneBossUI() :CObject(0, DP_UI)
{
	m_ui_pos = CVector2D(880, -10);
	m_ui_size = CVector2D(500, 250) * 0.8;

	m_hp_frame_image_p = GET_RESOURCE("Boss_HP_Bar_Frame", CImage*);
	m_hp_bar_p = new CBar(GET_RESOURCE("Boss_HP_Bar", CImage*), CCharacterBoss::GetInstance()->GetHitPointPointer(), CCharacterBoss::GetInstance()->GetHitPointMax(), m_ui_pos + CVector2D(9, 110.0), CVector2D(263,19));

}

CGameSceneBossUI::~CGameSceneBossUI()
{
	delete m_hp_bar_p;
}

void CGameSceneBossUI::Update()
{
	m_hp_bar_p->Update();
}

void CGameSceneBossUI::Draw()
{
	
	m_hp_frame_image_p->SetSize(m_ui_size);
	m_hp_frame_image_p->SetPos(m_ui_pos);
	m_hp_frame_image_p->Draw();
	m_hp_bar_p->Draw();
}
