#pragma once
#include "CObject.h"
#include "../Global.h"

class CObjectImage : public CObject {
private:
	CImage * m_image_p = nullptr;
public:
	CObjectImage(CImage* _image,int _draw_priority = 0);
	virtual ~CObjectImage();
	void Update(float delta_time);
	void Draw();
};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
*/
