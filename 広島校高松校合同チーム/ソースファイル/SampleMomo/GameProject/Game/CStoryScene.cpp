#include "CStoryScene.h"
#include "string.h"


CStoryScene::CStoryScene() : CObject(0, 0)
{
	
}

CStoryScene::~CStoryScene()
{
}

void CStoryScene::Update()
{
	
}

void CStoryScene::Draw()
{
	
}

void CStoryScene::SetParam()
{
	dis_cnt = 0;
	rect_cnt = 0;
	draw_cnt = 0;
	lim = RECTSIZE_X;
	complete_flg = false;
}

void CStoryScene::SetSubSentense(int sent)
{
	scene_change_cnt = 0; //画面遷移カウント
	num_decison = 1;//判定用数字
	subscript = 0;//添え字
	sentence_num = sent;//文章数
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

void CStoryScene::SetArrayValue(int num_array[])
{
	pos_array[num_array[0]].top_x = num_array[1];
	pos_array[num_array[0]].top_y = num_array[2];
	pos_array[num_array[0]].bottom_x = num_array[3];
	pos_array[num_array[0]].bottom_y = num_array[4];
	pos_array[num_array[0]].size = CVector2D(num_array[5], num_array[6]);
	pos_array[num_array[0]].pos = CVector2D(num_array[7], num_array[8]);
}

void CStoryScene::SetSentense(int repite, char name_a[][MAX_SENTENSE_SIZE], 
	                                      char name_b[][MAX_SENTENSE_SIZE])
{
	for (int i = 0; i < repite; i++) {
		strcpy_s(name_a[i], name_b[i]);
	}
}

void CStoryScene::SetAll(int sent_num)
{
	SetStory(name[0], pos_array[0]);
	SetTextBox();
	SetText(t_name[0]);
	SetIcon();
	SetSubSentense(sent_num);
	SetParam();
}

void CStoryScene::DelValue(int _sub, CVector4D rect, CVector4D size_pos)
{
	int nums[9];
	nums[0] = _sub;
	nums[1] = rect.x; nums[2] = rect.y;
	nums[3] = rect.z; nums[4] = rect.w;
	nums[5] = size_pos.x; nums[6] = size_pos.y;
	nums[7] = size_pos.z; nums[8] = size_pos.w;
	SetArrayValue(nums);
}

void CStoryScene::NextStory(char story_name[][MAX_SENTENSE_SIZE],
	                        int sub, rect_pos_size values)
{
	SetStory(story_name[sub],values);
}

void CStoryScene::NextText(char text_name[][MAX_SENTENSE_SIZE])
{
	//変数の初期化
	SetParam();
	SetText(text_name[subscript]);
}

void CStoryScene::UpdateText(int word,int limit)
{
	//文字出力完了していないなら、
	if (complete_flg == false) {
		if (dis_cnt == 4&& rect_cnt <= lim * word) {
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

void CStoryScene::UpdateStory2(int change, int next_array)
{
	if (subscript == num_decison) {
		UpdateStory(pos_array[subscript - 1], pos_array[subscript]);
		num_decison++;
		if (num_decison == change)NextStory(name, 1, pos_array[next_array]);
	}
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

void CStoryScene::AllDraw()
{
	m_s_img.Draw();
	m_text_box.Draw();
	m_text.Draw();
	IconDraw();
}

void CStoryScene::RectUp()
{
	m_text.SetRect(MIN, MIN, RECTSIZE_X + rect_cnt, RECTSIZE_Y);
	m_text.SetSize(RECTSIZE_X + rect_cnt, RECTSIZE_Y+10);
}

void CStoryScene::ChangeScene(int sent_num)
{
	if (complete_flg == true && subscript == sent_num - 1) {
		scene_change_cnt++;
	}

	if (scene_change_cnt == 60)SetIsDelete();
}
