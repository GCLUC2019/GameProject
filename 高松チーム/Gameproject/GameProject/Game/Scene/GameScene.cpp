#include "GameScene.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../GameProject/Game/Character/Player.h"
#include "../GameProject/Game/Character/EnemyBase/Enemy/Enemy01.h"
#include "../GameProject/Game/Character/EnemyBase/Enemy/Enemy02.h"
#include "../GameProject/Game/Character/EnemyBase/Enemy/Enemy05.h"
#include "../GameProject/Boss.h"

GameScene::GameScene()
{
	new Resource();
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new Enemy01());
    TaskManager::GetInstance()->AddTask(new Enemy02());
	TaskManager::GetInstance()->AddTask(new Enemy05());
	TaskManager::GetInstance()->AddTask(new BossHead());
	TaskManager::GetInstance()->AddTask(new BossHand());
	//TaskManager::GetInstance()->AddTask(new BossTail());
	//TaskManager::GetInstance()->AddTask(new BossManager());
}

GameScene::~GameScene()
{
}
