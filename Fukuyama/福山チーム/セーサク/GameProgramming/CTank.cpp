#include "CRectangle.h"
#include "CTank.h"
#include<stdio.h>

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
	mHead.Update();
	mCanon.Update();

	CMatrix33 rot;
	rot.SetRotation(mRotation);
	mForward = rot.MultiVector2(CVector2(0.0f, 1.0f));
	mBackward = rot.MultiVector2(CVector2(0.0f, 1.0f));
	mHead.mMatrix = mMatrix*mHead.mMatrix;
	mCanon.mMatrix = mHead.mMatrix*mCanon.mMatrix;
	mPForward = rot.MultiVector2(CVector2(0.0f, 2.3f));   //’Ç‰Á Š˜“c
	mEForward = rot.MultiVector2(CVector2(0.0f, 0.6f));

}
void CTank::LeftTurn(){
	mRotation += 1.0f;
}
void CTank::RightTurn(){
	mRotation -= 1.0f;
}
void CTank::Forward(){
	mPosition = mPosition + mForward;
}
void CTank::Backward(){
	mPosition = mPosition - mForward;
}

void CTank::HeadLeftTurn(){
	mHead.mRotation += 1.0f;
}
void CTank::HeadRightTurn(){
	mHead.mRotation -= 1.0f;
}
void CTank::PHeadLeftTurn(){
	mHead.mRotation += 20.0f;
}
void CTank::PHeadRightTurn(){
	mHead.mRotation -= 20.0f;
}



//’Ç‰Á Š˜“c
void CTank::EnemyUp(){
	mPosition.y += 1;
}
void CTank::EnemyDown(){
	mPosition.y -= 1;
}
void CTank::PForward(){
	mPosition = mPosition + mPForward;
}

void CTank::EForward(){
	mPosition = mPosition + mEForward;
}
void CTank::EnemyUp2(){
	mPosition.x += 0.5f;
}
void CTank::EnemyDown2(){
	mPosition.x -= 0.5f;
}



void CTank::Render(){
	CRectangle::Render();
	mHead.Render();
	mCanon.Render();

}
void CTank::OnCollision(CCollider*p){
	printf("CTank::OnCollision\n");
}

