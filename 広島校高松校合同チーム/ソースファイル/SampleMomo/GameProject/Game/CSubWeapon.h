#pragma once
#include "../Game/CGameSceneObject.h"
#include "CAnimation.h"
#include "../Global.h"

enum {	//アニメーションの種類の番号
	eItemAnimIdIdle,
	eItemyAnimIdMax,
};

enum {	//アニメーションの画像を入れる番号
	eItemAnimIdle1,
	eEnemyAnimMax,
};

enum {  //サブ武器のタイプ
	eWeaponSpear,	//槍
	eWeaponAxe,		//斧
	eWeaponGun		//銃
};

class CSubWeaponItem : public CGameSceneObject {
private:
	bool m_equip_flag;		//武器を装備しているかのフラグ
	int m_weapon_num;		//武器の種類
	float m_energy;			//武器の耐久値
public:
	CSubWeaponItem(CVector3D pos, int weapon_num);
	~CSubWeaponItem();
	void LoadAnimImage();

	void GameSceneObjectUpdate();

	void PlayerGetItem();	//プレイヤーに拾われた時に呼ばれる


};

