#pragma once
#include "CObject.h"
#include "../Global.h"

//配列の最大数
#define MAX_TEXT_ARRAY 50
#define MAX_STORY_ARRAY 50
#define MAX_SENTENSE_SIZE 50
#define ARRAY_SIZE 50

//テキストの文字数	
#define CHAR_NUM 30

//添え字
#define SUB0 0
#define SUB1 1
#define SUB2 2
#define SUB3 3
#define SUB4 4
#define SUB5 5
#define SUB6 6
#define SUB7 7
#define SUB8 8
#define SUB9 9
#define SUB10 10
#define SUB11 11

//紙芝居サイズと座標
//#define STORY_SIZE  CVector2D(1000,600)
//#define STORY_POSITION  CVector2D(140,20)

#define STORY_SIZE  CVector2D(1000,550)
#define STORY_POSITION  CVector2D(140,45)

//テキストボックスサイズと座標
#define BOX_SIZE CVector2D(1100,70)
#define BOX_POSISHON CVector2D(100, 630)
//テキストサイズと座標及び初期切り取りサイズ
#define TEXT_SIZE CVector2D(1100,70)
#define TEXT_POSISHON CVector2D(130, 635)
#define TEXT_DEF_SIZE CVector2D(30,50)
//テキスト切り取りサイズ
#define RECTSIZE_X 30
#define RECTSIZE_Y 40
//アイコンサイズと座標
#define ICON_POSISHON CVector2D(1100,660)
#define ICON_SIZE CVector2D(30,30)
//サイズ最小値
#define MIN 0
//サイズ最大値
#define MAX_X 4093
#define MAX_Y 2894
//表示サイズ最小値と最大値
#define DRAW_MAX_X 1020
#define DRAW_MAX_Y 600
//表示位置の最大値と最小値
#define POS_MAX_X 750
#define POS_MAX_Y 320
#define POS_MIN_X 130
#define POS_MIN_Y 20

class CStoryScene : public CObject {
protected:
	CImage* m_while_screen_p = new CImage();
	CImage* m_frame_p = new CImage();

	CImage m_s_img;
	CImage m_text_box;
	CImage m_text;
	CImage m_icon;
	int rect_cnt;
	double dis_cnt;
	short int lim;
	short int sentence_num;
	double draw_cnt;
	short int subscript;
	int num_decison;
	double scene_change_cnt;
	int m_story_image_num = 0;

	struct rect_pos_size {
		int top_x;
		int top_y;
		int bottom_x;
	    int bottom_y;
		CVector2D size;
		CVector2D pos;
	};
	
	rect_pos_size pos_array[ARRAY_SIZE];

	bool complete_flg;
	char name[MAX_STORY_ARRAY][MAX_SENTENSE_SIZE];
	char t_name[MAX_TEXT_ARRAY][MAX_SENTENSE_SIZE];

	CImage* m_guide_text_p = nullptr;
	double guide_draw_cnt = 0.0;

	bool m_is_show_white_screen = true;

	bool m_is_fade_effect = true;
public:
	CStoryScene();
	~CStoryScene();
	virtual void Update();
	virtual void Draw();
	void SetParam();
	void SetSubSentense(int sent);
	void SetTextBox();
	void SetIcon();
	void SetStory(char story_name[], rect_pos_size values);
	void SetStory2(rect_pos_size pos_a);
	void SetText(char text_name[]);
	void SetArrayValue(int num_array[]);
	void SetSentense(int repite, char name_a[][MAX_SENTENSE_SIZE], 
		                         char name_b[][MAX_SENTENSE_SIZE]);
	void SetAll(int sent_num);
	//配列数値受け渡し関数
	void DelValue(int _sub, CVector4D rect, CVector4D size_pos);
	//次の画像を表示する関数
	void NextStory(char story_name[][MAX_SENTENSE_SIZE],int sub, rect_pos_size values);
	//次のテキストを表示する関数
	void NextText(char text_name[][MAX_SENTENSE_SIZE]);
	//表示したい文章の文字数と文章数
	void UpdateText(int word,int limit);
	//現在の構造体と次の構造体
	void UpdateStory(rect_pos_size& pos_now,rect_pos_size& pos_next);
	//引数を次の紙芝居を表示するタイミングと座標等のデータを入れた添え字
	void UpdateStory2(int change, int next_array);
	//変更まとめ関数
	void ChangeAll(rect_pos_size& pos_a, rect_pos_size& pos_b);
	//切り取り位置変更関数(引数は現在と次の値と変化値）
	int ChangeRect(int& now, int& next);
	//座標及びサイズ変更関数
	CVector2D ChangeVector(CVector2D& now, CVector2D& next);
	//アイコンを点滅させて表示する
	void IconDraw();
	//描写関連まとめ関数
	void AllDraw();
	void RectUp();
	//次のシーンに変更関数(引数は表示する文章数）
	void ChangeScene(int sent_num);

	void SetIsFadeEffect(bool _is) { m_is_fade_effect = _is; }
};

/*
２０１９/3/11 ストーリーシーンクラス　作成　松川
紙芝居の座標・サイズ設定関数
テキストボックスの座標・サイズ設定関数
テキストの座標・サイズ設定関数
追加
2019/3/13 ストーリーシーンクラス　完成　作成　松川
上記の関数を追加
*/