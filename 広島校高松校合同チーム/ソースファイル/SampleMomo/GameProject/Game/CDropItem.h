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
2019/03/06 クラス定義。基本機能実装。 by shingai
2019/03/11 アニメーションシステム、影表示システム、当たり判定システム実装。 by shingai
*/

