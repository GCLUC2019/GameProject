#pragma once
#include "CObject.h"
#include "../Global.h"
#include "CSubWeapon.h"

class CBar;
class CGameSceneUI : public CObject {
private:
	CImage * m_guide_input_p = nullptr;
	CImage * m_guide_how_to_end_guide_p = nullptr;

	CImage * m_hp_frame_image_p = nullptr;
	//CImage * m_weapon_frame_image_p = nullptr;
	CImage * m_reserve_image_p = nullptr;
	CBar * m_hp_bar_p = nullptr;
	CBar*m_weapon_bar_p = nullptr;
	//float*GetWeaponHitPointPointer;
	//float*GetWeaponHitPointMaxPointer;
	CVector2D m_ui_pos;
	CVector2D m_ui_size;

	CImage * m_weapon_image_p[eWeaponMax];

	int* m_weapon_id_p = nullptr;
	int* m_reserve_num_p = nullptr;

	bool m_is_show_guide = false;
	bool m_is_begin_frame = true;
public:
	CGameSceneUI();
	~CGameSceneUI();
	void Update();
	void SetIsShowGuide(bool _is) { m_is_show_guide = _is; };
	void Draw();
};