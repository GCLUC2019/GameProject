#include "GameScene.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../GameProject/Game/Character/Player.h"
#include "../GameProject/Game/Character/EnemyBase/EnemyManager.h"
#include "../GameProject/Boss.h"
#include "../GameProject/Game/Character/EnemyBase/Boss/BossManager.h"
#include "../Stage/ground.h"
#include "../Item/Item.h"
#include "../Item/ItemBox.h"
#include "../GameProject/Game/Scene/Title.h"
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include"../Character/EnemyBase/Enemy/Enemy01.h"
#include "../../Game/UI/UI.h"
#include "../GameProject/Game/Stage/MapData.h"
>>>>>>> 7b7833fccc61631035d5b5e9c0ad3425b18ce63d
=======
#include"../Character/EnemyBase/Enemy/Enemy04.h"
#include "../../Game/UI/UI.h"
>>>>>>> 341f6f95b9c8109d44ef84c49b2c44a5d8d53fec
GameScene::GameScene() : Task(eGameScene)
{
	new Resource();
	TaskManager::GetInstance()->AddTask(new Stage01());
	TaskManager::GetInstance()->AddTask(new EnemyManager());
	TaskManager::GetInstance()->AddTask(new BossManager());
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eHyoutan,CVector2D(256,360)));
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eInari, CVector2D(512, 360)));
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eKakera, CVector2D(768, 360)));
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eKoban, CVector2D(1024, 360)));
	TaskManager::GetInstance()->AddTask(new ItemBox(Box_Typ::eTrueBox, CVector2D(512, 560)));
	TaskManager::GetInstance()->AddTask(new ItemBox(Box_Typ::eDummyBox, CVector2D(768, 560)));
	TaskManager::GetInstance()->AddTask(new Player());
<<<<<<< HEAD
<<<<<<< HEAD
=======
	TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(100, 100)));
	TaskManager::GetInstance()->AddTask(new UI());
    TaskManager::GetInstance()->AddTask(new MapData());
>>>>>>> 7b7833fccc61631035d5b5e9c0ad3425b18ce63d
=======
	TaskManager::GetInstance()->AddTask(new Enemy04(CVector2D(300, 300)));
	TaskManager::GetInstance()->AddTask(new UI());
>>>>>>> 341f6f95b9c8109d44ef84c49b2c44a5d8d53fec

}

GameScene::~GameScene()
{
}
