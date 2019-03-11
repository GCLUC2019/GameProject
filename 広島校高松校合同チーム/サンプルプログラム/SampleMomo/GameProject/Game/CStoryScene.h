#pragma once
#include "CObject.h"
#include "../Global.h"

class CStoryScene : public CObject {
private:
	CImage m_s_img;
	CImage m_text_box;
	CImage m_text;
public:
	CStoryScene();
	~CStoryScene();
	void Update();
	void Draw();
	void SetTextBox();
	void SetStory(char story_name[]);
	void SetText(char text_name[]);
};