#pragma once
#include"../../Base/Task.h"

enum Box_Typ {
	eTrueBox,
	eDummyBox,
};

class ItemBox :public Task{
	CAnimImage m_img;
	CVector2D m_pos;
	int m_box_typ;
	
public:
	/*
	@param _m_box_typ	[in]作るアイテムの種類
	@param  _m_pos		[in]座標
	*/
	ItemBox(int _m_box_typ, CVector2D _m_pos);
	void Update();
	void Draw();
	~ItemBox();


};