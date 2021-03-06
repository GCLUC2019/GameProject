#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	共通データ
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

/*　const　定数宣言
.h
namespace Global {
	const float gravity = (9.8f * 10);
}

class Global {
	static const float gravity;
};

.cpp
const float Global::gravity=9.8f;
*/

#define GRAVITY (9.8f*60)
// 1/60秒
#define SPF		(1.0f/60.0f)
//aのバイト数を求める
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))


#ifdef _DEBUG
	#define DEBUG_PRINT(s) printf(s)
#else
	#define DEBUG_PRINT(s)
#endif

#define PLUS(a,b) (a+b)
#define MINUS(a,b) (a-b)

