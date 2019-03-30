﻿#include "CStorySceneClear.h"
#include "CTitle.h"
#include "CGameScene.h"
#include "CStageClear.h"

//ステージクリア１のテキスト数
#define CREAR_SENTENSE_NUM 11
//ステージクリア１の紙芝居数
#define CREAR_STORY_NUM 2
//表示する絵を変えるための文章数
#define CHANGE_NUM 8
//次の紙芝居の配列ナンバー
#define NEXT_ARRAY_NUM 12

//画像切り取りサイズの初期値と変動値
#define DEF_RECT_TOP_X 714
#define DEF_RECT_TOP_Y 355
#define DEF_RECT_BOT_X 1660
#define DEF_RECT_BOT_Y 1308

#define RECT_TOP_X 0
#define RECT_TOP_Y 345
#define RECT_BOT_X 1609
#define RECT_BOT_Y 2000

//#define RECT_BOT_X 1659
//#define RECT_BOT_Y 2894

#define RECT_TOP_X2 2015
#define RECT_TOP_Y2 0
#define RECT_BOT_X2 3207
#define RECT_BOT_Y2 1500


#define RECT_TOP_X3 2530
#define RECT_TOP_Y3 2228
#define RECT_BOT_X3 2856
#define RECT_BOT_Y3 2846


#define RECT_TOP_X4 1471
#define RECT_TOP_Y4 1271
#define RECT_BOT_X4 2025
#define RECT_BOT_Y4 1788

#define RECT_TOP_X5 0
#define RECT_TOP_Y5 0
#define RECT_BOT_X5 3564
#define RECT_BOT_Y5 1808

#define RECT_TOP_X6 381
#define RECT_TOP_Y6 98
#define RECT_BOT_X6 1817
#define RECT_BOT_Y6 1284

#define RECT_TOP_X7 381
#define RECT_TOP_Y7 98
#define RECT_BOT_X7 1817
#define RECT_BOT_Y7 1284

/*
#define RECT_TOP_X6 550
#define RECT_TOP_Y6 250
#define RECT_BOT_X6 1200
#define RECT_BOT_Y6 1700
*/

//#define RECT_TOP_X7 2800
//#define RECT_TOP_X8 1200

#define RECT_TOP_X8 381
#define RECT_TOP_Y8 0
#define RECT_BOT_X8 1904
#define RECT_BOT_Y8 1684

#define RECT_TOP_X9 0
#define RECT_TOP_Y9 0
#define RECT_BOT_X9 3312
#define RECT_BOT_Y9 2594
//#define RECT_BOT_Y9 2894

//画像サイズの初期値と変動値
#define DEF_SIZE_X 300
#define DEF_SIZE_Y 300
#define SIZE_X 400
#define SIZE_Y 600
#define SIZE_X2 500
#define SIZE_Y2 300
#define SIZE_X3 450
#define SIZE_Y3 300
#define SIZE_X4 300
#define SIZE_Y4 300
#define SIZE_X8 600
#define SIZE_Y8 600
//表示位置の変動値
#define DEF_POS_X 200
#define DEF_POS_Y 100
#define POS_X  450
#define POS_X2 450
#define POS_X3 450
#define POS_X4 350
#define POS_Y4 150
#define POS_X6 300
#define POS_Y6 50
#define POS_X8 200

CStorySceneClear::CStorySceneClear(int _clear_stage)
{
	CSound::GetInstance()->StopAll();
	CSound::GetInstance()->GetSound("BGM_Stage_Clear")->Play();

	Setchar(_clear_stage);
	SetValue(_clear_stage);
	SetAll(CREAR_SENTENSE_NUM);
	m_clear_stage = _clear_stage;
}

CStorySceneClear::~CStorySceneClear()
{
 // CTitle* c_title_p = new CTitle();
  //TaskManager::GetInstance()->AddTask(c_title_p);
	TaskManager::GetInstance()->AddTask(new CStageClear(m_clear_stage));
}

void CStorySceneClear::Update()
{
	UpdateText(CHAR_NUM, sentence_num);
	UpdateStory2(CHANGE_NUM, NEXT_ARRAY_NUM);
	ChangeScene(CREAR_SENTENSE_NUM);
}

void CStorySceneClear::Draw()
{
	AllDraw();
}

