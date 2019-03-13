#include "GameScene.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../GameProject/Game/Character/Player.h"
#include "../GameProject/Game/Character/EnemyBase/EnemyManager.h"
#include "../GameProject/Boss.h"
#include "../GameProject/Game/Character/EnemyBase/Boss/BossManager.h"
#include "../Item/Item.h"

GameScene::GameScene() : Task(eGameScene)
{
	new Resource();
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new EnemyManager());
	//TaskManager::GetInstance()->AddTask(new BossHead());
	//TaskManager::GetInstance()->AddTask(new BossHand());
	//TaskManager::GetInstance()->AddTask(new BossTail());
	TaskManager::GetInstance()->AddTask(new BossManager());
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eHyoutan,CVector2D(256,360)));
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eInari, CVector2D(512, 360)));
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eKakera, CVector2D(768, 360)));
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eKoban, CVector2D(1024, 360)));
}

GameScene::~GameScene()
{
}
