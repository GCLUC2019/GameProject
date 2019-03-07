#pragma once
#include "stdafx.h"
/**
* @file		Global.h
* @brief	ã§í ÉfÅ[É^
**/

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720


#define GRAVITY (9.8f*10)

/*
namespace Global {
	const float gravity = (9.8f * 10);
}

Global::gravity;

*/

class Global {
private:
	static const float gravity;
	static const float fps;
};

const int fps = 60;
const float spf = (1.0f / 60.0f);

// 1/60ïb
#define SPF		(1.0f/60.0f)

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#ifdef _DEBUG
	#define DEBUG_PRINT(s) printf(s);
#else
	#define DEBUG_PRINT(s)
#endif