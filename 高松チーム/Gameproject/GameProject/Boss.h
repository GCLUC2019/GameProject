#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"


/*
�S��
�Ԟ��@Boss.cppp,h
*/


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////���N���X/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossHead :public EnemyBase {
private:
	enum Head {
		eIdle,
		eUp,
		eFireAttackDown,
		eHeadAttackDown,
		eFireAttack,
		eHeadAttack,
		eDeath,
	};
	CImage m_shadow;//�e

	CVector2D m_player_pos; //�v���C���[�̍��W���i�[����

	CRect m_rect2;//�ҋ@���̋�`

	bool m_anim_flag;//�A�j���[�V�����t���O
	bool m_draw_flag;
	bool m_approach_flag; //�����t���O
	bool m_shadow_flag;//�e���o����������

	int m_state;
	int m_anim_cnt;//�A�j���[�V�����J�E���g
	int m_idle_cnt;//�ҋ@��Ԃł��鎞��
	int m_shadow_size;

	float m_shadow_y;//�e��y���W
	float m_shadow_x;

	float m_hp;




protected:


public:
	BossHead(const CVector2D &player_pos, const int state);

	~BossHead();

	void Idle();

	void FireAttack();

	void HeadAttack();

	void UpMove();

	void HitCheck();

	void FireDownMove();

	void HeadDownMove();

	void Update();

	void Draw();

	

	friend class BossManager;
};

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////��N���X/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossRightHand :public EnemyBase {
private:
	enum RightHand {
		eIdle,
		eUp,
		eDownAttack,
		eLazerAttack,

	};
	CImage m_shadow;//�e

	CVector2D m_player_pos; //�v���C���[�̍��W���i�[����

	CVector2D m_center;
	//CVector2D m_center2;

	int m_cnt;//�G�t�F�N�g�p�Ɏg���Ă܂�
	int m_state;
	int m_idle_cnt;//�ҋ@��Ԃł��鎞��

	float m_ang;
	float m_rot;//�~����
	float m_rot2;//�~����
	float m_r;  //���a

	int m_shadow_size;
	float m_shadow_y;//�e��y���W
	float m_shadow_x;

	bool m_anim_flag;//�A�j���[�V�����t���O
	bool m_move_flag;//�ړ��t���O
	bool m_idle_flag;

protected:


public:

	BossRightHand(const CVector2D &player_pos, const int state);

	~BossRightHand();

	void Idle();

	void Attack();

	void UpMove();

	void DownMove();

	void Update();

	void Draw();
	friend class BossManager;
};

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////��N���X/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossLeftHand :public EnemyBase {
private:
	enum LeftHand {
		eIdle,
		eUp,
		eDownAttack,
		eHandAttack,

	};
	CImage m_shadow;//�e

	CVector2D m_center;
	CVector2D m_player_pos; //�v���C���[�̍��W���i�[����


	int m_cnt;//�G�t�F�N�g�p�Ɏg���Ă܂�
	int m_state;
	int m_idle_cnt;//�ҋ@��Ԃł��鎞��

	float m_ang;
	float m_rot;//�~����
	float m_rot2;//�~����
	float m_r;  //���a
	int m_shadow_size;
	float m_shadow_y;//�e��y���W
	float m_shadow_x;

	bool m_slash_flag;//�U����

public:
	BossLeftHand(const CVector2D &player_pos, const int state);

	~BossLeftHand();

	void Idle();

	void Attack();

	void UpMove();

	void DownMove();

	void Update();

	void Draw();
	friend class BossManager;
};

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////�K���N���X/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossTail :public EnemyBase {
private:
	enum  Tail {
		eIdle,
		eUp,
		eDown,
		eTailAttack,
	};
	CVector2D m_player_pos; //�U������Ƃ��Ɏg���v���C���[�̍��W���i�[����
	CImage m_shadow;//�e

	int m_state;
	int m_anim_cnt;
	int m_shadow_size;

	bool m_attack_flag;
	bool m_idle_flag;

	float m_shadow_y;//�e��y���W
	float m_shadow_x;

public:

	BossTail(const CVector2D &player_pos, const int state);

	~BossTail();

	void Update();

	void Idle();

	void TailAttack();

	void UpMove();

	void DownMove();

	void HitCheck(Task*_t);

	void Draw();
	friend class BossManager;


};

class BossDeath :public EnemyBase {
private:
	
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

	BossDeath();

	~BossDeath();

	void Update();

	void Draw();
	friend class BossManager;


};

