#pragma once
#include "CObject.h"
#include "../Global.h"

/*
�X�e�[�W�̓����蔻��Ȃ�
*/



class CCommonObject : public CObject {
private:
	CImage * m_object_image_p = nullptr;
public:
	CCommonObject(CImage* _image,CVector3D _pos,CVector2D _size,CVector3D _rads);
	void Draw();
};

/*
2019/03/06 �N���X��`�B��{�@�\�����B by shingai
*/
