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
	const float pop_pos_offset_x = +800;
	switch (_wave_id) {
	case eWave1:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(300, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(850+ pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(1050 + pop_pos_offset_x, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(1250 + pop_pos_offset_x, -151, 450 + 100), this));
		m_pop_enemy_num = 3;
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f * 1, 720.0f, 720.0f));
		m_next_wave_id = eWave2;
		break;
	case eWave2:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(1500, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(1500 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(1800 + pop_pos_offset_x, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(2000 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f * 2, 720.0f, 720.0f));
		m_pop_enemy_num = 3;
		m_next_wave_id = eWave3;
		break;
	case eWave3:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(1500, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(1500 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(1800 + pop_pos_offset_x, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(2000 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f * 2, 720.0f, 720.0f));
		m_pop_enemy_num = 3;
		m_next_wave_id = eWave4;
		break;
	case eWave4:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(1500, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(1500 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(1800 + pop_pos_offset_x, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(2000 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f * 2, 720.0f, 720.0f));
		m_pop_enemy_num = 3;
		m_next_wave_id = eWave5;
		break;
	case eWave5:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(1500, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(2700 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(3000 + pop_pos_offset_x, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(3200 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f * 3, 720.0f, 720.0f));
		m_pop_enemy_num = 3;
		m_next_wave_id = eWave6;
		break;
	case eWave6:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(2700, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(2700 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(3000 + pop_pos_offset_x, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(3200 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f * 3, 720.0f, 720.0f));
		m_pop_enemy_num = 3;
		m_next_wave_id = eWave7;
		break;
	case eWave7:
		CGameScene::GetInstance()->SetCheckPoint(CVector3D(2700, -220, 550));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(2700 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe, CVector3D(3000 + pop_pos_offset_x, -151, 450 + 200), this));
		CGameScene::GetInstance()->AddGameSceneObject(new CCharacterEnemy(eEnemyIdGun, CVector3D(3200 + pop_pos_offset_x, -151, 450 + 100), this));
		CGameScene::GetInstance()->SetGameSceneLimitPosMax(CVector3D(1280.0f * 3, 720.0f, 720.0f));
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