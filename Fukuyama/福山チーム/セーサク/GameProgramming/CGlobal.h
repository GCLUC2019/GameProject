#pragma once
#include"CFPS.h"
/**
* @file		Global.h
* @brief	���ʃf�[�^
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


#define GRAVITY (9.8f*50)
// 1/60�b
#define SPF		(1.0f/60.0f)


#ifdef _DEBUG
#define DEBUG_PRINT(s) printf(s);
#else
#define DEBUG_PRINT(s)
#endif