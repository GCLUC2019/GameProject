#include "CDropItem.h"
#include "../Global.h"

CDropItem::CDropItem(int _item_id,CImage* _image_p):CObject(eTaskIdDropItem)
{
	m_item_id = _item_id;
	m_item_image_p = _image_p;
	SetDrawPriority(5000);
}

CDropItem::~CDropItem()
{
}

void CDropItem::Update()
{
}

void CDropItem::AfterUpdate()
{
}

void CDropItem::Gravity()
{
}

void CDropItem::BeforeCollisionCheck()
{
}

void CDropItem::BeforeUpdate()
{
}

void CDropItem::Draw()
{
	if (m_item_image_p == nullptr) return;
	m_item_image_p->SetFlipH(m_is_flip);
	m_item_image_p->SetSize(m_size.x, m_size.y);
	m_item_image_p->SetCenter(m_size.x / 2.0, m_size.y / 2.0);
	CVector2D draw_pos = CVector2D(m_pos.x, m_pos.y + m_pos.z) - GetScroll();
	m_item_image_p->SetPos(draw_pos);
	m_item_image_p->Draw();

	//CVector2D draw_adj = m_draw_adj;
	//if (m_is_flip == true) draw_adj.x *= -1.0f;

	//m_anim_image_p[m_play_anim_image]->SetPos(draw_pos + draw_adj);
	//m_anim_image_p[m_play_anim_image]->SetCenter(m_size.x / 2.0, m_size.y / 2.0);
	//m_anim_image_p[m_play_anim_image]->Draw();
}

void CDropItem::CollisionCheck(Task * _collision_task)
{
}
