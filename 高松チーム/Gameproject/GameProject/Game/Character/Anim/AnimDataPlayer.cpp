#include "AnimDataPlayer.h"

/*　担当
国見　Enemy01～05
*/

static TexAnim PlayerIdle[] = {
	{0,5},
{1,5},
{2,5},
{3,5},
{4,5},
{5,5},
{6,5},
{7,5},
};

static TexAnim PlayerLongAttack[] = {
	{10,30},
{11,5},
};

static TexAnim PlayerShortAttack01[] = {
	{20,5},
{21,5},
{22,5},
};

static TexAnim PlayerShortAttack02[] = {
	{30,5},
{31,5},
};

static TexAnim PlayerShortAttack03[] = {
	{40,5},
{41,5},
};

static TexAnim PlayerDamage[] = {
	{50,60},
};

static TexAnim PlayerDeath[] = {
	{50,30},
{51,30},
{52,30},
};

static TexAnim PlayerJumpUp[] = {
	{60,30},
};

static TexAnim PlayerJumpDown[] = {
	{61,10},
{62,30},
};

static TexAnim PlayerUp[] = {
	{70,30},
{71,30},
};

static TexAnim PlayerRun[] = {
	{80,5},
{81,5},
{82,5},
{83,5},
{84,5},
{85,5},
};

static TexAnim PlayerCrouch[] = {
	{90,5},
{91,30},
};

TexAnimData PlayerAnimData[] = {
	ANIMDATA(PlayerIdle),
	ANIMDATA(PlayerLongAttack),
	ANIMDATA(PlayerShortAttack01),
	ANIMDATA(PlayerShortAttack02),
	ANIMDATA(PlayerShortAttack03),
	ANIMDATA(PlayerDamage),
	ANIMDATA(PlayerDeath),
	ANIMDATA(PlayerJumpUp),
	ANIMDATA(PlayerJumpDown),
	ANIMDATA(PlayerUp),
	ANIMDATA(PlayerRun),
	ANIMDATA(PlayerCrouch),
};


/*
プレイヤーエフェクト
*/
static TexAnim PlayerEffectLongAttack[] = {
	{ 11,30 },
{ 12,30 },
};

static TexAnim PLayerEffectShortAttack01[] = {
	{ 0,30 },
{ 1,30 },
};

static TexAnim PLayerEffectShortAttack02[] = {
	{ 2,30 },
{ 3,30 },
};

static TexAnim PLayerEffectShortAttack03[] = {
	{ 4,30 },
{ 5,30 },
};

static TexAnim PlayerEffectSpecialAttack[] = {
	{0,10},
{1,10},
{2,10},
{3,10},
{4,10},
{5,10},
{6,10},
{7,10},
{8,10},
{9,10},
};

TexAnimData PlayerEffectAnimData[] = {
	ANIMDATA(PlayerEffectLongAttack),
	ANIMDATA(PLayerEffectShortAttack01),
	ANIMDATA(PLayerEffectShortAttack02),
	ANIMDATA(PLayerEffectShortAttack03),
	ANIMDATA(PlayerEffectSpecialAttack),
};