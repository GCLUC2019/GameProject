//����



#pragma once
#include "Cstdafx.h"
#include "Task.h"
class CAppearManager : public Task {
private:

	float m_time; //!���Ԍv���p

public:
	/*!
	@brief	�R���X�g���N�^
	**/
	CAppearManager();
	/*!
	@brief	�f�X�g���N�^
	**/
	~CAppearManager();
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

