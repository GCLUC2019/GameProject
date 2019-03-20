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

static TexAnim BossTailAttackMotion[] = {
	{ 8,4 },
{ 9,4 },
{ 10,4 },
{ 11,4 },
{ 12,4 },
{ 13,4 },
{ 14,6 },
{ 15,6 },
};
TexAnimData BossAnimData2[] = {
	ANIMDATA(BossHead),
	ANIMDATA(BossTailAttackMotion),
};

static TexAnim BossTailAnim[] = {
	{ 0,10 },
{ 1,10 },
{ 2,10 },
{ 3,10 },
};

static TexAnim BossFireAttackMotion[] = {
	{ 8,10 },
{ 9, 10 },
};

TexAnimData BossAnimData[] = {
	ANIMDATA(BossTailAnim),
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

static TexAnim BossDeathEffect1[] = {
	{ 0,20 },
{ 1,20 },
{ 2,20 },
{ 3,20 },
{ 4,20 },
{ 5,20 },
{ 6,20 },
{ 7,20 },
{ 8,20 },
{ 9,20 },
};

static TexAnim BossDeathEffect2[] = {
	{ 0,20 },
{ 1,20 },
{ 2,20 },
{ 3,20 },
{ 4,20 },
{ 5,20 },
{ 6,20 },
{ 7,20 },
{ 8,20 },
{ 9,20 },
};

TexAnimData BossDeathEffectAnimData[] = {
	ANIMDATA(BossDeathEffect1),
	ANIMDATA(BossDeathEffect2),
};