#pragma once
#include "../stdafx.h"
#include "../System/Task.h"
class BallManager : public Task {
private:
	
	float m_time; //!���Ԍv���p

public:
	/*!
		@brief	�R���X�g���N�^
	**/
	BallManager();
	/*!
		@brief	�f�X�g���N�^
	**/
	~BallManager();
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