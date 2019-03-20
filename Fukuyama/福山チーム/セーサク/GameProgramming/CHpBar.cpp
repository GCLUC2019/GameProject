#include "CHpBar.h"

void CHpBar::SetHpBar(CRectangle*task, const CVector2&pos, const CVector2 &size, float*color, float max, float hp){
	SetColor(0.0f, 0.0f, 0.0f, 1.0f);
	SetVertex(0.0f, size.x,0.0f, size.y);
	mPosition.x = pos.x + -size.x / 2.0f;
	mPosition.y = pos.y;
	mMax = max;
	mHp = hp;
	mBar.SetColor(color[0], color[1], color[2], color[3]);
	mBar.SetVertex(0.0f, size.x, 0.0f, size.y);
	mBar.mScale.x = mHp / mMax;
	mpTask = task;
}

void CHpBar::Update(){
	CRectangle::Update();
	mBar.mScale.x = mHp / mMax;
	mBar.Update();
	CMatrix33 matrix;
	matrix.SetTranslate(mpTask->mPosition.x, mpTask->mPosition.y);
	mMatrix = matrix*mMatrix;
	mBar.mMatrix = mMatrix*mBar.mMatrix;
	if (mHp <= 0.0f){
		mEnabled = false;
	}
}

void CHpBar::PUpdate(){
	CRectangle::Update();
	mBar.mScale.x = mHp / mMax;
	mBar.Update();
	CMatrix33 matrix;
	//matrix.SetTranslate(mpTask->mPosition.x, mpTask->mPosition.y);
	mMatrix = matrix*mMatrix;
	mBar.mMatrix = mMatrix*mBar.mMatrix;
	if (mHp <= 0.0f){
		mEnabled = false;
	}
}

void CHpBar::Render(){
	CRectangle:: Render();
	mBar.Render();
}