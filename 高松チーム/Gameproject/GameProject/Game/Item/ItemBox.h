#pragma once
#include"../../Base/Task.h"

enum Box_Typ {
	eTrueBox,
	eDummyBox,
};

class ItemBox :public Task{
<<<<<<< HEAD
	CAnimImage m_img;
	CVector2D m_pos;
	int m_box_typ;
	
=======
	CAnimImage m_img;	//�摜
	CVector2D m_pos;	//���W
	int m_box_typ;		//���̎��
	bool m_open_flg;	//���̊J���
	int m_time;
	CRect m_rect;
>>>>>>> 7b7833fccc61631035d5b5e9c0ad3425b18ce63d
public:
	/*
	@param _m_box_typ	[in]���A�C�e���̎��
	@param  _m_pos		[in]���W
	*/
	ItemBox(int _m_box_typ, CVector2D _m_pos);
	void Update();
	void HitCheck(/*Task* _t*/);
	void Draw();
	~ItemBox();
<<<<<<< HEAD


=======
	CVector2D GetPos() {
		return m_pos;
	}
	CRect GetRect() {
		return m_rect;
	}
>>>>>>> 7b7833fccc61631035d5b5e9c0ad3425b18ce63d
};