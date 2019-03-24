#include "CGameSceneWave.h"
#include "CGameScene.h"
#include "CCharacterEnemy.h"


CGameSceneWave::CGameSceneWave(int _wave_id) : CObject(0,0)
{
	m_wave_id = _wave_id;
	m_next_wave_id = -1;
	Init();
	LoadWave(_wave_id);
}

CGameSceneWave::~CGameSceneWave()
{
}

void CGameSceneWave::CheckDeadCount()
{
	if (m_count_dead >= m_pop_enemy_num) {		
		SetIsDelete();
		CGameScene::GetInstance()->WaveDone(m_next_wave_id);
	}
}

void CGameSceneWave::Init()
{
	for (int i = 0; i < GAME_WAVE_ENEMY_MAX; i++) {
		m_pop_enemy_p[i] = nullptr;
	}
	m_pop_enemy_num = 0;
}

void CGameSceneWave::LoadWave(int _wave_id)
{
	switch (_wave_id) {
	case eWave1:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(0, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(1280, -151, 450 + 100), this));
		m_pop_enemy_num = 1;
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f, 720.0f, 720.0f));
		m_next_wave_id = eWave2;
		break;
	case eWave2:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(600, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(1840, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f + 640.0f * 1, 720.0f, 720.0f));
		m_pop_enemy_num = 1;
		m_next_wave_id = eWave3;
		break;
	case eWave3:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(1200, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(2560, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(2560, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f + 640.0f * 2, 720.0f, 720.0f));
		m_pop_enemy_num = 2;
		m_next_wave_id = eWave4;
		break;
	case eWave4:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(1800, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(3200, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(3200, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f + 640.0f * 3, 720.0f, 720.0f));
		m_pop_enemy_num = 2;
		m_next_wave_id = eWave5;
		break;
	case eWave5:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(2400, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(3800, -151, 450 + 100), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(3800, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(3600, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f + 640.0f * 4, 720.0f, 720.0f));
		m_pop_enemy_num = 3;
		m_next_wave_id = eWave6;
		break;
	case eWave6:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(3000, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(4480, -151, 450 + 100), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(4480, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(4280, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f + 640.0f * 5, 720.0f, 720.0f));
		m_pop_enemy_num = 3;
		m_next_wave_id = eWave7;
		break;
	case eWave7:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(3600, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(5120, -151, 450 + 100), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(5120, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(4920, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f + 640.0f * 6, 720.0f, 720.0f));
		m_pop_enemy_num = 3;
		m_next_wave_id = -1;
		break;
	}
}

void CGameSceneWave::DeadEnemy(int _character_id)
{
	m_pop_enemy_p[_character_id] = nullptr;
	m_count_dead++;
	CheckDeadCount();
}