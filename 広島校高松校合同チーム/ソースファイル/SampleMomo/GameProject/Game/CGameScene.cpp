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
#include "CFade.h"
#include "CStorySceneClear.h"
#include "CGameSceneWave.h"
#include "CGameSceneBossUI.h"
#include "CSubWeapon.h"


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
	m_reserve_num = RESERVE_MAX;
	m_now_scene = eStage1;
	SetCheckPoint(CVector3D(300, -220, 550));
	m_last_wave = -1;
	PopPlayer();
	SetupScene();
}


void CGameScene::AddGameSceneObject(Task * _object)
{
	TaskManager::GetInstance()->AddTask(_object);
	m_game_scene_object_p[m_game_scene_object_num++] = _object;
}

void CGameScene::ClearGameSceneObject()
{
	//ポインタの中身がそもそも破棄されてる場合があるよね、今回。
	for (int i = 0; i < m_game_scene_object_num; i++) {
		if (m_game_scene_object_p[i] == nullptr) continue;
		m_game_scene_object_p[i]->SetIsDelete();
		m_game_scene_object_p[i] = nullptr;
	}
	m_game_scene_object_num = 0;
}

void CGameScene::EraseGameSceneObject(Task * _object)
{
	for (int i = 0; i < m_game_scene_object_num; i++) {
		if (m_game_scene_object_p[i] == _object) {
			m_game_scene_object_p[i] = nullptr;
		}
	}
}

void CGameScene::WaveDone(int _next_wave)
{
	m_last_wave = _next_wave;

	switch (m_now_scene) {
	case eStage1:
		SetGameSceneLimitPosMin(CVector3D(100.0f, 0.0f, 340.0f));
		SetGameSceneLimitPosMax(CVector3D(1280.0f * 6, 720.0f, 720.0f));
		break;
	case eStage1Boss:
		SetGameSceneLimitPosMin(CVector3D(100.0f, 0.0f, 340.0f));
		SetGameSceneLimitPosMax(CVector3D(1280.0f * 2, 720.0f, 720.0f));
		break;
	}

	if(_next_wave != -1) AddGameSceneObject(new CGameSceneWave(_next_wave));

}

void CGameScene::Update()
{
	CheckSceneChange();
}

void CGameScene::CheckSceneChange()
{
	if (m_next_scene == -1) return;
	CCharacterPlayer* player_p = CCharacterPlayer::GetInstance();
	if (player_p != nullptr) {
		if (player_p->GetPos().x >= m_next_scene_pos) {
			ChangeScene(m_next_scene);
		}
	}
}

void CGameScene::Miss()
{
	m_reserve_num--;
	if (m_reserve_num < 0) {
		//ゲームオーバー呼び出し
		TaskManager::GetInstance()->AddTask(new CGameOver());
		return;
	}

	ClearGameSceneObject();
	DeletePlayer();
	PopPlayer();
	SetupScene();
}

void CGameScene::StageClear()
{
	ClearGameSceneObject();
	DeletePlayer();
	switch (m_now_scene) {
	case eStage1Boss:
		TaskManager::GetInstance()->AddTask(new CStorySceneClear(m_now_scene));
		break;
	}
	CFade::GetInstance()->SetFadeOut(0);
	CFade::GetInstance()->SetFadeIn(30);
}

void CGameScene::PopPlayer()
{
	if (m_player_object_p != nullptr) DeletePlayer();
	TaskManager::GetInstance()->AddTask(m_player_object_p = new CCharacterPlayer(CVector3D(300, -201 - 300, 550)));
}

void CGameScene::DeletePlayer()
{
	if (m_player_object_p == nullptr) return;
	m_player_object_p->SetIsDelete();
}

