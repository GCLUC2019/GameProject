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
	left:�l�p�`�����W
	right:�l�p�`�E���W
	bottom:�l�p�`�����W
	top:�l�p�`����W
	tleft:�摜�����W
	tright:�摜�E���W
	tbottom:�摜�����W
	ttop:�摜����W
	*/
	void DrawImage(int left, int right, int bottom, int top, float tleft, float tright, float tbottom, float ttop)  const {
		//�e�N�X�`����L���ɂ���
		glEnable(GL_TEXTURE_2D);
		//�A���t�@�u�����h��L���ɂ���
		glEnable(GL_BLEND);
		//�u�����h���@���w��
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//�e�N�X�`�����w��
		glBindTexture(GL_TEXTURE_2D, mId);

		float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		//�F�̐ݒ�
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

		//�e�N�X�`�������
		glBindTexture(GL_TEXTURE_2D, 0);
		//�A���t�@�u�����h�𖳌�
		glDisable(GL_BLEND);
		//�e�N�X�`���𖳌�
		glDisable(GL_TEXTURE_2D);
	}
	/*
	DrawImage
	ltx,lty:�l�p�`������W
	lbx,lby:�l�p�`�������W
	rbx,rby:�l�p�`�E�����W
	rtx,rty:�l�p�`�E����W
	tleft:�摜�����W
	tright:�摜�E���W
	tbottom:�摜�����W
	ttop:�摜����W
	*/
	void DrawImage(float ltx, float lty, float lbx, float lby, float rbx, float rby, float rtx, float rty, float tleft, float tright, float tbottom, float ttop)  const {
		//�e�N�X�`����L���ɂ���
		glEnable(GL_TEXTURE_2D);
		//�A���t�@�u�����h��L���ɂ���
		glEnable(GL_BLEND);
		//�u�����h���@���w��
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//�e�N�X�`�����w��
		glBindTexture(GL_TEXTURE_2D, mId);

		float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		//�F�̐ݒ�
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

		//�e�N�X�`�������
		glBindTexture(GL_TEXTURE_2D, 0);
		//�A���t�@�u�����h�𖳌�
		glDisable(GL_BLEND);
		//�e�N�X�`���𖳌�
		glDisable(GL_TEXTURE_2D);
	}

};

#endif