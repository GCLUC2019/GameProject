#include "CBullet.h"
#include <stdio.h>

void CBullet::Init(){
	SetVertex(-3.0f, 3.0f, -3.0f, 3.0f);
	mCollider = new CCircleCollider();
	mCollider->mRadius = 3.0f;
	mCollider->mpTask = this;
	CCollisionManager::Get()->Add(mCollider);
}

void CBullet::Update(){
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

void CBullet::Render(){
	if (mLife > 0){
		CRectangle::Render();
	}
}





void CBullet::OnCollision(CCircleCollider*p){
	printf("CBullet::OnCollision\n");
}


void CBullet::OnCollision(CCollider*p){
	if (mTaskTag == EPLAYERBULLET&&p->mpTask->mTaskTag == EENEMYTANK){
		mEnabled = false;
	}
	if (mTaskTag == EENEMYBULLET&&p->mpTask->mTaskTag == EPLAYERTANK){
		mEnabled = false;
	}
}

