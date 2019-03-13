#pragma once
#include "../GameProject/Base/Task.h"

class BossManager : public Task {
private:
	enum {
		eNothing,
		eIdle,
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
	CVector2D m_pos5;//�K���̍��W
	CVector2D m_center;
	CVector2D m_center2;

	int m_state;//�{�X�̏��
	int m_boss_hp;//�{�X�̗̑�

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
