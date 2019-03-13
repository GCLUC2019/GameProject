#pragma once
#include "CObject.h"
#include "../Global.h"

class CBar: public CObject {
private:
	CImage * m_HPbar_img = nullptr;
public:
	int damage;
	float hp;
	float now_hp;
	int max_bar_size;
	int now_bar_size;
	int m_decrease_hp;
	CBar();
	~CBar();
	void Update();
	void Draw();
};