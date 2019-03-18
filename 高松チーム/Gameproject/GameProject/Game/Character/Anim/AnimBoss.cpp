#include "AnimBoss.h"

/*
íSìñÅ@î‘ûä
*/

static TexAnim BossHead[] = {
	{ 0,10 },
{ 1,10 },
{ 2,10 },
{ 3,10 },
{ 4,10 },
{ 5,10 },
{ 6,10 },
{ 7,10 },
};

static TexAnim BossTail[] = {
	{ 8,4 },
{ 9,4 },
{ 10,4 },
{ 11,4 },
{ 12,4 },
{ 13,4 },
{ 14,12 },
{ 15,12 },
};

static TexAnim BossHand[] = {
	{ 16,10 },
{ 17,10 },
};

static TexAnim BossTailAttackMotion[] = {
	{ 24,15 },
{ 25,15 },
{ 26,15 },
{ 27,15 },
};

static TexAnim BossFireAttackMotion[] = {
	{ 32,10 },
{ 33, 10 },
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
{ 27,3 },
{ 28,3 },
{ 29,3 },
};

TexAnimData BossLazerEffectAnimData[] = {
	ANIMDATA(BossLazerEffect),
};

static TexAnim BossSlashEffect[] = {
	{ 0,2 },
{ 1,2 },
{ 2,2 },
{ 3,2 },
{ 4,2 },
{ 5,2 },
{ 6,2 },
{ 7,2 },
};

TexAnimData BossSlashEffectAnimData[] = {
	ANIMDATA(BossSlashEffect),
};