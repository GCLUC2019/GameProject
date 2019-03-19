#include "CGameSceneUI.h"
#include "CCharacterPlayer.h"
#include "CBar.h"
#include "CSubWeapon.h"

CGameSceneUI::CGameSceneUI() :CObject(0, DP_UI)
{
	m_ui_pos = CVector2D(0, 450);
	m_ui_size = CVector2D(518,332);

	m_hp_frame_image_p = GET_RESOURCE("HP_Bar_Frame", CImage*);
	m_weapon_frame_image_p = GET_RESOURCE("Weapon_Bar_Frame", CImage*);

	//ƒŠƒXƒg‚É’Ç‰Á‚·‚é‚Ù‚Ç‚Å‚à‚È‚¢‚Ì‚Å
	m_hp_bar_p = new CBar(GET_RESOURCE("HP_Bar", CImage*), CCharacterPlayer::GetInstance()->GetHitPointPointer(), CCharacterPlayer::GetInstance()->GetHitPointMax(), m_ui_pos + CVector2D(178, 137), CVector2D(330, 25));

	m_weapon_bar_p = new CBar(GET_RESOURCE("Weapon_Bar", CImage*), CCharacterPlayer::GetInstance()->GetPlayerEquipWeaponEndurancePointer(), ENDURANCE_MAX, m_ui_pos + CVector2D(246, 212), CVector2D(330*0.6, 25*0.6));

	m_weapon_id_p = CCharacterPlayer::GetInstance()->GetPlayerEquipWeaponIdPointer();

	for (int i = 0; i < eWeaponMax; i++) {
		switch (i) {
		case eWeaponSpear:
			m_weapon_image_p[i] = GET_RESOURCE("IconSpear", CImage*);
			break;
		case eWeaponAxe:
			m_weapon_image_p[i] = GET_RESOURCE("IconAxe", CImage*);
			break;
		case eWeaponGun:
			m_weapon_image_p[i] = GET_RESOURCE("IconGun", CImage*);
			break;
		}
		
	}
}

CGameSceneUI::~CGameSceneUI()
{
	delete m_hp_bar_p;
	delete m_weapon_bar_p;
}

void CGameSceneUI::Update()
{
	m_hp_bar_p->Update();
	m_weapon_bar_p->Update();
}

void CGameSceneUI::Draw()
{
	m_hp_frame_image_p->SetSize(m_ui_size);
	m_hp_frame_image_p->SetPos(m_ui_pos);
	m_hp_frame_image_p->Draw();
	m_weapon_frame_image_p->SetSize(CVector2D(500, 250) * 0.6);
	m_weapon_frame_image_p->SetPos(m_ui_pos + CVector2D(150, 130));
	m_weapon_frame_image_p->Draw();
	m_hp_bar_p->Draw();
	m_weapon_bar_p->Draw();

	int weapon_id = *m_weapon_id_p;
	if (weapon_id != -1) {
		switch (weapon_id) {
		case eWeaponSpear:
		case eWeaponAxe:
			m_weapon_image_p[weapon_id]->SetPos(m_ui_pos + CVector2D(233, 252.5));
			m_weapon_image_p[weapon_id]->SetSize(CVector2D(80, 80));
			m_weapon_image_p[weapon_id]->Draw();
			break;
		case eWeaponGun:
			m_weapon_image_p[weapon_id]->SetPos(m_ui_pos + CVector2D(235, 254.5));
			m_weapon_image_p[weapon_id]->SetSize(CVector2D(76, 76));
			m_weapon_image_p[weapon_id]->Draw();
			break;
		}
		
	}
	
}
