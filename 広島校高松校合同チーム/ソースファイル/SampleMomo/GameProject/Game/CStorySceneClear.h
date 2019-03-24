#pragma once
#include "CStoryScene.h"

class CStorySceneClear:public CStoryScene
{
private:
	int m_clear_stage;
public:
	CStorySceneClear(int _clear_stage);
	~CStorySceneClear();
	void Update();
	void Draw();
	void Setchar(int _clear_stage);
	void SetValue(int _clear_stage);
};