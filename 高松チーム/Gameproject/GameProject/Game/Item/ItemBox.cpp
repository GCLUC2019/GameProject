#include "ItemBox.h"
#include"AnimItemBox.h"
#include "../Resource/Resource.h"
#include "Item.h"
#include"../GameData/GameData.h"
#include"../CollitionBase.h"
ItemBox::ItemBox(int _m_box_typ, CVector2D _m_pos) :Task(CharacterData::eItemBox),
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
		break;
	case eDummyBox:
		m_img.ChangeAnimation(AnimItemBox::eDummyBoxClose);
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
	if (CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack01, 50.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack02, 50.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack03, 50.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectLongAttack, 50.0f))
	{
		m_open_flg = true;
	}

}
void ItemBox::Draw()
{
	m_img.UpdateAnimation();
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 150);
	m_img.SetPos(m_pos - CVector2D(0, g_game_data.m_scroll.y / 3));
	m_img.Draw();
}

ItemBox::~ItemBox()
{
	if (TaskManager::GetInstance()->FindObject(CharacterData::eGameTitle) != nullptr) {
		return;
	}

	int k = 0;
	k = Utility::Rand(15, 20);
	switch (m_box_typ)
	{
	case Box_Typ::eDummyBox:
		break;
	case Box_Typ::eTrueBox:

		for (k ; k > 0; k--) {
			TaskManager::GetInstance()->AddTask(new Item(ItemList::eKoban, m_pos + CVector2D(Utility::Rand(-50, 50), Utility::Rand(-50, 50))));
		}
		TaskManager::GetInstance()->AddTask(new Item(Random(ItemList::eInari,ItemList::eHyoutan), m_pos + CVector2D(Utility::Rand(-50, 50), Utility::Rand(-50, 50))));
		break;
	default:
		break;
	}
}
