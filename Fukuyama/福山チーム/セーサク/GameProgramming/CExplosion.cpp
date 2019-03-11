#include "CExplosion.h"

void CExplosion::Init(){
	SetVertex(-30, 30, -30, 30);
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mLife = 20;
	mEnabled = true;
	mSize = 3.0f / mLife;
	mScale = CVector2(0.0f, 0.0f);
	mAlpha = 1.0f / mLife;
}

void CExplosion::Update(){
	if (mLife > 0){
		mLife--;
		mScale.x += mSize;
		mScale.y += mSize;
		CRectangle::Update();
		mColor[3] -= mAlpha;
	}
	else{
		mEnabled = false;
	}
}
	