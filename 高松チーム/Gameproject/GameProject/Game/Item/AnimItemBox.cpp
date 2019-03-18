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

static TexAnim DummyBoxOpen[] = {
	{ 7,20 },
{ 8,20 },
{ 9,20 },
};

TexAnimData ItemBoxAnimData[] = {
	ANIMDATA(TrueBoxClose),
	ANIMDATA(TrueBoxOpen),
	ANIMDATA(DummyBoxClose),
	ANIMDATA(DummyBoxOpen),
};

