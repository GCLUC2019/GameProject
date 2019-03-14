#include "CTitle.h"
#include "CObjectImage.h"
#include "CStorySceneOpening.h"
#include "CBar.h"
CTitle::CTitle() : CObject(0, 0)
{
	ADD_RESOURCE("Back", CImage::LoadImage("Back.png"));
	m_background_image_p= GET_RESOURCE("Back", CImage*);
	ADD_RESOURCE("Back_txt", CImage::LoadImage("Back_txt.png"));
	m_backtxt_p = GET_RESOURCE("Back_txt", CImage*);
	m_backtxt_p->SetPos(1050, -50);
}

CTitle::~CTitle()
{
	
}

void CTitle::Update()
{
	//スペースキーでタイトル画面を破棄
	if (CInput::GetState(0,CInput::ePush, CInput::eButton1)) {
		SetIsDelete();
		//Delete();
		NextScene();
	}
	//2秒間タイトルの文字を表示させる
	if (m_flash_txt == true) {
		if (m_count_txt % 120 == 0) {
			m_draw_txt = false;
			m_count_txt = 0;
			m_flash_txt = false;
		}
		++m_count_txt;
	}
	//1秒間タイトルの文字を消す
	if (m_flash_txt == false) {
		if (m_count_txt2 % 60 == 0) {
			m_draw_txt = true;
			m_count_txt2 = 0;
			m_flash_txt = true;
		}
		++m_count_txt2;
	}
	
}

void CTitle::Draw()
{
	m_background_image_p->Draw();
	if (m_draw_txt == true) {
		m_backtxt_p->Draw();
	}
	
	//m_backtxt_p->Draw();
	//printf("Drawしました");
}

void CTitle::NextScene()
{
	TaskManager::GetInstance()->AddTask(new CStorySceneOpening());
}



//更新履歴2019/03/11 タイトルを追加
//ストーリーシーンのへ移行を追加
//2019/03/12　タイトルの点滅表示を追加