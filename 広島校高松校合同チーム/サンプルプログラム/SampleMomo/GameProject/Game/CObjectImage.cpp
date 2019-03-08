#include "CObjectImage.h"


CObjectImage::CObjectImage(CImage * _image, int _draw_priority) : CObject(eTaskManagerIdGeneral, eTaskIdNone, 0, _draw_priority)
{
	m_image_p = _image;
}

CObjectImage::~CObjectImage()
{
}

void CObjectImage::Update(float delta_time)
{
}

void CObjectImage::Draw()
{
	if (m_image_p == nullptr) return;
	m_image_p->SetFlipH(m_is_flip);
	m_image_p->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_image_p->SetPos(m_pos.x,m_pos.y + m_pos.z);
	m_image_p->Draw();
}
