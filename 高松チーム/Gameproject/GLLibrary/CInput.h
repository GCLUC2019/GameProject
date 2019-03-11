/*!
*	@brief	�L�[���̓N���X
*
*
**/
#pragma once
#include "GL.h"

#include "windows.h"
#include "CVector.h"




#define PAD_MAX 5

class CInput {
public:
	enum E_STATE{
		ePush,		//�������u��
		eHold,		//�����Ă���
		ePull,		//�������u��
		eFree,		//�����Ă���
		eStateMax,
	};

	enum E_BUTTON {
		eButton1 = 0,
		eButton2,
		eButton3,
		eButton4,
		eButton5,
		eButton6,
		eButton7,
		eButton8,
		eButton9,
		eButton10,
		eButton11,
		eButton12,
		eButton13,
		eMouseL,
		eMouseR,
		eMouseC,
		eUp,
		eDown,
		eLeft,
		eRight,
		eKeyMax = 31
	};
	static char	m_key_code[PAD_MAX][eKeyMax];
	static char	m_pad_code[PAD_MAX][16];
	static unsigned long m_key_old[PAD_MAX];
	static unsigned long m_key_state[PAD_MAX][eStateMax];
	static CVector2D m_mouse_vec;
	static CVector2D m_mouse_pos;
	static CVector2D m_mouse_pos_old;
	static int		m_mouse_wheel;
	static int		m_mouse_wheelOld;
	static bool		m_mouse_inside;

public:
	static bool Init();

	/*!
		@brief	�L�[�̏�Ԃ�����
		@param	no		[in] �R���g���[���[�ԍ�
		@param	state	[in] ���
		@param	button	[in] �{�^��
		@retval	true:�w�肵����ԁ@false:�w�肵����Ԃł͂Ȃ�
	**/
	static bool GetState(int no,E_STATE state,E_BUTTON button){
		return (m_key_state[no][state] & (1<<button))>0;
	}
	/*!
		@brief	�L�[�̏�Ԃ������ݒ�
		@param	no		[in] �R���g���[���[�ԍ�
		@param	state	[in] ���
		@param	button	[in] �{�^��
		@retval	����
	**/
	static void SetState(int no,E_STATE state,E_BUTTON button){
		m_key_state[no][state] |= (1<<button);
	}

	/*!
		@brief	�e�{�^���ɑΉ�����L�[��ݒ�
		@param	no		[in] �R���g���[���[�ԍ�
		@param	button	[in] �{�^��
		@param	code	[in] �L�[�R�[�h
		@retval	����
	**/
	static void SetButton(int no,E_BUTTON button,char code){
		m_key_code[no][button] = code;
	}
	/*!
		@brief	�e�{�^���ɑΉ�����L�[��ݒ�
		@param	no		[in] �R���g���[���[�ԍ�
		@param	button	[in] �{�^��
		@param	num		[in] �p�b�h�{�^��
		@retval	����
	**/
	static void SetPadButton(int no, E_BUTTON button, int num){
		m_pad_code[no][button] = num;
	}

	
	/*!
		@brief	�}�E�X�J�[�\���̍��W���擾
		@retval	�}�E�X�J�[�\���̍��W
	**/
	static CVector2D GetMousePoint() {
		

		return m_mouse_pos;
	}
	
	/*!
		@brief	�}�E�X�̈ړ��ʂ��擾
		@retval	�}�E�X�̈ړ���
	**/
	static CVector2D GetMouseVec() {
		return m_mouse_vec;
	}
	
	/*!
		@brief	�}�E�X�J�[�\�����E�C���h�E���Ɏ��߂�t���O�̐ݒ�
		@param	f		[in] true:�E�C���h�E���Ɏ��߂�
		@param	f		[in] true:�E�C���h�E���ŃJ�[�\�������[�v����
		@retval	����
	**/
	static void SetMouseInside(bool f);

	/*!
		@brief	�}�E�X�J�[�\���̕\���ݒ�
		@param	f		[in] true:�\���@false:��\��
		@retval	����
	**/
	static void ShowCursor(bool f) {
		 ::ShowCursor(f);
		 ::ShowCursor(f);
	}
	
	/*!
		@brief	�}�E�X�z�C�[���̕ω��ʎ擾
		@retval	�}�E�X�z�C�[���̕ω���
	**/
	static int GetMouseWheel() {
		return m_mouse_wheelOld;
	}
	/*!
		@brief	�}�E�X�z�C�[���̕ω��ʂ�������
		@param	a		[in] �ω���
		@retval	����
	**/
	static void AddMouseWheel(int a) {
		m_mouse_wheel+=a;
	}

	/*!
		@brief	�L�[�̏�Ԃ��X�V����
		@retval	����
	**/
	static void UpDate();
	
	static float toFloat(int i){
		return ((float)i - (0x7FFF)) / 0x8000;
	};
	static void UpdateClipCursor(int f);
};

#define PUSH(key) CInput::GetState(0,CInput::ePush,key)
#define HOLD(key) CInput::GetState(0,CInput::eHold,key)
#define PULL(key) CInput::GetState(0,CInput::ePull,key)
#define FREE(key) CInput::GetState(0,CInput::eFree,key)