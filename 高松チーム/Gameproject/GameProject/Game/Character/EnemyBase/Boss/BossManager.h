#pragma once
#include "../GameProject/Base/Task.h"


/*
   �쐬�ҁ@�Ԟ�
   �}�l�[�W���[�őҋ@��Ԃ��Ǘ�����
*/
class BossManager : public Task {
private:
	enum {
		eIdle,
		eNothing,
		eAttack,
		eDeath,
	};

	CAnimImage m_img; //��
	CImage m_img2;//�E��ʂ�����ق�
	CImage m_img3;//����
	CAnimImage m_img4;//�K��

	CImage m_img5;//���ꂽ�Ƃ��̉摜

	CVector2D m_pos; //���̍��W
	CVector2D m_pos2;//�E��̍��W
	CVector2D m_pos3;//����̍��W
	CVector2D m_pos4;//�K���̍��W
	CVector2D m_pos5;//
	CVector2D m_center;
	CVector2D m_center2;
	CVector2D m_player_pos;

	int m_state;//�{�X�̏��
	int m_boss_attack_type;//�{�X�̍U�������ނ�ԍ��ŐU�蕪����
	int m_boss_hp;//�{�X�̗̑�
	int m_idle_cnt;//�ҋ@��Ԃł��鎞��

	float m_rot;//�~����
	float m_rot2;//�~����
	float m_r;  //���a

	bool m_idle_flag;
	bool m_attack_flag;
	bool m_death_flag;

public:

	BossManager();

	void Idle();

	void Attack();

	void Death();

	void Update();

	void Draw();
};
