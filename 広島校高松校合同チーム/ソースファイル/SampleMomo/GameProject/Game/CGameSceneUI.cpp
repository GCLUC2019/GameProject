#include "CGameSceneUI.h"
#include "CCharacterPlayer.h"
#include "CBar.h"
#include "CSubWeapon.h"
#include "CGameScene.h"

CGameSceneUI::CGameSceneUI() :CObject(0, DP_UI)
{
	m_ui_pos = CVector2D(0,15);
	m_ui_size = CVector2D(500,250) * 0.8;

	m_hp_frame_image_p = GET_RESOURCE("HP_Bar_Frame", CImage*);
	//m_weapon_frame_image_p = GET_RESOURCE("Weapon_Bar_Frame", CImage*);
	m_reserve_image_p = GET_RESOURCE("Flag", CImage*);

	//ƒŠƒXƒg‚É’Ç‰Á‚·‚é‚Ù‚Ç‚Å‚à‚È‚¢‚Ì‚Å
	m_hp_bar_p = new CBar(GET_RESOURCE("HP_Bar_Fix", CImage*), CCharacterPlayer::GetInstance()->GetHitPointPointer(), CCharacterPlayer::GetInstance()->GetHitPointMax(), m_ui_pos + CVector2D(160, 95.5) * 0.8, CVector2D(330, 25) * 0.8);
	

	m_weapon_bar_p = new CBar(GET_RESOURCE("Weapon_Bar", CImage*), CCharacterPlayer::GetInstance()->GetPlayerEquipWeaponEndurancePointer(), ENDURANCE_MAX, m_ui_pos + CVector2D(164, 122.5), CVector2D(352*0.6, 25*0.6));

	m_weapon_id_p = CCharacterPlayer::GetInstance()->GetPlayerEquipWeaponIdPointer();

	

	m_reserve_num_p = CGameScene::GetInstance()->GetReserveNumPointer();


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
	/*
	m_weapon_frame_image_p->SetSize(CVector2D(500, 250) * 0.6);
	m_weapon_frame_image_p->SetPos(m_ui_pos + CVector2D(100, 100));
	m_weapon_frame_image_p->Draw();
	*/
	m_hp_bar_p->Draw();
	m_weapon_bar_p->Draw();


	for (int i = 0; i < *m_reserve_num_p; i++) {
		m_reserve_image_p->SetPos(m_ui_pos + CVector2D(i * 20 + 110, 22));
		m_reserve_image_p->SetSize(50, 50);
		m_reserve_image_p->Draw();
	}
	

	int weapon_id = *m_weapon_id_p;
	if (weapon_id != -1) {
		switch (weapon_id) {
		case eWeaponSpear:
		case eWeaponAxe:
			m_weapon_image_p[weapon_id]->SetPos(m_ui_pos + CVector2D(185,182.5));
			m_weapon_image_p[weapon_id]->SetSize(CVector2D(50, 50));
			m_weapon_image_p[weapon_id]->Draw();
			break;
		case eWeaponGun:
			m_weapon_image_p[weapon_id]->SetPos(m_ui_pos + CVector2D(187, 184.5));
			m_weapon_image_p[weapon_id]->SetSize(CVector2D(46, 46));
			m_weapon_image_p[weapon_id]->Draw();
			break;
		}
		
	}
	
}
