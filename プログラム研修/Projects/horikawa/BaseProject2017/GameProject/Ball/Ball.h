#pragma once
#include "../stdafx.h"
#include "../System/Task.h"
class Ball : public Task {
private:
	CVector2D m_pos;		//�{�[���̈ʒu
	CVector2D m_vec;		//�{�[���̈ړ���
public:
	/*!
		@brief	�R���X�g���N�^
		@param	pos			[in] �o���ʒu
	**/
	Ball(const CVector2D& pos);

	/*!
	@brief	�f�t�H���g�R���X�g���N�^
	@param	pos			[in] �o���ʒu
	**/
	Ball();

	/*!
		@brief	�f�X�g���N�^
	**/
	~Ball();
	/*!
		@brief	�X�V����
		@param	delta_time			[in] �O��̍X�V����̌o�ߎ���
	**/
	void Update(float delta_time);
	/*!
		@brief	�`�揈��
	**/
	void Render();

	/*!
	@brief	�{�[���̈ړ��ʂ�ݒ�
	@param	vec			[in] �ړ���
	**/
	void SetVector(const CVector2D& vec) {           //�|�C���^���g�p���������y������A�Z�������̓w�b�_�[�ɍ�蓮����y������(�C�����C���֐�
		m_vec = vec;
	}

	CVector2D GetVector() const {    //const�͒��g��ς������Ȃ�
		return m_vec;
	}
};