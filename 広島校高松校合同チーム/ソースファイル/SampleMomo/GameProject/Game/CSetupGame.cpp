#include "CSetupGame.h"
#include "CGameScene.h"
#include "CStorySceneOpening.h"
#include "CTitle.h"
#include "CLoadResorce.h"

//�N�����ɌĂ΂�܂��B
void CSetupGame::Setup()
{
	TaskManager::GetInstance()->AddTask(new CTitle());
}