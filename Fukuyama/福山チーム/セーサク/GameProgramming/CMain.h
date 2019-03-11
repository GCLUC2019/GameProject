#pragma once

#include "glut.h"
#include "CCollider.h"
#include "CScene.h"


#define W_H		800 //Window•
#define W_V		600 //Window‚‚³

class CMain {
	int		mState;
public:
	static CScene::ESceneTag mSceneTag;

	CMain() : mState(0) {}

	void MainLoop() {
		switch (mState)
		{
		case 0:
			Init();
			mState = 1;
			break;
		default:
			Update();
			break;
		}
	}
	void Init();
	void Update();

	~CMain(){
		CCollisionManager::Get()->Destroy();
		CTaskManager::Get()->Destroy();
	}
};

