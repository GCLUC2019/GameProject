#pragma once
#include "../GameProject/Base/Task.h"


/*
   �쐬�ҁ@�Ԟ�
   �}�l�[�W���[�őҋ@��Ԃ��Ǘ�����
*/
class BossManager : public Task {
private:
	enum Manager{
		eIdle,
		eAttackDown = 2,
		eAttackDown2,
		eDeath,
		eNothing,
		eUp,
	};

	CImage m_img; //���ꂽ�Ƃ��̉摜
	CAnimImage m_img2;//���ꂽ�Ƃ��G�t�F�N�g
	CAnimImage m_img3;//���ꂽ�Ƃ��G�t�F�N�g�@���̂Q

	CVector2D m_pos; //���ꂽ�Ƃ��̍��W
	CVector2D m_player_pos;//�v���C���[�̍��W���擾���Ċi�[
	CVector2D m_pos2;//���ӂ����ƍ��W
	CVector2D m_pos3;//�G�t�F�N�g���W�@���̂Q
	CVector2D m_rect_pos;//��`�ړ��̂ۂ�

	int m_state;//�{�X�̏��
	int m_boss_attack_type;//�{�X�̍U�������ނ�ԍ��ŐU�蕪����
	int m_boss_hp;//�{�X�̗̑�
	int m_idle_cnt;//�ҋ@��Ԃł��鎞��
	int m_cnt;

	bool m_idle_flag;

public:

	BossManager();

	~BossManager();

	void Nothing();

	void Idle();

	void Attack();

	void Death();

	void Update();

	void Draw();

	friend class BossHand;
};
