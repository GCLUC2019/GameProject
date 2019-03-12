#include "GameScene.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../GameProject/Game/Character/Player.h"
#include "../GameProject/Game/Character/EnemyBase/EnemyManager.h"
#include "../GameProject/Boss.h"
#include "../GameProject/Game/Character/EnemyBase/Boss/BossManager.h"

GameScene::GameScene() : Task(eGameScene)
{
	new Resource();
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new EnemyManager());
	//TaskManager::GetInstance()->AddTask(new BossHead());
	//TaskManager::GetInstance()->AddTask(new BossHand());
	//TaskManager::GetInstance()->AddTask(new BossTail());
	TaskManager::GetInstance()->AddTask(new BossManager());
}

GameScene::~GameScene()
{
}
