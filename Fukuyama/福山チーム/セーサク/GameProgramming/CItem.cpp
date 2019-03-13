//¬ì

#include "CItem.h"

int type;

void CItem::Init(){
	SetVertex(-10.0f, 10.0f, -10.0f, 10.0f);
	mCollider = new CCircleCollider();
	mCollider->mRadius = 10.0f;
	mCollider->mpTask = this;
	CCollisionManager::Get()->Add(mCollider);
}

void CItem::Update(){
	/*
	if (type == 1){
	SetUv(heal);
	}
	if (type == 2){
	SetUv(strengthen);
	}
	if (type == 3){
	SetUv(Invincible);
	}
	*/
	CCollisionManager::Get()->Collision(mCollider);
}

void CItem::Render(){
	CRectangle::Render();
}

void CItem::OnCollision(CCircleCollider*p){
	if (mTaskTag == EPLAYERBULLET&&p->mpTask->mTaskTag == EENEMYTANK){
		if (type == 1){  //‰ñ•œ

			mEnabled = false;
		}
		if (type == 2){  //‹­‰»

			mEnabled = false;

		}
		if (type == 3){  //–³“G

			mEnabled = false;

		}
	}
}

void CItem::OnCollision(CCollider*p){
	printf("CItem::OnCollision\n");
}


//ªªª
/*
bool CItem::Collision(CCharacter *m, CCharacter *yo) {
//‘Šè‚ÆÕ“Ë‚µ‚Ä‚¢‚é‚©”»’è
if (CRectangle::Collision(yo, &dx, &dy)) {
switch (yo->mTag) {
case EPLAYER: //‘Šè‚ªƒvƒŒƒCƒ„[
if (type == 1){  //‰ñ•œ

}
if (type == 2){  //‹­‰»

}
if (type == 3){  //–³“G

}
}
//Õ“Ë‚µ‚Ä‚¢‚é
return true;
}
//Õ“Ë‚µ‚Ä‚¢‚È‚¢
return false;
}
*/

/*
if (mHpBar.mHp <= 0.0f){
if(rand() % 2)==1{
CItem*Item = new CItem();
Item->mTaskTag = EITEM;
Item->mPosition = mCanon.mMatrix*CVector2(0.0f, 25.0f);
CTaskManager::Get()->Add(Item);
}
}
*/