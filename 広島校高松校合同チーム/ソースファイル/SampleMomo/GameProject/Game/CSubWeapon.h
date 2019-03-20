#pragma once
#include "../Game/CGameSceneObject.h"
#include "CAnimation.h"
#include "../Global.h"

class CCharacterPlayer;

#define ENDURANCE_MAX 10.0f

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
	eWeaponGun,		//銃
	eWeaponMax,
};

class CSubWeaponItem : public CGameSceneObject {
private:
	
	//bool m_equip_flag;		//プレイヤーがこの武器を装備しているかのフラグ
	int m_weapon_id;		//武器の種類
	float m_endurance;	//武器の耐久値
	static bool m_get_flag;	//武器を拾えるかどうかのフラグ(重なった武器を同時に拾えないようにするフラグ)
public:
	CSubWeaponItem(CVector3D pos, int weapon_id);
	~CSubWeaponItem();

	void LoadAnimImage();			//アニメーション読み込み

	void GameSceneObjectUpdate();	//更新処理

	void PlayerGetItem();	//プレイヤーに拾われた時に呼ばれる


};

