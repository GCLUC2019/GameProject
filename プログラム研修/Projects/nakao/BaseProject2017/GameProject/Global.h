#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	共通データ
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
/*
.hに記述
class GLOBAL
{
	static const float gravity;
};
.cppに記述
const float  GLOBAL::gravity = 9.8f * 10;
*/
#define GRAVITY (9.8f*10)
// 1/60秒
#define SPF		(1.0f/60.0f)

#define ARRAY_SIZE(a)  (sizeof(a)/sizeof(a[0]))


#ifdef _DEBUG
	#define DEBUG_PRINT(a) printf(a)
#else
 #define DEBUG_PRINT(a) 
#endif 