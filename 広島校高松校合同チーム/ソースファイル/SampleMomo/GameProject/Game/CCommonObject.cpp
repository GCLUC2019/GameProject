#include "CCommonObject.h"

CCommonObject::CCommonObject(CImage * _image, CVector3D _pos, CVector2D _size, CVector3D _rads) : CObject(eTaskIdCommonObject, 0)
{
	m_object_image_p = _image;
	SetPos(_pos);
	SetSize(_size);
	SetRads(_rads);
}

void CCommonObject::Draw()
{
	if (m_object_image_p == nullptr) return;
	m_object_image_p->SetFlipH(m_is_flip);
	m_object_image_p->SetSize(m_size.x, m_size.y);
	CVector2D draw_pos = CVector2D(m_pos.x, m_pos.y + m_pos.z) - GetScroll();
	m_object_image_p->SetPos(draw_pos);
	m_object_image_p->SetCenter(m_size.x / 2.0, m_size.y / 2.0);
	m_object_image_p->Draw();
}
