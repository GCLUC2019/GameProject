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

<<<<<<< HEAD
enum {
=======
enum PlayerEffectAnim {
>>>>>>> 7b7833fccc61631035d5b5e9c0ad3425b18ce63d
	ePELongAttack,
	ePEShortAttack01,
	ePEShortAttack02,
	ePEShortAttack03,
	ePESpecialAttack,
};

extern TexAnimData PlayerAnimData[];
extern TexAnimData PlayerEffectAnimData[];

