#pragma once
#include "CCharacter.h"

/*
�W�����v��̒��n���ɍd���ǉ�
����s���𒅒n����̂��܂��^�C�~���O�ōs���΍d�����L�����Z���ł���̂�
��肭���Ό��͐����ɂ����͂�
*/


#define PLAYER_ATTACK_FRAME (20)
#define PLAYER_ATTACK_HIT_FRAME_START (11)
#define PLAYER_ATTACK_HIT_FRAME_END (20)

#define PLAYER_SIDE_ATTACK_FRAME (20)
#define PLAYER_SIDE_ATTACK_HIT_FRAME_START (11)
#define PLAYER_SIDE_ATTACK_HIT_FRAME_END (20)

#define PLAYER_FINISH_ATTACK_FRAME (42)
#define PLAYER_FINISH_ATTACK_HIT_FRAME_START (34)
#define PLAYER_FINISH_ATTACK_HIT_FRAME_END (42)


#define PLAYER_SPEAR_ATTACK_FRAME (20)
#define PLAYER_SPEAR_ATTACK_HIT_FRAME_START (11)
#define PLAYER_SPEAR_ATTACK_HIT_FRAME_END (20)


#define PLAYER_AXE_ATTACK_FRAME (20)
#define PLAYER_AXE_ATTACK_HIT_FRAME_START (8)
#define PLAYER_AXE_ATTACK_HIT_FRAME_END (20)



#define PLAYER_GUN_ATTACK_FRAME (40)
#define PLAYER_GUN_ATTACK_HIT_FRAME_START (21)
#define PLAYER_GUN_ATTACK_HIT_FRAME_END (22)

//�\������̃t���[��(������U�����Ƃɂ����ق����悢)
#define PLAYER_ATTACK_RESERVE_ANIM_FRAME (15)


//�U���̐ݒ�
#define PLAYER_ATTACK_LENGTH CVector3D(200,100,200)
#define PLAYER_ATTACK_POWER (1.0)

#define PLAYER_SIDE_ATTACK_LENGTH CVector3D(150,100,250)
#define PLAYER_SIDE_ATTACK_POWER (1.0)

#define PLAYER_FINISH_ATTACK_LENGTH CVector3D(150,500,200)
#define PLAYER_FINISH_ATTACK_POWER (1.0)

#define PLAYER_SPEAR_ATTACK_LENGTH CVector3D(250,500,200)
#define PLAYER_SPEAR_ATTACK_POWER (1.5)


#define PLAYER_AXE_ATTACK_LENGTH CVector3D(150,500,300)
#define PLAYER_AXE_ATTACK_POWER (2.0)


#define PLAYER_GUN_ATTACK_LENGTH CVector3D(1200,200,50)
#define PLAYER_GUN_ATTACK_POWER (3.0)





//���n�d������
//0 15
#define PLAYER_LANDING_ACTION_FRAME (10)

//���n�A�j����������������鎞��
#define PLAYER_LANDING_ANIM_FRAME (20)


#define MEMORY_HIT_ATTACKED_ENEMY_MAX (1000)

#define PLAYER_EVASION_FRAME (36)
#define PLAYER_EVASION_ANIM_DELAY (PLAYER_EVASION_FRAME / 4)




#define PLAYER_EVASION_MOVE_START_FRAME (PLAYER_EVASION_ANIM_DELAY * 2)
#define PLAYER_RECEIVE_INPUT_EVASION_TIME (10 + 5)
#define PLAYER_RECEIVE_INPUT__EVASION_TIME_AFTER_EVASION (30 + 20 + 10)
#define PLAYER_EVASION_MOVE_VEC (10.0f)

//#define PLAYER_EVASION_MOVE_END_FRAME (PLAYER_EVASION_ANIM_DELAY * 5)


#define PLAYER_AFTER_DAMAGE_INVINCIBLE (40)
#define PLAYER_KNOCK_BACK_FRAME (30.0)
#define PLAYER_DAMAGE_FRAME (30.0)

#define PLAYER_EVASION_RESERVE_FRAME (PLAYER_EVASION_ANIM_DELAY * 2)

//����̈ړ��������I�������̓��[�V�����L�����Z���\�Ƃ���B

#define PLAYER_DOWN_FRAME (60 * 2)

