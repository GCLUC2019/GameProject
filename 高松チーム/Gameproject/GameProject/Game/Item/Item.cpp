#include "Item.h"
#include "../Character/CharacterBase.h"
#include "../Character/Player.h"

Item::Item(int _m_item_type, CVector2D _m_pos) : Task(eItem),
m_item_type(_m_item_type),
m_pos(_m_pos)
{
	/*m_item_type = _m_item_type;
	m_pos = _m_pos;*/

	switch (m_item_type)
	{
	case eKoban:
		m_img = COPY_RESOURCE("PEffectLongAttack", CImage*);
		m_img.SetRect(0, 320, 32, 352);
		m_img.SetPos(m_pos);
		m_img.SetSize(20, 20);
		m_img.SetCenter(10, 10);
		break;
	case eInari:
		m_img = COPY_RESOURCE("PEffectLongAttack", CImage*);
		m_img.SetRect(0, 256, 64, 320);
		m_img.SetPos(m_pos);
		m_img.SetSize(40, 40);
		m_img.SetCenter(20, 20);
		break;
	case eKakera:
		m_img = COPY_RESOURCE("Kakera", CImage*);
		m_img.SetPos(m_pos);
		m_img.SetSize(50, 50);
		m_img.SetCenter(25, 25);
		break;
	case eHyoutan:
		m_img = COPY_RESOURCE("PEffectLongAttack", CImage*);
		m_img.SetRect(64, 256, 128, 320);
		m_img.SetPos(m_pos);
		m_img.SetSize(40, 40);
		m_img.SetCenter(20, 20);
		break;
	default:
		break;
	}

}

void Item::Update()
{
	Task* p = TaskManager::GetInstance()->FindObject(ePlayer);
	if (p == nullptr) 
		return;

	return;
}

void Item::Draw()
{
	m_img.Draw();
}
