#pragma once
#include "../../Base/Task.h"
#include "../../Game/Scene/GameScene.h"
#include "../../Game/Resource/Resource.h"

class Title : public Task {
private:
    //画像データ
    CImage m_img_back;
    CImage m_img_rogobase;
    CImage m_img_rogoclear;
    CImage m_img_ohuda;
    CImage m_img_pushstart;
    //各位置
    CVector2D m_title_pos;
    CVector2D m_rogo_pos;
    CVector2D m_ohuda_pos;
    CVector2D m_start_pos;
    int m_cnt;//カウント
    float m_size;//rogoclearのサイズ変量
    float m_time;//お札の回転値
public:
    Title();
    ~Title();
    void Update();
    void Draw();
};