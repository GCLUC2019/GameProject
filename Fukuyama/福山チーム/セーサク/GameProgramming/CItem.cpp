//小川

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
	if (type == 1){  //回復

	}
	if (type == 2){  //強化

	}
	if (type == 3){  //無敵

	}
}


//↑↑↑
/*
bool CItem::Collision(CCharacter *m, CCharacter *yo) {
//相手と衝突しているか判定
if (CRectangle::Collision(yo, &dx, &dy)) {
switch (yo->mTag) {
case EPLAYER: //相手がプレイヤー
if (type == 1){  //回復

}
if (type == 2){  //強化

}
if (type == 3){  //無敵

}
}
//衝突している
return true;
}
//衝突していない
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