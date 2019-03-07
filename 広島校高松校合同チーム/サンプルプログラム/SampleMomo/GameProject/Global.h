#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	���ʃf�[�^
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


#define GRAVITY (9.8f*10)
// 1/60�b
#define SPF		(1.0f/60.0f)

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#ifdef _DEBUG
	#define DEBUG_PRINT(s) printf(s);
#else
	#define DEBUG_PRINT(s)
#endif