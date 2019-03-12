#include "AnimDataPlayer.h"

/*Å@íSìñ
çëå©Å@Enemy01Å`05
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
{11,30},
};

static TexAnim PlayerShortAttack01[] = {
	{20,15},
{21,15},
{22,15},
};

static TexAnim PlayerShortAttack02[] = {
	{30,15},
{31,15},
};

static TexAnim PlayerShortAttack03[] = {
	{40,15},
{41,15},
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
	{90,30},
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