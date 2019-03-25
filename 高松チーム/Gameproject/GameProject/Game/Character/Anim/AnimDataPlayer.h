#pragma once
#include "../../Gameproject/GameProject/stdafx.h"

enum PlayerStateAnim{
	ePIdle,
	ePLongAttack,
	ePShortAttack01,
	ePShortAttack02,
	ePShortAttack03,
	ePDamage,
	ePDeath,
	ePJumpUp,//
	ePJumpDown,//
	ePUp,//
	ePRun,//
	ePCrouch,
};

enum PlayerEffectAnim {
	ePELongAttack,
	ePEShortAttack01,
	ePEShortAttack02,
	ePEShortAttack03,
	ePESpecialAttack,
	ePEGetDamage,
	ePESpecialAttackEffectFire,
};

extern TexAnimData PlayerAnimData[];
extern TexAnimData PlayerEffectAnimData[];

