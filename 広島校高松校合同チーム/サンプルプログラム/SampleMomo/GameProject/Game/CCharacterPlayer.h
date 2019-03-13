#pragma once
#include "CCharacter.h"



#define PLAYER_ATTACK_FRAME (15)



enum {
	ePlayerAnimIdIdle,
	ePlayerAnimIdMove,
	ePlayerAnimIdRun,
	ePlayerAnimIdAttack,
	ePlayerAnimIdMax,
};

enum {
	ePlayerAnimIdle0,
	ePlayerAnimIdle1,
	ePlayerAnimIdle2,
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
	ePlayerAnimMax,
};




class CCharacterPlayer : public CCharacter {
private:
	
	
	bool m_is_jumping = false;
	int m_jumping_count = 0;

	bool m_is_attacking = false;
	int m_attacking_count = 0;
	
	bool m_is_dashing = false;

public:
	CCharacterPlayer();
	~CCharacterPlayer();
	void LoadAnimImage();

	void InputDash();
	void InputAttack();
	void InputMove();
	void InputJump();

	void Attacking();
	void Jumping();
	void Move();
	void Update();
	void CharacterDraw();
	void AdjAnim();
	void CalcScroll();
};

/*
2019/03/06 �N���X��`�B��{�@�\�����B by shingai
2019/03/11 �ړ��A�W�����v���A�X�N���[���@�\�������B
*/
