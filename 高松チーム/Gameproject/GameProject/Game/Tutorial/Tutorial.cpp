#include "Tutorial.h"
#include "../Character/Player.h"
#include "../Character/EnemyBase/Enemy/Enemy02.h"

Tutorial::Tutorial() : Task(eGameTutorial)
{
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new Enemy02(CVector2D(700,500)));
}

void Tutorial::Update()
{

}

void Tutorial::Draw()
{

}
