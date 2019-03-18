#pragma once
#include "../../Base/Task.h"
#define MAX_LINE 64
/*�S��
�@�����@class Tutorial 
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
	�@@brief�@�`���[�g���A���p����UI
	*/
	void DescriptionUI();


};