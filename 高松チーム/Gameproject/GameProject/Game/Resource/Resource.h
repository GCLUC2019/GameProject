#pragma once
#include "../../stdafx.h"

class Resource {
public:
	Resource()
	{
		/*�@
			�g�p����.cpp�Ɂ@
			#include "../GameProject/Game/Resource/Resource.h"�@
			���R�s�y���ē\��t����

		@brief			 ../data/Image/�K�v�ȃt�@�C����
		@param a	[in] ���ʎq
		@param b	[in] �ǂݍ��݂����t�@�C���̏ꏊ
		*/

		ADD_RESOURCE("Player", CImage::LoadImage("../data/Image/chara_gauge_face.png"));

	}
};

