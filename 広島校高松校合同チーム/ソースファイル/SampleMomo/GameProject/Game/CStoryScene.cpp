#include "CStoryScene.h"
#include "string.h"
#include "CFade.h"


CStoryScene::CStoryScene() : CObject(0, 0)
{
	
}

CStoryScene::~CStoryScene()
{
	delete m_while_screen_p;
	delete m_frame_p;
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
 	//printf("story_name%s\n", story_name);
 	SetStory2(values);
}

void CStoryScene::SetStory2(rect_pos_size value)
{
	//切り取り位置の設定
	m_s_img.SetRect(value.top_x, value.top_y,
		value.bottom_x, value.bottom_y);
	//サイズと座標の初期値を設定
	//m_s_img.SetPos(value.pos);
	//m_s_img.SetSize(value.size);


	//割合じゃちょっとあれだな

	
	//CVector2D draw_size = value.size * 1.25;
	CVector2D draw_size = CVector2D(value.bottom_x - value.top_x, value.bottom_y - value.top_y);
	

	//縮尺を維持してスケーリング

	bool is_scaling_x = false;
	bool is_scaling_y = false;

	double mult_x = 0.0;
	double mult_y = 0.0;

	if (draw_size.x >= STORY_SIZE.x) {
		mult_x = STORY_SIZE.x / draw_size.x;
		is_scaling_x = true;
	}
	if (draw_size.y >= STORY_SIZE.y) {
		mult_y = STORY_SIZE.y / draw_size.y;
		is_scaling_y = true;
	}

	double mult;
	if (is_scaling_x == true || is_scaling_y == true) {

		if (is_scaling_x == true && is_scaling_y == true) {
			if (mult_x < mult_y) mult = mult_x;
			else mult = mult_y;
		}
		else if(is_scaling_x == true) mult = mult_x;
		else if (is_scaling_y == true) mult = mult_y;

		draw_size *= mult;
	}



	//if (draw_size.x >= STORY_SIZE.x) draw_size.x = STORY_SIZE.x;
	//if (draw_size.y >= STORY_SIZE.y) draw_size.y = STORY_SIZE.y;

	m_s_img.SetSize(draw_size);

	CVector2D draw_pos = STORY_POSITION + ((STORY_SIZE - draw_size) / 2.0);

	m_s_img.SetPos(draw_pos);



	const CVector2D frame_size = CVector2D(20, 20);

	m_frame_p->SetColor(0, 0, 0, 2.55);
	
	/*
	m_frame_p->SetPos(draw_pos + (draw_size - draw_size* 1.05) / 2.0);
	
	m_frame_p->SetSize(draw_size * 1.05);
	*/
	m_frame_p->SetPos(draw_pos + (draw_size - (draw_size + frame_size)) / 2.0);
	m_frame_p->SetSize(draw_size + frame_size);
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
	//char* story_name_ad = story_name[0] + sub;

	//char* story_ad = story_name[sub];

	//printf("story_ad  %s sub %d\n", story_ad, sub);
	
	SetStory(story_name[sub],values);
}

void CStoryScene::NextText(char text_name[][MAX_SENTENSE_SIZE])
{
	if (m_is_fade_effect == true) {
		CFade::GetInstance()->SetFadeOut(0);
		CFade::GetInstance()->SetFadeIn(25);
	}
	//変数の初期化
	SetParam();
	SetText(text_name[subscript]);
}

void CStoryScene::UpdateText(int word,int limit)
{
	//文字出力完了していないなら、
	if (complete_flg == false) {
		if (dis_cnt >= 4&& rect_cnt <= lim * word) {
			RectUp();
			rect_cnt += RECTSIZE_X;
			dis_cnt = 0;
		}
		//スペースボタンで文字を出力完了に
		if (CInput::GetState(0, CInput::ePush, CInput::eButton2) || CInput::GetState(0, CInput::ePush, CInput::eButton10)) {
			m_guide_text_p = nullptr;
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
		if (CInput::GetState(0, CInput::ePush, CInput::eButton2) || CInput::GetState(0, CInput::ePush, CInput::eButton10)) {
			m_guide_text_p = nullptr;
			subscript++;
			NextText(t_name);
		}
	}

	dis_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
}

void CStoryScene::UpdateStory(rect_pos_size& pos_now, rect_pos_size& pos_next)
{
	SetStory2(pos_next);
}

void CStoryScene::UpdateStory2(int change, int next_array)
{
	if (subscript == num_decison) {
		
		num_decison++;

		//printf("name %s\n", name);
		//printf("num_decison %d\n", num_decison);
		if (num_decison % change == 0) {
 			NextStory(name, (1 + m_story_image_num++), pos_array[next_array]);
		}

		UpdateStory(pos_array[subscript - 1], pos_array[subscript]);
	}
}

void CStoryScene::ChangeAll(rect_pos_size & pos_a, rect_pos_size & pos_b)
{
	pos_a.top_x += ChangeRect(pos_a.top_x, pos_b.top_x) * CFPS::GetDeltaTime() * GAME_BASE_FPS;
	pos_a.top_y += ChangeRect(pos_a.top_y, pos_b.top_y) * CFPS::GetDeltaTime() * GAME_BASE_FPS;
	pos_a.bottom_x += ChangeRect(pos_a.bottom_x, pos_b.bottom_x) * CFPS::GetDeltaTime() * GAME_BASE_FPS;
	pos_a.bottom_y += ChangeRect(pos_a.bottom_y, pos_b.bottom_y) * CFPS::GetDeltaTime() * GAME_BASE_FPS;
	pos_a.pos += ChangeVector(pos_a.pos, pos_b.pos) * CFPS::GetDeltaTime() * GAME_BASE_FPS;
	pos_a.size += ChangeVector(pos_a.size, pos_b.size) * CFPS::GetDeltaTime() * GAME_BASE_FPS;
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
	draw_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if (draw_cnt <= 30) {
		m_icon.Draw();
	}
	else if (draw_cnt > 60) draw_cnt = 0;
}

void CStoryScene::AllDraw()
{
	m_while_screen_p->SetColor(2.55, 2.55, 2.55,2.55);
	m_while_screen_p->SetSize(1280, 720);
	m_while_screen_p->SetPos(0, 0);
	if(m_is_show_white_screen == true) m_while_screen_p->Draw();

	
	m_frame_p->Draw();

	m_s_img.Draw();
	m_text_box.Draw();
	m_text.Draw();


	guide_draw_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;

	if (guide_draw_cnt <= 150) {
		if (m_guide_text_p != nullptr) m_guide_text_p->Draw();//一旦ガイドもここで描画
	}
	if (guide_draw_cnt >= 180) guide_draw_cnt = 0;
	

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
		scene_change_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}

	if (scene_change_cnt >= 60)SetIsDelete();
}
