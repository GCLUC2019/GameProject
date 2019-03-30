#include "CStorySceneOpening.h"
#include "CGameScene.h"

//オープニングのテキスト数
#define OPENING_SENTENSE_NUM 10
//オープニングの紙芝居数
#define OPENING_STORY_NUM 3
//表示する絵を変えるための文章数
#define CHANGE_NUM 6

//次の紙芝居の配列ナンバー
#define NEXT_ARRAY_NUM 5

//画像切り取りサイズの初期値と変動値
#define DEF_RECT_TOP_X 1680

#define RECT_TOP_X 1765
#define RECT_TOP_Y 646
#define RECT_BOT_X 2570
#define RECT_BOT_Y 1400


#define RECT_TOP_X2 1470
#define RECT_TOP_Y2 1947
#define RECT_BOT_X2 2870
#define RECT_BOT_Y2 2894

#define RECT_BOT_X3 1650

#define RECT_TOP_X5 62
#define RECT_TOP_Y5 50
#define RECT_BOT_X5 493
#define RECT_BOT_Y5 1381

#define RECT_TOP_X6 607
#define RECT_TOP_Y6 334
#define RECT_BOT_X6 1133
#define RECT_BOT_Y6 1597

#define RECT_TOP_X7 1280
#define RECT_TOP_Y7 366
#define RECT_BOT_X7 3072
#define RECT_BOT_Y7 2894


#define RECT_TOP_X8 1280
#define RECT_TOP_Y8 366
#define RECT_BOT_X8 3072
#define RECT_BOT_Y8 2894

//#define RECT_TOP_X8 1200

//画像サイズの初期値と変動値
#define DEF_SIZE_X 400
#define DEF_SIZE_Y 600
#define SIZE_X 300
#define SIZE_Y 350
#define SIZE_X2 500
#define SIZE_Y2 300
#define SIZE_X3 400
#define SIZE_Y3 600
#define SIZE_X4 200
#define SIZE_Y4 400

#define SIZE_X8 600
#define SIZE_Y8 600
//表示位置の変動値
#define POS_X  450
#define POS_X2 250
#define POS_X6 300
#define POS_Y6 50
#define POS_X8 200


CStorySceneOpening::CStorySceneOpening()
{
	
	AddRAll();
	Setchar();
	SetValue();
	SetAll(OPENING_SENTENSE_NUM);
	CSound::GetInstance()->StopAll();
	CSound::GetInstance()->GetSound("SE_Decision")->Play();
	CSound::GetInstance()->GetSound("BGM_Intro_Story")->Play(true);


	//とりあえずここにガイド表示用の作業もいれとく
	m_guide_text_p = GET_RESOURCE("Guide_How_To_Forward", CImage*);
	m_guide_text_p->SetSize(500, 100);
	m_guide_text_p->SetPos(900, 500);
}

CStorySceneOpening::~CStorySceneOpening()
{
	CGameScene::GetInstance()->Init();
	CGameScene::GetInstance()->Setup();
}

void CStorySceneOpening::Update()
{
	UpdateText(CHAR_NUM, sentence_num);
	
	
	//printf("現在の絵 %d\n", num_decison);
	
	int change_num = CHANGE_NUM;
	if (num_decison == 8)change_num = 8 + 1;

	UpdateStory2(change_num, NEXT_ARRAY_NUM);
	

	ChangeScene(OPENING_SENTENSE_NUM);
}

void CStorySceneOpening::Draw()
{
	AllDraw();
}

void CStorySceneOpening::AddRAll()
{
	/*
	ADD_RESOURCE("Story", CImage::LoadImage("story1.png"));
	ADD_RESOURCE("Story2", CImage::LoadImage("story2.png"));
	ADD_RESOURCE("Textbox", CImage::LoadImage("TextBox.png"));

	ADD_RESOURCE("Text1-1", CImage::LoadImage("Text1-1.png"));
	ADD_RESOURCE("Text1-2", CImage::LoadImage("Text1-3.png"));
	ADD_RESOURCE("Text1-3", CImage::LoadImage("Text1-2.png"));
	ADD_RESOURCE("Text1-4", CImage::LoadImage("Text1-4.png"));
	ADD_RESOURCE("Text1-5", CImage::LoadImage("Text1-5.png"));
	ADD_RESOURCE("Text1-6", CImage::LoadImage("Text1-6.png"));
	ADD_RESOURCE("Text1-7", CImage::LoadImage("Text1-7.png"));
	ADD_RESOURCE("Text1-8", CImage::LoadImage("Text1-8.png"));
	ADD_RESOURCE("Text1-9", CImage::LoadImage("Text1-9.png"));
	ADD_RESOURCE("Text1-10", CImage::LoadImage("Text1-10.png"));
	ADD_RESOURCE("Send", CImage::LoadImage("SendIcon.png"));
	*/
}

