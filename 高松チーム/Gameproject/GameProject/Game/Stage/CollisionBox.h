#pragma once
#include "../../Base/Task.h"
#include "../CollitionBase.h"
/*
担当
田中  class CollisionBox　
*/
//当たり判定を持たせるだけのクラス
class CollisionBox :public Task {
protected:
    CVector2D m_pos;
    CRect m_rect;
public:
    CollisionBox(const CVector2D &_pos, const CRect &_rect);
    void Update();
    void Draw();
    void HitCheck();

    int GetType() { return m_type; }
    float GetDepth() { return m_depth; }

    CVector2D GetPos() {
        return  m_pos;
    }
    CRect GetRect() {
        return m_rect;
    }
};