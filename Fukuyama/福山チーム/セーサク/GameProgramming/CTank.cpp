#include "CTank.h"
#include "CRectangle.h"
#include "CExplosion.h"
#include "CTexture.h"


void CTank::Init(){
	SetVertex(-20.0f, 20.0f, -24.0f, 24.0f);
	mHead.SetVertex(-12.0f, 12.0f, -12.0f, 12.0f);
	mHead.mPosition.y = -4.0f;
	mCanon.SetVertex(-3.0, 3.0f, 12.0f, 25.0f);
	mBoxCollider.mSize.x = 20.0f;
	mBoxCollider.mSize.y = 24.0f;
	mBoxCollider.mpTask = this;
}


void CTank::Update(){
	CRectangle::Update();

	CMatrix33 rot;
	rot.SetRotation(mRotation);
	mForward = rot.MultiVector2(CVector2(0.0f, 1.0f));
	mBackward = rot.MultiVector2(CVector2(0.0f, -1.0f));
	mHead.Update();
	mHead.mMatrix = mMatrix*mHead.mMatrix;
	mCanon.Update();
	mCanon.mMatrix = mHead.mMatrix*mCanon.mMatrix;
}


void CTank::LeftTurn(){
	mRotation = mRotation+1;
}


void CTank::RightTurn(){
	mRotation = mRotation-1;
}

void CTank::Forward(){
	mPosition = mPosition + mForward;
}

void CTank::Backward(){
	mPosition = mPosition - mForward;
}

void CTank::HeadLeftTurn(){
	mHead.mRotation = mHead.mRotation + 1;
}


void CTank::HeadRightTurn(){
	mHead.mRotation = mHead.mRotation - 1;
}

void CTank::Render(){
	CRectangle::Render();
	mHead.Render();
	mCanon.Render();
}

void CTank::OnCollision(CCollider*p){
	printf("CTank::OnCollision\n");
}
