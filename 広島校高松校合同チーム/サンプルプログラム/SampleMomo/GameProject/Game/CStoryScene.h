#pragma once
#include "CObject.h"
#include "../Global.h"

class CStoryScene : public CObject {
private:
	CImage m_s_img;
	CImage m_text_box;
	CImage m_text;
	int rect_cnt;
	int dis_cnt = 0;
public:
	CStoryScene();
	~CStoryScene();
	void Update();
	void Draw();
	void SetTextBox();
	void SetStory(char story_name[]);
	void SetText(char text_name[]);
	//表示したい文章の文字数
	void UpdateText(int word);
};

/*
２０１９/3/11 ストーリーシーンクラス　作成　松川
紙芝居の座標・サイズ設定関数
テキストボックスの座標・サイズ設定関数
テキストの座標・サイズ設定関数
追加
*/