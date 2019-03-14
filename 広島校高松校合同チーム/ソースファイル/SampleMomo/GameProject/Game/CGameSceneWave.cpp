#include "CGameSceneWave.h"
#include "CGameScene.h"

CGameSceneWave::CGameSceneWave(int _wave_id) : CObject(0,0)
{
	Init();
}

CGameSceneWave::~CGameSceneWave()
{
}

void CGameSceneWave::CheckDeadCount()
{
	if (m_count_dead >= m_pop_enemy_num) {		
		SetIsDelete();
		CGameScene::GetInstance()->WaveDone();
	}
}

void CGameSceneWave::Init()
{
	for (int i = 0; i < GAME_WAVE_ENEMY_MAX; i++) {
		m_pop_enemy_p[i] = nullptr;
	}
}

void CGameSceneWave::DeadEnemy(int _character_id)
{
	m_pop_enemy_p[_character_id] = nullptr;
	m_count_dead++;
}