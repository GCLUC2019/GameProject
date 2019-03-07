#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	���ʃf�[�^
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

//Global.h�ňȉ���錾����
//class Global {
//	static const float gravity;
//	static const float fps;
//};
//
////Global.cpp�ňȉ����`����
//const float Global::gravity=9.8f;
//const float Global::fps=60;

#define GRAVITY (9.8f*50)
// 1/60�b
#define SPF		(1.0f/60.0f)

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

#ifdef _DEBUG
    #define DEBUG_PRINT(s) printf(s)
#else 
    #define RELEASE_PRINT(s)
#endif

#ifdef _DEBUG
#define DEBUG_DATA_NUM(a,b) printf(a,b)
#else 
#define DEBUG_DATA_NUM(a)
#endif

