//����

#ifndef CAppear_H
#define CAppear_H

#pragma once
#include "CStdafx.h"
#include "Task.h"
#include "CRectangle.h"

class CAppear : public Task {
private:
	CVector2 m_pos;		//�{�[���̈ʒu
	CVector2 m_vec;		//�{�[���̈ړ���
public:
	/*!
	@brief	�R���X�g���N�^
	@param	pos			[in] �o���ʒu
	**/
	CAppear();
	CAppear(const CVector2& pos);
	/*!
	@brief	�f�X�g���N�^
	**/
	~CAppear();
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
	@brief �{�[���̈ړ��ʂ�ݒ�
	@@param _vector [in] �ړ���
	**/
	void SetVector(const CVector2& _vector) { m_vec = _vector; };
};


#endif
