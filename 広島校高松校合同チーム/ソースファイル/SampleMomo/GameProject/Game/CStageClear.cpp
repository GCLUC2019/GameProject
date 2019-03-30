#include "CStageClear.h"
#include "CStorySceneClear.h"
#include "CGameScene.h"
#include "CTitle.h"
#include "CFade.h"
#include "CAnimation.h"


/*
//表示位置と表示サイズ
#define DRAW_SIZE CVector2D(600,350)
#define DRAW_POS CVector2D(350,100)

//明滅間隔
#define BLITE_INTEVAL (45)
#define VANISH_INTERVAL (BLITE_INTEVAL*2)
*/

//シーンチェンジ間隔
//#define CHANGE_INTERVAL (3)


#define FADE_OUT_COUNT (60)
#define NEXT_SCENE_COUNT (800)

CStageClear::CStageClear(int _clear_stage_id):CObject(0, 5)
{
	CFade::GetInstance()->SetFadeOut(0);
	CFade::GetInstance()->SetFadeIn(25);

	m_clear_stage_id = _clear_stage_id;
	
	//m_stage_clear_logo_p = GET_RESOURCE("StageClearLogo", CImage*);

	m_stage_clear_back_ground_p = GET_RESOURCE("StageClearBackGround", CImage*);

	/*
	m_stage_clear_logo_p->SetSize(DRAW_SIZE);
	m_stage_clear_logo_p->SetPos(DRAW_POS);
	*/

	CSound::GetInstance()->StopAll();
	CSound::GetInstance()->GetSound("BGM_Stage_Clear_Screen")->Play();

	m_stage_logo_p = new CAnimation();
	m_stage_logo_p->ReadAnimDataFile("StageClear/STAGE_CLEAR_LOGO.anim");

	m_island_bright_effect_p = new CAnimation();
	m_island_bright_effect_p->ReadAnimDataFile("StageClear/ISLAND_BRIGHT_EFFECT.anim");

	m_bright_effect_p = new CAnimation();
	m_bright_effect_p->ReadAnimDataFile("StageClear/BRIGHT_EFFECT.anim");
}

CStageClear::~CStageClear()
{
	
}

void CStageClear::Update()
{
	/*
	if ((CInput::GetState(0, CInput::ePush, CInput::eButton2) || CInput::GetState(0, CInput::ePush, CInput::eButton10)) && m_is_fade_out == false) {
		m_change_cnt = NEXT_SCENE_COUNT - FADE_OUT_COUNT;
	}
	*/

	m_change_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;

	if (m_change_cnt >= NEXT_SCENE_COUNT - FADE_OUT_COUNT && m_is_fade_out == false) {
		m_is_fade_out = true;
		CFade::GetInstance()->SetFadeOut(FADE_OUT_COUNT);
		CFade::GetInstance()->SetFadeIn(30);
	}
	if(m_change_cnt >= NEXT_SCENE_COUNT) NextScene();
	//if (m_change_cnt == CHANGE_INTERVAL) NextScene();
}

void CStageClear::Draw()
{
	m_stage_clear_back_ground_p->SetSize(1280,720);
	m_stage_clear_back_ground_p->SetPos(0,0);
	m_stage_clear_back_ground_p->Draw();


	m_stage_logo_p->SetWillPlayAnim(0);
	m_stage_logo_p->CheckWillPlayAnim();
	m_stage_logo_p->PlayAnim();


	CImage* draw_image = m_stage_logo_p->GetPlayAnimImage();
	draw_image->SetAng(0);
	draw_image->SetFilter(GL_NEAREST);
	draw_image->SetPos(265,30);
	draw_image->SetSize(750, 160);
	draw_image->Draw();


	m_island_bright_effect_p->SetWillPlayAnim(0);
	m_island_bright_effect_p->CheckWillPlayAnim();
	m_island_bright_effect_p->PlayAnim();
	draw_image = m_island_bright_effect_p->GetPlayAnimImage();
	draw_image->SetAng(0);
	draw_image->SetFilter(GL_NEAREST);
	draw_image->SetPos(815, 350);
	draw_image->SetSize(300, 300);
	draw_image->Draw();

	m_bright_effect_p->SetWillPlayAnim(0);
	m_bright_effect_p->CheckWillPlayAnim();
	m_bright_effect_p->PlayAnim();
	draw_image = m_bright_effect_p->GetPlayAnimImage();
	draw_image->SetFilter(GL_NEAREST);

	//エフェクト配置
	draw_image->SetAng(3.14);
	draw_image->SetPos(510, 320);
	draw_image->SetSize(400, 400);
	draw_image->Draw();


	draw_image->SetAng(3.14);
	draw_image->SetPos(1210, 320);
	draw_image->SetSize(400, 400);
	draw_image->Draw();

	draw_image->SetAng(3.14);
	draw_image->SetPos(1010, 370);
	draw_image->SetSize(400,400);
	draw_image->Draw();



	draw_image->SetAng(3.14);
	draw_image->SetPos(1010, 550);
	draw_image->SetSize(200, 200);
	draw_image->Draw();

	draw_image->SetAng(3.14);
	draw_image->SetPos(1110, 550);
	draw_image->SetSize(100, 100);
	draw_image->Draw();

	draw_image->SetAng(3.14);
	draw_image->SetPos(1010, 450);
	draw_image->SetSize(100, 100);
	draw_image->Draw();

	draw_image->SetAng(3.14);
	draw_image->SetPos(1010, 600);
	draw_image->SetSize(100, 100);
	draw_image->Draw();

	draw_image->SetAng(-1.5);
	draw_image->SetPos(225, 310);
	draw_image->SetSize(100, 100);
	draw_image->Draw();

	draw_image->SetAng(-1.5);
	draw_image->SetPos(235, 290);
	draw_image->SetSize(120, 120);
	draw_image->Draw();


	draw_image->SetAng(-0.5);
	draw_image->SetPos(485, 235);
	draw_image->SetSize(150, 150);
	draw_image->Draw();

	draw_image->SetAng(0);
	draw_image->SetPos(400, 350);
	draw_image->SetSize(200, 200);
	draw_image->Draw();

	/*
	m_draw_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if(m_draw_cnt<BLITE_INTEVAL) m_stage_clear_logo_p->Draw();
	if (m_draw_cnt > VANISH_INTERVAL) {
		m_draw_cnt = 0;
		m_change_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}
	*/
}

void CStageClear::NextScene()
{

	//TaskManager::GetInstance()->AddTask(new CStorySceneClear(m_clear_stage_id));
	CGameScene::GetInstance()->ClearGameSceneObject();
	SetIsDelete();
	TaskManager::GetInstance()->AddTask(new CTitle());
}
