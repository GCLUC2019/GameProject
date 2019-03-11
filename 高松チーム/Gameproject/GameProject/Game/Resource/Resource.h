#pragma once
#include "../../stdafx.h"

class Resource {
public:
	Resource()
	{
		/*　
			使用する.cppに　
			#include "../GameProject/Game/Resource/Resource.h"　
			をコピペして貼り付ける

		@brief			 ../data/Image/必要なファイル名
		@param a	[in] 識別子
		@param b	[in] 読み込みたいファイルの場所
		*/

		ADD_RESOURCE("Player", CImage::LoadImage("../data/Image/chara_gauge_face.png"));

	}
};

