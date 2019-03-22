#pragma once
#include "CObject.h"
#include "../Global.h"

class CBar: public CObject {
private:
	CImage * m_bar_img = nullptr;
public:
	float m_max_value;
	float* m_now_value;
	float m_bar_value_now;
	float m_mult_value;
	bool m_is_scroll = false;
	CBar(CImage* _img, float*_value,float _max_value, CVector3D _pos, CVector2D _size,bool _is_scrool = false);
	CBar(CImage* _img, float*_value, float _max_value, CVector2D _pos, CVector2D _size, bool _is_scrool = false);
	~CBar();
	void Update();
	void Draw();
};