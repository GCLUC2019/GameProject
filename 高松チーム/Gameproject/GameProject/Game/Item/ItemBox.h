#pragma once
#include"../../Base/Task.h"

static enum Box_Typ {
	eTrueBox,
	eDummyBox,
};

class ItemBox :public Task{
	CAnimImage m_img;	//�摜
	CVector2D m_pos;	//���W
	int m_box_typ;		//���̎��
	bool m_open_flg;	//���̊J���
	int m_time;
public:
	/*
	@param _m_box_typ	[in]���A�C�e���̎��
	@param  _m_pos		[in]���W
	*/
	ItemBox(int _m_box_typ, CVector2D _m_pos);
	void Open();
	void Update();
	void Draw();
	~ItemBox();


};