#include "GameScene2.h"
#include "../GameProject/Game/Character/Player.h"
#include "../GameProject/Game/Character/EnemyBase/Boss/BossManager.h"
#include "../../Game/UI/UI.h"
#include "../GameProject/Game/Stage/BossStage.h"
#include "../GameProject/Game/Scene/Result.h"

GameScene2::GameScene2() : Task(eGameScene2)
{
	new GameSceneResourse2();
	TaskManager::GetInstance()->AddTask(new BossStage());
	TaskManager::GetInstance()->AddTask(new BossManager());
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new UI());
	TaskManager::GetInstance()->AddTask(new BossGageBaseUI());
	TaskManager::GetInstance()->AddTask(new BossHpUI());
	SOUND("n32")->Play(true);
}

GameScene2::~GameScene2()
{
	
}

void GameScene2::Update()
{
	Task* p = TaskManager::FindObject(CharacterData::eBossManager);
	BossManager* n = dynamic_cast<BossManager*>(p);
	if (n == nullptr) {
		TaskManager::GetInstance()->AddTask(new GameClear());
		TaskManager::KillAll();
	}
}
