#pragma once
#include "CStoryScene.h"

//�I�[�v�j���O�̃e�L�X�g��
#define OPENING_SENTENSE_NUM 6

//�摜�؂���T�C�Y�̏����l�ƕϓ��l
#define DEF_SIZE_TOP_X 2500
#define CHANGE_SIZE_TOP_X 1650
#define CHANGE_SIZE_BOTTOM_X 2600
#define CHANGE_SIZE_BOTTOM_Y 1550
#define CHANGE_SIZE_TOP_X2 550
#define CHANGE_SIZE_TOP_Y2 1500
#define CHANGE_SIZE_BOTTOM_X2 2800
#define CHANGE_SIZE_BOTTOM_X3 1650
//�摜�T�C�Y�̏����l�ƕϓ��l
#define DEF_SIZE_X 400
#define DEF_SIZE_Y 600
#define CHANGE_SIZE_X 300
#define CHANGE_SIZE_Y 350
#define CHANGE_SIZE_X2 500
#define CHANGE_SIZE_Y2 300
#define CHANGE_SIZE_X3 400
#define CHANGE_SIZE_Y3 600
#define CHANGE_SIZE_BOTTOM_X3 1650
//�\���ʒu�̕ϓ��l
#define CHANGE_POS_X  450
#define CHANGE_POS_X2 250


class CStorySceneOpening:public CStoryScene
{
public:
	CStorySceneOpening();
	~CStorySceneOpening();
    void Update();
    void Draw();
	void AddRAll();
	void Setchar();
	void SetValue();
};


