#include "CGameScene.h"
//#include "CCharacterEnemy.h"
#include "CCharacterPlayer.h"
#include "CObjectImage.h"
#include "CCommonObject.h"
#include "CStoryScene.h"
#include "CTitle.h"
#include "CBar.h"
#include "CGameSceneUI.h"
#include "CCharacterEnemy.h"
#include "CCharacterBoss.h"
#include "CGameOver.h"

/*

プレイヤーめりこみの原因について
当たり判定の順番的にプレイヤーが対応する側（当たっている時に移動する側）になる為プレイヤーが敵などのオブジェクトに合わせて移動を戻している形になるから

対策


良くないが動作可能な対策
プレイヤーの当たり判定順位の調整（後に調整すればよいということになる。


良い対策
当たり判定をしたことを相手オブジェクトにも伝える仕組み


根本的原因
奥行きで辺り判定が変わる理由

描画順番でソートは行っているが、その順番はUpdateなどの更新にも利用されるから。

*/

//#include "CDropItem.h"
static CGameScene* s_instance_p = nullptr;

CGameScene::CGameScene() : CObject(0, 0)
{
	Init();
}

CGameScene::~CGameScene()
{
}

void CGameScene::Init()
{
	for (int i = 0; i < GAME_SCENE_OBJECT_MAX; i++) {
		m_game_scene_object_p[i] = nullptr;
	}
}

void CGameScene::Setup()
{
	

	for (int i = 0; i < 6; i++) {
		//床張り(役割は単純なので処理の軽い汎用オブジェクトで代用)
		AddGameSceneObject(new CCommonObject(nullptr, CVector3D(1280.0f * i,10000.0f, 0.0f), CVector2D(0, 0), CVector3D(1280.0f, 1.0f + 10000.0f, 720.0f)));
		AddGameSceneObject(new CObjectImage(GET_RESOURCE("Stage_Background_0", CImage*), CVector3D(1280 * i, 0, 0), CVector2D(1280, 720), -1));
	}

	//AddGameSceneObject(new CCommonObject(nullptr, CVector3D(600, 0, 600), CVector2D(0, 0), CVector3D(50, 50, 50)));

	SetGameSceneLimitPosMin(CVector3D(100.0f, 0.0f, 340.0f));

	SetGameSceneLimitPosMax(CVector3D(1280.0f*6,720.0f,720.0f));

	
	CCharacterPlayer* player_p = new CCharacterPlayer();
	AddGameSceneObject(player_p);
	player_p->SetPos(300, -2500, 500);
	

	//for (int i = 0; i < 1;i++) AddGameSceneObject(new CCharacterEnemy());

	/*
	CDropItem* drop_item_p;
	AddGameSceneObject(drop_item_p = new CDropItem(eItemIdSpear));
	drop_item_p->SetPos(CVector3D(200,200,200));
	drop_item_p->SetSize(CVector2D(200, 200));
	*/


	//敵の配置
	/*for(int i = 0; i < 70;i++) AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe,CVector3D(1000 +  200 * i,-2500,450 + 100 )));


	for (int i = 0; i < 0; i++) AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(2000 + 200 * i, -2500, 450 + 100 * i)));
*/

	AddGameSceneObject(new CCharacterBoss());
	
	AddGameSceneObject(new CGameSceneUI());

	CFPS::Wait();//deltatime安定化用
}


void CGameScene::AddGameSceneObject(Task * _object)
{
	TaskManager::GetInstance()->AddTask(_object);
	m_game_scene_object_p[m_game_scene_object_num++] = _object;
}

void CGameScene::ClearGameSceneObject()
{
	for (int i = 0; i < m_game_scene_object_num; i++) {
		m_game_scene_object_p[i]->SetIsDelete();
		m_game_scene_object_p[i] = nullptr;
	}
	m_game_scene_object_num = 0;
}

void CGameScene::WaveDone()
{
}

void CGameScene::GameOver()
{
	ClearGameSceneObject();
	TaskManager::GetInstance()->AddTask(new CGameOver());
}

CGameScene * CGameScene::GetInstance()
{
	if (s_instance_p == nullptr) s_instance_p = new CGameScene();
	return s_instance_p;
}
