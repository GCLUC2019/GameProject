#pragma once
#include "CObject.h"
#include "../Global.h"

class CBar: public CObject {
private:
	CImage * m_HPbar_img = nullptr;
public:
	//int damage;
	//int size_y;
	float hp;
	float*now_hp;
	float m_bar_value_now;
	//int max_bar_size;
	//int now_bar_size;
	CVector2D m_bar_size;
	CVector2D m_bar_pos;
	float m_mult_hp;
	CBar(CImage* _img, float*_hp,float _max_hp, CVector2D _pos, CVector2D _size);
	~CBar();
	void Update();
	void Draw();
};