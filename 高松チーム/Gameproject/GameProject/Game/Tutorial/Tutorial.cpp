#include "Tutorial.h"
#include "../Character/Player.h"
#include "../Character/EnemyBase/Enemy/TutorialEnemy.h"
#include "../Stage/ground.h"
#include "../Resource/Resource.h"
#include "../GameProject/Game/Scene/Title.h"

Tutorial::Tutorial() : Task(eGameTutorial)
{
	new Resource();
	TaskManager::GetInstance()->AddTask(new Stage01());
	TaskManager::GetInstance()->AddTask(new Player());
	TaskManager::GetInstance()->AddTask(new TutorialEnemy(CVector2D(800, 450)));
}

Tutorial::~Tutorial()
{
	TaskManager::KillAll();
	TaskManager::GetInstance()->AddTask(new Title());
}

void Tutorial::Update()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton6))
		SetKill();
}

void Tutorial::DescriptionUI()
{

}

void Tutorial::Draw()
{

}
