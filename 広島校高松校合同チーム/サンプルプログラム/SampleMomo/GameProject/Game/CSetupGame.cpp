#include "CSetupGame.h"
#include "CGameScene.h"
#include "CStoryScene.h"
#include "CTitle.h"
#include "CLoadResorce.h"

//起動時に呼ばれます。
void CSetupGame::Setup()
{
	//CGameScene::GetInstance()->Setup();
	TaskManager::GetInstance()->AddTask(new CTitle());
	//TaskManager::GetInstance()->AddTask(new CStoryScene());
}