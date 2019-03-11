#include "CStoryScene.h"

#define STORY_SIZE  CVector2D(1000,600)
#define STORY_POSISHON  CVector2D(140,20)
#define BOX_SIZE CVector2D(1100,70)
#define BOX_POSISHON CVector2D(100, 630)
#define TEXT_SIZE CVector2D(1100,70)
#define TEXT_POSISHON CVector2D(130, 635)
#define TEXT_DEF_SIZE CVector2D(30,50)

CStoryScene::CStoryScene() : CObject(0, 0)
{
	ADD_RESOURCE("Story", CImage::LoadImage("story1.png"));
	ADD_RESOURCE("Textbox", CImage::LoadImage("TextBox.png"));
	ADD_RESOURCE("Text1-1", CImage::LoadImage("Text1-1.png"));
	char name[] = "Story";
	char t_name[] = "Text1-1";
	SetStory(name);
	SetTextBox();
	SetText(t_name);

	rect_cnt = 0;
    dis_cnt = 0;
}

CStoryScene::~CStoryScene()
{
}

void CStoryScene::Update()
{
	UpdateText(24);
}

void CStoryScene::Draw()
{
	m_s_img.Draw();
	m_text_box.Draw();
	m_text.Draw();
}

void CStoryScene::SetTextBox()
{
	m_text_box = COPY_RESOURCE("Textbox", CImage*);
	m_text_box.SetSize(BOX_SIZE);
	m_text_box.SetPos(BOX_POSISHON);
}

void CStoryScene::SetStory(char story_name[])
{
	m_s_img= COPY_RESOURCE(story_name, CImage*);
	m_s_img.SetPos(STORY_POSISHON);
	m_s_img.SetSize(STORY_SIZE);
}

void CStoryScene::SetText(char text_name[])
{
	m_text= COPY_RESOURCE(text_name, CImage*);
	m_text.SetPos(TEXT_POSISHON);
	//êÿÇËéÊÇËèâä˙à íu
	m_text.SetRect(0,0,30,40);
	m_text.SetSize(TEXT_DEF_SIZE);
}

void CStoryScene::UpdateText(int word)
{
	
	if (dis_cnt == 5) {
		if (rect_cnt <= rect_cnt * word) {
			m_text.SetRect(0, 0, 30 + rect_cnt, 40);
			m_text.SetSize(30 + rect_cnt, 50);
			rect_cnt += 30;
		}
		dis_cnt = 0;
	}
	dis_cnt++;
}
