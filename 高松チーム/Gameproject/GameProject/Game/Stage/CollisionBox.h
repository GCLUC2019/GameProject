#pragma once
#include "../../Base/Task.h"
#include "../CollitionBase.h"

class CollisionBox :public Task {
private:
    CVector2D m_pos;
    CRect m_rect;
public:
    CollisionBox();
    void Update();
    void Draw();

};