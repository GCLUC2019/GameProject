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
	ADD_RESOURCE("Story2", CImage::LoadImage("story2.png"));
	ADD_RESOURCE("Textbox", CImage::LoadImage("TextBox.png"));
	ADD_RESOURCE("Text1-1", CImage::LoadImage("Text1-1.png"));
	ADD_RESOURCE("Text1-2", CImage::LoadImage("Text1-3.png"));
	ADD_RESOURCE("Text1-3", CImage::LoadImage("Text1-2.png"));
	ADD_RESOURCE("Text1-4", CImage::LoadImage("Text1-4.png"));
	ADD_RESOURCE("Text1-5", CImage::LoadImage("Text1-5.png"));
	ADD_RESOURCE("Text1-6", CImage::LoadImage("Text1-6.png"));
	ADD_RESOURCE("Send", CImage::LoadImage("SendIcon.png"));
	strcpy_s(name[0], "Story");
	strcpy_s(name[1], "Story2");
    strcpy_s(t_name[0],"Text1-1");
	strcpy_s(t_name[1], "Text1-2");
	strcpy_s(t_name[2], "Text1-3");
	strcpy_s(t_name[3], "Text1-4");
	strcpy_s(t_name[4], "Text1-5");
	strcpy_s(t_name[5], "Text1-6");
	pos_array[0].top_x= 2500; pos_array[0].top_y = 0;
	pos_array[0].bottom_x = 4093; pos_array[0].bottom_y = 2894;
	pos_array[0].size = CVector2D(400, 600);
	pos_array[0].pos = CVector2D(750, 20);
	pos_array[1].top_x = 1650; pos_array[1].top_y = 0;
	pos_array[1].bottom_x = 2600; pos_array[1].bottom_y = 1550;
	pos_array[1].size = CVector2D(300, 350);
	pos_array[1].pos = CVector2D(450, 20);
	pos_array[2].top_x = 550; pos_array[2].top_y = 1500;
	pos_array[2].bottom_x = 2800; pos_array[2].bottom_y = 2894;
	pos_array[2].size = CVector2D(500, 300);
	pos_array[2].pos = CVector2D(250, 300);
	pos_array[3].top_x = 0; pos_array[3].top_y = 0;
	pos_array[3].bottom_x = 1650; pos_array[3].bottom_y = 2894;
	pos_array[3].size = CVector2D(400, 600);
	pos_array[3].pos = CVector2D(130, 20);
	pos_array[4].top_x = 0; pos_array[4].top_y = 0;
	pos_array[4].bottom_x = 4093; pos_array[4].bottom_y = 2894;
	pos_array[4].size = CVector2D(1020, 600);
	pos_array[4].pos = CVector2D(130, 20);

	SetAll();
	subscript = 0;//添え字
	sentence_num = 6;//文章数
}

CStoryScene::~CStoryScene()
{
}

void CStoryScene::Update()
{
	UpdateText(30, sentence_num);
	if (subscript == 1)UpdateStory(pos_array[subscript-1],pos_array[subscript]);
	if (subscript == 2)UpdateStory(pos_array[subscript - 1], pos_array[subscript]);
	if (subscript == 3)UpdateStory(pos_array[subscript - 1], pos_array[subscript]);
	if (subscript == 4)UpdateStory(pos_array[subscript - 1], pos_array[subscript]);
	if (subscript == 5)NextStory(name,1,pos_array[0]);
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

void CStoryScene::SetStory(char story_name[], rect_pos_size values)
{
	m_s_img= COPY_RESOURCE(story_name, CImage*);
	SetStory2(values);
}

void CStoryScene::SetStory2(rect_pos_size value)
{
	//切り取り位置の設定
	m_s_img.SetRect(value.top_x, value.top_y,
		value.bottom_x, value.bottom_y);
	//サイズと座標の初期値を設定
	m_s_img.SetPos(value.pos);
	m_s_img.SetSize(value.size);
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
	SetStory(name[0], pos_array[0]);
	SetTextBox();
	SetText(t_name[0]);
	SetIcon();
	SetParam();
}

void CStoryScene::NextStory(char story_name[][1024],int sub, rect_pos_size values)
{
	SetStory(story_name[sub],values);
}

void CStoryScene::NextText(char text_name[][1024])
{
	//変数の初期化
	SetParam();
	SetText(text_name[subscript]);
}

void CStoryScene::UpdateText(int word,int limit)
{
	//文字出力完了していないなら、
	if (complete_flg == false) {
		if (dis_cnt == 5&& rect_cnt <= lim * word) {
			RectUp();
			rect_cnt += RECTSIZE_X;
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
	if (subscript<sentence_num-1&&dis_cnt >= 15&&complete_flg == true) {
		if (CInput::GetState(0, CInput::ePush, CInput::eButton1)) {
			subscript++;
			NextText(t_name);
		}
	}

	dis_cnt++;
}

void CStoryScene::UpdateStory(rect_pos_size& pos_now, rect_pos_size& pos_next)
{
	SetStory2(pos_next);
}

void CStoryScene::ChangeAll(rect_pos_size & pos_a, rect_pos_size & pos_b)
{
	pos_a.top_x += ChangeRect(pos_a.top_x, pos_b.top_x);
	pos_a.top_y += ChangeRect(pos_a.top_y, pos_b.top_y);
	pos_a.bottom_x += ChangeRect(pos_a.bottom_x, pos_b.bottom_x);
	pos_a.bottom_y += ChangeRect(pos_a.bottom_y, pos_b.bottom_y);
	pos_a.pos += ChangeVector(pos_a.pos, pos_b.pos);
	pos_a.size += ChangeVector(pos_a.size, pos_b.size);
}

int CStoryScene::ChangeRect(int & now, int & next)
{
	int range = 100;
	//現在の値が次の値より大きいなら左にずらす
	if( now > next+range)return -30;
	//現在の値が次の値より小さいなら右にずらす
	if ( now < next-range)return 30;
	//それ以外なら０を返す
	else return 0;
}

CVector2D CStoryScene::ChangeVector(CVector2D & now, CVector2D & next)
{
	int x=0, y=0;
	int range = 12;
	//現在の値が次の値より大きいなら左にずらす
	if (now.x > next.x+ range)x = -3;
	if (now.y > next.y+ range)y = -3;
	//現在の値が次の値より小さいなら右にずらす
	if (now.x < next.x-range)x = 3;
	if (now.y < next.y- range)y = 3;
	return CVector2D(x,y);
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
