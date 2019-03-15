#include "MapData.h"

MapData::MapData():Task(eMap)
{
    m_pos = CVector2D(640, 360);
    m_rect = CRect(-50, -1, 50, 1);
}

void MapData::Update()
{
}

void MapData::Draw()
{
#ifdef _DEBUG//デバッグ表示　見れない場合は背景をなくしてください
    Utility::DrawQuad(CVector2D(m_rect.m_left, m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
    Utility::DrawQuad(CVector2D(m_rect.m_left, m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
    Utility::DrawQuad(CVector2D(m_rect.m_right, m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
    Utility::DrawQuad(CVector2D(m_rect.m_right, m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));

#endif // _DEBUG
}
