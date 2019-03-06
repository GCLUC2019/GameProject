#include "CAnimImage.h"



CAnimImage::CAnimImage() : m_animData(nullptr) {

}
CAnimImage::~CAnimImage() {

}
CAnimImage* CAnimImage::LoadImage(const char* filename, TexAnimData *d, int width , int height) {
	CAnimImage *img = new CAnimImage();
	if (img->Load(filename, d, width, height)) {
		return img;
	}
	delete img;
	return false;
}

bool CAnimImage::Load(const char* filename, TexAnimData *d, int width, int height) {
	if (CImage::Load(filename)) {
		AttachAnimationData(d, width, height);
		SetSize(width, height);
		return true;
	}
	return false;
}

CAnimImage::CAnimImage(const CImage& img, TexAnimData *d, int width, int height) {
	*this = img;
	AttachAnimationData(d, width, height);
}
CAnimImage::CAnimImage(const CImage* img, TexAnimData *d, int width, int height) {
	*this = *img;
	AttachAnimationData(d, width, height);
}
CAnimImage& CAnimImage::operator = (const CImage& img) {
	memcpy(this, &img, sizeof(CImage));
	return *this;
}
void CAnimImage::UpdateAnimation() {
	if (!m_animData) return;
	m_animCount += m_animSpeed;
	if (m_animCount >= m_animData[m_animJam].pData[m_animIndex].cnt) {
		m_animIndex++;
		m_animCount = 0;
		if (m_animIndex >= m_animData[m_animJam].size) {
			if (m_animLoop) {
				m_animIndex = 0;
			}
			else {
				m_animIndex = m_animData[m_animJam].size - 1;
				m_animCount = m_animData[m_animJam].pData[m_animIndex].cnt;
			}
		}
	}
}


void CAnimImage::AttachAnimationData(TexAnimData *d, int width, int height) {

	m_animData = d;
	m_animJam = -1;
	m_animSpeed = 1;
	m_pat_width = width;
	m_pat_height = height;

}
void CAnimImage::ChangeAnimation(int num,  bool loop, int index, bool check) {
	if (!m_animData) return;
	if (check) {
		if (m_animJam == num) return;
	}
	m_animJam = num;
	m_animIndex = index;
	m_animCount = 0;
	m_animLoop = loop;

}
void CAnimImage::SetAnimationSpeed(float speed) {
	m_animSpeed = speed;
}
bool CAnimImage::CheckAnimationEnd() {
	if (!m_animData) return true;
	return (m_animCount == m_animData[m_animJam].pData[m_animIndex].cnt && m_animIndex >= m_animData[m_animJam].size - 1);

}


void CAnimImage::Draw() {
	if (m_animData) {
		float x = (float)(m_pat_width * (m_animData[m_animJam].pData[m_animIndex].pat % (m_width / abs((int)m_pat_width))));
		float y = (float)(m_pat_height * (m_animData[m_animJam].pData[m_animIndex].pat / (m_width / abs((int)m_pat_width))));
		SetRect(x, y, x + m_pat_width, y + m_pat_height);
	}
	CImage::Draw();
}