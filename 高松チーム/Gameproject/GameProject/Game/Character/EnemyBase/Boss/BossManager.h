#pragma once
#include "../GameProject/Base/Task.h"


/*
   �쐬�ҁ@�Ԟ�
   �}�l�[�W���[�őҋ@��Ԃ��Ǘ�����
*/
class BossManager : public Task {
private:
	enum B{
		eIdle,
		eAttackDown = 2,
		eAttackDown2,
		eDeath,
		eNothing,
		ePriparation,
	};

	CAnimImage m_img; //���ꂽ�Ƃ��̉摜

	CVector2D m_pos; //���ꂽ�Ƃ��̍��W
	CVector2D m_player_pos;//�v���C���[�̍��W���擾���Ċi�[

	int m_state;//�{�X�̏��
	int m_boss_attack_type;//�{�X�̍U�������ނ�ԍ��ŐU�蕪����
	int m_boss_hp;//�{�X�̗̑�
	int m_idle_cnt;//�ҋ@��Ԃł��鎞��

	bool m_death_flag;
	bool m_idle_flag;

public:

	BossManager();

	~BossManager();

	void Nothing();

	void Priparation();

	void Idle();

	void Attack();

	void Death();

	void Update();

	void Draw();

	friend class BossHand;
};
