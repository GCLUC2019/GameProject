#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	共通データ
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

//class Global {
//    static const float gravity = (9.8f * 10);
//};
#define GRAVITY (9.8f*10)
// 1/60秒
#define SPF		(1.0f/60.0f)
//aのバイト数を求める
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
//出現位置の数
#define POINT_MAX 5
