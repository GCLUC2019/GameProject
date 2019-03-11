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
	void Update();
	void Draw();
	void next_scene();
};

