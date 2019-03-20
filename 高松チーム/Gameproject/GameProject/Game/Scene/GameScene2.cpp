#include "GameScene2.h"
#include "../GameProject/Game/Character/Player.h"
#include "../GameProject/Game/Character/EnemyBase/Boss/BossManager.h"
#include "../../Game/UI/UI.h"
#include "../GameProject/Game/Stage/BossStage.h"

GameScene2::GameScene2() : Task(eGameScene2)
{
	TaskManager::GetInstance()->AddTask(new BossStage());
	TaskManager::GetInstance()->AddTask(new BossManager());
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new UI());
}

GameScene2::~GameScene2()
{
}

void GameScene2::Update()
{
}
