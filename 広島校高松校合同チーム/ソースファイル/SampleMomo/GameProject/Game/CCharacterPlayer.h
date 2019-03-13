#pragma once
#include "CCharacter.h"



#define PLAYER_ATTACK_FRAME (15)

#define PLAYER_ATTACK_LENGTH CVector3D(300,300,50)

#define PLAYER_ATTACK_POWER (1.0f)

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
2019/03/06 クラス定義。基本機能実装。 by shingai
2019/03/11 移動、ジャンプ等、スクロール機能等実装。
*/
