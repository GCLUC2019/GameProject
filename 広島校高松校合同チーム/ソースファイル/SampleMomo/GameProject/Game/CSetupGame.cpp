#include "CSetupGame.h"
#include "CGameScene.h"
#include "CStorySceneOpening.h"
#include "CTitle.h"
#include "CLoadResorce.h"

//起動時に呼ばれます。
void CSetupGame::Setup()
{
	TaskManager::GetInstance()->AddTask(new CTitle());
}