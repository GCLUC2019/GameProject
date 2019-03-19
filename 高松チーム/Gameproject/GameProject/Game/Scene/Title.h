#pragma once
#include "../../Base/Task.h"
#include "../../Game/Scene/GameScene.h"
#include "../../Game/Resource/Resource.h"
/*
�S��
�c��  class Title
*/
class Title : public Task {
private:
    //�摜�f�[�^
    CImage m_img_back;
    CImage m_img_rogobase;
    CImage m_img_rogoclear;
    CImage m_img_ohuda;
    CImage m_img_pushstart;
    //�e�ʒu
    CVector2D m_title_pos;
    CVector2D m_rogo_pos;
    CVector2D m_ohuda_pos;
    CVector2D m_start_pos;
    int m_cnt;//�J�E���g
    float m_size;//rogoclear�̃T�C�Y�ϗ�
    float m_time;//���D�̉�]�l
public:
    Title();
    ~Title();
    void Update();
    void Draw();
};