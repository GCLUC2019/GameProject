#pragma once
#include "CObject.h"
#include "../Global.h"

/*
ストーリーパート後に呼ばれるステージクリア演出
*/

class CAnimation;

class  CStageClear:public CObject
{
private:
	CImage * m_stage_clear_back_ground_p = nullptr;
	CAnimation * m_stage_logo_p = nullptr;
	CAnimation * m_island_bright_effect_p = nullptr;
	CAnimation * m_bright_effect_p = nullptr;

	double m_draw_cnt = 0;
	double m_change_cnt = 0;
	int m_clear_stage_id = -1;
	bool m_is_fade_out = false;


public:
	CStageClear(int _clear_stage_id);
	~CStageClear();
	void Update();
	void Draw();
	void NextScene();
};