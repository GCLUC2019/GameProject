#include "CGameOver.h"
#include "CGameScene.h"
#include "CTitle.h"

//表示する位置とサイズ
#define GAMEOVER_SIZE CVector2D(500,300)
#define GAMEOVER_POS CVector2D(200, 50)
#define CONTINUE_SIZE CVector2D(100,300)
#define CONTINUE_POS CVector2D(300, 300)
#define RETURN_SIZE CVector2D(100,300)
#define RETURN_POS CVector2D(400, 300)

//画面遷移番号
#define CONTINUE 0
#define RETURN_TO_TITLE 1

//最大値と最小値
#define MAX 1
#define MIN 0

//明滅間隔
#define BLITE_INTEVAL 45
#define VANISH_INTERVAL BLITE_INTEVAL*2


CGameOver::CGameOver()
{
	m_game_over_p = GET_RESOURCE("GameOver", CImage*);
	m_continue_p = GET_RESOURCE("Continue", CImage*);
	m_return_p = GET_RESOURCE("Return", CImage*);
	m_game_over_p->SetSize(GAMEOVER_SIZE);
	m_game_over_p->SetPos(GAMEOVER_POS);
	m_continue_p->SetSize(CONTINUE_SIZE);
	m_continue_p->SetPos(CONTINUE_POS);
	m_return_p->SetSize(RETURN_SIZE);
	m_return_p->SetPos(RETURN_POS);
}

CGameOver::~CGameOver()
{
	CTitle * c_title_p = nullptr;
	switch (m_serect_num)
	{
	case CONTINUE:
		CGameScene::GetInstance()->SetupScene();
		break;
	case RETURN_TO_TITLE:
	    c_title_p = new CTitle();
		TaskManager::GetInstance()->AddTask(c_title_p);
		break;
	default:
		break;
	}
}

void CGameOver::Update()
{
	m_draw_cnt++;
	if (CInput::GetState(0, CInput::ePush, CInput::eUp)) {
		m_serect_num--;
		if (m_serect_num < MIN)m_serect_num = MAX;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eDown)) {
		m_serect_num++;
		if (m_serect_num > MAX)m_serect_num = MIN;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eButton1)) {
		SetIsDelete();
	}
}

void CGameOver::Draw()
{
	m_game_over_p->Draw();

	if (m_serect_num == CONTINUE) {
		m_return_p->Draw();
		if (m_draw_cnt < BLITE_INTEVAL)m_continue_p->Draw();
	}
	else if (m_serect_num == RETURN_TO_TITLE) {
		m_continue_p->Draw();
		if (m_draw_cnt < BLITE_INTEVAL)m_return_p->Draw();
	}

    if (m_draw_cnt > VANISH_INTERVAL)m_draw_cnt = 0;
	
}
