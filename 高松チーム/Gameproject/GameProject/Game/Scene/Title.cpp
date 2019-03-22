#include "Title.h"
#include"../GameData/GameData.h"
#include "../Tutorial/Tutorial.h"
#include "../GameProject/Game/UI/UI.h"

#define BACKXSIZE 1280
#define BACKYSIZE 720
#define ROGOXSIZE 520
#define ROGOYSIZE 700
#define OHUDASIZE 580

Title::Title() :Task(eGameTitle),
m_title_pos(CVector2D(BACKXSIZE / 2, BACKYSIZE / 2)),
m_rogo_pos(CVector2D(BACKXSIZE * 3 / 4, BACKYSIZE * 1 / 2 + 37)),
m_start_pos(CVector2D(BACKXSIZE * 3 / 4, BACKYSIZE * 5 / 6)),
m_ohuda_pos(CVector2D(BACKXSIZE * 3 / 4, BACKYSIZE * 1 / 2)),
m_cnt(0),
m_size(0.0f),
m_time(0.0f),
m_choice(0)
{
	g_game_data.m_score = 0;
	g_game_data.m_dead_cnt = 0;
	g_game_data.m_player_switch_flg == false;
    ADD_RESOURCE("Title", CImage::LoadImage("../data/Image/title.png"));
    ADD_RESOURCE("Choice", CImage::LoadImage("../data/Image/choice.png"));
    ADD_RESOURCE("RogoBase", CImage::LoadImage("../data/Image/rogo_base.png"));
    ADD_RESOURCE("RogoClear", CImage::LoadImage("../data/Image/rogo_cl.png"));
    ADD_RESOURCE("RogoHuda", CImage::LoadImage("../data/Image/rogo_huda.png"));
    ADD_RESOURCE("RogoUI", CImage::LoadImage("../data/Image/chara_gauge_face.png"));
    ADD_RESOURCE("Window", CImage::LoadImage("../data/Image/balloon.png"));
    m_img_back = COPY_RESOURCE("Title", CImage*);
    m_img_rogobase = COPY_RESOURCE("RogoBase", CImage*);
    m_img_rogoclear = COPY_RESOURCE("RogoClear", CImage*);
    m_img_ohuda = COPY_RESOURCE("RogoHuda", CImage*);
    m_img_choice = COPY_RESOURCE("Choice", CImage*);
    m_img_icon = COPY_RESOURCE("RogoUI", CImage*);
    m_img_window = COPY_RESOURCE("Window", CImage*);
	SOUND("Enishi")->Play(true);
}

Title::~Title()
{
	SOUND("Enishi")->Stop();
}

void Title::Update()
{
	Task* p = TaskManager::FindObject(CharacterData::eFadeOut);
	FadeOut* n = dynamic_cast<FadeOut*>(p);
	if (n != nullptr)
		mp_fadeout= n->GetFadeOut();

    m_cnt += 1;
    if (m_cnt >= 540) {
        m_cnt = 0;
        m_size = 0;
    }
    if (CInput::GetState(0, CInput::ePush, CInput::eUp)) {
		SOUND("highspeed-movement1")->Play();
        m_choice++;
    }
    if (CInput::GetState(0, CInput::ePush, CInput::eDown)) {
		SOUND("highspeed-movement1")->Play();
        m_choice--;
    }
    if (m_choice < 0)m_choice = 1;
    if (m_choice > 1)m_choice = 0;
    //printf("%d", m_choice);
    if (CInput::GetState(0, CInput::ePush, CInput::eButton2)) {
		SOUND("se_027")->Play();
		TaskManager::GetInstance()->AddTask(new FadeOut());
		if (mp_fadeout >= 1.0f)
		{
			switch (m_choice) {
			case 0:
				TaskManager::AddTask(new Tutorial());
				break;
			case 1:
				TaskManager::AddTask(new GameScene());
				break;
			}

			n->SetKill();
			SetKill();
		}
    }


}

void Title::Draw()
{
    //îwåi
    m_img_back.SetPos(m_title_pos);
    m_img_back.SetCenter(BACKXSIZE / 2, BACKYSIZE / 2);
    m_img_back.Draw();
    //ÉçÉSÇÃâe
    m_img_rogoclear.SetCenter(ROGOXSIZE / 2, ROGOYSIZE / 2);   
    m_img_rogoclear.SetSize(ROGOXSIZE + m_size* ROGOXSIZE/(ROGOXSIZE+ ROGOYSIZE),
        ROGOYSIZE + m_size * ROGOYSIZE / (ROGOXSIZE + ROGOYSIZE));
    m_img_rogoclear.SetPos(CVector2D(m_rogo_pos.x - m_size * ROGOXSIZE / (ROGOXSIZE + ROGOYSIZE) / 2,
        m_rogo_pos.y - m_size * ROGOYSIZE / (ROGOXSIZE + ROGOYSIZE) / 2));
    //âeÇÃëÂÇ´Ç≥ÇïœÇ¶ÇÈ
    if (m_cnt >= 120) {
        if (m_cnt >= 240) {
            m_size -= 2.0f;
        }
        else
        m_size += 4.0f;
        m_img_rogoclear.Draw();
    }
    
    //Ç®éD
    m_img_ohuda.SetSize(OHUDASIZE, OHUDASIZE);
    m_img_ohuda.SetCenter((OHUDASIZE) / 2, OHUDASIZE / 2);
    m_img_ohuda.SetPos(m_ohuda_pos);
    m_time -= 0.01f;
    m_img_ohuda.SetAng(m_time); 
    m_img_ohuda.Draw();
	//ÉçÉS
	m_img_rogobase.SetSize(ROGOXSIZE, ROGOYSIZE);
	m_img_rogobase.SetCenter(ROGOXSIZE / 2, ROGOYSIZE / 2);
	m_img_rogobase.SetPos(m_rogo_pos);
	m_img_rogobase.Draw();
    //Window
    m_img_window.SetCenter((1280 / 3+150) / 2, 200 / 2);
    m_img_window.SetPos(m_start_pos);
    m_img_window.SetSize(1280 / 3+150, 200);
    m_img_window.Draw();
    //choice
    m_img_choice.SetCenter(1280/3/2, 150/2);
    m_img_choice.SetPos(m_start_pos);
    m_img_choice.SetSize(1280 / 3+50, 150);
    m_img_choice.Draw();
    //iocn
    m_img_icon.SetCenter(38, 38);
    m_img_icon.SetSize(75, 75);
    m_img_icon.SetPos(CVector2D(m_start_pos.x-250, m_start_pos.y -38+75* m_choice));
    m_img_icon.Draw();
}
