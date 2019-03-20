#pragma once
#include "../../Gameproject/GameProject/stdafx.h"


enum Motion1{
	eBossHeadAnim,
	eBossTailAttackMotion,
};
enum Motion2{
	
	eBossTailAnim,
	eBossFireAttackMotion,
	
};
enum {
	eBossFireEffect,
};
enum {
	eBossLazerEffect,
};

enum {
	eBossSlashEffect,
};

enum {
	eBossDeathEffect1,
	eBossDeathEffect2,
};


extern TexAnimData BossAnimData2[];
extern TexAnimData BossAnimData[];
extern TexAnimData BossFireEffectAnimData[];
extern TexAnimData BossLazerEffectAnimData[];
extern TexAnimData BossSlashEffectAnimData[];
extern TexAnimData BossDeathEffectAnimData[];


