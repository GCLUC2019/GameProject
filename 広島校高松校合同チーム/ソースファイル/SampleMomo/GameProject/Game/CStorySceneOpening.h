#pragma once
#include "CStoryScene.h"

class CStorySceneOpening:public CStoryScene
{
public:
	CStorySceneOpening();
	~CStorySceneOpening();
    void Update();
    void Draw();
	void AddRAll();
	void Setchar();
	void SetValue();
};


