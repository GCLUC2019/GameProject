//è¨êÏ

#include "CArrow.h"
#include <stdio.h>

void CArrow::Init(){
	SetVertex(-3.0f, 3.0f, -3.0f, 3.0f);
	mCollider = new CCircleCollider();
	mCollider->mRadius = 3.0f;
	mCollider->mpTask = this;
	CCollisionManager::Get()->Add(mCollider);
}

void CArrow::Update(){
	if (mLife > 0){
		mPosition = mPosition + mForward*mVelocity;
		mLife--;
		CRectangle::Update();
	}
	else{
		mEnabled = false;
	}
	CCollisionManager::Get()->Collision(mCollider);
}

void CArrow::Render(){
	if (mLife > 0){
		CRectangle::Render();
	}
}





void CArrow::OnCollision(CCircleCollider*p){
	printf("CArrow::OnCollision\n");
}

/*
void CArrow::OnCollision(CCollider*p){
if (mTaskTag == EPLAYERARROW&&p->mpTask->mTaskTag == EENEMYTANK){
mEnabled = false;
}
}
*/

