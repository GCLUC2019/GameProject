#include "CollisionBox.h"
#include "../../Game/GameData/GameData.h"
CollisionBox::CollisionBox(const CVector2D &_pos, const CRect &_rect):Task(eCollisionBox)
{
    m_pos = _pos;
    m_rect = _rect;
}

void CollisionBox::Update()
{
}

void CollisionBox::Draw()
{
    m_rect = CRect(m_rect.m_left, m_rect.m_top + g_game_data.m_scroll.y, m_rect.m_right, m_rect.m_bottom + g_game_data.m_scroll.y);
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
