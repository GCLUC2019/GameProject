#include "Result.h"
#include "../GameProject/Game/Scene/Title.h"

GameClear::GameClear() : Task(eGameClear)
{
	m_gameclear_pos = CVector2D(0, 0);
	m_gameclear_img = COPY_RESOURCE("GameClear", CImage*);

}

GameClear::~GameClear()
{

}

void GameClear::Update()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton2)) {
		TaskManager::KillAll();
		TaskManager::GetInstance()->AddTask(new Title());

	}
}

void GameClear::Draw()
{
	m_gameclear_img.SetSize(1280, 720);
	m_gameclear_img.SetPos(m_gameclear_pos);
	m_gameclear_img.Draw();
}


