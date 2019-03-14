#pragma once
#include"../../Base/Task.h"

static enum Box_Typ {
	eTrueBox,
	eDummyBox,
};

class ItemBox :public Task{
	CAnimImage m_img;	//画像
	CVector2D m_pos;	//座標
	int m_box_typ;		//箱の種類
	bool m_open_flg;	//箱の開閉状態
	int m_time;
public:
	/*
	@param _m_box_typ	[in]作るアイテムの種類
	@param  _m_pos		[in]座標
	*/
	ItemBox(int _m_box_typ, CVector2D _m_pos);
	void Open();
	void Update();
	void Draw();
	~ItemBox();


};