#pragma once
#include "../../stdafx.h"
#include "../Character/Anim/AnimData.h"
#include "../Character/Anim/AnimDataPlayer.h"
#include "../Character/Anim/AnimBoss.h"
#include "../Character/Anim/AnimUI.h"
#include"../Item/AnimItemBox.h"
#include "../Character/Anim/AnimEnemyEffect.h"
#include "../../Base/Task.h"
class Resource :public Task{
public:
	Resource():Task(eResource)
	{
		/*　
			使用する.cppに　
			#include "../GameProject/Game/Resource/Resource.h"　
			をコピペして貼り付ける

		@brief			 ../data/Image/必要なファイル名
		@param a	[in] 識別子
		@param b	[in] 読み込みたいファイルの場所
		*/
	}
};

class TitleResource : public Task {
public:
	TitleResource() : Task(ResourceData::eTitleResource){
		ADD_RESOURCE("Title", CImage::LoadImage("../data/Image/title.png"));
		ADD_RESOURCE("Choice", CImage::LoadImage("../data/Image/choice.png"));
		ADD_RESOURCE("RogoBase", CImage::LoadImage("../data/Image/rogo_base.png"));
		ADD_RESOURCE("RogoClear", CImage::LoadImage("../data/Image/rogo_cl.png"));
		ADD_RESOURCE("RogoHuda", CImage::LoadImage("../data/Image/rogo_huda.png"));
		ADD_RESOURCE("RogoUI", CImage::LoadImage("../data/Image/chara_gauge_face.png"));
		ADD_RESOURCE("Window", CImage::LoadImage("../data/Image/balloon.png"));
	}
};

class TutorialResource : public Task {
public:
	TutorialResource() : Task(ResourceData::eTutorialResource) {

		ADD_RESOURCE("Shadow", CImage::LoadImage("../data/Image/shadow.png"));
		ADD_RESOURCE("Ground", CImage::LoadImage("../data/Image/bg_ground.png"));
		ADD_RESOURCE("Bamboo", CImage::LoadImage("../data/Image/bg_bamboo.png"));
		ADD_RESOURCE("SkyBlue", CImage::LoadImage("../data/Image/bg_sky_01.png"));
		ADD_RESOURCE("SkyRed", CImage::LoadImage("../data/Image/bg_sky_02.png"));

		ADD_RESOURCE("Player", CAnimImage::LoadImage("../data/Image/motion_player.png", PlayerAnimData, 512, 512));
		ADD_RESOURCE("PEffectShortAttack", CAnimImage::LoadImage("../data/Image/motion_effect.png", PlayerEffectAnimData, 512, 512));
		ADD_RESOURCE("PEffectLongAttack", CAnimImage::LoadImage("../data/Image/item_matome_1.png", PlayerEffectAnimData, 128, 128));
		ADD_RESOURCE("PESpecialAttack", CAnimImage::LoadImage("../data/Image/pipo-mapeffect013a-1.png", PlayerEffectAnimData, 400, 400));

		ADD_RESOURCE("Enemy02", CAnimImage::LoadImage("../data/Image/zako_daruma_motion.png", Enemy02AnimData, 512, 512));

		ADD_RESOURCE("RogoUI", CImage::LoadImage("../data/Image/chara_gauge_face.png"));
		ADD_RESOURCE("GageBaseUI", CImage::LoadImage("../data/Image/chara_gauge_base.png"));
		ADD_RESOURCE("PlayerGageUI", CImage::LoadImage("../data/Image/chara_gauge.png"));
		ADD_RESOURCE("BalloonUI", CImage::LoadImage("../data/Image/balloon.png"));
		ADD_RESOURCE("SpecialGageUI", CAnimImage::LoadImage("../data/Image/item_matome_1.png", SpecialGageUIAnimData, 128, 128));
		ADD_RESOURCE("SpecialGageEffect", CAnimImage::LoadImage("../data/Image/pipo-gate01b480.png", SpecialGageEffectAnimData, 480, 480));

	}
};

