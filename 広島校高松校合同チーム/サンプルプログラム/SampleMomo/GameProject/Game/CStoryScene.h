#pragma once
#include "CObject.h"
#include "../Global.h"

class CStoryScene : public CObject {
private:
	CImage m_s_img;
	CImage m_text_box;
	CImage m_text;
	CImage m_icon;
	int rect_cnt;
	int dis_cnt;
	int lim;
	int sentence_num;
	int draw_cnt;
	int subscript;

	struct rect_pos_size {
		int top_x;
		int top_y;
		int bottom_x;
		int bottom_y;
		CVector2D size;
		CVector2D pos;
	};
	
	rect_pos_size pos_array[5];

	bool complete_flg;

	char name[2][1024];
	char t_name[6][1024];
public:
	CStoryScene();
	~CStoryScene();
	void Update();
	void Draw();
	void SetParam();
	void SetTextBox();
	void SetIcon();
	void SetStory(char story_name[], rect_pos_size values);
	void SetStory2(rect_pos_size pos_a);
	void SetText(char text_name[]);
	void SetAll();
	//���̉摜��\������֐�
	void NextStory(char story_name[][1024],int sub, rect_pos_size values);
	//���̃e�L�X�g��\������֐�
	void NextText(char text_name[][1024]);
	//�\�����������͂̕������ƕ��͐�
	void UpdateText(int word,int limit);
	//���݂̍\���̂Ǝ��̍\����
	void UpdateStory(rect_pos_size& pos_now,rect_pos_size& pos_next);
	//�ύX�܂Ƃߊ֐�
	void ChangeAll(rect_pos_size& pos_a, rect_pos_size& pos_b);
	//�؂���ʒu�ύX�֐�(�����͌��݂Ǝ��̒l�ƕω��l�j
	int ChangeRect(int& now, int& next);
	//���W�y�уT�C�Y�ύX�֐�
	CVector2D ChangeVector(CVector2D& now, CVector2D& next);
	//�A�C�R����_�ł����ĕ\������
	void IconDraw();
	void RectUp();
};

/*
�Q�O�P�X/3/11 �X�g�[���[�V�[���N���X�@�쐬�@����
���ŋ��̍��W�E�T�C�Y�ݒ�֐�
�e�L�X�g�{�b�N�X�̍��W�E�T�C�Y�ݒ�֐�
�e�L�X�g�̍��W�E�T�C�Y�ݒ�֐�
�ǉ�
*/