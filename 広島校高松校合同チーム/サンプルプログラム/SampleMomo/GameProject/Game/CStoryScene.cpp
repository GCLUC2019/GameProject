#include "CStoryScene.h"
#include "string.h"

#define STORY_SIZE  CVector2D(1000,600)
#define STORY_POSISHON  CVector2D(140,20)
#define BOX_SIZE CVector2D(1100,70)
#define BOX_POSISHON CVector2D(100, 630)
#define TEXT_SIZE CVector2D(1100,70)
#define TEXT_POSISHON CVector2D(130, 635)
#define TEXT_DEF_SIZE CVector2D(30,50)
#define RECTSIZE_X 30
#define RECTSIZE_Y 40
#define ICON_POSISHON CVector2D(1100,660)
#define ICON_SIZE CVector2D(30,30)
#define MAX_STRINGS 1024

CStoryScene::CStoryScene() : CObject(0, 0)
{
	ADD_RESOURCE("Story", CImage::LoadImage("story1.png"));
	ADD_RESOURCE("Textbox", CImage::LoadImage("TextBox.png"));
	ADD_RESOURCE("Text1-1", CImage::LoadImage("Text1-1.png"));
	ADD_RESOURCE("Text1-2", CImage::LoadImage("Text1-3.png"));
	ADD_RESOURCE("Text1-3", CImage::LoadImage("Text1-2.png"));
	ADD_RESOURCE("Send", CImage::LoadImage("SendIcon.png"));
	strcpy_s(name, "Story");
    strcpy_s(t_name[0],"Text1-1");
	strcpy_s(t_name[1], "Text1-2");
	strcpy_s(t_name[2], "Text1-3");
	pos_array[0].top_x= 2500; pos_array[0].top_y = 0;
	pos_array[0].bottom_x = 4093; pos_array[0].bottom_y = 2894;
	pos_array[0].size = CVector2D(400, 600);
	pos_array[0].pos = CVector2D(450, 20);
	SetAll();
	subscript = 0;//添え字
	sentence_num = 3;//文章数
}

CStoryScene::~CStoryScene()
{
}

void CStoryScene::Update()
{
	UpdateText(24, sentence_num);
}

void CStoryScene::Draw()
{
	m_s_img.Draw();
	m_text_box.Draw();
	m_text.Draw();
	IconDraw();
}

void CStoryScene::SetParam()
{
	rect_cnt = 0;
	dis_cnt = 0;
	draw_cnt = 0;
	lim = RECTSIZE_X;
	complete_flg = false;
}

void CStoryScene::SetTextBox()
{
	m_text_box = COPY_RESOURCE("Textbox", CImage*);
	m_text_box.SetSize(BOX_SIZE);
	m_text_box.SetPos(BOX_POSISHON);
}

void CStoryScene::SetIcon()
{
	m_icon = COPY_RESOURCE("Send", CImage*);
	m_icon.SetSize(ICON_SIZE);
	m_icon.SetPos(ICON_POSISHON);
}

void CStoryScene::SetStory(char story_name[], rect_pos_size pos_a)
{
	m_s_img= COPY_RESOURCE(story_name, CImage*);
	//切り取り位置の設定
	m_s_img.SetRect(pos_a.top_x, pos_a.top_y,
		pos_a.bottom_x, pos_a.bottom_y);
	//サイズと座標の初期値を設定
	m_s_img.SetPos(pos_a.pos);
	m_s_img.SetSize(pos_a.size);
}

void CStoryScene::SetText(char text_name[])
{
	m_text= COPY_RESOURCE(text_name, CImage*);
	m_text.SetPos(TEXT_POSISHON);
	//切り取り初期位置
	m_text.SetRect(0,0, RECTSIZE_X, RECTSIZE_Y);
	m_text.SetSize(TEXT_DEF_SIZE);
}

void CStoryScene::SetAll()
{
	SetStory(name, pos_array[0]);
	SetTextBox();
	SetText(t_name[0]);
	SetIcon();
	SetParam();
}

void CStoryScene::NextText(char text_name[][1024])
{
	SetParam();
	SetText(text_name[subscript]);
}

void CStoryScene::UpdateText(int word,int limit)
{
	//文字出力完了していないなら、
	if (complete_flg == false) {
		if (dis_cnt == 5) {
			if (rect_cnt <= lim * word) {
				RectUp();
				rect_cnt += RECTSIZE_X;
			}
			dis_cnt = 0;
		}
		//スペースボタンで文字を出力完了に
		if (CInput::GetState(0, CInput::ePush, CInput::eButton1)) {
			rect_cnt = lim * word;
			RectUp();
			complete_flg = true;
			dis_cnt = 0;
		}
		//指定した文字を出力を終えた場合
		if (rect_cnt >= lim * word) {
			complete_flg = true;
			dis_cnt = 0;
		}
	}

	//文章を表示し終えた後スペースキーで次の文章へ
	if (subscript<sentence_num-1&&dis_cnt >= 30&&complete_flg == true) {
		if (CInput::GetState(0, CInput::ePush, CInput::eButton1)) {
			subscript++;
			NextText(t_name);
		}
	}

	dis_cnt++;
}

void CStoryScene::IconDraw()
{
	draw_cnt++;
	if (draw_cnt <= 30) m_icon.Draw();
	else if (draw_cnt > 60) draw_cnt = 0;
}

void CStoryScene::RectUp()
{
	m_text.SetRect(0, 0, RECTSIZE_X + rect_cnt, RECTSIZE_Y);
	m_text.SetSize(RECTSIZE_X + rect_cnt, 50);
}
