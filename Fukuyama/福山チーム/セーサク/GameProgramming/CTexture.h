#ifndef CTEXTURE_H
#define CTEXTURE_H
#include "glut.h"

struct STgaheader{
	unsigned char  dummy1[12];
	unsigned short width;
	unsigned short height;
	unsigned char  depth;
	unsigned char  dummy2;
};

class CTexture{
public:
	GLuint mId;
	STgaheader header;

	CTexture() :mId(0){}

	~CTexture(){
		if (mId != 0){
			glDeleteTextures(1, &mId);
			mId = 0;
		}
	}
	void Load(const char*filename);
};

#endif