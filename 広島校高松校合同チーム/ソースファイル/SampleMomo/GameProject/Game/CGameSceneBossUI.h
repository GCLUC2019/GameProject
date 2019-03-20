#pragma once
#include "CObject.h"
#include "../Global.h"
#include "CSubWeapon.h"

class CBar;
class CGameSceneBossUI : public CObject {
private:
	CImage * m_hp_frame_image_p = nullptr;
	CBar * m_hp_bar_p = nullptr;

	CVector2D m_ui_pos;
	CVector2D m_ui_size;
public:
	CGameSceneBossUI();
	~CGameSceneBossUI();
	void Update();
	void Draw();
};