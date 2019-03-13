//����

#ifndef CAppear_H
#define CAppear_H

#pragma once
#include "CStdafx.h"
#include "Task.h"
#include"CRectangle.h"

class CAppear : public Task {
private:
	CVector2 m_pos;		//�{�[���̈ʒu
	CVector2 m_vec;		//�{�[���̈ړ���
public:
	/*!
	@brief	�R���X�g���N�^
	@param	pos			[in] �o���ʒu
	**/
	CAppear(const CVector2& pos);
	/*!
	@brief	�f�X�g���N�^
	**/
	CAppear();
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

	void SetVecter(const CVector2&vec){
		m_vec = vec;
	}
};


#endif
