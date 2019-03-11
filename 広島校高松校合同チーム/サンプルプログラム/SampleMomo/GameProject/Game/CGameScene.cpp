#include "CGameScene.h"
#include "CCharacterEnemy.h"
#include "CCharacterPlayer.h"
#include "CObjectImage.h"
#include "CCommonObject.h"
#include "CStoryScene.h"
#include "CTitle.h"

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
		AddGameSceneObject(new CCommonObject(nullptr, CVector3D(1280 * i, 0, 0), CVector2D(0, 0), CVector3D(1280, 1, 720)));
		AddGameSceneObject(new CObjectImage(GET_RESOURCE("Stage_Background_0", CImage*), CVector3D(1280 * i, 0, 0), CVector2D(1280, 720), -1));
	}

	//AddGameSceneObject(new CCommonObject(nullptr, CVector3D(600, 0, 600), CVector2D(0, 0), CVector3D(50, 50, 50)));

	SetGameSceneLimitPosMin(CVector3D(100.0f, 0.0f, 340.0f));

	SetGameSceneLimitPosMax(CVector3D(1280.0f*6,720.0f,720.0f));

	CCharacterPlayer* player_p = new CCharacterPlayer();
	AddGameSceneObject(player_p);

	player_p->SetSize(400, 400);
	player_p->SetPos(500, -300, 500);
	//player_p->SetRads(10, 10, 10);


	CCharacterEnemy* enemy_p = new CCharacterEnemy();
	AddGameSceneObject(enemy_p);
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

CGameScene * CGameScene::GetInstance()
{
	if (s_instance_p == nullptr) s_instance_p = new CGameScene();
	return s_instance_p;
}
