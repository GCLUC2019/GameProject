#pragma once
#include "CharacterBase.h"
/*
�쐬�@����	
�@����@�b��
 �\���@		:�ړ�
 SHIFT�L�[	:���Ⴊ��	
 Z�L�[		:�ߋ����U���@�@	
 SPACE�L�[	:�W�����v
 X�L�[		:�������U��
 Q�L�[		:�K�E�U��
*/
class Player : public CharacterBase {
private:

	int m_HP;				//�̗�
	int m_special;			//�K�E�p�ϐ��i���ʂ̂�j

	CImage m_shadow;		//
	CVector2D m_pos_old;	//�O���W
	float m_speed;			//�ړ����x
	int m_state;			// ���
	int m_state_old;		// �O���
	int m_jump_vec;			//�W�����v�l
	float m_depth;			//�`�扜�s��


	//�t���O
	bool m_flip;			//���]�t���O
	bool m_damage_flg;		//�_���[�W�t���O
	bool m_jump_flg;		//�W�����v�t���O
	bool m_squat_flg;		//���Ⴊ�݃t���O
	bool m_attack_flg;		//�U���t���O
	bool m_special_flg;		//�K�E�U���t���O

	
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
	/*
	@brief �_���[�W��Ԑ���֐��i���G�Ƃ����S�ւ̈ڍs�Ƃ��j
	*/
	void DamageState();
public:
	/*
	@brief �@			�_���[�W�֐�
	@param _damage	[in]�^����_���[�W 
	*/
	void Damage(int _damage);
	Player();
	void Update();
	void Draw();
	int GetHP() {
		return m_HP;
	}
};