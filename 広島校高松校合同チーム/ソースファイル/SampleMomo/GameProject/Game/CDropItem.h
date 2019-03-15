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
2019/03/06 クラス定義。基本機能実装。 by shingai
2019/03/11 アニメーションシステム、影表示システム、当たり判定システム実装。 by shingai
*/

