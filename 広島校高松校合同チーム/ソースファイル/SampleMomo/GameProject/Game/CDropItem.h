#pragma once
#include "CGameSceneObject.h"

enum {
	eItemIdNone,
	eItemIdSpear,
};

enum {
	eItemAnimIdStatic = 0,
};

enum {
	eItemAnimStatic0,
};


class CDropItem : public CGameSceneObject {
private:
	int m_item_id = eItemIdNone;
	CImage* m_item_image_p = nullptr;
protected:
public:
	CDropItem(int _item_id);
	virtual ~CDropItem();
	void GameSceneObjectUpdate();
	void GameSceneObjectAfterUpdate();
	void GameSceneObjectBeforeCollisionCheck();
	void GameSceneObjectBeforeUpdate();
	void GameSceneObjectDraw();
	void GameSceneObjectCollisionCheck(Task* _collision_task);
};


/*
2019/03/06 �N���X��`�B��{�@�\�����B by shingai
2019/03/11 �A�j���[�V�����V�X�e���A�e�\���V�X�e���A�����蔻��V�X�e�������B by shingai
*/

