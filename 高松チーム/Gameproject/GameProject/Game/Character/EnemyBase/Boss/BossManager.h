#pragma once
#include "../GameProject/Base/Task.h"

class BossManager : public Task {
private:
	enum {
		eNothing,
		eIdle,
		eAttack,
	};

	CAnimImage m_img; //��
	CImage m_img2;//�E��ʂ�����ق�
	CImage m_img3;//����
	CAnimImage m_img4;//�K��

	CVector2D m_pos; //���̍��W
	CVector2D m_pos2;//�E��̍��W
	CVector2D m_pos3;//����̍��W
	CVector2D m_pos4;//�K���̍��W
	CVector2D m_center;
	CVector2D m_center2;

	int m_state;

	float m_rot;//�~����
	float m_rot2;//�~����
	float m_r;  //���a

	bool Idle_flag;
	bool Attack_flag;

public:

	BossManager();

	void Update();

	void Draw();
};
