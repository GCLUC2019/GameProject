#include "../Anim/AnimEnemyEffect.h"

static TexAnim E2AttackEffect[] = {
    { 0,5 },
{ 1,5 },
{ 2,5 },
{ 3,5 },
{ 4,5 }
};

TexAnimData E2AttackEffectAnimData[] = {
    ANIMDATA(E2AttackEffect)
};

static TexAnim E4EXAttackEffect[] = {
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
{ 11,3 }
}; 

static TexAnim E4SAttackEffect[] = {
	{ 0,3 },
{ 1,3 },
{ 2,3 },
{ 3,3 },
{ 4,3 },
{ 5,3 },
{ 6,3 },
{ 7,20 }
};
static TexAnim E4LAttackEffect[] = {
	{ 0,5 },
{ 1,5 },
{ 2,5 },
{ 3,5 },
{ 4,5 },
{ 5,5 },
{ 6,5 },
{ 7,5 },
{ 8,5 },
{ 9,5 },
{ 10,5 },
{ 11,5 },
{ 12,5 },
{ 13,5 },
{ 14,5 }
};

TexAnimData E4AttackEffectAnimData[] = {
	ANIMDATA(E4EXAttackEffect),
	ANIMDATA(E4SAttackEffect),
	ANIMDATA(E4LAttackEffect)
};
