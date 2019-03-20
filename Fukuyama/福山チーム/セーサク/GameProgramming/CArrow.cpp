//è¨êÏ

#include "CArrow.h"
#include <stdio.h>

CTexture CArrow::mTexImage;

void CArrow::Init(){
	mTexImage.Load("P-ya.tga");
	SetVertex(-10.0f, 50.0f, -5.0f, 5.0f);
	mBoxCollider = new CBoxCollider();
	mBoxCollider->mSize.x = 60.0f;
	mBoxCollider->mSize.y = 10.0f;
	mBoxCollider->mpTask = this;
	CCollisionManager::Get()->Add(mBoxCollider);
}

void CArrow::Update(){
	if (mLife > 0){
		mPosition = mPosition + mForward*mVelocity * 2;
		mLife--;
		CRectangle::Update();
	}
	else{
		mEnabled = false;
	}
	CCollisionManager::Get()->Collision(mBoxCollider);
}

void CArrow::Render(){
	if (mLife > 0){
		CRectangle::Render();
	}
}





void CArrow::OnCollision(CCircleCollider*p){
	printf("CArrow::OnCollision\n");
}

void CArrow::OnCollision(CCollider*p){
	if (mTaskTag == EARROW&&p->mpTask->mTaskTag == EENEMYTANK){
		mEnabled = false;
	}
}

