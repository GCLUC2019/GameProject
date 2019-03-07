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
};