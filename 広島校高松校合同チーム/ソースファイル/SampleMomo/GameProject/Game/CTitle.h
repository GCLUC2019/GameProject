#pragma once
#include "CObject.h"
#include "../Global.h"

class CTitle : public CObject {
private:
	CImage* m_background_image_p = nullptr;
	CImage* m_backtxt_p = nullptr;
	double m_count_txt;
	double m_count_txt2;
	bool m_draw_txt = true;
	bool m_flash_txt = true;

public:
	CTitle();
	~CTitle();
	
	
	void Update();
	void Draw();
	void NextScene();
};
