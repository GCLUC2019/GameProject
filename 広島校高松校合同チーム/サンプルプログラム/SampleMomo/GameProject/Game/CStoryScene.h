#pragma once
#include "CObject.h"
#include "../Global.h"

class CStoryScene : public CObject {
private:
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

	char name[2][1024];
	char t_name[6][1024];
public:
	CStoryScene();
	~CStoryScene();
	void Update();
	void Draw();
	void SetParam();
	void SetTextBox();
	void SetIcon();
	void SetStory(char story_name[], rect_pos_size values);
	void SetStory2(rect_pos_size pos_a);
	void SetText(char text_name[]);
	void SetAll();
	//次の画像を表示する関数
	void NextStory(char story_name[][1024],int sub, rect_pos_size values);
	//次のテキストを表示する関数
	void NextText(char text_name[][1024]);
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
	void RectUp();
};

/*
２０１９/3/11 ストーリーシーンクラス　作成　松川
紙芝居の座標・サイズ設定関数
テキストボックスの座標・サイズ設定関数
テキストの座標・サイズ設定関数
追加
*/