#include "Utility.h"


void Utility::DrawLine(const CVector2D &s, const CVector2D &e, const CVector4D &color) {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//�e��@�\�𖳌���
	//�J�����O����
	glDisable(GL_CULL_FACE);
	//���C�e�B���O����
	glDisable(GL_LIGHTING);
	//�f�v�X�e�X�g����
	glDisable(GL_DEPTH_TEST);
	//
	//���˓��e�̍s����쐬
	//
	CMatrix	mProj = CMatrix(
		2.0f / GL::window_width, 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / GL::window_height, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	//���e�s����p�̕��ɐݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf(mProj.f);

	//���f�����r���[�s����Đݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();



	glBegin(GL_LINES);
	//�J���[�ݒ�
	glColor4fv(color.v);
	//�`��

	glVertex2f(s.x, s.y);
	glVertex2f(e.x, e.y);
	glEnd();


	//���̍s��Ɛݒ�ɖ߂�
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	glPopAttrib();


}
void Utility::DrawQuad(const CVector2D &pos, const CVector2D &size, const CVector4D &color) {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//�e��@�\�𖳌���
	//�J�����O����
	glDisable(GL_CULL_FACE);
	//���C�e�B���O����
	glDisable(GL_LIGHTING);
	//�f�v�X�e�X�g����
	glDisable(GL_DEPTH_TEST);
	//
	//���˓��e�̍s����쐬
	//
	CMatrix	mProj = CMatrix(
		2.0f / GL::window_width, 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / GL::window_height, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	//���e�s����p�̕��ɐݒ�
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf(mProj.f);

	//���f�����r���[�s����Đݒ�
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();



	glBegin(GL_QUADS);
	//�J���[�ݒ�
	glColor4fv(color.v);
	//�`��

	glVertex2f(pos.x, pos.y);
	glVertex2f(pos.x, pos.y + size.y);
	glVertex2f(pos.x + size.x, pos.y + size.y);
	glVertex2f(pos.x + size.x, pos.y);
	glEnd();


	//���̍s��Ɛݒ�ɖ߂�
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	glPopAttrib();


}

