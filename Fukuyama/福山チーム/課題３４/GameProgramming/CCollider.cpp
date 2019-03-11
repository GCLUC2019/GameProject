#include "CCollider.h"
#include "math.h"
#include <stdio.h>

CCollisionManager*CCollisionManager::mpInstance = 0;

CCollisionManager*CCollisionManager::Get(){
	if (mpInstance == 0){
		mpInstance = new CCollisionManager();
	}
	return mpInstance;
}

bool CCollider::Collision(CCircleCollider*p1, CCircleCollider*p2){
	CVector2 pos1 =
		p1->mpTask->mMatrix*p1->mPosition;
	CVector2 pos2 =
		p2->mpTask->mMatrix*p2->mPosition;
	pos1 = pos1 - pos2;
	//return pos1.Length() < p1->mRadius + p2->mRadius;
	if (pos1.Length() < p1->mRadius + p2->mRadius){
		p1->mAdjust = pos1*
			((p1->mRadius + p2->mRadius - pos1.Length())
			/(p1->mRadius + p2->mRadius));
		p2->mAdjust = p1->mAdjust*-1;
		return true;
	}
	else{
		p1->mAdjust = p2->mAdjust = CVector2(0.0f, 0.0f);
	}
	return false;
}

bool CCollider::Collision(CCircleCollider*p1, CBoxCollider*p2){
	CVector2 pos1 =
		p1->mpTask->mMatrix*p1->mPosition;
	CVector2 up =
		p2->mpTask->mMatrix*CVector2(0.0f, 1.0f) - 
		p2->mpTask->mMatrix*CVector2(0.0f, 0.0f);
	CVector2 right =
		p2->mpTask->mMatrix*CVector2(1.0f, 0.0f) - 
		p2->mpTask->mMatrix*CVector2(0.0f, 0.0f);
	pos1 = pos1 - p2->mpTask->mPosition;
	float dup = up.dot(pos1);
	float dright = right.dot(pos1);
	//return dup < p1->mRadius + p2->mSize.y &&
		//dright < p1->mRadius + p2->mSize.x;
	if (abs(dup) < p1->mRadius + p2->mSize.y&&abs(dright) < p1->mRadius + p2->mSize.x)
	{
		float fup = ((p1->mRadius + p2->mSize. y) - abs(dup));
		float fright = ((p1->mRadius + p2->mSize.x) - abs(dright));
		if (dup < 0.0f){
			fup = -fup;
		}
		if (dright < 0.0f){
			fright = -fright;
		}
		if (abs(fup)>abs(fright)){
			p1->mAdjust = right*fright;
		}
		else if (abs(fup) < abs(fright)){
			p1->mAdjust = up*fup;
		}
		else{
			p1->mAdjust = up*fup + right*fright;
		}
		p2->mAdjust = p1->mAdjust*-1;
		return true;
	}
	else{
		p1 -> mAdjust = p2->mAdjust = CVector2(0.0f, 0.0f);
	}
	return false;
}

void CCollisionManager::Add(CCollider*p){
	if (mpHead == 0){
		mpHead = p;
		mpTail = p;
		mpTail->mpNext = 0;
	}
	else{
		mpTail->mpNext = p;
		mpTail = p;
		mpTail->mpNext = 0;
	}
}

bool CCircleCollider::Collision(CCircleCollider*p){
	return CCollider::Collision(p, this);
}

bool CBoxCollider::Collision(CCircleCollider*p){
	return CCollider::Collision(p,this);
}


void CCollisionManager::Collision(CCircleCollider*p){
	CCollider*col = mpHead;
	while (col){
		if (col != p && col->Collision(p)){
			p->mpTask->OnCollision(col);
			col->mpTask->OnCollision(p);
		}
		col = col->mpNext;
	}
}

void CCollisionManager::Collision(CBoxCollider*p){
	CCollider*col = mpHead;
	while (col){
		if (col != p&&col->Collision(p)){
			p->mpTask->OnCollision(col);
			col->mpTask->OnCollision(p);
		}
		col = col->mpNext;
	}
}

void CCollisionManager::Destroy(){
	CCollider*col = mpHead;
	while (col){
		mpHead = col->mpNext;
		delete col;
		col = mpHead;
	}
	mpTail = 0;
	delete mpInstance;
	mpInstance = 0;
}

void CCollisionManager::Remove(){
	CCollider*prev = 0;
	CCollider*col = mpHead;
	while (col){
		if (!col->mpTask->mEnabled){
			if (prev == 0){
				mpHead = col->mpNext;
				delete col;
				col = mpHead;
			}
			else{
				prev->mpNext = col->mpNext;
				delete col;
				col = prev->mpNext;
			}
		}
		else{
			prev = col;
			col = col->mpNext;
		}
	}
	mpTail = prev;
}