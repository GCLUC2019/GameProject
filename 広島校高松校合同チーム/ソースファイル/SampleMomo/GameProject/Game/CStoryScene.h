#pragma once
#include "CObject.h"
#include "../Global.h"

//�Y����
#define SUB0 0
#define SUB1 1
#define SUB2 2
#define SUB3 3
#define SUB4 4
#define SUB5 5

//���ŋ��T�C�Y�ƍ��W
#define STORY_SIZE  CVector2D(1000,600)
#define STORY_POSISHON  CVector2D(140,20)
//�e�L�X�g�{�b�N�X�T�C�Y�ƍ��W
#define BOX_SIZE CVector2D(1100,70)
#define BOX_POSISHON CVector2D(100, 630)
//�e�L�X�g�T�C�Y�ƍ��W�y�я����؂���T�C�Y
#define TEXT_SIZE CVector2D(1100,70)
#define TEXT_POSISHON CVector2D(130, 635)
#define TEXT_DEF_SIZE CVector2D(30,50)
//�e�L�X�g�؂���T�C�Y
#define RECTSIZE_X 30
#define RECTSIZE_Y 40
//�A�C�R���T�C�Y�ƍ��W
#define ICON_POSISHON CVector2D(1100,660)
#define ICON_SIZE CVector2D(30,30)
//�T�C�Y�ŏ��l
#define MIN 0
//�T�C�Y�ő�l
#define MAX_X 4093
#define MAX_Y 2894
//�\���T�C�Y�ŏ��l�ƍő�l
#define DRAW_MAX_X 1020
#define DRAW_MAX_Y 600
//�\���ʒu�̍ő�l�ƍŏ��l
#define POS_MAX_X 750
#define POS_MAX_Y 300
#define POS_MIN_X 130
#define POS_MIN_Y 20

class CStoryScene : public CObject {
protected:
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
	int num_decison;

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
	char name[2][80];
	char t_name[6][80];
public:
	CStoryScene();
	~CStoryScene();
	virtual void Update();
	virtual void Draw();
	void SetParam();
	void SetSubSentense(int sent);
	void SetTextBox();
	void SetIcon();
	void SetStory(char story_name[], rect_pos_size values);
	void SetStory2(rect_pos_size pos_a);
	void SetText(char text_name[]);
	void SetArrayValue(int num_array[]);
	void SetSentense(int repite, char name_a[][80], char name_b[][80]);
	void SetAll();
	//���̉摜��\������֐�
	void NextStory(char story_name[][80],int sub, rect_pos_size values);
	//���̃e�L�X�g��\������֐�
	void NextText(char text_name[][80]);
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
	//�`�ʊ֘A�܂Ƃߊ֐�
	void AllDraw();
	void RectUp();
};

/*
�Q�O�P�X/3/11 �X�g�[���[�V�[���N���X�@�쐬�@����
���ŋ��̍��W�E�T�C�Y�ݒ�֐�
�e�L�X�g�{�b�N�X�̍��W�E�T�C�Y�ݒ�֐�
�e�L�X�g�̍��W�E�T�C�Y�ݒ�֐�
�ǉ�
*/