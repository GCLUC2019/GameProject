#pragma once
#include "../../Base/Task.h"
#include "../CollitionBase.h"

class CollisionBox :public Task {
private:
    CVector2D m_pos;
    CRect m_rect;
public:
    CollisionBox(CVector2D _pos, CRect _rect);
    void Update();
    void Draw();
    void HitCheck();
    int GetType() { return m_type; }
    float GetDepth() { return m_depth; }
    CVector2D GetPos() {
        return  CVector2D(-1, -1);
    }
    CRect GetRect() {
        return CRect(0, 0, 0, 0);
    }
};