void CStorySceneOpening::Setchar()
{
	char name_array[][MAX_SENTENSE_SIZE] = { "Story" ,"Story2","Story3"};
	char name_array2[][MAX_SENTENSE_SIZE] = { "Text1-1" ,"Text1-2" ,"Text1-3"
		                                     ,"Text1-4", "Text1-5" ,"Text1-6" 
	                                         ,"Text1-7"  ,"Text1-8" ,"Text1-9"
		                                     ,"Text1-10" };

	for (int i = 0; i < 3; i++) {
		//strcpy_s(name_a[i], name_b[i]);
		strcpy_s(name[i], MAX_SENTENSE_SIZE,name_array[i]);
	}
	
	//SetSentense(OPENING_STORY_NUM, name, name_array);
	SetSentense(OPENING_SENTENSE_NUM, t_name, name_array2);
}

void CStorySceneOpening::SetValue()
{  
	CVector4D rects = CVector4D(DEF_RECT_TOP_X, MIN, MAX_X, MAX_Y);
	CVector4D size_poses= CVector4D(DEF_SIZE_X, DEF_SIZE_Y, POS_MAX_X, POS_MIN_Y);
	DelValue(SUB0, rects, size_poses);

    rects = CVector4D(RECT_TOP_X, RECT_TOP_Y, RECT_BOT_X, RECT_BOT_Y);
    size_poses = CVector4D(SIZE_X, SIZE_Y, POS_X, POS_MIN_Y);
	DelValue(SUB1, rects, size_poses);

	rects = CVector4D(RECT_TOP_X2, RECT_TOP_Y2, RECT_BOT_X2, RECT_BOT_Y2);
	size_poses = CVector4D(SIZE_X2, SIZE_Y2, POS_X2, POS_MAX_Y);
	DelValue(SUB2, rects, size_poses);

	rects = CVector4D(MIN, MIN, RECT_BOT_X3, MAX_Y);
	size_poses = CVector4D(SIZE_X3, SIZE_Y3, POS_MIN_X, POS_MIN_Y);
	DelValue(SUB3, rects, size_poses);

	rects = CVector4D(MIN, MIN, MAX_X, MAX_Y);
	size_poses = CVector4D(DRAW_MAX_X, DRAW_MAX_Y,POS_MIN_X, POS_MIN_Y);
	DelValue(SUB4, rects, size_poses);






	//2枚目
	rects = CVector4D(RECT_TOP_X5, RECT_TOP_Y5, RECT_BOT_X5, RECT_BOT_Y5);
	size_poses = CVector4D(SIZE_X4, SIZE_Y4, POS_MIN_X, POS_MIN_Y);
	DelValue(SUB5, rects, size_poses);

	rects = CVector4D(RECT_TOP_X6, RECT_TOP_Y6, RECT_BOT_X6, RECT_BOT_Y6);
	size_poses = CVector4D(SIZE_X4, SIZE_Y4, POS_X6, POS_Y6);
	DelValue(SUB6, rects, size_poses);

	rects = CVector4D(RECT_TOP_X7, RECT_TOP_Y7, RECT_BOT_X7, RECT_BOT_Y7);
	size_poses = CVector4D(DEF_SIZE_X, DEF_SIZE_Y, POS_MAX_X, POS_MIN_Y);
	DelValue(SUB7, rects, size_poses);


	//3枚目

	rects = CVector4D(RECT_TOP_X8, RECT_TOP_Y8, RECT_BOT_X8, RECT_BOT_Y8);
	size_poses = CVector4D(SIZE_X8, SIZE_Y8, POS_X8, POS_MIN_Y);
	DelValue(SUB8, rects, size_poses);

	rects = CVector4D(MIN, MIN, MAX_X, MAX_Y);
	size_poses = CVector4D(DRAW_MAX_X, DRAW_MAX_Y, POS_MIN_X, POS_MIN_Y);
	DelValue(SUB9, rects, size_poses);
}
