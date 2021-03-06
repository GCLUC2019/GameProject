#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	共通データ
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define DEBUG_PRINT(s)




#define GRAVITY (9.8f*50)
// 1/60秒
#define SPF		(1.0f/60.0f)

#ifdef _DEBUG
#define DEBUG_PRINT(s) printf(s)
#else
#define DEBUG_PRINT(s)
#endif
