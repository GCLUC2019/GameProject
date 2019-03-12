#include "EnemyManager.h"
#include "../EnemyBase/Enemy/Enemy01.h"
#include "../EnemyBase/Enemy/Enemy02.h"
#include "../EnemyBase/Enemy/Enemy05.h"

EnemyManager::EnemyManager()
{
	TaskManager::GetInstance()->AddTask(new Enemy01());
	TaskManager::GetInstance()->AddTask(new Enemy02());
	TaskManager::GetInstance()->AddTask(new Enemy05());

}

void EnemyManager::Update()
{

}

void EnemyManager::Draw()
{
}


