#include "CGameSceneBossUI.h"
#include "CCharacterBoss.h"

#include "CBar.h"
#include "CGameScene.h"

CGameSceneBossUI::CGameSceneBossUI() :CObject(0, DP_UI)
{
	m_ui_pos = CVector2D(500, 0);
	m_ui_size = CVector2D(500, 300);

	m_hp_frame_image_p = GET_RESOURCE("HP_Bar_Frame", CImage*);
	m_hp_bar_p = new CBar(GET_RESOURCE("Boss_HP_Bar", CImage*), CCharacterBoss::GetInstance()->GetHitPointPointer(), CCharacterBoss::GetInstance()->GetHitPointMax(), m_ui_pos + CVector2D(0, 0), CVector2D(330 * 0.6, 25 * 0.6));

}

CGameSceneBossUI::~CGameSceneBossUI()
{
}

void CGameSceneBossUI::Update()
{
}

void CGameSceneBossUI::Draw()
{
}
