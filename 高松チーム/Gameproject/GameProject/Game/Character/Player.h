#pragma once
#include "CharacterBase.h"

class Player : public CharacterBase {
private:
	CImage m_Shadow;	//
	float m_Spd;		//移動速度
	int m_State;		// 状態
	bool m_Jump_flg;		//ジャンプフラグ
	bool m_Squat_flg;		//しゃがみフラグ
	bool m_Attack_flg;	//
public:
	Player();
	void Move();
	void Update();
	void Draw();
};