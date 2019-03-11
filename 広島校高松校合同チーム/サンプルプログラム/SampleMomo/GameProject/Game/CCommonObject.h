#pragma once
#include "CObject.h"
#include "../Global.h"

/*
ステージの当たり判定など
*/



class CCommonObject : public CObject {
private:
	CImage * m_object_image_p = nullptr;
public:
	CCommonObject(CImage* _image,CVector3D _pos,CVector2D _size,CVector3D _rads);
	void Draw();
};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
*/
