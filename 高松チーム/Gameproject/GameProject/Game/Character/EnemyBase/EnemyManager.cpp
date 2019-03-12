#include "EnemyManager.h"
#include "../EnemyBase/Enemy/Enemy01.h"
#include "../EnemyBase/Enemy/Enemy02.h"
#include "../EnemyBase/Enemy/Enemy05.h"

EnemyManager::EnemyManager(): Task(eEnemyBaseManager),
	m_wave_flg(false),
	m_appear_type(eWave1_1),
	m_wave1_1_flg(false),
	m_wave1_2_flg(false),
	m_wave2_1_flg(false),
	m_wave2_2_flg(false)
{
	

}

void EnemyManager::Update()
{
	++m_cnt;
	if (m_cnt >= 300)	m_appear_type = eWave1_2;
	if (m_cnt >= 1000)	m_appear_type = eWave2_1;
	if (m_cnt >= 1600)	m_appear_type = eWave2_2;

}

void EnemyManager::Draw()
{
	switch (m_appear_type) {
	case eWave1_1:
		if (m_wave1_1_flg == false) {
			m_wave1_1_flg = true;
			TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
			TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
		}
		break;

	case eWave1_2:
		if (m_wave1_2_flg == false && m_wave1_1_flg == true) {
			m_wave1_2_flg = true;
			TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
			TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
			TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
			TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
		}
		break;



	case eWave2_1:
		if (m_wave2_1_flg == false && m_wave1_2_flg == true) {
			m_wave2_1_flg = true;
			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
		}
		break;

	case eWave2_2:
		if (m_wave2_2_flg == false && m_wave2_1_flg == true) {
			m_wave2_2_flg = true;
			TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
			TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
			TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
			TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(0, 1280), Utility::Rand(360, 720))));
		}
		break;

	default:
		break;
	}
}


