#include "CObjectImage.h"


CObjectImage::CObjectImage(CImage * _image, int _draw_priority) : CObject(0,_draw_priority)
{
	m_image_p = _image;
	m_image_p->SetFilter(GL_NEAREST);
}

CObjectImage::CObjectImage(CImage * _image, CVector3D _pos, CVector2D _size, int _draw_priority, bool _flip) : CObject(0, _draw_priority)
{
	m_image_p = _image;
	SetPos(_pos);
	SetSize(_size);
	m_is_flip = _flip;
	m_image_p->SetFilter(GL_NEAREST);
}

CObjectImage::~CObjectImage()
{
}

void CObjectImage::Update()
{
	SetDrawPriority(m_pos.z);
}

void CObjectImage::Draw()
{
	if (m_image_p == nullptr) return;
	m_image_p->SetFlipH(m_is_flip);
	m_image_p->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	CVector2D draw_pos = CVector2D(m_pos.x, m_pos.y + m_pos.z) - GetScroll();
	m_image_p->SetPos(draw_pos);
	m_image_p->Draw();
}
