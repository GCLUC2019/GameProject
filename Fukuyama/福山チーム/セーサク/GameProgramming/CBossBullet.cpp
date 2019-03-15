#include"CBossBullet.h"
#include <stdio.h>
#include"CExplosion.h"

extern CTexture Texture;

void CBossBullet::Init(){
	mCollider = new CCircleCollider();
	SetVertex(-10.0f, 10.0f, -10.0f, 10.0f);
	mCollider->mRadius = 3.0f;
	mCollider->mpTask = this;
	CCollisionManager::Get()->Add(mCollider);
}
void CBossBullet::Update(){
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
void CBossBullet::Render(){
	if (mLife > 0){
		CRectangle::Render();
	}

}
void CBossBullet::OnCollision(CCollider*p){
	if (mTaskTag == EPLAYERBULLET&&p->mpTask->mTaskTag == EENEMYTANK){
		mEnabled = false;
	}
	if (mTaskTag == EENEMYBULLET&&p->mpTask->mTaskTag == EPLAYERTANK){
		mEnabled = false;
	}
	if (mTaskTag == EBOSSBULLET&&p->mpTask->mTaskTag == EENEMYTANK){
		mEnabled = false;
	}
	if (mTaskTag == EBOSSBULLET&&p->mpTask->mTaskTag == EPLAYERTANK){
		mEnabled = false;
	}
	if (mTaskTag == EBOSSBULLET&&p->mpTask->mTaskTag == EENEMYBULLET){
		mEnabled = false;

	}

}