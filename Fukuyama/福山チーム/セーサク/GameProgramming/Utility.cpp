#include "Utility.h"


void Utility::DrawLine(const CVector2D &s, const CVector2D &e, const CVector4D &color) {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//各種機能を無効に
	//カリング無効
	glDisable(GL_CULL_FACE);
	//ライティング無効
	glDisable(GL_LIGHTING);
	//デプステスト無効
	glDisable(GL_DEPTH_TEST);
	//
	//正射投影の行列を作成
	//
	CMatrix	mProj = CMatrix(
		2.0f / GL::window_width, 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / GL::window_height, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	//投影行列を専用の物に設定
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf(mProj.f);

	//モデル＆ビュー行列を再設定
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();



	glBegin(GL_LINES);
	//カラー設定
	glColor4fv(color.v);
	//描画

	glVertex2f(s.x, s.y);
	glVertex2f(e.x, e.y);
	glEnd();


	//元の行列と設定に戻す
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	glPopAttrib();


}
void Utility::DrawQuad(const CVector2D &pos, const CVector2D &size, const CVector4D &color) {
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//各種機能を無効に
	//カリング無効
	glDisable(GL_CULL_FACE);
	//ライティング無効
	glDisable(GL_LIGHTING);
	//デプステスト無効
	glDisable(GL_DEPTH_TEST);
	//
	//正射投影の行列を作成
	//
	CMatrix	mProj = CMatrix(
		2.0f / GL::window_width, 0.0f, 0.0f, -1.0f,
		0.0f, -2.0f / GL::window_height, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);

	//投影行列を専用の物に設定
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadMatrixf(mProj.f);

	//モデル＆ビュー行列を再設定
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();



	glBegin(GL_QUADS);
	//カラー設定
	glColor4fv(color.v);
	//描画

	glVertex2f(pos.x, pos.y);
	glVertex2f(pos.x, pos.y + size.y);
	glVertex2f(pos.x + size.x, pos.y + size.y);
	glVertex2f(pos.x + size.x, pos.y);
	glEnd();


	//元の行列と設定に戻す
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);


	glPopAttrib();


}

