#include "ItemBox.h"
#include"AnimItemBox.h"
#include "../Resource/Resource.h"

ItemBox::ItemBox(int _m_box_typ, CVector2D _m_pos) :Task(eItemBox),
m_pos(_m_pos),
m_box_typ(_m_box_typ),
m_time(0)

{
	m_rect = CRect(-50, -50, 50, 50);
	m_img = COPY_RESOURCE("ItemBox", CAnimImage*);
	switch (m_box_typ)
	{
	case eTrueBox:
		m_img.ChangeAnimation(AnimItemBox::eTrueBoxClose);
		//m_img.ChangeAnimation(AnimItemBox::eTrueBoxOpen);
		break;
	case eDummyBox:
		m_img.ChangeAnimation(AnimItemBox::eDummyBoxClose);
		//m_img.ChangeAnimation(AnimItemBox::eDummyBoxOpen01);
		break;
	default:
		break;
	}
}

void ItemBox::Open()
{
	
	switch (m_box_typ)
	{
	case eTrueBox:
		m_img.ChangeAnimation(AnimItemBox::eTrueBoxOpen);
		if (m_time >= 120)
			SetKill();
		break;
	case eDummyBox:
		if (m_time == 0)
			m_img.ChangeAnimation(AnimItemBox::eDummyBoxOpen01);
		if (m_time == 20)
			m_img.ChangeAnimation(AnimItemBox::eDummyBoxOpen02);
		if (m_time >= 180)
			SetKill();
		break;
	default:
		break;
	}
	
	
	m_time++;
	
}

void ItemBox::Update()
{
	if (m_open_flg)
		Open();
#ifdef _DEBUG
	if (CInput::GetState(0, CInput::eHold, CInput::eMouseR))
		m_open_flg = true;
#endif

}
void ItemBox::HitCheck()
{
}
void ItemBox::Draw()
{
	m_img.UpdateAnimation();
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	m_img.SetPos(m_pos);
	m_img.Draw();
}

ItemBox::~ItemBox()
{
}
