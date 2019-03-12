#pragma once
#include "../../stdafx.h"
#include "../Character/Anim/AnimData.h"
#include "../Character/Anim/AnimDataPlayer.h"
#include "../Character/Anim/AnimBoss.h"


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

		
		ADD_RESOURCE("Player", CAnimImage::LoadImage("../data/Image/motion_player.png", PlayerAnimData, 512,512));
		ADD_RESOURCE("PEffectShortAttack", CAnimImage::LoadImage("../data/Image/motion_effect.png", PlayerEfectAnimData, 512, 512));
		ADD_RESOURCE("PEffectLongAttack", CAnimImage::LoadImage("../data/Image/item_matome_1.png", PlayerEfectAnimData, 128, 128));
		ADD_RESOURCE("Boss", CAnimImage::LoadImage("../data/Image/moton_jaryu.png", BossAnimData, 768, 768));
		ADD_RESOURCE("GameClear", CImage::LoadImage("../data/Image/push start.png"));
		ADD_RESOURCE("Enemy01", CAnimImage::LoadImage("../data/Image/zako_chochin_motion.png", Enemy01AnimData,512,512));
		ADD_RESOURCE("Enemy02", CAnimImage::LoadImage("../data/Image/zako_daruma_motion.png", Enemy02AnimData, 512, 512));
		ADD_RESOURCE("Enemy03", CAnimImage::LoadImage("../data/Image/zako_hi_motion.png", Enemy03AnimData, 512, 512));
		ADD_RESOURCE("Enemy04", CAnimImage::LoadImage("../data/Image/zako_kamaitachi_motion.png", Enemy04AnimData, 512, 512));
		ADD_RESOURCE("Enemy05", CAnimImage::LoadImage("../data/Image/zako_niku_motion.png", Enemy05AnimData, 512, 512));
		ADD_RESOURCE("BossFire", CAnimImage::LoadImage("../data/Image/pipo-btleffect162.png",BossFireEffectAnimData,768,768));
		//ADD_RESOURCE("BossLazer", CAnimImage::LoadImage("../data/Image/pipo-btleffect162.png", BossLazerEffectAnimData, 640,480));
		ADD_RESOURCE("Title", CImage::LoadImage("../data/Image/title.png"));

	}
};

