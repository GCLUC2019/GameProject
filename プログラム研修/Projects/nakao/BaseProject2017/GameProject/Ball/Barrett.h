#pragma once
#include"../GameProject/stdafx.h"
#include "../System/Task.h"

class Barrett:public Task{
private:
	CVector2D m_pos;
public:
	Barrett(const CVector2D& _pos);
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