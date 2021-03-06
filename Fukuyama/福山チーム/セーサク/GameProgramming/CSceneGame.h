//#ifndef CSCENEGAME_H
//#define CSCENEGAME_H

#include "CScene.h"
#include "CCollider.h"
#include "CRectangle.h"

class CSceneGame :public CScene,Task{
public:
	CSceneGame(){
		mSceneTag = EGAME;
	}
	~CSceneGame(){
		CCollisionManager::Get()->Destroy();
		CTaskManager::Get()->Destroy();
	}
	void Init();
	void Update();

	int mEnemyIntervar;
	int mEnemyLimit;
};

class CSceneWin :public CScene{
public:
	CSceneWin(){
		mSceneTag = EWIN;
	}
	CTexture mTexture;
	CRectangle mWin;
	void Init();
	void Update();
};

class CSceneLose :public CScene{
public:
	CSceneLose(){
		mSceneTag = ELOSE;
	}
	CTexture mTexture;
	CRectangle mLose;
	void Init();
	void Update();
};

class CSceneTitle :public CScene{
public:
	CSceneTitle(){
		mSceneTag = ETITLE;
	}
	
	CTexture mTexture;
	CTexture mEnterTex;
	CRectangle mTitle;
	CRectangle mEnter;
	void Init();
	void Update();
};

//#endif