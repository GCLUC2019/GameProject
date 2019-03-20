#include "CGameOver.h"
#include "CGameScene.h"
#include "CTitle.h"

//表示する位置とサイズ
#define GAMEOVER_SIZE CVector2D(1000,200)
#define GAMEOVER_POS CVector2D(140, 50)
#define CONTINUE_SIZE CVector2D(600,100)
#define CONTINUE_POS CVector2D(340, 350)
#define RETURN_SIZE CVector2D(600,100)
#define RETURN_POS CVector2D(340, 550)

//画面遷移番号
#define CONTINUE 0
#define RETURN_TO_TITLE 1

//最大値と最小値
#define MAX 1
#define MIN 0

//明滅間隔
#define BLITE_INTEVAL 45
#define VANISH_INTERVAL BLITE_INTEVAL*2


CGameOver::CGameOver() : CObject(0, DP_UI+10)
{
	m_game_over_p = GET_RESOURCE("GameOver", CImage*);
	m_continue_p = GET_RESOURCE("Continue", CImage*);
	m_return_p = GET_RESOURCE("Return", CImage*);
	m_grey_background_p = new CImage();
	


	m_game_over_p->SetSize(GAMEOVER_SIZE);
	m_game_over_p->SetPos(GAMEOVER_POS);
	m_continue_p->SetSize(CONTINUE_SIZE);
	m_continue_p->SetPos(CONTINUE_POS);
	m_return_p->SetSize(RETURN_SIZE);
	m_return_p->SetPos(RETURN_POS);
}

CGameOver::~CGameOver()
{
	delete m_grey_background_p;
	switch (m_serect_num)
	{
	case CONTINUE:
		CGameScene::GetInstance()->Continue();
		break;
	case RETURN_TO_TITLE:
		CGameScene::GetInstance()->ReturnTitle();
		break;
	default:
		break;
	}
}

void CGameOver::Update()
{
	//m_draw_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if (CInput::GetState(0, CInput::ePush, CInput::eUp)) {
		CSound::GetInstance()->GetSound("SE_Cursor")->Play();
		m_serect_num--;
		if (m_serect_num < MIN)m_serect_num = MAX;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eDown)) {
		CSound::GetInstance()->GetSound("SE_Cursor")->Play();
		m_serect_num++;
		if (m_serect_num > MAX)m_serect_num = MIN;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eButton1)) {
		CSound::GetInstance()->GetSound("SE_Decision")->Play();
		SetIsDelete();
	}
}

void CGameOver::Draw()
{
	
	m_grey_background_p->Draw();
	m_grey_background_p->SetSize(1280, 720);
	m_grey_background_p->SetPos(0, 0);
	m_grey_background_p->SetColor(0, 0, 0, 0.3f);

	m_game_over_p->Draw();

	

	if (m_serect_num == CONTINUE) {
		m_return_p->SetColor(0, 0, 0, 2.55f);
		m_return_p->Draw();
		m_continue_p->SetColor(2.55f, 2.55f, 2.55f, 2.55f);
		m_continue_p->Draw();
		//if (m_draw_cnt < BLITE_INTEVAL) m_continue_p->Draw();
	}
	else if (m_serect_num == RETURN_TO_TITLE) {
		m_return_p->SetColor(2.55f, 2.55f, 2.55f, 2.55f);
		m_return_p->Draw();
		m_continue_p->SetColor(0.0, 0, 0, 2.55f);
		m_continue_p->Draw();
		//if (m_draw_cnt < BLITE_INTEVAL) m_return_p->Draw();
	}

    if (m_draw_cnt > VANISH_INTERVAL) m_draw_cnt = 0;
	
}
