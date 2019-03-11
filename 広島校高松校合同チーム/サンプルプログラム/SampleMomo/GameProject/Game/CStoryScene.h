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

	char name[1024];
	char t_name[3][1024];
public:
	CStoryScene();
	~CStoryScene();
	void Update();
	void Draw();
	void SetParam();
	void SetTextBox();
	void SetIcon();
	void SetStory(char story_name[], rect_pos_size pos_a);
	void SetText(char text_name[]);
	void SetAll();
	//次のテキストを表示する関数
	void NextText(char text_name[][1024]);
	//表示したい文章の文字数と文章数
	void UpdateText(int word,int limit);
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