#define PLAYER_DOWN_ANIM_DELAY (14)
#define PLAYER_DOWN_ANIM_FRAME (PLAYER_DOWN_ANIM_DELAY*2)


#define WEAPON_USE_ENDURANCE_DAMAGE (2.0f)


#define KEEP_FINAL_ATTACK_TIMEOUT (54)

//���n���[�V�����������ɔh�������ꍇ�`�����[�V�������J�b�g�\�ɂ���B

/*
���n���[�V�����̓W�����v�ȊO�ł̓L�����Z���s�ɂ���B
*/

enum {
	eEvasionFlipRight,
	eEvasionFlipLeft,
	eEvasionFlipUp,
	eEvasionFlipDown,
};

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
	ePlayerAnimIdSideAttack,
	ePlayerAnimIdFinishAttack,
	ePlayerAnimIdSideAttackReserve,
	ePlayerAnimIdFinishAttackKeepSlash,
	ePlayerAnimIdSpearAttack,
	ePlayerAnimIdSpearAttackReserve,
	ePlayerAnimIdAxeAttack,
	ePlayerAnimIdAxeAttackReserve,
	ePlayerAnimIdGunAttack,
	ePlayerAnimIdGunAttackReserve,
	ePlayerAnimIdMoveRight,
	ePlayerAnimIdMoveLeft,
	ePlayerAnimIdJumpRight,
	ePlayerAnimIdJumpLeft,
	ePlayerAnimIdLandRight,
	ePlayerAnimIdLandLeft,
	ePlayerAnimIdFallRight,
	ePlayerAnimIdFallLeft,
	ePlayerAnimIdIdleRight,
	ePlayerAnimIdIdleLeft,
	ePlayerAnimIdEvasionRight,
	ePlayerAnimIdEvasionFastRight,
	ePlayerAnimIdEvasionReserveRight,
	ePlayerAnimIdEvasionLeft,
	ePlayerAnimIdEvasionFastLeft,
	ePlayerAnimIdEvasionReserveLeft,
	ePlayerAnimIdVerticalAttack,
	ePlayerAnimIdVerticalAttackReserve,
	ePlayerAnimIdMax,
};


//����enum�̎g�p�p�x�������Ԍ������B�������Ă������ق����������肵�����ł͂���
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
	ePlayerAnimSideAttack0,
	ePlayerAnimSideAttack1,
	ePlayerAnimSideAttack2,
	ePlayerAnimSideAttack3,
	ePlayerAnimFinishAttack0,
	ePlayerAnimFinishAttack1,
	ePlayerAnimFinishAttack2,
	ePlayerAnimFinishAttack3,
	ePlayerAnimFinishAttack4,
	ePlayerAnimFinishAttack5,
	ePlayerAnimIdSideAttackReserve0,
	ePlayerAnimIdSideAttackReserve1,
	ePlayerAnimIdSideAttackReserve2,
	ePlayerAnimMax,
};




class CCharacterPlayer : public CCharacter {
private:
	
	CVector3D m_attack_length;
	double m_attack_power;
	int m_attack_total_frame;
	int m_attack_hit_frame_start;
	int m_attack_hit_frame_end;
	
	bool m_is_jumping = false;
	double m_jumping_count = 0.0;

	bool m_is_attacking = false;
	double m_attacking_count = 0.0;
	int m_attack_combo_count = 0;


	//�U�����̕���̏��
	int m_attack_weapon_id = -1;

	//����̏��
	int m_equip_weapon_id = -1;

	//����ϋv�l
	float m_equip_endurance = 0.0f;

	//����U�����Ă��邩�̃X�e�[�g
	bool m_is_weapon_attacking = false;

	//�������U����
	bool m_is_range_attack = false;
	
	//�������U�������ɂ����ꂩ�̓G�ɓ��ĂĂ��邩(���̏ꍇ�͈ꔭ�ɂ�1�̂̓G�Ȃ̂ŁA�ђʂȂ�)
	bool m_is_hit_range_attack = false;

	bool m_is_dashing = false;

	bool m_is_damage = false;
	double m_damage_count = 0;

	bool m_is_landing_action_now = false;
	double m_landing_anim_count = 0;
	double m_landing_action_count = 0;

