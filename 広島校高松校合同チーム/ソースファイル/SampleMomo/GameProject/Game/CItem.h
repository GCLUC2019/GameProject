#pragma once
#include "../Game/CGameSceneObject.h"
#include "CAnimation.h"
#include "../Global.h"

enum {
	eItemPeach,
	eItemFlag,
	eItemMax,
};

class CItem : public CGameSceneObject {
private:
	int m_item_id;
	static bool m_get_item_flag;
public:
	CItem(CVector3D pos, int _item_id);
	~CItem();

	void LoadAnimImage();			//アニメーション読み込み

	void GameSceneObjectUpdate();	//更新処理

	void PlayerGetItem();	//プレイヤーに拾われた時に呼ばれる

	void GameSceneObjectBeforeUpdate();
	void GameSceneObjectAfterUpdate();
	static bool GetIsTakeItemNow();
};

