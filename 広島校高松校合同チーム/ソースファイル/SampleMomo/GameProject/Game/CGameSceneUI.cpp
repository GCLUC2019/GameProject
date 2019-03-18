#include "CGameSceneUI.h"
#include "CCharacterPlayer.h"
#include "CBar.h"

CGameSceneUI::CGameSceneUI() :CObject(0, DP_UI)
{
	m_ui_pos = CVector2D(0, 450);
	m_ui_size = CVector2D(518,332);

	m_hp_frame_image_p = GET_RESOURCE("HP_Bar_Frame", CImage*);
	TaskManager::GetInstance()->AddTask(m_hp_bar_p = new CBar(GET_RESOURCE("HP_Bar", CImage*), CCharacterPlayer::GetInstance()->GetHitPointPointer(), CCharacterPlayer::GetInstance()->GetHitPointMax(), m_ui_pos + CVector2D(178,137), CVector2D(330,25)));
}

CGameSceneUI::~CGameSceneUI()
{
	m_hp_bar_p->SetIsDelete();
}

void CGameSceneUI::Update()
{
}

void CGameSceneUI::Draw()
{
	m_hp_frame_image_p->SetSize(m_ui_size);
	m_hp_frame_image_p->SetPos(m_ui_pos);
	m_hp_frame_image_p->Draw();
}
