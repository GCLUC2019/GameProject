#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
�S��
�Ԟ��@Boss.cppp,h
*/


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////�����N���X/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossHead :public EnemyBase {
private:
	enum Head{
		eIdle,
		eUp,
		eFireAttackDown,
		eHeadAttackDown,
		eFireAttack,
		eHeadAttack,
	};
	CImage m_shadow;//�e
	
	CVector2D m_player_pos; //�v���C���[�̍��W���i�[����
	CVector2D m_shadow_pos;//�e�̍��W

	CRect m_rect2;//�ҋ@���̋�`

	bool m_anim_flag;//�A�j���[�V�����t���O
	bool m_draw_flag;
	bool m_approach_flag; //�����t���O
	bool m_shadow_flag;//�e���o����������

	int m_state;
	int m_anim_cnt;//�A�j���[�V�����J�E���g
	int m_idle_cnt;//�ҋ@��Ԃł��鎞��
	int m_shadow_size;


protected:


public:
	BossHead(const CVector2D &player_pos,const int state);

	~BossHead();

	void Idle();

	void FireAttack();

	void HeadAttack();

	void UpMove();

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

class BossLeftHand :public EnemyBase {
private:
	enum LeftHand {
		eIdle,
		eUp,
		eDownAttack,
		eHandAttack,

	};
	CVector2D m_center;
	CVector2D m_player_pos; //�v���C���[�̍��W���i�[����


	int m_cnt;//�G�t�F�N�g�p�Ɏg���Ă܂�
	int m_state;
	int m_idle_cnt;//�ҋ@��Ԃł��鎞��

	float m_ang;
	float m_rot;//�~����
	float m_rot2;//�~����
	float m_r;  //���a

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
class BossTail :public EnemyBase{
private:
	enum  Tail{
		eIdle,
		eUp,
		eDown,
		eTailAttack,
	};
	CVector2D m_player_pos; //�U������Ƃ��Ɏg���v���C���[�̍��W���i�[����

	int m_state;
	int m_anim_cnt;


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

