#include "CDropItem.h"
#include "../Global.h"

CDropItem::CDropItem(int _item_id):CGameSceneObject(eTaskIdDropItem)
{
	m_item_id = _item_id;
	switch (_item_id) {
	case eItemIdSpear:
		m_anim_image_p[eItemAnimStatic0] = GET_RESOURCE("IconSpear", CImage*);
		m_anim_info[eItemAnimIdStatic].image_num = 1;
		m_anim_info[eItemAnimIdStatic].image_id = eItemAnimStatic0;
		m_anim_info[eItemAnimIdStatic].delay = 10;
		break;
	}
}

CDropItem::~CDropItem()
{
}

void CDropItem::GameSceneObjectUpdate()
{
	SetWillPlayAnim(eItemAnimIdStatic);
}

void CDropItem::GameSceneObjectAfterUpdate()
{
}


void CDropItem::GameSceneObjectBeforeCollisionCheck()
{
}

void CDropItem::GameSceneObjectBeforeUpdate()
{
}

void CDropItem::GameSceneObjectDraw()
{
	/*
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
	*/
}

void CDropItem::GameSceneObjectCollisionCheck(Task * _collision_task)
{
}
