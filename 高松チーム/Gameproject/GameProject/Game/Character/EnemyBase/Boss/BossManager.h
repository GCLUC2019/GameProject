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
		eUp,
		eAttackDown,
		eAttackDown2,
		eDeath,
		eNothing,
	};

	CAnimImage m_img; //��

	CVector2D m_pos; //���̍��W
	CVector2D m_player_pos;//�v���C���[�̍��W���擾���Ċi�[

	int m_state;//�{�X�̏��
	int m_boss_attack_type;//�{�X�̍U�������ނ�ԍ��ŐU�蕪����
	int m_boss_hp;//�{�X�̗̑�
	int m_idle_cnt;//�ҋ@��Ԃł��鎞��

	bool m_death_flag;

public:

	BossManager();

	void Nothing();

	void Idle();

	void Attack();

	void Death();

	void Update();

	void Draw();
};
