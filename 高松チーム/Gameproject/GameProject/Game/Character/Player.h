#pragma once
#include "CharacterBase.h"
/*
�쐬�@����	
*/
class Player : public CharacterBase {
private:
	CImage m_Shadow;		//
	CVector2D m_pos_old;	//�O���W
	float m_Spd;			//�ړ����x
	int m_State;			// ���
	int m_Jumpvec;			//�W�����v�l
	float m_Depth;			//�`�扜�s��
	bool m_Jump_flg;		//�W�����v�t���O
	bool m_Squat_flg;		//���Ⴊ�݃t���O
	bool m_Attack_flg;		//�U��
public:
	Player();
	/*
	@brief �ړ�����֐�
	*/
	void Move();
	void Jump();
	void Update();
	void Draw();
};