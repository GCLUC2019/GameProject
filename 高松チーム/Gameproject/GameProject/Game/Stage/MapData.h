#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/Base/TaskManager.h"
#include "../CollitionBase.h"
class MapData :public Task {
private:
    CVector2D m_pos;
    CRect m_rect;
public:
    MapData();
    void Update();
    void Draw();
    CVector2D GetPos() {
        return m_pos;
    }
    CRect GetRect() {
        return m_rect;
    }
};