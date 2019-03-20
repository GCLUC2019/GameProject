#include "CStageClear.h"
#include "CStorySceneClear.h"
#include "CGameScene.h"

//表示位置と表示サイズ
#define DRAW_SIZE CVector2D(600,350)
#define DRAW_POS CVector2D(350,100)

//明滅間隔
#define BLITE_INTEVAL (45)
#define VANISH_INTERVAL (BLITE_INTEVAL*2)

//シーンチェンジ間隔
#define CHANGE_INTERVAL (3)


CStageClear::CStageClear(int _clear_stage_id):CObject(0, 5)
{
	m_clear_stage_id = _clear_stage_id;
	m_stage_clear_logo_p = GET_RESOURCE("StageClearLogo", CImage*);
	m_stage_clear_logo_p->SetSize(DRAW_SIZE);
	m_stage_clear_logo_p->SetPos(DRAW_POS);
}

CStageClear::~CStageClear()
{
	
}

void CStageClear::Update()
{
	if (m_change_cnt == CHANGE_INTERVAL) NextScene();
}

void CStageClear::Draw()
{
	m_draw_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if(m_draw_cnt<BLITE_INTEVAL) m_stage_clear_logo_p->Draw();
	if (m_draw_cnt > VANISH_INTERVAL) {
		m_draw_cnt = 0;
		m_change_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}
}

void CStageClear::NextScene()
{
	TaskManager::GetInstance()->AddTask(new CStorySceneClear(m_clear_stage_id));
	CGameScene::GetInstance()->ClearGameSceneObject();
	SetIsDelete();
}
