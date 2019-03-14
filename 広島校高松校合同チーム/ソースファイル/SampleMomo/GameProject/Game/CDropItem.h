#pragma once
#include "CObject.h"

enum {
	eItemIdNone,
	eItemIdSpear,
};
class CDropItem : public CObject {
private:
	int m_item_id = eItemIdNone;
	CImage* m_item_image_p = nullptr;
protected:
public:
	CDropItem(int _item_id,CImage* _image_p);
	virtual ~CDropItem();
	void Update();
	void AfterUpdate();
	void Gravity();
	void BeforeCollisionCheck();
	void BeforeUpdate();
	void Draw();
	void CollisionCheck(Task* _collision_task);
};


/*
2019/03/06 �N���X��`�B��{�@�\�����B by shingai
2019/03/11 �A�j���[�V�����V�X�e���A�e�\���V�X�e���A�����蔻��V�X�e�������B by shingai
*/

