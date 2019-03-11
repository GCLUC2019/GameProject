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
		ADD_RESOURCE("Boss", CImage::LoadImage("../data/Image/moton_jaryu.png"));
		ADD_RESOURCE("GameClear", CImage::LoadImage("../data/Image/push start.png"));
		ADD_RESOURCE("Enemy01", CImage::LoadImage("../data/Image/zako_chochin_motion.png"));
		ADD_RESOURCE("Enemy02", CImage::LoadImage("../data/Image/zako_daruma_motion.png"));
		ADD_RESOURCE("Enemy03", CImage::LoadImage("../data/Image/zako_hi_motion.png"));
		ADD_RESOURCE("Enemy04", CImage::LoadImage("../data/Image/zako_kamaitachi_motion.png"));
		ADD_RESOURCE("Enemy05", CImage::LoadImage("../data/Image/zako_niku_motion.png"));
		ADD_RESOURCE("BossFire", CImage::LoadImage("../data/Image/pipo-btleffect162.png"));

	}
};

