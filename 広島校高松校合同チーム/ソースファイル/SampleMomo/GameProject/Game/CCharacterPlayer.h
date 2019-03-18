#pragma once
#include "CCharacter.h"

/*
�W�����v��̒��n���ɍd���ǉ�
����s���𒅒n����̂��܂��^�C�~���O�ōs���΍d�����L�����Z���ł���̂�
��肭���Ό��͐����ɂ����͂�
*/

#define PLAYER_ATTACK_FRAME (30)

#define PLAYER_ATTACK_ANIM_DELAY (PLAYER_ATTACK_FRAME / 3)



//�U�����肪��������t���[��
#define PLAYER_ATTACK_HIT_FRAME_START (PLAYER_ATTACK_ANIM_DELAY * 1)
//�U�����肪�I������t���[��
#define PLAYER_ATTACK_HIT_FRAME_END (PLAYER_ATTACK_ANIM_DELAY * 3)


//�\������̃f�B���C
#define PLAYER_ATTACK_RESERVE_ANIM_DELAY (PLAYER_ATTACK_ANIM_DELAY * 2)
//�\������̃t���[��
#define PLAYER_ATTACK_RESERVE_ANIM_FRAME (PLAYER_ATTACK_RESERVE_ANIM_DELAY * 2)

#define PLAYER_ATTACK_LENGTH CVector3D(300,50,75)

#define PLAYER_ATTACK_POWER (1.0f)



#define PLAYER_DAMAGE_ANIM_FRAME (20)


//���n�d������
//0 15
#define PLAYER_LANDING_ACTION_FRAME (10)

//���n�A�j����������������鎞��
#define PLAYER_LANDING_ANIM_FRAME (20)


#define MEMORY_HIT_ATTACKED_ENEMY_MAX (1000)

#define PLAYER_EVASION_FRAME (36)
#define PLAYER_EVASION_ANIM_DELAY (PLAYER_EVASION_FRAME / 4)
#define PLAYER_AFTER_DAMAGE_INVINCIBLE (60)
#define PLAYER_EVASION_MOVE_START_FRAME (PLAYER_EVASION_ANIM_DELAY * 2)
#define PLAYER_RECEIVE_INPUT_EVASION_TIME (10)
#define PLAYER_RECEIVE_INPUT__EVASION_TIME_AFTER_EVASION (30 + 20)

//#define PLAYER_EVASION_MOVE_END_FRAME (PLAYER_EVASION_ANIM_DELAY * 5)


#define PLAYER_EVASION_RESERVE_FRAME (PLAYER_EVASION_ANIM_DELAY * 2)

//����̈ړ��������I�������̓��[�V�����L�����Z���\�Ƃ���B

#define PLAYER_DOWN_FRAME (60 * 5)

#define PLAYER_DOWN_ANIM_DELAY (14)
#define PLAYER_DOWN_ANIM_FRAME (PLAYER_DOWN_ANIM_DELAY*2)


//���n���[�V�����������ɔh�������ꍇ�`�����[�V�������J�b�g�\�ɂ���B

/*
���n���[�V�����̓W�����v�ȊO�ł̓L�����Z���s�ɂ���B
*/


enum {
	ePlayerAnimIdIdle,
	ePlayerAnimIdMove,
	ePlayerAnimIdRun,
	ePlayerAnimIdJump,
	ePlayerAnimIdAttack,
	ePlayerAnimIdAttackReserve,
	ePlayerAnimIdLand,
	ePlayerAnimIdFall,
	ePlayerAnimIdDamage,
	ePlayerAnimIdEvasion,
	ePlayerAnimIdEvasionFast,//�ŏ��̂��Ⴊ�ރ��[�V�������J�b�g�����ȗ���
	ePlayerAnimIdEvasionReserve,
	ePlayerAnimIdDown,
	ePlayerAnimIdDowned,
	ePlayerAnimIdMax,
};

