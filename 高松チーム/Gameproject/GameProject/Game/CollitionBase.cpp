#include "CollitionBase.h"
#include"../Game/Character/EnemyBase/EnemyBase.h"
#include "../GameProject/Game/GameData/GameData.h"

CollitionBase::CollitionBase()
{
}

void CollitionBase::Update()
{
}

bool CollitionBase::CollisionCheckRect(Task * b1, int _type)
{
	Task* b2 = TaskManager::GetInstance()->GetHead();
	if(b2 == b1)
		b2 = b2->GetNext();
	while (b2) {
		if (b2->GetType() == _type)
		{
			
			CRect r1 = CRect(
				b1->GetPos().x + b1->GetRect().m_left,
				b1->GetPos().y + b1->GetRect().m_top,
				b1->GetPos().x + b1->GetRect().m_right,
				b1->GetPos().y + b1->GetRect().m_bottom);

			/*CRect((b1->GetPos().x + b1->GetRect().m_left) - g_game_data.m_scroll.x,
				(b1->GetPos().y + b1->GetRect().m_top) - g_game_data.m_scroll.y,
				(b1->GetPos().x + b1->GetRect().m_right) - g_game_data.m_scroll.x,
				(b1->GetPos().y + b1->GetRect().m_bottom) - g_game_data.m_scroll.y);*/

			
			CRect r2 = CRect(
				b2->GetPos().x + b2->GetRect().m_left,
				b2->GetPos().y + b2->GetRect().m_top,
				b2->GetPos().x + b2->GetRect().m_right,
				b2->GetPos().y + b2->GetRect().m_bottom);

				/*CRect((b2->GetPos().x + b2->GetRect().m_left) - g_game_data.m_scroll.x,
				(b2->GetPos().y + b2->GetRect().m_top) - g_game_data.m_scroll.y,
					(b2->GetPos().x + b2->GetRect().m_right) - g_game_data.m_scroll.x,
					(b2->GetPos().y + b2->GetRect().m_bottom) - g_game_data.m_scroll.y);*/
		
#ifdef _DEBUG//デバッグ表示　見れない場合は背景をなくしてください
			Utility::DrawQuad(CVector2D(r1.m_left, r1.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r1.m_left, r1.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r1.m_right, r1.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r1.m_right, r1.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			
			Utility::DrawQuad(CVector2D(r2.m_left, r2.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r2.m_left, r2.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r2.m_right, r2.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r2.m_right, r2.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif // _DEBUG

			if (CCollision::CollisionRect(r1, r2))
				return true;
			else b2 = b2->GetNext();
		}
		else
			b2 = b2->GetNext();

		if (b2 == b1)
			b2 = b2->GetNext();
	}

	return false;
	
}

bool CollitionBase::CollisionCheckPoint(Task * b1, int _type)
{
    Task* b2 = TaskManager::GetInstance()->GetHead();
    if (b2 == b1)
        b2 = b2->GetNext();
    while (b2) {
        if (b2->GetType() == _type)
        {

            CRect r2 = CRect(
                b2->GetPos().x + b2->GetRect().m_left,
                b2->GetPos().y + b2->GetRect().m_top,
                b2->GetPos().x + b2->GetRect().m_right,
                b2->GetPos().y + b2->GetRect().m_bottom);

            CVector2D b1_pos = b1->GetPos();
            b1_pos = CVector2D(b1_pos.x, b1_pos.y + b1->GetRect().m_bottom);


            if (CCollision::CollisionRectPoint(r2, b1_pos))
                return true;
            else b2 = b2->GetNext();
        }
        else
            b2 = b2->GetNext();

        if (b2 == b1)
            b2 = b2->GetNext();
    }

    return false;

}

Task * CollitionBase::GetCollisionCheckRect(Task * b1, int _type)
{
	Task* b2 = TaskManager::GetInstance()->GetHead();
	if (b2 == b1)
		b2 = b2->GetNext();
	while (b2) {
		if (b2->GetType() == _type)
		{

			CRect r1 = CRect(
				b1->GetPos().x + b1->GetRect().m_left,
				b1->GetPos().y + b1->GetRect().m_top,
				b1->GetPos().x + b1->GetRect().m_right,
				b1->GetPos().y + b1->GetRect().m_bottom);


			CRect r2 = CRect(
				b2->GetPos().x + b2->GetRect().m_left,
				b2->GetPos().y + b2->GetRect().m_top,
				b2->GetPos().x + b2->GetRect().m_right,
				b2->GetPos().y + b2->GetRect().m_bottom);

#ifdef _DEBUG//デバッグ表示　見れない場合は背景をなくしてください
			Utility::DrawQuad(CVector2D(r1.m_left, r1.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r1.m_left, r1.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r1.m_right, r1.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r1.m_right, r1.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));

			Utility::DrawQuad(CVector2D(r2.m_left, r2.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r2.m_left, r2.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r2.m_right, r2.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
			Utility::DrawQuad(CVector2D(r2.m_right, r2.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif // _DEBUG

			if (CCollision::CollisionRect(r1, r2))
				return b2;
			else b2 = b2->GetNext();
		}
		else
			b2 = b2->GetNext();

		if (b2 == b1)
			b2 = b2->GetNext();
	}

	return nullptr;
}

bool CollitionBase::CollitionCheckflip(int fliptype, Task * b1, Task * b2)
{
	/*switch (fliptype)
	{
	case 0:
		if (b1->m_pos.x < b2->m_pos.x) return true;
		else return false;
		break;

	case 1:
		if (b1->m_pos.x > b2->m_pos.x) return true;
		else return false;
		break;

	case 2:
		if (b1->m_pos.y > b2->m_pos.y) return true;
		else return false;
		break;

	case 3:
		if (b1->m_pos.y < b2->m_pos.y) return true;
		else return false;
		break;

	default:
		break;
	}
	*/
	return false;
}
