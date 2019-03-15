#pragma once
#include"../../Base/Task.h"

enum ItemList  
{
	eKoban,
	eInari,
	eKakera,
	eHyoutan,
};

class Item : public Task {
	
	int m_item_type;
	CImage m_img;
	CVector2D m_pos;
	CRect m_rect;
public:
	/*
	@param _m_item_type	[in]作るアイテムの種類
	@param  _m_pos		[in]座標
	*/
	Item(int _m_item_type,CVector2D _m_pos);
	void Update();
	void Draw();
<<<<<<< HEAD
=======
	void HitCheck(/*Task* _t*/);
	 CVector2D GetPos() {
		 return m_pos;
	}
	 CRect GetRect() {
		 return m_rect;
	 }
>>>>>>> 7b7833fccc61631035d5b5e9c0ad3425b18ce63d
};