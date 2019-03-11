#pragma once
#include "CObject.h"
#include "../Global.h"

class CStoryScene : public CObject {
private:
public:
	CStoryScene();
	~CStoryScene();
	void Update();
	void Draw();
};