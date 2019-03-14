#include "Tutorial.h"
#include "../Character/Player.h"
#include "../Character/EnemyBase/Enemy/Enemy05.h"
#include "../Stage/ground.h"

Tutorial::Tutorial() : Task(eGameTutorial)
{
	TaskManager::GetInstance()->AddTask(new Stage01());
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new Enemy05(CVector2D(700,500)));
}

void Tutorial::Update()
{

}

void Tutorial::DescriptionUI()
{

}

void Tutorial::Draw()
{

}
