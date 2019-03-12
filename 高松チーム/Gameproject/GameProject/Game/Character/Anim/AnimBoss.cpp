#include "AnimBoss.h"

/*
íSìñÅ@î‘ûä
*/

static TexAnim BossHead[] = {
	{ 0,50 },
{ 1,50 },
{ 2,50 },
{ 3,50 },
{ 4,50 },
{ 5,50 },
{ 6,50 },
{ 7,50 },
};

static TexAnim BossTail[] = {
	{ 8,50 },
{ 9,50 },
{ 10,50 },
{ 11,50 },
{ 12,50 },
{ 13,50 },
{ 14,50 },
{ 15,50 },
};

static TexAnim BossHand[] = {
	{ 16,50 },
{ 17,50 },
};

static TexAnim BossTailAttackMotion[] = {
	{ 24,50 },
{ 25,50 },
{ 26,50 },
{ 27,50 },
};

static TexAnim BossFireAttackMotion[] = {
	{ 32,50 },
{ 33,50 },
};


TexAnimData BossAnimData[] = {
	ANIMDATA(BossHead),
	ANIMDATA(BossTail),
	ANIMDATA(BossHand),
	ANIMDATA(BossTailAttackMotion),
	ANIMDATA(BossFireAttackMotion),
};



static TexAnim BossFireEffect[] = {
	{ 0,3 },
{ 1,3 },
{ 2,3 },
{ 3,3 },
{ 4,3 },
{ 5,3 },
{ 6,3 },
{ 7,3 },
{ 8,3 },
{ 9,3 },
{ 10,3 },
{ 11,3 },
{ 12,3 },
{ 13,3 },
{ 14,3 },
{ 15,3 },
{ 16,3 },
{ 17,3 },
{ 18,3 },
{ 19,3 },
};

TexAnimData BossFireEffectAnimData[] = {
	ANIMDATA(BossFireEffect),
};

static TexAnim BossLazerEffect[] = {
	{ 0,3 },
{ 1,3 },
{ 2,3 },
{ 3,3 },
{ 4,3 },
{ 5,3 },
{ 6,3 },
{ 7,3 },
{ 8,3 },
{ 9,3 },
{ 10,3 },
{ 11,3 },
{ 12,3 },
{ 13,3 },
{ 14,3 },
{ 15,3 },
{ 16,3 },
{ 17,3 },
{ 18,3 },
{ 19,3 },
{ 20,3 },
{ 21,3 },
{ 22,3 },
{ 23,3 },
{ 24,3 },
{ 25,3 },
{ 26,3 },
};

TexAnimData BossLazerEffectAnimData[] = {
	ANIMDATA(BossLazerEffect),
};