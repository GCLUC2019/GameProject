#pragma once
#include "CCharacter.h"



#define PLAYER_ATTACK_FRAME (15)

//�c��5�t���[���ȉ��̎��ɍU�����肪��������
#define PLAYER_ATTACK_HIT_FRAME_START (5)
//�c��0�t���[���ȉ��̎��ɍU������I��
#define PLAYER_ATTACK_HIT_FRAME_END (0)

#define PLAYER_ATTACK_LENGTH CVector3D(300,300,50)

#define PLAYER_ATTACK_POWER (1.0f)

#define PLAYER_DAMAGE_ANIM_FRAME (20)


#define MEMORY_HIT_ATTACKED_ENEMY_MAX (1000)


enum {
	ePlayerAnimIdIdle,
	ePlayerAnimIdMove,
	ePlayerAnimIdRun,
	ePlayerAnimIdJump,
	ePlayerAnimIdAttack,
	ePlayerAnimIdLand,
	ePlayerAnimIdFall,
	ePlayerAnimIdDamage,
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
	ePlayerAnimDamage0,
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

	//�U�������G���L�����Ă����|�C���^�z��
	int m_memory_hit_attacked_enemy_num = 0;
	Task* m_memory_hit_attacked_enemy_p[MEMORY_HIT_ATTACKED_ENEMY_MAX];


public:
	CCharacterPlayer();
	~CCharacterPlayer();
	void LoadAnimImage();

	void InputDash();
	void InputAttack();
	void InputMove();
	void InputJump();

	void Landing();
	void Attacking();
	void Jumping();
	void Falling();
	void Move();
	void Update();
	void CharacterDraw();
	void AdjAnim();
	void CalcScroll();

	void ReceiveAttack();
};

/*
2019/03/06 �N���X��`�B��{�@�\�����B by shingai
2019/03/11 �ړ��A�W�����v���A�X�N���[���@�\�������B
*/
