#pragma once
#include "../../stdafx.h"
#include "../Character/Anim/AnimData.h"
#include "../Character/Anim/AnimDataPlayer.h"
#include "../Character/Anim/AnimBoss.h"


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

		
		ADD_RESOURCE("Player", CAnimImage::LoadImage("../data/Image/motion_player.png", PlayerAnimData, 512,512));
		ADD_RESOURCE("PEffectShortAttack", CAnimImage::LoadImage("../data/Image/motion_effect.png", PlayerEffectAnimData, 512, 512));
		ADD_RESOURCE("PEffectLongAttack", CAnimImage::LoadImage("../data/Image/item_matome_1.png", PlayerEffectAnimData, 128, 128));
		ADD_RESOURCE("PESpecialAttack", CAnimImage::LoadImage("../data/Image/pipo-mapeffect013a-1.png", PlayerEffectAnimData, 400, 400));

		ADD_RESOURCE("Boss", CAnimImage::LoadImage("../data/Image/moton_jaryu.png", BossAnimData, 768, 768));
		ADD_RESOURCE("GameClear", CImage::LoadImage("../data/Image/push start.png"));
		ADD_RESOURCE("Enemy01", CAnimImage::LoadImage("../data/Image/zako_chochin_motion.png", Enemy01AnimData,512,512));
		ADD_RESOURCE("Enemy02", CAnimImage::LoadImage("../data/Image/zako_daruma_motion.png", Enemy02AnimData, 512, 512));
		ADD_RESOURCE("Enemy03", CAnimImage::LoadImage("../data/Image/zako_hi_motion.png", Enemy03AnimData, 512, 512));
		ADD_RESOURCE("Enemy04", CAnimImage::LoadImage("../data/Image/zako_kamaitachi_motion.png", Enemy04AnimData, 512, 512));
		ADD_RESOURCE("Enemy05", CAnimImage::LoadImage("../data/Image/zako_niku_motion.png", Enemy05AnimData, 512, 512));
		ADD_RESOURCE("BossFire", CAnimImage::LoadImage("../data/Image/pipo-btleffect162.png",BossFireEffectAnimData,1280,960));
		ADD_RESOURCE("Shadow", CImage::LoadImage("../data/Image/shadow.png"));
		ADD_RESOURCE("Ground", CImage::LoadImage("../data/Image/bg_ground.png"));
		ADD_RESOURCE("Bamboo", CImage::LoadImage("../data/Image/bg_bamboo.png"));
		ADD_RESOURCE("SkyBlue", CImage::LoadImage("../data/Image/bg_sky_01.png"));
		ADD_RESOURCE("SkyRed", CImage::LoadImage("../data/Image/bg_sky_02.png"));
		ADD_RESOURCE("Kakera", CImage::LoadImage("../data/Image/item_kakera.png"));
		ADD_RESOURCE("MagicCircle", CImage::LoadImage("../data/Image/mahoujin_image.png"));
		ADD_RESOURCE("BossLazer", CAnimImage::LoadImage("../data/Image/pipo-btleffect141.png", BossLazerEffectAnimData, 640,480));
		ADD_RESOURCE("Title", CImage::LoadImage("../data/Image/title.png"));

	}
};

