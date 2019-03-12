#include "AnimDataPlayer.h"

/*�@�S��
�����@Enemy01�`05
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
	{17,30},
{18,30},
{19,30},
};

static TexAnim PlayerJumpUp[] = {
	{20,30},
{21,30},
};

static TexAnim PlayerJumpDown[] = {
	{21,30},
{22,30},
};

static TexAnim PlayerUp[] = {
	{23,30},
{24,30},
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