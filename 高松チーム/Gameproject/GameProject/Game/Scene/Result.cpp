#include "Result.h"
#include "../GameProject/Game/Scene/Title.h"

GameClear::GameClear() : Task(eGameClear)
{
	m_gameclear_pos = CVector2D(1280 / 2, 720 / 2);
	m_gameclear_img = COPY_RESOURCE("GameClear", CImage*);
	
}

GameClear::~GameClear()
{
	TaskManager::KillAll();
	TaskManager::GetInstance()->AddTask(new Title());
}

void GameClear::Update()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton2)) {
		SetKill();
	}
}

void GameClear::Draw()
{
	m_gameclear_img.SetSize(300, 100);
	m_gameclear_img.SetPos(m_gameclear_pos);
	m_gameclear_img.Draw();
}


