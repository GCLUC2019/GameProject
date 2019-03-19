#pragma once
#include"CFPS.h"
/**
* @file		Global.h
* @brief	ã§í ÉfÅ[É^
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


#define GRAVITY (9.8f*50)
// 1/60ïb
#define SPF		(1.0f/60.0f)


#ifdef _DEBUG
#define DEBUG_PRINT(s) printf(s);
#else
#define DEBUG_PRINT(s)
#endif