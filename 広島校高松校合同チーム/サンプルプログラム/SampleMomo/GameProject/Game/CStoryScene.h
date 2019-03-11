#pragma once
#include "CObject.h"
#include "../Global.h"

class CStoryScene : public CObject {
private:
	CImage m_s_img;
	CImage m_text_box;
	CImage m_text;
	int rect_cnt;
	int dis_cnt = 0;
public:
	CStoryScene();
	~CStoryScene();
	void Update();
	void Draw();
	void SetTextBox();
	void SetStory(char story_name[]);
	void SetText(char text_name[]);
	//�\�����������͂̕�����
	void UpdateText(int word);
};

/*
�Q�O�P�X/3/11 �X�g�[���[�V�[���N���X�@�쐬�@����
���ŋ��̍��W�E�T�C�Y�ݒ�֐�
�e�L�X�g�{�b�N�X�̍��W�E�T�C�Y�ݒ�֐�
�e�L�X�g�̍��W�E�T�C�Y�ݒ�֐�
�ǉ�
*/