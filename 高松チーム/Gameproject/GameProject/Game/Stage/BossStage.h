#pragma once
#include "../../Base/Task.h"

class BossStage :public Task {
private:
    CImage m_img;
protected:
    CVector2D m_pos;
public:
    BossStage();
    void Update();
    void Draw();
    /*CVector2D GetPos() const {
        return m_pos;
    }*/
};