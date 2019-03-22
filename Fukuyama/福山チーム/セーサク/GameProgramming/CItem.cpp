//¬ì

#include "CItem.h"
#include "CPlayerTank.h"

CTexture CItem::mTexImage;

void CItem::Init(){
	mTexImage.Load("Item.tga");
	SetVertex(-15.0f, 15.0f, -15.0f, 15.0f);
	mCollider = new CCircleCollider();
	mCollider->mRadius = 10.0f;
	mCollider->mpTask = this;
	CCollisionManager::Get()->Add(mCollider);
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void CItem::Update(){
	CRectangle::Update();
	CCollisionManager::Get()->Collision(mCollider);

	if (mType == 1){
		CRectangle::SetTexture(&mTexImage, 84, 110, 54, 12);
	}
	if (mType == 2){
		CRectangle::SetTexture(&mTexImage, 58, 84, 54, 12);
	}
	if (mType == 3){
		CRectangle::SetTexture(&mTexImage, 110, 138, 54, 12);
	}
}

void CItem::Render(){
	CRectangle::Render();
}

void CItem::OnCollision(CCollider*p){
	if (mTaskTag == EITEM&&p->mpTask->mTaskTag == EPLAYERTANK){
		if (mType == 1){  //‰ñ•œ
			CPlayerTank::spInstance->mHpBar.mHp += 10.0f;
			printf("CItem1::OnCollision\n");
		}
		if (mType == 2){  //‹­‰»
			CPlayerTank::spInstance->strengthen += 300;
			printf("CItem2::OnCollision\n");
		}
		if (mType == 3){  //–³“G
			CPlayerTank::spInstance->Invincible += 1;
			printf("CItem3::OnCollision\n");
		}
		mEnabled = false;
	}
}
