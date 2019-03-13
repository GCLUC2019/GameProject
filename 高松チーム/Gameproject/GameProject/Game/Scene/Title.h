#pragma once
#include "../../Base/Task.h"
#include "../../Game/Resource/Resource.h"

class Title : public Task {
private:
    CImage m_img_back;
    CImage m_img_rogo;
    CVector2D m_pos;
public:
    Title();
    void Update();
    void Draw();
};