	//�U�������G���L�����Ă����|�C���^�z��
	int m_memory_hit_attacked_enemy_num = 0;
	Task* m_memory_hit_attacked_enemy_p[MEMORY_HIT_ATTACKED_ENEMY_MAX];

	//�W�����v�U�����͉����s�����ł��Ȃ��̂ŁA���̂Ƃ��ɓG�ɂ͂��܂�Ƌl�݂ɂȂ�̂�
	double m_keep_final_attack_timeout = 0;

	bool m_is_input_evasion_flip = 0;
	
	
	bool m_is_input_evasion = false;

	bool m_is_evasion = false;

	bool m_is_early_input_attack = false;

	double m_evasion_count = 0;
	double m_evasion_reserve_count = 0;
	bool m_is_fast_evasion = false;

	int m_evasion_dir_type = 0;
	int m_will_evasion_dir_type = 0;

	double m_receive_input_evasion_time_count_l = 0;
	double m_receive_input_evasion_time_count_r = 0;

	double m_receive_input_evasion_time_count_u = 0;
	double m_receive_input_evasion_time_count_d = 0;

	double m_after_damage_invincible_count = 0;

	double m_attack_reserve_count = 0;

	bool m_is_down = false;
	double m_down_count = 0;

	bool m_is_move = false;

	bool m_is_sended_miss = false;
	
	

	//�{�X�̓���U���Ȃǂɂ��d��
	bool m_is_freeze = false;
	double m_freeze_count = 0.0;

	bool m_is_show_attack_effect = false;

public:
	CCharacterPlayer(CVector3D _pos);
	~CCharacterPlayer();
	void LoadAnimImage();


	void InputDestroyWeapon();
	void InputDash();
	void InputAttack();
	void InputMove();
	void InputJump();
	void InputEvasion();
	void BeginEvasion();


	void DoingEvasion();
	void DoingDown();
	void DoingDamage();



	void AfterDamageInvincible();
	void DoingLandingAction();
	void Landing();
	void ReserveAttacking();
	
	void Attacking();
	void AttackingHitFrame();

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

	void ReceiveAttack();
	void ReceiveKnockBack(CCharacter *_from, double _power);


	void CheckEquipEndurance();

	void PlayerGainEquip(int _equip_id, float _equip_endurance) {
		m_equip_weapon_id = _equip_id;
		m_equip_endurance = _equip_endurance;
	};


	void SetFreeze(int _count) {
		m_is_freeze = true;
		m_freeze_count = _count;
		m_is_attacking = false;
		m_is_evasion = false;
		m_is_jumping = false;
	};

	void Freezing();
	

	void PlayerDestroyEquip() {
		m_equip_weapon_id = -1;
		m_equip_endurance = 0.0f;
	}

	int GetPlayerEquipWeaponId() { return m_equip_weapon_id; };
	int* GetPlayerEquipWeaponIdPointer() { return &m_equip_weapon_id; };
	float* GetPlayerEquipWeaponEndurancePointer() { return &m_equip_endurance; };


	static CCharacterPlayer* GetInstance();


	//�`���[�g���A���p�t���O�p����
	bool GetIsMoving() { return m_is_move; };
	bool GetIsEvasion() { return m_is_evasion; };
	bool GetIsJumping() { return m_is_jumping; };
	bool GetIsAttacking() { return m_is_attacking; };
	bool GetIsDashing() { return m_is_dashing; };
	bool GetIsWeaponAttacking() { return m_is_weapon_attacking; };

};

/*
2019/03/06 �N���X��`�B��{�@�\�����B by shingai
2019/03/11 �ړ��A�W�����v���A�X�N���[���@�\�������B by shingai
�`2019/03/17 �F�X�ȋ@�\������ by shingai
�U���͈ړ����͂Ȃ��ŃR���{�U���i3��ނ̋Z���J��o��)

���ړ����͂ōU��1(X���ɔ��肪�L��)
�c�ړ����͂ōU��2(Z���ɔ��肪�L��)
�󒆂ɂ����Ԃœ��͂ōU��3(Y���ɔ��肪�L���A���n�܂ōU�����肪����)
���J��o�����Ƃ��ł���B�i�R���{�������ɓ����U����A�����邱�Ƃ��\)

*/
