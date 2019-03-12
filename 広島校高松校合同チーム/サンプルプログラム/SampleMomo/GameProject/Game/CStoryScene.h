#pragma once
#include "CObject.h"
#include "../Global.h"

//添え字
#define SUB0 0
#define SUB1 1
#define SUB2 2
#define SUB3 3
#define SUB4 4
#define SUB5 5

//紙芝居サイズと座標
#define STORY_SIZE  CVector2D(1000,600)
#define STORY_POSISHON  CVector2D(140,20)
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
#define POS_MAX_Y 300
#define POS_MIN_X 130
#define POS_MIN_Y 20

class CStoryScene : public CObject {
protected:
	CImage m_s_img;
	CImage m_text_box;
	CImage m_text;
	CImage m_icon;
	int rect_cnt;
	int dis_cnt;
	int lim;
	int sentence_num;
	int draw_cnt;
	int subscript;
	int num_decison;

	struct rect_pos_size {
		int top_x;
		int top_y;
		int bottom_x;
		int bottom_y;
		CVector2D size;
		CVector2D pos;
	};
	
	rect_pos_size pos_array[5];

	bool complete_flg;
	char name[2][80];
	char t_name[6][80];
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
	void SetSentense(int repite, char name_a[][80], char name_b[][80]);
	void SetAll();
	//次の画像を表示する関数
	void NextStory(char story_name[][80],int sub, rect_pos_size values);
	//次のテキストを表示する関数
	void NextText(char text_name[][80]);
	//表示したい文章の文字数と文章数
	void UpdateText(int word,int limit);
	//現在の構造体と次の構造体
	void UpdateStory(rect_pos_size& pos_now,rect_pos_size& pos_next);
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
};

/*
２０１９/3/11 ストーリーシーンクラス　作成　松川
紙芝居の座標・サイズ設定関数
テキストボックスの座標・サイズ設定関数
テキストの座標・サイズ設定関数
追加
*/