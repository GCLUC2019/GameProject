#pragma once
#include "CObject.h"

class CGameOver :public CObject {
private:
	CImage * m_game_over_p = nullptr;
	CImage* m_continue_p = nullptr;
	CImage* m_return_p = nullptr;
	CImage* m_grey_background_p = nullptr;
	int m_serect_num = 0;
	double m_draw_cnt = 0;
public:
	CGameOver();
	~CGameOver();
	void Update();
	void Draw();
};