void CStorySceneClear::Setchar(int _clear_stage)
{
	switch (_clear_stage) {
	case eStage1Boss:{
			char name_array[][MAX_SENTENSE_SIZE] = { "CrearIvent"  ,"CrearIvent2" };
			char name_array2[][MAX_SENTENSE_SIZE] = { "Text2-1" ,"Text2-2" ,"Text2-3"
				,"Text2-4", "Text2-5" ,"Text2-6"
				,"Text2-7"  ,"Text2-8" ,"Text2-9"
				,"Text2-10", "Text2-11" };
			//SetSentense(CREAR_STORY_NUM, name, name_array);
			for (int i = 0; i < 2; i++) {
				strcpy_s(name[i], MAX_SENTENSE_SIZE, name_array[i]);
			}

			SetSentense(CREAR_SENTENSE_NUM, t_name, name_array2);
			break;
		}
	}
}

void CStorySceneClear::SetValue(int _clear_stage)
{
	switch (_clear_stage) {
	case eStage1Boss: {
		CVector4D rects = CVector4D(DEF_RECT_TOP_X, DEF_RECT_TOP_Y, DEF_RECT_BOT_X, DEF_RECT_BOT_Y);
		CVector4D size_poses = CVector4D(DEF_SIZE_X, DEF_SIZE_Y, DEF_POS_X, DEF_POS_Y);
		DelValue(SUB0, rects, size_poses);

		rects = CVector4D(RECT_TOP_X, RECT_TOP_Y, RECT_BOT_X, RECT_BOT_Y);
		size_poses = CVector4D(SIZE_X, SIZE_Y, POS_MIN_X, POS_MIN_Y);
		DelValue(SUB1, rects, size_poses);

		rects = CVector4D(RECT_TOP_X2, RECT_TOP_Y2, RECT_BOT_X2, RECT_BOT_Y2);
		size_poses = CVector4D(SIZE_X2, SIZE_Y2, POS_X2, POS_MIN_Y);
		DelValue(SUB2, rects, size_poses);

		rects = CVector4D(RECT_TOP_X3, RECT_TOP_Y3, RECT_BOT_X3, RECT_BOT_Y3);
		size_poses = CVector4D(SIZE_X3, SIZE_Y3, POS_X3, POS_MAX_Y);
		DelValue(SUB3, rects, size_poses);

		rects = CVector4D(RECT_TOP_X4, RECT_TOP_Y4, RECT_BOT_X4, RECT_BOT_Y4);
		size_poses = CVector4D(SIZE_X4, SIZE_Y4, POS_X4, POS_Y4);
		DelValue(SUB4, rects, size_poses);

		rects = CVector4D(RECT_TOP_X5, RECT_TOP_Y5, RECT_BOT_X5, RECT_BOT_Y5);
		size_poses = CVector4D(DEF_SIZE_X, DEF_SIZE_Y, DEF_POS_X, DEF_POS_Y);
		DelValue(SUB5, rects, size_poses);

		rects = CVector4D(RECT_TOP_X6, RECT_TOP_Y6, RECT_BOT_X6, RECT_BOT_Y6);
		size_poses = CVector4D(DEF_SIZE_X, DEF_SIZE_Y, DEF_POS_X, DEF_POS_Y);
		DelValue(SUB6, rects, size_poses);

		rects = CVector4D(RECT_TOP_X7, RECT_TOP_Y7, RECT_BOT_X7, RECT_BOT_Y7);
		size_poses = CVector4D(DEF_SIZE_X, DEF_SIZE_Y, POS_MAX_X, POS_MIN_Y);
		DelValue(SUB7, rects, size_poses);

		rects = CVector4D(RECT_TOP_X8, RECT_TOP_Y8, RECT_BOT_X8, RECT_BOT_Y8);
		size_poses = CVector4D(SIZE_X8, SIZE_Y8, POS_X8, POS_MIN_Y);
		DelValue(SUB8, rects, size_poses);

		rects = CVector4D(RECT_TOP_X9, RECT_TOP_Y9, RECT_BOT_X9, RECT_BOT_Y9);
		size_poses = CVector4D(DRAW_MAX_X, DRAW_MAX_Y, POS_MIN_X, POS_MIN_Y);
		DelValue(SUB9, rects, size_poses);

		rects = CVector4D(MIN, MIN, MAX_X, MAX_Y);
		size_poses = CVector4D(DRAW_MAX_X, DRAW_MAX_Y, POS_MIN_X, POS_MIN_Y);
		DelValue(SUB10, rects, size_poses);

		rects = CVector4D(MIN, MIN, MAX_X, MAX_Y);
		size_poses = CVector4D(DRAW_MAX_X, DRAW_MAX_Y, POS_MIN_X, POS_MIN_Y);
		DelValue(SUB11, rects, size_poses);
	}
	}
}
