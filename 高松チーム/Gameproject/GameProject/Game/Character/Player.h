#pragma once
#include "CharacterBase.h"
/*
�쐬�@����	
�@����@�b��
 �\���@	:�ړ�
 z�L�[	:���Ⴊ��	�i�摜���t���j
 x�L�[	:�U���@�@	�i�摜�����j
 c�L�[	:�W�����v
*/
class Player : public CharacterBase {
private:
	CImage m_shadow;		//

	CVector2D m_pos_old;	//�O���W
	float m_speed;			//�ړ����x
	int m_state;			// ���
	int m_state_old;		// �O���
	int m_jump_vec;			//�W�����v�l
	float m_depth;			//�`�扜�s��
	bool m_flip;			//���]�t���O
	bool m_jump_flg;		//�W�����v�t���O
	bool m_squat_flg;		//���Ⴊ�݃t���O
	bool m_attack_flg;		//�U���t���O
	bool m_special_flg;		//�K�E�U���t���O
public:
	Player();
	/*
	@brief �ړ�����֐�
	*/
	void Move();
	/*
	@brief �W�����v����֐�
	*/
	void Jump();
	/*
	@brief �U������֐�
	*/
	void Attack();
	/*
	@brief �K�E�U���֐�
	*/
	void Special();
	/*
	@brief �A�j���[�V�����ݒ�֐�
	*/
	void SetAnim();


	void Update();
	void Draw();
};