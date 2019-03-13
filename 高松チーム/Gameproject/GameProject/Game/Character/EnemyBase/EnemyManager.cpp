#include "EnemyManager.h"
#include "../EnemyBase/Enemy/Enemy01.h"
#include "../EnemyBase/Enemy/Enemy02.h"
#include "../EnemyBase/Enemy/Enemy05.h"

EnemyManager::EnemyManager():
	m_wave_flg(false)
{
	TaskManager::GetInstance()->AddTask(new Enemy01(CVector2D(Utility::Rand(0, 1280), Utility::Rand(400, 720))));
	TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(Utility::Rand(0, 1280), Utility::Rand(400, 720))));
	TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(Utility::Rand(0,1280), Utility::Rand(400, 720))));

}

void EnemyManager::Update()
{
	
}

void EnemyManager::Draw()
{
}


