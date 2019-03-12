#include "CStorySceneOpening.h"
#include "CStoryScene.h"



CStorySceneOpening::CStorySceneOpening()
{
	AddRAll();
	Setchar();
	SetValue();
	SetSubSentense(OPENING_SENTENSE_NUM);
	SetAll();
}

CStorySceneOpening::~CStorySceneOpening()
{
}

void CStorySceneOpening::Update()
{
	UpdateText(30, sentence_num);
	if (subscript == num_decison) {
		UpdateStory(pos_array[subscript - 1], pos_array[subscript]);
		num_decison++;
		if(num_decison==6)NextStory(name, 1, pos_array[0]);
	}
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
	ADD_RESOURCE("Send", CImage::LoadImage("SendIcon.png"));
}

void CStorySceneOpening::Setchar()
{
	char name_array[][80] = { "Story" ,"Story2" };
	char name_array2[][80] = { "Text1-1" ,"Text1-2" ,"Text1-3" 
		                      ,"Text1-4", "Text1-5" ,"Text1-6" };
	SetSentense(2, name, name_array);
	SetSentense(6, t_name, name_array2);
}

void CStorySceneOpening::SetValue()
{
	int nums0[] = { SUB0, DEF_SIZE_TOP_X,MIN,MAX_X,MAX_Y,
		            DEF_SIZE_X,DEF_SIZE_Y,
		            POS_MAX_X,POS_MIN_Y };
	int nums1[] = { SUB1, CHANGE_SIZE_TOP_X,MIN,CHANGE_SIZE_BOTTOM_X,
		            CHANGE_SIZE_BOTTOM_Y,CHANGE_SIZE_X,CHANGE_SIZE_Y,
		            CHANGE_POS_X,POS_MIN_Y };
	int nums2[] = { SUB2, CHANGE_SIZE_TOP_X2,CHANGE_SIZE_TOP_Y2,
		            CHANGE_SIZE_BOTTOM_X2,MAX_Y,CHANGE_SIZE_X2,CHANGE_SIZE_Y2,
		            CHANGE_POS_X2,POS_MAX_Y };
	int nums3[] = { SUB3,MIN,MIN,CHANGE_SIZE_BOTTOM_X3,MAX_Y,
		            CHANGE_SIZE_X3,CHANGE_SIZE_Y3,
		            POS_MIN_X,POS_MIN_Y };
	int nums4[] = { SUB4, MIN,MIN,MAX_X,MAX_Y,
		            DRAW_MAX_X,DRAW_MAX_Y,
		            POS_MIN_X,POS_MIN_Y };
	SetArrayValue(nums0);
	SetArrayValue(nums1);
	SetArrayValue(nums2);
	SetArrayValue(nums3);
	SetArrayValue(nums4);
}
