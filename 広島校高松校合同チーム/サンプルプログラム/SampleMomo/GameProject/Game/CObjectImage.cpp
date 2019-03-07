#include "CObjectImage.h"


CObjectImage::CObjectImage(CImage * _image) : CObject(eId_ObjectImage, eUp_ObjectImage, eRd_ObjectImage)
{
	m_image_p = _image;
}

CObjectImage::~CObjectImage()
{
}

void CObjectImage::Update(float delta_time)
{
}

void CObjectImage::Render()
{
	if (m_image_p == nullptr) return;
	m_image_p->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_image_p->SetPos(m_pos.x,m_pos.y + m_pos.z);
	m_image_p->Draw();
}
