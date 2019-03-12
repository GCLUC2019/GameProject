#pragma once
#include "CObject.h"
#include "../Global.h"

class CTitle : public CObject {
private:
	CImage* m_background_image_p = nullptr;
	CImage* m_backtxt_p = nullptr;
public:
	CTitle();
	~CTitle();
	int m_count_txt;
	int m_count_txt2;
	bool m_draw_txt = true;
	bool m_flash_txt = true;
	void Update();
	void Draw();
	void NextScene();
};

