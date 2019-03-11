#include <stdio.h>
#include "CTexture.h"

void CTexture::Load(const char*filename){
	unsigned char*data;
	FILE*fp;
	fp = fopen(filename, "rb");
	if (fp == 0){
		printf("file not found:%s\n", filename);
		return;
	}
	fread(&header, sizeof(header), 1, fp);
	int length = header.width*header.height*header.depth / 8;
	data = new unsigned char[length];
	fread(data, length, 1, fp);
	fclose(fp);

	glGenTextures(1, &mId);
	glBindTexture(GL_TEXTURE_2D, mId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	if (header.depth == 32)
		gluBuild2DMipmaps(GL_TEXTURE_2D, 4, header.width, header.height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, data);
	else
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, header.width, header.height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, 0);
	delete[]data;
}