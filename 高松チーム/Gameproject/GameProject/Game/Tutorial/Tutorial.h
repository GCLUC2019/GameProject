#pragma once
#include "../../Base/Task.h"
#define MAX_LINE 64
/*担当
　国見　class Tutorial 
*/

class Tutorial : public Task {
private:
	bool m_state_flg;
    CFont m_font;
    char m_text[MAX_LINE][128];
    int m_line;
    int m_line_size;
protected:
public:
	Tutorial();
	~Tutorial();
	void Draw();
	void Update();
	/*
	　@brief　チュートリアル用説明UI
	*/
	void DescriptionUI();


};