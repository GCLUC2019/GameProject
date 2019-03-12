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
	@brief �@			�_���[�W�֐�
	@param _damage	[in]�^����_���[�W
	*/
	Item(int _m_item_type,CVector2D _m_pos);
	void Update();
	void Draw();
};