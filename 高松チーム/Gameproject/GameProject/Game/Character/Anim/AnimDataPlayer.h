#pragma once
#include "../../Gameproject/GameProject/stdafx.h"

enum {
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

enum {
	ePELongAttack,
	ePEShortAttack01,
	ePEShortAttack02,
	ePEShortAttack03,
	ePESpecialAttack,
};

extern TexAnimData PlayerAnimData[];
extern TexAnimData PlayerEffectAnimData[];

