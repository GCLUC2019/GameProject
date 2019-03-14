#include "CImage.h"
#include "CCollision.h"



CImage::CImage() : m_pos(0,0),m_center(0,0),m_size(0,0),m_src_rect(0,0,0,0),m_ang(0),m_flipH(false),m_color(1.0f,1.0f,1.0f,1.0f){
}
CImage::~CImage(){
}
bool CImage::Load(const char* path){
	bool f=false;
	f= CTexture::Load(path);
	if (f){
		SetPos(0, 0);
		SetRect(0, 0, (float)m_width, (float)m_height);
		SetSize((float)m_width, (float)m_height);
	}
	return f;
	

}

CImage* CImage::LoadImage(const char* path) {
	CImage* img = new CImage();
	if (img->Load(path)) {
		return img;
	}
	delete img;
	return nullptr;
}



void CImage::Draw() {

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
	CMatrix mT,mR;

	mT.Transelate(m_pos.x,m_pos.y,0.0f);
	
	mR.RotationZ(-m_ang);

	glLoadMatrixf((mT * mR).f);




	MapTexture();

	//画像を張り付けるためのポリゴンの作成
	struct SVertex {
		float tu;
		float tv;
		float vx;
		float vy;
		float vz;
	};
	SVertex vertices[] = {
		//テクスチャー座標 uv														頂点座標xyz
		{ m_src_rect.m_left/m_width,m_src_rect.m_top/m_height,0-m_center.x,			0-m_center.y,			0.0f },		//左上
		{ m_src_rect.m_right/m_width,m_src_rect.m_top/m_height,m_size.x-m_center.x,	0-m_center.y,			0.0f },		//右上
		{ m_src_rect.m_left/m_width,m_src_rect.m_bottom/m_height,0-m_center.x,		m_size.y-m_center.y,	0.0f },		//左下
		{ m_src_rect.m_right/m_width,m_src_rect.m_bottom/m_height,m_size.x-m_center.x,m_size.y-m_center.y,	0.0f }		//右下
	};
	//左右反転処理
	if(m_flipH) {
		float t = vertices[0].tu;
		vertices[0].tu = vertices[2].tu = vertices[1].tu;
		vertices[1].tu = vertices[3].tu = t;
		
	}


	//描画
	glColor4fv(m_color.v);
	glInterleavedArrays(GL_T2F_V3F, 0, vertices);
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);

	UnmapTexture();

	//元の行列と設定に戻す
	glPopMatrix();
    glMatrixMode(GL_PROJECTION);
	glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
	

	glPopAttrib();
	
}

bool CImage::CollitionImage(const CImage &img) {
	CRect rect(img.m_pos.x - img.m_center.x, img.m_pos.y - img.m_center.y,
		img.m_pos.x - img.m_center.x + img.m_size.x, img.m_pos.y - img.m_center.y + img.m_size.y);

	return CollitionRect(rect);
}
bool CImage::CollitionRect(const CRect &rect) {
	CRect rect2(this->m_pos.x - this->m_center.x, this->m_pos.y - this->m_center.y,
		this->m_pos.x - this->m_center.x + this->m_size.x, this->m_pos.y - this->m_center.y + this->m_size.y);
	return CCollision::CollisionRect(rect2, rect);
}
bool CImage::CollitionPoint(const CVector2D &pos) {
	CRect rect(this->m_pos.x - this->m_center.x, this->m_pos.y - this->m_center.y,
		this->m_pos.x - this->m_center.x + this->m_size.x, this->m_pos.y - this->m_center.y + this->m_size.y);
	return CCollision::CollisionRectPoint(rect, pos);

}