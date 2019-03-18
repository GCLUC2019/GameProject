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

#define mHeader header

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
	/*
	DrawImage
	left:四角形左座標
	right:四角形右座標
	bottom:四角形下座標
	top:四角形上座標
	tleft:画像左座標
	tright:画像右座標
	tbottom:画像下座標
	ttop:画像上座標
	*/
	void DrawImage(int left, int right, int bottom, int top, float tleft, float tright, float tbottom, float ttop)  const {
		//テクスチャを有効にする
		glEnable(GL_TEXTURE_2D);
		//アルファブレンドを有効にする
		glEnable(GL_BLEND);
		//ブレンド方法を指定
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//テクスチャを指定
		glBindTexture(GL_TEXTURE_2D, mId);

		float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		//色の設定
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glColor4fv(diffuse);

		glBegin(GL_TRIANGLES);
		glTexCoord2f(tleft / mHeader.width, (mHeader.height - ttop) / mHeader.height);
		glVertex2d(left, top);
		glTexCoord2f(tleft / mHeader.width, (mHeader.height - tbottom) / mHeader.height);
		glVertex2d(left, bottom);
		glTexCoord2f(tright / mHeader.width, (mHeader.height - tbottom) / mHeader.height);
		glVertex2d(right, bottom);
		glTexCoord2f(tleft / mHeader.width, (mHeader.height - ttop) / mHeader.height);
		glVertex2d(left, top);
		glTexCoord2f(tright / mHeader.width, (mHeader.height - tbottom) / mHeader.height);
		glVertex2d(right, bottom);
		glTexCoord2f(tright / mHeader.width, (mHeader.height - ttop) / mHeader.height);
		glVertex2d(right, top);
		glEnd();

		//テクスチャを解放
		glBindTexture(GL_TEXTURE_2D, 0);
		//アルファブレンドを無効
		glDisable(GL_BLEND);
		//テクスチャを無効
		glDisable(GL_TEXTURE_2D);
	}
	/*
	DrawImage
	ltx,lty:四角形左上座標
	lbx,lby:四角形左下座標
	rbx,rby:四角形右下座標
	rtx,rty:四角形右上座標
	tleft:画像左座標
	tright:画像右座標
	tbottom:画像下座標
	ttop:画像上座標
	*/
	void DrawImage(float ltx, float lty, float lbx, float lby, float rbx, float rby, float rtx, float rty, float tleft, float tright, float tbottom, float ttop)  const {
		//テクスチャを有効にする
		glEnable(GL_TEXTURE_2D);
		//アルファブレンドを有効にする
		glEnable(GL_BLEND);
		//ブレンド方法を指定
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//テクスチャを指定
		glBindTexture(GL_TEXTURE_2D, mId);

		float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		//色の設定
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glColor4fv(diffuse);

		glBegin(GL_TRIANGLES);
		glTexCoord2f(tleft / mHeader.width, (mHeader.height - ttop) / mHeader.height);
		glVertex2f(ltx, lty);
		glTexCoord2f(tleft / mHeader.width, (mHeader.height - tbottom) / mHeader.height);
		glVertex2f(lbx, lby);
		glTexCoord2f(tright / mHeader.width, (mHeader.height - tbottom) / mHeader.height);
		glVertex2d(rbx, rby);
		glTexCoord2f(tleft / mHeader.width, (mHeader.height - ttop) / mHeader.height);
		glVertex2d(ltx, lty);
		glTexCoord2f(tright / mHeader.width, (mHeader.height - tbottom) / mHeader.height);
		glVertex2d(rbx, rby);
		glTexCoord2f(tright / mHeader.width, (mHeader.height - ttop) / mHeader.height);
		glVertex2d(rtx, rty);
		glEnd();

		//テクスチャを解放
		glBindTexture(GL_TEXTURE_2D, 0);
		//アルファブレンドを無効
		glDisable(GL_BLEND);
		//テクスチャを無効
		glDisable(GL_TEXTURE_2D);
	}

};

#endif