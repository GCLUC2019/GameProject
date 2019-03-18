#include "ItemBox.h"
#include"AnimItemBox.h"
#include "../Resource/Resource.h"
#include "Item.h"

ItemBox::ItemBox(int _m_box_typ, CVector2D _m_pos) :Task(CharacterData::eItemBox),
m_pos(_m_pos),
<<<<<<< HEAD
m_box_typ(_m_box_typ)
=======
m_box_typ(_m_box_typ),
m_time(0)

>>>>>>> 7b7833fccc61631035d5b5e9c0ad3425b18ce63d
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
<<<<<<< HEAD
		//m_img.ChangeAnimation(AnimItemBox::eDummyBoxOpen);
=======
>>>>>>> 7b7833fccc61631035d5b5e9c0ad3425b18ce63d
		break;
	default:
		break;
	}
}

void ItemBox::Update()
{
	
	m_img.UpdateAnimation();
}

<<<<<<< HEAD
=======
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
>>>>>>> 7b7833fccc61631035d5b5e9c0ad3425b18ce63d
void ItemBox::Draw()
{
	m_img.SetSize(200, 200);
	m_img.SetCenter(100, 100);
	m_img.SetPos(m_pos);
	m_img.Draw();
}

ItemBox::~ItemBox()
{
	int k = 0;
	k = Utility::Rand(20, 30);
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
