#include "ItemBox.h"
#include"AnimItemBox.h"
#include "../Resource/Resource.h"

ItemBox::ItemBox(int _m_box_typ, CVector2D _m_pos) :Task(eItemBox),
m_pos(_m_pos),
m_box_typ(_m_box_typ)
{
	m_img = COPY_RESOURCE("ItemBox", CAnimImage*);
	switch (m_box_typ)
	{
	case eTrueBox:
		m_img.ChangeAnimation(AnimItemBox::eTrueBoxClose);
		//m_img.ChangeAnimation(AnimItemBox::eTrueBoxOpen);
		break;
	case eDummyBox:
		m_img.ChangeAnimation(AnimItemBox::eDummyBoxClose);
		//m_img.ChangeAnimation(AnimItemBox::eDummyBoxOpen);
		break;
	default:
		break;
	}
}

void ItemBox::Update()
{
	
	m_img.UpdateAnimation();
}

void ItemBox::Draw()
{
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	m_img.SetPos(m_pos);
	m_img.Draw();
}

ItemBox::~ItemBox()
{
}
