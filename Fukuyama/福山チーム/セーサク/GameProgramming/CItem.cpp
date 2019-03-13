//����

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
		if (type == 1){  //��

			mEnabled = false;
		}
		if (type == 2){  //����

			mEnabled = false;

		}
		if (type == 3){  //���G

			mEnabled = false;

		}
	}
}

void CItem::OnCollision(CCollider*p){
	printf("CItem::OnCollision\n");
}


//������
/*
bool CItem::Collision(CCharacter *m, CCharacter *yo) {
//����ƏՓ˂��Ă��邩����
if (CRectangle::Collision(yo, &dx, &dy)) {
switch (yo->mTag) {
case EPLAYER: //���肪�v���C���[
if (type == 1){  //��

}
if (type == 2){  //����

}
if (type == 3){  //���G

}
}
//�Փ˂��Ă���
return true;
}
//�Փ˂��Ă��Ȃ�
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