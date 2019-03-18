#include "CollisionBox.h"

CollisionBox::CollisionBox(CVector2D _pos, CRect _rect):Task(eCollisionBox),
m_pos(_pos),
m_rect(_rect)
{

}

void CollisionBox::Update()
{

}

void CollisionBox::Draw()
{
#ifdef _DEBUG//デバッグ表示　見れない場合は背景をなくしてください
    Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
    Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
    Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
    Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif//DEBUG
}

void CollisionBox::HitCheck()
{
}