class GameSceneResourse : public Task {
public:
	GameSceneResourse() : Task(ResourceData::eGameSceneResourse) {
		ADD_RESOURCE("Player", CAnimImage::LoadImage("../data/Image/motion_player.png", PlayerAnimData, 512, 512));
		ADD_RESOURCE("PEffectShortAttack", CAnimImage::LoadImage("../data/Image/motion_effect.png", PlayerEffectAnimData, 512, 512));
		ADD_RESOURCE("PEffectLongAttack", CAnimImage::LoadImage("../data/Image/item_matome_1.png", PlayerEffectAnimData, 128, 128));
		ADD_RESOURCE("PESpecialAttack", CAnimImage::LoadImage("../data/Image/pipo-mapeffect013a-1.png", PlayerEffectAnimData, 400, 400));
		ADD_RESOURCE("PEGetDamage", CAnimImage::LoadImage("../data/Image/Effect_p020.png", PlayerEffectAnimData, 200, 200));

		//必殺のもろもろ
		ADD_RESOURCE("Curtain", CImage::LoadImage("../data/Image/curtain.png"));
		ADD_RESOURCE("Cutin", CImage::LoadImage("../data/Image/cutin.png"));
		ADD_RESOURCE("Hissathu", CImage::LoadImage("../data/Image/text02.png"));

		ADD_RESOURCE("Enemy01", CAnimImage::LoadImage("../data/Image/zako_chochin_motion.png", Enemy01AnimData, 512, 512));
		ADD_RESOURCE("Enemy02", CAnimImage::LoadImage("../data/Image/zako_daruma_motion.png", Enemy02AnimData, 512, 512));
		ADD_RESOURCE("Enemy2Effect", CAnimImage::LoadImage("../data/Image/Enemy2Effect.png", E2AttackEffectAnimData, 192, 192));
		ADD_RESOURCE("Enemy03", CAnimImage::LoadImage("../data/Image/zako_hi_motion.png", Enemy03AnimData, 512, 512));
		ADD_RESOURCE("Enemy04EffectS", CAnimImage::LoadImage("../data/Image/ef_s01.png", E4AttackEffectAnimData, 200, 180));
		ADD_RESOURCE("Enemy04EffectEX", CAnimImage::LoadImage("../data/Image/slash_ex.png", E4AttackEffectAnimData, 500, 50));
		ADD_RESOURCE("Enemy04", CAnimImage::LoadImage("../data/Image/zako_kamaitachi_motion.png", Enemy04AnimData, 512, 512));
		ADD_RESOURCE("Enemy05", CAnimImage::LoadImage("../data/Image/zako_niku_motion.png", Enemy05AnimData, 512, 512));
		
		ADD_RESOURCE("Shadow", CImage::LoadImage("../data/Image/shadow.png"));
		ADD_RESOURCE("Ground", CImage::LoadImage("../data/Image/bg_ground.png"));
		ADD_RESOURCE("Bamboo", CImage::LoadImage("../data/Image/bg_bamboo.png"));
		ADD_RESOURCE("SkyBlue", CImage::LoadImage("../data/Image/bg_sky_01.png"));
		ADD_RESOURCE("SkyRed", CImage::LoadImage("../data/Image/bg_sky_02.png"));
		ADD_RESOURCE("Kakera", CImage::LoadImage("../data/Image/item_kakera.png"));
		ADD_RESOURCE("MagicCircle", CImage::LoadImage("../data/Image/mahoujin_image.png"));
	
	
		ADD_RESOURCE("ItemBox", CAnimImage::LoadImage("../data/Image/itembox_motion_object.png", ItemBoxAnimData, 512, 512));
	
		ADD_RESOURCE("RogoUI", CImage::LoadImage("../data/Image/chara_gauge_face.png"));
		ADD_RESOURCE("GageBaseUI", CImage::LoadImage("../data/Image/chara_gauge_base.png"));
		ADD_RESOURCE("PlayerGageUI", CImage::LoadImage("../data/Image/chara_gauge.png"));
		ADD_RESOURCE("GuidanceUI", CImage::LoadImage("../data/Image/go_sign.png"));
		ADD_RESOURCE("SpecialGageUI", CAnimImage::LoadImage("../data/Image/item_matome_1.png", SpecialGageUIAnimData, 128, 128));
		ADD_RESOURCE("SpecialGageEffect", CAnimImage::LoadImage("../data/Image/pipo-gate01b480.png", SpecialGageEffectAnimData, 480, 480));
		
	}
};