void CGameScene::SetupScene()
{
	//フェードイン・フェードアウト
	CFade::GetInstance()->SetFadeOut(0);
	CFade::GetInstance()->SetFadeIn(30);

	m_player_object_p->SetPos(m_check_point);
	m_player_object_p->SetPosOld(m_check_point);

	/*
	m_player_object_p->SetPos(CVector3D(300, -201, 550));
	m_player_object_p->SetPosOld(m_player_object_p->GetPos());
	*/
	

	AddGameSceneObject(new CGameSceneUI());

	switch (m_now_scene) {
	case eStage1:
		CSound::GetInstance()->StopAll();
		CSound::GetInstance()->GetSound("BGM_Title")->Play(true);
		//CSound::GetInstance()->StopAll();
		//CSound::GetInstance()->GetSound("BGM_Stage")->Play(true);
		for (int i = 0; i < 6; i++) {
			//床張り(役割は単純なので処理の軽い汎用オブジェクトで代用)
			AddGameSceneObject(new CCommonObject(nullptr, CVector3D(1280.0f * i, 10000.0f, 0.0f), CVector2D(0, 0), CVector3D(1280.0f, 1.0f + 10000.0f, 720.0f)));
			AddGameSceneObject(new CObjectImage(GET_RESOURCE("Stage_Background_0_Bot", CImage*), CVector3D(1280 * i, 0, 0), CVector2D(1280, 720), -1));
			AddGameSceneObject(new CObjectImage(GET_RESOURCE("Stage_Background_0_Top", CImage*), CVector3D(1280 * i, -720, 0), CVector2D(1280, 720), -1));			
		}
		SetGameSceneLimitPosMin(CVector3D(100.0f, 0.0f, 340.0f));
		SetGameSceneLimitPosMax(CVector3D(1280.0f * 6, 720.0f, 720.0f));
		

		if(m_last_wave != -1) AddGameSceneObject(new CGameSceneWave(m_last_wave));
		else AddGameSceneObject(new CGameSceneWave(eWave1));

		/*
		AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(2000, -151, 450 + 100)));
		AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(1500, -151, 450 + 100)));
		AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(1000, -151, 450 + 100)));
		AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(2500, -151, 450 + 100)));
		AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(3000, -151, 450 + 100)));
		AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(3400, -151, 450 + 100)));
		AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(4200, -151, 450 + 100)));
		AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(4400, -151, 450 + 100)));
		AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(4600, -151, 450 + 100)));
		*/
		m_next_scene = eStage1Boss;
		m_next_scene_pos = 1280 * 6 - 100;

		//テスト用銃
		//AddGameSceneObject(new CSubWeaponItem(CVector3D(300,-100,500),eWeaponGun));
		break;
	case eStage1Boss:
		CSound::GetInstance()->StopAll();
		CSound::GetInstance()->GetSound("BGM_Boss")->Play(true);
		for (int i = 0; i < 2; i++) {
			//床張り(役割は単純なので処理の軽い汎用オブジェクトで代用)
			AddGameSceneObject(new CCommonObject(nullptr, CVector3D(1280.0f * i, 10000.0f, 0.0f), CVector2D(0, 0), CVector3D(1280.0f, 1.0f + 10000.0f, 720.0f)));

			if (i % 2 == 0) {
				AddGameSceneObject(new CObjectImage(GET_RESOURCE("Stage_Background_0_Boss_Bot", CImage*), CVector3D(1280 * i, 0, 0), CVector2D(1280, 720), -1));
				AddGameSceneObject(new CObjectImage(GET_RESOURCE("Stage_Background_0_Boss_Top", CImage*), CVector3D(1280 * i, -720, 0), CVector2D(1280, 720), -1));
			}

			else {
				AddGameSceneObject(new CObjectImage(GET_RESOURCE("Stage_Background_0_Boss_Bot", CImage*), CVector3D(1280 * i, 0, 0), CVector2D(1280, 720),false,-1));
				AddGameSceneObject(new CObjectImage(GET_RESOURCE("Stage_Background_0_Boss_Top", CImage*), CVector3D(1280 * i, -720, 0), CVector2D(1280, 720), false,-1));
			}

		}
		SetGameSceneLimitPosMin(CVector3D(100.0f, 0.0f, 340.0f));
		SetGameSceneLimitPosMax(CVector3D(1280.0f * 2, 720.0f, 720.0f));

		AddGameSceneObject(new CCharacterBoss());
		AddGameSceneObject(new CGameSceneBossUI());
		m_next_scene = -1;
		break;
	}
	CFPS::Wait();//deltatime安定化用
}

void CGameScene::ReturnTitle()
{
	ClearGameSceneObject();
	DeletePlayer();
	CFade::GetInstance()->SetFadeOut(0);
	CFade::GetInstance()->SetFadeIn(30);
	TaskManager::GetInstance()->AddTask(new CTitle());
}

void CGameScene::Continue()
{
	ClearGameSceneObject();
	DeletePlayer();
	Setup();
}

void CGameScene::ChangeScene(int _scene_id)
{
	m_now_scene = _scene_id;
	ClearGameSceneObject();
	SetCheckPoint(CVector3D(300, -220, 550));
	SetupScene();
}

CGameScene * CGameScene::GetInstance()
{
	if (s_instance_p == nullptr) {
		TaskManager::GetInstance()->AddTask(s_instance_p = new CGameScene());
	}
	return s_instance_p;
}
