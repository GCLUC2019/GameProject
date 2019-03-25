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
#include"../Character/EnemyBase/Enemy/Enemy04.h"
#include "../../Game/UI/UI.h"
#include "../GameProject/Game/Stage/CollisionBox.h"
#include "../Character/EnemyBase/Enemy/Enemy02.h"
#include "../GameData/GameData.h"
#include"../GameProject/Game/Scene/GameScene2.h"
GameScene::GameScene() : Task(eGameScene)
{
	new GameSceneResourse();
	TaskManager::GetInstance()->AddTask(new Stage01());
	TaskManager::GetInstance()->AddTask(new EnemyManager());
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eHyoutan,CVector2D(256,360)));
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eInari, CVector2D(512, 360)));
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eKakera, CVector2D(768, 360)));
	TaskManager::GetInstance()->AddTask(new Item(ItemList::eKoban, CVector2D(1024, 360)));
	TaskManager::GetInstance()->AddTask(new ItemBox(Box_Typ::eTrueBox, CVector2D(512, 560)));
	TaskManager::GetInstance()->AddTask(new ItemBox(Box_Typ::eDummyBox, CVector2D(768, 560)));
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new UI());
    TaskManager::GetInstance()->AddTask(new CollisionBox(CVector2D(500, 300), CRect(-200, -1, 200, 1)));
	SOUND("ikusa_japan2")->Play(true);

}

GameScene::~GameScene()
{
	SOUND("ikusa_japan2")->Stop();
}

void GameScene::Update()
{
	if (g_game_data.m_dead_cnt >= 10 && m_go_flg == false) {
		m_go_flg = true;
		TaskManager::GetInstance()->AddTask(new GuidanceUI());
	}

	Task* p = TaskManager::FindObject(ePlayer);
	Player* n = dynamic_cast<Player*>(p);
	if(n != nullptr)
	m_player_pos_x = n->GetPos();


	if (g_game_data.m_dead_cnt >= 10 && m_player_pos_x.x >= 1280)
			g_game_data.m_scroll.x += 10;
	if (g_game_data.m_scroll.x >= 1280) g_game_data.m_scroll.x = 1280;


	if (g_game_data.m_dead_cnt >= 20)
		TaskManager::GetInstance()->AddTask(new GuidanceUI());

	if (g_game_data.m_dead_cnt >= 20 && m_player_pos_x.x - g_game_data.m_scroll.x >= 1280) {

		TaskManager::KillAll();
		TaskManager::GetInstance()->AddTask(new GameScene2());
	}
	
}
