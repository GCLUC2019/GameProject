#pragma once
#include "../../Base/Task.h"
#define MAX_LINE 64
/*íSìñ
Å@çëå©Å@class Tutorial 
*/

class Tutorial : public Task {
private:
	bool m_state_flg;
   
protected:
public:
	Tutorial();
	~Tutorial();
	void Draw();
	void Update();
	


};

class Balloon : public Task {
private:
	CVector2D m_pos;
	CImage m_img;
	int cnt;
	bool m_get_specialattack;
public:
	Balloon();
	void Update();
	void Draw();
	CVector2D GetPos() {
		return  CVector2D(0, 750);
	}
};

class DescriptionUI : public Task {
private:
	CFont m_font;
	char m_text[MAX_LINE][128];
	int m_line;
	int m_line_size;

public:
	DescriptionUI();
	void Update();
	void Draw();
	CVector2D GetPos() {
		return  CVector2D(0, 800);
	}
};