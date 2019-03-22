#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/Game/UI/UI.h"


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
	CImage m_img;

	CVector2D m_player_pos;//�v���C���[�̍��W���擾���Ċi�[
	CVector2D m_pos;

	CVector2D m_rect_pos;//��`�ړ��̂ۂ�

	CRect m_rect;

	int m_state;//�{�X�̏��
	int m_boss_attack_type;//�{�X�̍U�������ނ�ԍ��ŐU�蕪����
	int m_boss_hp;//�{�X�̗̑�
	int m_idle_cnt;//�ҋ@��Ԃł��鎞��
	int m_cnt;

	//float m_hp;

	bool m_idle_flag;

public:

	BossManager();

	BossManager(int state);

	~BossManager();

	void Nothing();

	void Idle();

	void Attack();

	void Death();

	void Update();

	void Draw();

	friend class BossHead;
	friend class BossRightHand;
	friend class BossLeftHand;
	friend class BossTail;
};

class BossGageBaseUI : public UI{
private:
public:
	BossGageBaseUI();
	void Update();
	void Draw();
};

class BossHpUI : public UI {
private:
	float m_boss_hp_now;
	float m_boss_hp_max;
	float hp_width;
public:
	BossHpUI();
	void Update();
	void Draw();
};
