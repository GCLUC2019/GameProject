#include "CTitle.h"
#include "CObjectImage.h"
#include "CStorySceneOpening.h"
#include "CStorySceneClear.h"
#include "CBar.h"
#include "CGameScene.h"
#include "CFade.h"
#include "CStageClear.h"

CTitle::CTitle() : CObject(0, 0)
{

	m_background_image_p= GET_RESOURCE("Back", CImage*);

	m_blind_text_p = GET_RESOURCE("Guide_How_To_Start_Game", CImage*);
	
	m_blind_text_p->SetPos(140, 650);
	m_background_image_p->SetSize(1280, 720);

	CSound::GetInstance()->StopAll();
	CSound::GetInstance()->GetSound("BGM_Title")->Play(true);
}

CTitle::~CTitle()
{
	
}

void CTitle::Update()
{
	//シフト&スペースでタイトルスキップ
	if ((CInput::GetState(0, CInput::ePush, CInput::eButton2) || CInput::GetState(0, CInput::ePush, CInput::eButton10)) && CInput::GetState(0, CInput::eHold, CInput::eButton3)){
		SetIsDelete();
		CGameScene::GetInstance()->Init();
		CGameScene::GetInstance()->Setup();
	}
	//スペースキーでタイトル画面を破棄
	else if ((CInput::GetState(0, CInput::ePush, CInput::eButton2) || CInput::GetState(0, CInput::ePush, CInput::eButton10))) {
		SetIsDelete();
		//Delete();
		NextScene();
	}
	
	//2秒間タイトルの文字を表示させる
	if (m_flash_txt == true) {
		if (m_count_txt >= 120) {
			m_count_txt -= 120;
			m_draw_txt = false;
			m_count_txt = 0;
			m_flash_txt = false;
		}
		m_count_txt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}
	//1秒間タイトルの文字を消す
	if (m_flash_txt == false) {
		if (m_count_txt2 >= 60) {
			m_count_txt2 -= 60;
			m_draw_txt = true;
			m_count_txt2 = 0;
			m_flash_txt = true;
		}
		m_count_txt2 += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}
	
}

void CTitle::Draw()
{
	m_background_image_p->Draw();
	if (m_draw_txt == true) {
		m_blind_text_p->Draw();
	}
}

void CTitle::NextScene()
{
	CFade::GetInstance()->SetFadeOut(0);
	CFade::GetInstance()->SetFadeIn(25);
	TaskManager::GetInstance()->AddTask(new CStorySceneOpening());
	//TaskManager::GetInstance()->AddTask(new CStageClear(eStage1Boss));

	//TaskManager::GetInstance()->AddTask(new CStorySceneClear(1));
}



//更新履歴2019/03/11 タイトルを追加
//ストーリーシーンのへ移行を追加
//2019/03/12　タイトルの点滅表示を追加