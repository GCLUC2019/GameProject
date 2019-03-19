#pragma once
#include "CObject.h"
#include "../Global.h"

class  CStageClear:public CObject
{
private:
	CImage* m_stage_clear_logo_p = nullptr;
	double m_draw_cnt = 0;
	double m_change_cnt = 0;
	int m_clear_stage_id = -1;
public:
	CStageClear(int _clear_stage_id);
	~CStageClear();
	void Update();
	void Draw();
	void NextScene();
};