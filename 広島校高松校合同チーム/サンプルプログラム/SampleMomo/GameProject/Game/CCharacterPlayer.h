#pragma once
#include "CCharacter.h"




enum {
	ePlayerAnimIdIdle,
	ePlayerAnimIdMove,
	ePlayerAnimIdRun,
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

	
	
public:
	CCharacterPlayer();
	~CCharacterPlayer();
	void LoadAnimImage();
	void InputMove();
	void InputJump();
	void Jumping();
	void Move();
	void Update();
	void CharacterDraw();
	void MoveLimit();
	void CalcScroll();
};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
2019/03/11 移動、ジャンプ等、スクロール機能等実装。
*/
