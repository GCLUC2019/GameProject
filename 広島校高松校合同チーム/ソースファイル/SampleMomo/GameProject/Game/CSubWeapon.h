#pragma once
#include "../Game/CGameSceneObject.h"
#include "CAnimation.h"
#include "../Global.h"

class CCharacterPlayer;

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
	
	//bool m_equip_flag;		//プレイヤーがこの武器を装備しているかのフラグ
	int m_weapon_num;		//武器の種類
	float m_energy;			//武器の耐久値
	
	CCharacterPlayer* m_target_p;	//プレイヤーのポインタ

	static bool m_get_flag;	//武器を拾えるかどうかのフラグ(重なった武器を同時に拾えないようにするフラグ)
public:
	CSubWeaponItem(CVector3D pos, int weapon_num);
	~CSubWeaponItem();

	void LoadAnimImage();			//アニメーション読み込み

	void GameSceneObjectUpdate();	//更新処理

	void PlayerGetItem();	//プレイヤーに拾われた時に呼ばれる


};

