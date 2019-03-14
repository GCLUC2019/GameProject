#include "CStageCrear.h"
#include "CStorySceneCrear1.h"

//表示位置と表示サイズ
#define DRAW_SIZE CVector2D(600,350)
#define DRAW_POS CVector2D(350,100)

//明滅間隔
#define BLITE_INTEVAL 45
#define VANISH_INTERVAL BLITE_INTEVAL*2

//シーンチェンジ間隔
#define CHANGE_INTERVAL 3


CStageCrear::CStageCrear():CObject(0, 0)
{
	ADD_RESOURCE("Crear", CImage::LoadImage("StageCrear.png"));
	m_crear = COPY_RESOURCE("Crear", CImage*);
	m_crear.SetSize(DRAW_SIZE);
	m_crear.SetPos(DRAW_POS);
}

CStageCrear::~CStageCrear()
{
	CStoryScene* s_scene_p = new CStorySceneCrear1();
	TaskManager::GetInstance()->AddTask(s_scene_p);
}

void CStageCrear::Update()
{
	if (m_change_cnt == CHANGE_INTERVAL)SetIsDelete();
}

void CStageCrear::Draw()
{
	m_draw_cnt++;
	if(m_draw_cnt<BLITE_INTEVAL) m_crear.Draw();
	if (m_draw_cnt > VANISH_INTERVAL) {
		m_draw_cnt = 0;
		m_change_cnt++;
	}
}
