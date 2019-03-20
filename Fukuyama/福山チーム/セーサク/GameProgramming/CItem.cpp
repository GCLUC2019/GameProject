//小川

#include "CItem.h"
#include "CPlayerTank.h"

CTexture CItem::mTexImage;
CTexture CItem::mTexImage2;
CTexture CItem::mTexImage3;


void CItem::Init(){
	SetVertex(-20.0f, 20.0f, -20.0f, 20.0f);
	mCollider = new CCircleCollider();
	mCollider->mRadius = 10.0f;
	mCollider->mpTask = this;
	CCollisionManager::Get()->Add(mCollider);
	if (mType == 1){
		mTexImage.Load("heal");
	}
	if (mType == 2){
		mTexImage.Load("strengthen");
	}
	if (mType == 3){
		mTexImage.Load("Invincible");
	}
}

void CItem::Update(){
	CCollisionManager::Get()->Collision(mCollider);
}

void CItem::Render(){
	CRectangle::Render();
}

void CItem::OnCollision(CCollider*p){
	if (mTaskTag == EITEM&&p->mpTask->mTaskTag == EPLAYERTANK){
		if (mType == 1){  //回復
			CPlayerTank::spInstance->mHpBar.mHp += 40.0f;
			printf("CItem1::OnCollision\n");
		}
		if (mType == 2){  //強化

			printf("CItem2::OnCollision\n");
		}
		if (mType == 3){  //無敵

			printf("CItem3::OnCollision\n");
		}
		mEnabled = false;
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