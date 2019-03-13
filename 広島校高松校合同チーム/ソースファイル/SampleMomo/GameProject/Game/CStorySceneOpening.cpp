#include "CStorySceneOpening.h"

//オープニングのテキスト数
#define OPENING_SENTENSE_NUM 10
//オープニングの紙芝居数
#define OPENING_STORY_NUM 2
//表示する絵を変えるための文章数
#define CHANGE_NUM 6

//画像切り取りサイズの初期値と変動値
#define DEF_RECT_TOP_X 2500
#define RECT_TOP_X 1650
#define RECT_BOT_X 2600
#define RECT_BOT_Y 1550
#define RECT_TOP_X2 550
#define RECT_TOP_Y2 1500
#define RECT_BOT_X2 2800
#define RECT_BOT_X3 1650
#define RECT_BOT_X5 550
#define RECT_BOT_Y5 1450
#define RECT_TOP_X6 550
#define RECT_TOP_Y6 250
#define RECT_BOT_X6 1200
#define RECT_BOT_Y6 1700
#define RECT_TOP_X7 2800
#define RECT_TOP_X8 1200

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
}

CStorySceneOpening::~CStorySceneOpening()
{
}

void CStorySceneOpening::Update()
{
	UpdateText(CHAR_NUM, sentence_num);
	if (subscript == num_decison) {
		UpdateStory(pos_array[subscript - 1], pos_array[subscript]);
		num_decison++;
		if(num_decison== CHANGE_NUM)NextStory(name, 1, pos_array[5]);
	}

	ChangeScene(OPENING_SENTENSE_NUM);
	
}

void CStorySceneOpening::Draw()
{
	AllDraw();
}

void CStorySceneOpening::AddRAll()
{
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
}

void CStorySceneOpening::Setchar()
{
	char name_array[][MAX_SENTENSE_SIZE] = { "Story" ,"Story2" };
	char name_array2[][MAX_SENTENSE_SIZE] = { "Text1-1" ,"Text1-2" ,"Text1-3"
		                                     ,"Text1-4", "Text1-5" ,"Text1-6" 
	                                         ,"Text1-7"  ,"Text1-8" ,"Text1-9"
		                                     ,"Text1-10" };
	SetSentense(OPENING_STORY_NUM, name, name_array);
	SetSentense(OPENING_SENTENSE_NUM, t_name, name_array2);
}

void CStorySceneOpening::SetValue()
{                   
	int nums0[] = { /*添え字*/ SUB0,
		            //切り取りサイズ
		            DEF_RECT_TOP_X,MIN,MAX_X,MAX_Y,
		            //表示サイズ
		            DEF_SIZE_X,DEF_SIZE_Y,
		            //表示位置
		            POS_MAX_X,POS_MIN_Y };
	int nums1[] = { SUB1, 
		            RECT_TOP_X,MIN,RECT_BOT_X,RECT_BOT_Y,
		            SIZE_X,SIZE_Y,POS_X,POS_MIN_Y };
	int nums2[] = { SUB2, 
		            RECT_TOP_X2,RECT_TOP_Y2,RECT_BOT_X2,MAX_Y,
		            SIZE_X2,SIZE_Y2,POS_X2,POS_MAX_Y };
	int nums3[] = { SUB3,
		            MIN,MIN,RECT_BOT_X3,MAX_Y,
		            SIZE_X3,SIZE_Y3,POS_MIN_X,POS_MIN_Y };
	int nums4[] = { SUB4, 
		            MIN,MIN,MAX_X,MAX_Y,
		            DRAW_MAX_X,DRAW_MAX_Y,
		            POS_MIN_X,POS_MIN_Y };
	int nums5[] = { SUB5,
		            MIN,MIN,RECT_BOT_X5,RECT_BOT_Y5,
		            SIZE_X4,SIZE_Y4,POS_MIN_X,POS_MIN_Y };
	int nums6[] = { SUB6,
		            RECT_TOP_X6,RECT_TOP_Y6,RECT_BOT_X6,RECT_BOT_Y6,
		            SIZE_X4,SIZE_Y4,POS_X6,POS_Y6 };
	int nums7[] = { SUB7,
		            RECT_TOP_X7,MIN,MAX_X,MAX_Y,
		            DEF_SIZE_X,DEF_SIZE_Y,
		            POS_MAX_X,POS_MIN_Y };
	int nums8[] = { SUB8,
		            RECT_TOP_X8,MIN,MAX_X,MAX_Y,
		            SIZE_X8,SIZE_Y8,
		            POS_X8,POS_MIN_Y };
	int nums9[] = { SUB9,
		            MIN,MIN,MAX_X,MAX_Y,
		            DRAW_MAX_X,DRAW_MAX_Y,
		            POS_MIN_X,POS_MIN_Y };


	SetArrayValue(nums0);
	SetArrayValue(nums1);
	SetArrayValue(nums2);
	SetArrayValue(nums3);
	SetArrayValue(nums4);
	SetArrayValue(nums5);
	SetArrayValue(nums6);
	SetArrayValue(nums7);
	SetArrayValue(nums8);
	SetArrayValue(nums9);
}
