#include"AnimItemBox.h"


static TexAnim TrueBoxClose[] = {
	{ 0,30 },
{ 1,30 },
};
static TexAnim TrueBoxOpen[] = {
	{ 2,30 },
};

static TexAnim DummyBoxClose[] = {
	{ 5,30 },
{ 6,30 },
};

static TexAnim DummyBoxOpen01[] = {
	{ 7,20 },
};


static TexAnim DummyBoxOpen02[] = {
{ 8,30 },
{ 9,30 },
};


TexAnimData ItemBoxAnimData[] = {
	ANIMDATA(TrueBoxClose),
	ANIMDATA(TrueBoxOpen),
	ANIMDATA(DummyBoxClose),
	ANIMDATA(DummyBoxOpen01),
	ANIMDATA(DummyBoxOpen02),
};

