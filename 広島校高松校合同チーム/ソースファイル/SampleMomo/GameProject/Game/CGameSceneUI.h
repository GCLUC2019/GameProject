#pragma once
#include "CObject.h"
#include "../Global.h"

class CBar;
class CGameSceneUI : public CObject {
private:
	CImage * m_hp_frame_image_p = nullptr;
	CImage * m_weapon_frame_image_p = nullptr;
	CBar * m_hp_bar_p = nullptr;
	//CBar * m_weapon_bar_p = nullptr;
	CVector2D m_ui_pos;
	CVector2D m_ui_size;
public:
	CGameSceneUI();
	~CGameSceneUI();
	void Update();
	void Draw();
};