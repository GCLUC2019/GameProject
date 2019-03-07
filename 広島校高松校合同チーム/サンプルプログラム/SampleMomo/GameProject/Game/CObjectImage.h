#pragma once
#include "CObject.h"
#include "../Global.h"

class CObjectImage : public CObject {
private:
	CImage * m_image_p = nullptr;
public:
	CObjectImage(CImage* _image);
	virtual ~CObjectImage();
	void Update(float delta_time);
	void Render();
};