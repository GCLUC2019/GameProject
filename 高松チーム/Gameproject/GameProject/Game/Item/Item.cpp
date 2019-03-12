#include "Item.h"

Item::Item(int _m_item_type, CVector2D _m_pos) : Task(eItem),
m_item_type(_m_item_type),
m_pos(_m_pos)
{
	/*m_item_type = _m_item_type;
	m_pos = _m_pos;*/

	switch (m_item_type)
	{
	case eKoban:
		m_img = COPY_RESOURCE("Kakera", CImage*);
		//m_img.SetRect(50, 50, 100, 100);
		m_img.SetPos(m_pos);
		m_img.SetSize(30, 30);
		m_img.SetCenter(15, 15);
		break;
	case eInari:
		//m_img = COPY_RESOURCE("PEffectLongAttack", CImage*);
		
		m_img = COPY_RESOURCE("Kakera", CImage*);
		//m_img.SetRect(50, 50, 100, 100);
		m_img.SetPos(m_pos);
		m_img.SetSize(30, 30);
		m_img.SetCenter(15, 15);
		break;
	case eKakera:
		m_img = COPY_RESOURCE("Kakera", CImage*);
		//m_img.SetRect(50, 50, 100, 100);
		m_img.SetPos(m_pos);
		m_img.SetSize(30, 30);
		m_img.SetCenter(15, 15);
		break;
	case eHyoutan:
		m_img = COPY_RESOURCE("Kakera", CImage*);
		//m_img.SetRect(50, 50, 100, 100);
		m_img.SetPos(m_pos);
		m_img.SetSize(30, 30);
		m_img.SetCenter(15, 15);
		break;
	default:
		break;
	}

}

void Item::Update()
{
}

void Item::Draw()
{
	m_img.Draw();
}
