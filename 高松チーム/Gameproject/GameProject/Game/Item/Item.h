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
public:
	/*
	@param _m_item_type	[in]���A�C�e���̎��
	@param  _m_pos		[in]���W
	*/
	Item(int _m_item_type,CVector2D _m_pos);
	void Update();
	void Draw();
	 CVector2D GetPos() {
		 return m_pos;
	}
};