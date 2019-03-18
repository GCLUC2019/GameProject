#include "CSetupGame.h"
#include "CGameScene.h"
#include "CStorySceneOpening.h"
#include "CTitle.h"
#include "CLoadResorce.h"

//‹N“®Žž‚ÉŒÄ‚Î‚ê‚Ü‚·B
void CSetupGame::Setup()
{
	//CGameScene::GetInstance()->Setup();
	TaskManager::GetInstance()->AddTask(new CTitle());
	//TaskManager::GetInstance()->AddTask(new CStorySceneOpening());
}