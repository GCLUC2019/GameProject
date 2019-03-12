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

static TexAnim BossTailAttack[] = {
	{ 24,50 },
{ 25,50 },
{ 26,50 },
{ 27,50 },
};

static TexAnim BossFireAttack[] = {
	{ 32,50 },
{ 33,50 },
};


TexAnimData BossAnimData[] = {
	ANIMDATA(BossHead),
	ANIMDATA(BossTail),
	ANIMDATA(BossHand),
	ANIMDATA(BossTailAttack),
	ANIMDATA(BossFireAttack),
};

static TexAnim BossLazerEffect[] = {
	{ 0,50 },
	{ 1,50 },
	{ 2,50 },
	{ 3,50 },
	{ 4,50 },
	{ 5,50 },
	{ 6,50 },
	{ 7,50 },
};

static TexAnim BossFireEffect[] = {
	{ 0,50 },
	{ 1,50 },
	{ 2,50 },
	{ 3,50 },
	{ 4,50 },
	{ 5,50 },
	{ 6,50 },
	{ 7,50 },
	{ 8,50 },
	{ 9,50 },
	{ 10,50 },
	{ 11,50 },
	{ 12,50 },
	{ 13,50 },
	{ 14,50 },
	{ 15,50 },
	{ 16,50 },
	{ 17,50 },
	{ 18,50 },
	{ 19,50 },
	{ 20,50 },
};

TexAnimData BossFireEffectAnimData[] = {
	ANIMDATA(BossLazerEffect),
	ANIMDATA(BossFireEffect),
};