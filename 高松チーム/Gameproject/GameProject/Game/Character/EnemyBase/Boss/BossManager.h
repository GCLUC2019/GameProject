#pragma once
#include "../GameProject/Base/Task.h"

class BossManager : public Task {
private:
	CAnimImage m_img; //��
	CImage m_img2;//�E��ʂ�����ق�
	CImage m_img3;//����
	CAnimImage m_img4;//�K��

	CVector2D m_pos; //���̍��W
	CVector2D m_pos2;//�E��̍��W
	CVector2D m_pos3;//����̍��W
	CVector2D m_pos4;//�K���̍��W

	int m_state;
public:

	BossManager();

	void Update();

	void Draw();
};
