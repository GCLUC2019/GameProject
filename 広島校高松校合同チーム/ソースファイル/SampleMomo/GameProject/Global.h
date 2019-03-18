#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	���ʃf�[�^
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


#define GRAVITY (1.25f)

#define GRAVITY_LIMIT (40.0f)

// 1/60�b
#define SPF		(1.0f/60.0f)


//�Q�[���̓���z���FPS
//�S�Ă̓�����1�b��60�t���[���Ƃ��č���Ă���B
#define GAME_BASE_FPS (60.0)

//���ۂ̃t���[�����[�g
#define FPS (0)

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define DP_UI (5000)

#ifdef _DEBUG
	#define DEBUG_PRINT(s) printf(s);
#else
	#define DEBUG_PRINT(s)
#endif

enum {
	eTaskIdNone = 0,
	eTaskIdPlayer,
	eTaskIdEnemy,
	eTaskIdCommonObject,
	eTaskIdDropItem,
};

