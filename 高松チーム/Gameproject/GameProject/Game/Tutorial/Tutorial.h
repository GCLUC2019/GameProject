#pragma once
#include "../../Base/Task.h"
/*�S��
�@�����@class Tutorial 
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
	/*
	�@@brief�@�`���[�g���A���p����UI
	*/
	void DescriptionUI();


};