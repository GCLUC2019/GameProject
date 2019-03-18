#pragma once
#include "../../Base/Task.h"
#define MAX_LINE 64
/*担当
　国見　class Tutorial 
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
public:
	Balloon();
	void Update();
	void Draw();
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
};