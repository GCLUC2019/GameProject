#pragma once
#include "CharacterBase.h"

class Player : public CharacterBase {
private:
	CImage m_Shadow;	//
	float m_Spd;		//�ړ����x
	int m_State;		// ���
	bool m_Jump_flg;		//�W�����v�t���O
	bool m_Squat_flg;		//���Ⴊ�݃t���O
	bool m_Attack_flg;	//
public:
	Player();
	void Move();
	void Update();
	void Draw();
};