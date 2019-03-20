#pragma once
#include "CObject.h"
class CFade : CObject{
private:
	CImage* m_black_screen_p = nullptr;
	double m_alpha = 0.0;
	double m_fade_out_count = 0.0;
	double m_fade_in_count = 0.0;
	double m_fade_out_value_per_count;
	double m_fade_in_value_per_count;
public:
	CFade();
	void Update();
	void Draw();
	static CFade* GetInstance();
	void SetFadeOut(double _count) {
		if (_count < 1.0) {
			m_alpha = 2.55;
			return;
		}
		m_fade_out_count = _count;
		m_fade_out_value_per_count = 2.55 / _count;
	};
	void SetFadeIn(double _count) { 
		if (_count < 1.0) {
			m_alpha = 0.0;
			return;
		}
		m_fade_in_count = _count;
		m_fade_in_value_per_count = 2.55 / _count;
	};
};

/*
20190320 by shingai
*/