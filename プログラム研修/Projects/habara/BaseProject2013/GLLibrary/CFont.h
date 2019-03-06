#pragma once
#include "GL.h"

class CFont {
private:
 HFONT Hfont;
 HDC Hdc;
 int height;
public:
	CFont(const char *font = "�l�r�S�V�b�N", int size=24);
	void Draw(int x,int y,float r,float g,float b, const char *format, ...);
	void Draw(int x, int y, float r, float g, float b, const wchar_t *format, ...);

	void Release();
};