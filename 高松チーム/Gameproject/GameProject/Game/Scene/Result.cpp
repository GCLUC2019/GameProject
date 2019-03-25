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

GameOver::GameOver() :Task(eGameOver)
{
    ADD_RESOURCE("GameClear", CImage::LoadImage("Image/GameClearSmple.png"));
    ADD_RESOURCE("GameOver", CImage::LoadImage("Image/GameOverSmple.png"));
    ADD_RESOURCE("Restart", CImage::LoadImage("Image/GameOverText1.png"));
    ADD_RESOURCE("ToTitle", CImage::LoadImage("Image/GameOverText2.png"));
    ADD_RESOURCE("RogoUI", CImage::LoadImage("Image/chara_gauge_face.png"));
    m_main_img = COPY_RESOURCE("GameOver", CImage*);
    m_restart_img = COPY_RESOURCE("Restart", CImage*);
    m_totitle_img = COPY_RESOURCE("ToTitle", CImage*);
    m_img_icon = COPY_RESOURCE("RogoUI", CImage*);
    m_icon_pos = CVector2D(1280 / 2, 720 / 2);
    m_choice = 0;
}

GameOver::~GameOver()
{
}

void GameOver::Update()
{
    if (CInput::GetState(0, CInput::ePush, CInput::eDown)) {
        SOUND("highspeed-movement1")->Play();
        m_choice++;
    }
    if (CInput::GetState(0, CInput::ePush, CInput::eUp)) {
        SOUND("highspeed-movement1")->Play();
        m_choice--;
    }
    if (m_choice < 0)m_choice = 1;
    if (m_choice > 1)m_choice = 0;
    if (CInput::GetState(0, CInput::ePush, CInput::eButton2)) {
        SOUND("se_027")->Play();
        switch (m_choice) {
        case 0:
            TaskManager::GetInstance()->KillAll();
            TaskManager::AddTask(new Title());
            break;
        case 1:
            TaskManager::GetInstance()->KillAll();
            TaskManager::AddTask(new GameScene());
            break;
        default:
            break;
        }
        
    }


}

void GameOver::Draw()
{
    m_main_img.Draw();

    m_restart_img.SetSize(600, 140);
    m_restart_img.SetPos(CVector2D(1280 / 4, 350));
    m_restart_img.Draw();

    m_totitle_img.SetSize(600, 140);
    m_totitle_img.SetPos(CVector2D(1280 / 4, 500));
    m_totitle_img.Draw();

    m_img_icon.SetPos(CVector2D(1280 / 4 - 100, 380 + m_choice * 150));
    m_img_icon.Draw();
}