class GameSceneResourse2 : public Task {
public:
	GameSceneResourse2() : Task(ResourceData::eGameScene2Resourse) {
		//仮置きデータ
		/*
			RESOURCE
		*/
#ifdef _DEBUG
		ADD_RESOURCE("Player", CAnimImage::LoadImage("../data/Image/motion_player.png", PlayerAnimData, 512, 512));
		ADD_RESOURCE("PEffectShortAttack", CAnimImage::LoadImage("../data/Image/motion_effect.png", PlayerEffectAnimData, 512, 512));
		ADD_RESOURCE("PEffectLongAttack", CAnimImage::LoadImage("../data/Image/item_matome_1.png", PlayerEffectAnimData, 128, 128));
		ADD_RESOURCE("PESpecialAttack", CAnimImage::LoadImage("../data/Image/pipo-mapeffect013a-1.png", PlayerEffectAnimData, 400, 400));
		ADD_RESOURCE("PEGetDamage", CAnimImage::LoadImage("../data/Image/Effect_p020.png", PlayerEffectAnimData, 200, 200));

		//必殺のもろもろ
		ADD_RESOURCE("Curtain", CImage::LoadImage("../data/Image/curtain.png"));
		ADD_RESOURCE("Cutin", CImage::LoadImage("../data/Image/cutin.png"));
		ADD_RESOURCE("Hissathu", CImage::LoadImage("../data/Image/text02.png"));

		ADD_RESOURCE("Enemy01", CAnimImage::LoadImage("../data/Image/zako_chochin_motion.png", Enemy01AnimData, 512, 512));
		ADD_RESOURCE("Enemy02", CAnimImage::LoadImage("../data/Image/zako_daruma_motion.png", Enemy02AnimData, 512, 512));
		ADD_RESOURCE("Enemy2Effect", CAnimImage::LoadImage("../data/Image/Enemy2Effect.png", E2AttackEffectAnimData, 192, 192));
		ADD_RESOURCE("Enemy03", CAnimImage::LoadImage("../data/Image/zako_hi_motion.png", Enemy03AnimData, 512, 512));
		ADD_RESOURCE("Enemy04EffectS", CAnimImage::LoadImage("../data/Image/ef_s01.png", E4AttackEffectAnimData, 200, 180));
		ADD_RESOURCE("Enemy04EffectEX", CAnimImage::LoadImage("../data/Image/slash_ex.png", E4AttackEffectAnimData, 500, 50));
		ADD_RESOURCE("Enemy04", CAnimImage::LoadImage("../data/Image/zako_kamaitachi_motion.png", Enemy04AnimData, 512, 512));
		ADD_RESOURCE("Enemy05", CAnimImage::LoadImage("../data/Image/zako_niku_motion.png", Enemy05AnimData, 512, 512));

		ADD_RESOURCE("Shadow", CImage::LoadImage("../data/Image/shadow.png"));
		ADD_RESOURCE("Ground", CImage::LoadImage("../data/Image/bg_ground.png"));
		ADD_RESOURCE("Bamboo", CImage::LoadImage("../data/Image/bg_bamboo.png"));
		ADD_RESOURCE("SkyBlue", CImage::LoadImage("../data/Image/bg_sky_01.png"));
		ADD_RESOURCE("SkyRed", CImage::LoadImage("../data/Image/bg_sky_02.png"));
		ADD_RESOURCE("Kakera", CImage::LoadImage("../data/Image/item_kakera.png"));
		ADD_RESOURCE("MagicCircle", CImage::LoadImage("../data/Image/mahoujin_image.png"));


		ADD_RESOURCE("ItemBox", CAnimImage::LoadImage("../data/Image/itembox_motion_object.png", ItemBoxAnimData, 512, 512));

		ADD_RESOURCE("RogoUI", CImage::LoadImage("../data/Image/chara_gauge_face.png"));
		ADD_RESOURCE("GageBaseUI", CImage::LoadImage("../data/Image/chara_gauge_base.png"));
		ADD_RESOURCE("PlayerGageUI", CImage::LoadImage("../data/Image/chara_gauge.png"));
		ADD_RESOURCE("GuidanceUI", CImage::LoadImage("../data/Image/go_sign.png"));
		ADD_RESOURCE("SpecialGageUI", CAnimImage::LoadImage("../data/Image/item_matome_1.png", SpecialGageUIAnimData, 128, 128));
		ADD_RESOURCE("SpecialGageEffect", CAnimImage::LoadImage("../data/Image/pipo-gate01b480.png", SpecialGageEffectAnimData, 480, 480));

#endif // DEBUG

		
		//
		ADD_RESOURCE("Boss", CAnimImage::LoadImage("../data/Image/moton_jaryu2.png", BossAnimData, 768, 768));
		ADD_RESOURCE("Boss2", CAnimImage::LoadImage("../data/Image/moton_jaryu3.png", BossAnimData2, 768, 768));
		ADD_RESOURCE("GameClear", CImage::LoadImage("../data/Image/push start.png"));

		//ADD_RESOURCE("BossFire", CAnimImage::LoadImage("../data/Image/pipo-btleffect162.png",BossFireEffectAnimData,1280,960));
		ADD_RESOURCE("BossSlash", CAnimImage::LoadImage("../data/Image/Effect_p036.png", BossSlashEffectAnimData, 200, 200));
		ADD_RESOURCE("BossDeathEffect1", CAnimImage::LoadImage("../data/Image/pipo-mapeffect013c-1.png", BossDeathEffectAnimData, 192, 192));
		ADD_RESOURCE("BossDeathEffect2", CAnimImage::LoadImage("../data/Image/pipo-mapeffect013c-2.png", BossDeathEffectAnimData, 192, 192));
		ADD_RESOURCE("BossHP", CImage::LoadImage("../data/Image/boss_gauge.png"));
		ADD_RESOURCE("BossHPBack", CImage::LoadImage("../data/Image/boss_gauge_base.png"));
		ADD_RESOURCE("BossStage", CImage::LoadImage("../data/Image/bg_boss.png"));
	}
};
