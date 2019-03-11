#include "CSceneGame.h"
#include "CMain.h"
#include "Windows.h"
#include"CBoss.h"

extern CBoss*Boss;

void CSceneGame::Init(){
	Tank = new CPlayerTank();
	EnemyTank = new CEnemyTank();
	Tank->Init();
	EnemyTank->Init();
	EnemyTank->mPosition = CVector2(-400.0f, 250.0f);
	Boss->mPosition = CVector2(400.0f, -250.0f);
	EnemyTank->mRotation = 270.0f;
	Boss->mRotation = -270.0f;
	CTaskManager::Get()->Add(Tank);
	CTaskManager::Get()->Add(EnemyTank);
	CTaskManager::Get()->Add(Boss);
	Texture.Load("exp.tga");
}

void CSceneGame::Update(){
	CTaskManager::Get()->Update();
	CTaskManager::Get()->Render();
	CCollisionManager::Get()->Remove();
	CTaskManager::Get()->Remove();
}

void CSceneWin::Init(){
	mTexture.Load("Result.tga");
	mWin.SetVertex(-200, 200, -100, 100);
	mWin.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mWin.SetTexture(&mTexture, 0, 358, 142, 0);
}

void CSceneWin::Update(){
	mWin.Update();
	mWin.Render();
	if (GetKeyState(VK_RETURN) & 0x8000){
		CMain::mSceneTag = CScene::EGAME;
	}
}

void CSceneLose::Init(){
	mTexture.Load("Result.tga");
	mLose.SetVertex(-200, 200, -100, 100);
	mLose.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mLose.SetTexture(&mTexture, 0, 358, 0, -142);
}

void CSceneLose::Update(){
	mLose.Update();
	mLose.Render();
	if (GetKeyState(VK_RETURN) & 0x8000){
		CMain::mSceneTag = CScene::EGAME;
	}
}