enum {
	ePlayerAnimIdle0,
	ePlayerAnimIdle1,
	ePlayerAnimIdle2,
	ePlayerAnimIdle3,
	ePlayerAnimMove0,
	ePlayerAnimMove1,
	ePlayerAnimMove2,
	ePlayerAnimMove3,
	ePlayerAnimMove4,
	ePlayerAnimMove5,
	ePlayerAnimMove6,
	ePlayerAnimMove7,
	ePlayerAnimRun0,
	ePlayerAnimRun1,
	ePlayerAnimRun2,
	ePlayerAnimRun3,
	ePlayerAnimRun4,
	ePlayerAnimRun5,
	ePlayerAnimJump0,
	ePlayerAnimJump1,
	ePlayerAnimJump2,
	ePlayerAnimJump3,
	ePlayerAnimJump4,
	ePlayerAnimLand0,
	ePlayerAnimFall0,
	ePlayerAnimFall1,
	ePlayerAnimFall2,
	ePlayerAnimFall3,
	ePlayerAnimAttack0,
	ePlayerAnimAttack1,
	ePlayerAnimAttack2,
	ePlayerAnimIdAttackReserve0,
	ePlayerAnimIdAttackReserve1,
	ePlayerAnimDamage0,
	ePlayerAnimEvasion0,
	ePlayerAnimEvasion1,
	ePlayerAnimEvasion2,
	ePlayerAnimEvasion3,
	ePlayerAnimEvasion4,
	ePlayerAnimEvasion5,
	ePlayerAnimDown0,
	ePlayerAnimDown1,
	ePlayerAnimMax,
};




class CCharacterPlayer : public CCharacter {
private:
	
	
	bool m_is_jumping = false;
	int m_jumping_count = 0;

	bool m_is_attacking = false;
	int m_attacking_count = 0;
	
	bool m_is_dashing = false;

	int m_damage_anim_count = 0;

	bool m_is_landing_action_now = false;
	int m_landing_anim_count = 0;
	int m_landing_action_count = 0;

	//�U�������G���L�����Ă����|�C���^�z��
	int m_memory_hit_attacked_enemy_num = 0;
	Task* m_memory_hit_attacked_enemy_p[MEMORY_HIT_ATTACKED_ENEMY_MAX];


	bool m_is_input_evasion_flip = false;
	bool m_is_input_evasion = false;
	bool m_is_evasion = false;
	int m_evasion_count = 0;
	int m_evasion_reserve_count = 0;
	bool m_is_fast_evasion = false;


	int m_receive_input_evasion_time_count_l = 0;
	int m_receive_input_evasion_time_count_r = 0;

	int m_after_damage_invincible_count = 0;

	int m_attack_reserve_count = 0;

	bool m_is_down = false;
	int m_down_count = 0;

public:
	CCharacterPlayer();
	~CCharacterPlayer();
	void LoadAnimImage();

	void InputDash();
	void InputAttack();
	void InputMove();
	void InputJump();
	void InputEvasion();
	void BeginEvasion();

	void DoingEvasion();
	void DoingDown();

	void AfterDamageInvincible();
	void DoingLandingAction();
	void Landing();
	void Attacking();
	void Jumping();
	void Falling();
	void Move();

	void CharacterOutHitPoint();

	
	void CharacterBeforeUpdate();
	void CharacterUpdate();
	void CharacterBeforeCollisionCheck();
	void CollisionCheckCharacter(Task* _collision_task);
	void CharacterDraw();
	

	//�V���ȓ��͂������ꍇ�A���炩���ߓ��͂��Ă��������̂�j������
	void ClearEarlyInput();


	void AdjAnim();
	//void CalcScroll();

	void ReceiveAttack();
};

/*
2019/03/06 �N���X��`�B��{�@�\�����B by shingai
2019/03/11 �ړ��A�W�����v���A�X�N���[���@�\�������B
*/
