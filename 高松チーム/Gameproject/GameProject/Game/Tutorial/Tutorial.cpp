#include "Tutorial.h"
#include "../Character/Player.h"
#include "../Character/EnemyBase/Enemy/TutorialEnemy.h"
#include "../Stage/ground.h"
#include "../Resource/Resource.h"

Tutorial::Tutorial() : Task(eGameTutorial)
{
	new Resource();
	TaskManager::GetInstance()->AddTask(new Stage01());
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new TutorialEnemy(CVector2D(800,450)));
}

Tutorial::~Tutorial()
{

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
