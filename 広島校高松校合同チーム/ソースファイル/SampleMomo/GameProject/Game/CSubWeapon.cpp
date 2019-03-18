#include "../Game/CSubWeapon.h"

CSubWeaponItem::CSubWeaponItem(CVector3D pos, int weapon_num) :CGameSceneObject(eTaskIdDropItem, 0)
{
	
	m_equip_flag = false;
	m_weapon_num = weapon_num;

	SetPos(pos);
	SetSize(CVector2D(500,500));

	m_speed = 1.0f;
	m_energy = 100.0f;

	LoadAnimImage();

	SetIsShowShadow(true);
	SetRads(75, 150, 10);

	SetShadowSize(CVector2D(160, 50));
	SetDrawAdjPos(CVector2D(-60, 0.0f));

	//“–‚½‚è”»’è‚Ì—Dæ“x
	SetCollisionPriority(5);

	m_anim_p->SetWillPlayAnim(eItemAnimIdIdle);

}

CSubWeaponItem::~CSubWeaponItem()
{
	

}

void CSubWeaponItem::LoadAnimImage()
{
	m_anim_p->SetAnimImage(eItemAnimIdle1, GET_RESOURCE("SpearIcon", CImage*));
	//m_anim_image_p[eItemAnimIdle1] = GET_RESOURCE("Enemy_Damage_0", CImage*);

	AnimInfo* m_anim_info = m_anim_p->GetAnimInfoArray();
	m_anim_info[eItemAnimIdIdle].image_num = 1;
	m_anim_info[eItemAnimIdIdle].image_id = eItemAnimIdle1;
	m_anim_info[eItemAnimIdIdle].delay[0] = 30;

}

void CSubWeaponItem::GameSceneObjectUpdate()
{
	m_anim_p->SetWillPlayAnim(eItemAnimIdIdle);
}

void CSubWeaponItem::PlayerGetItem()
{
}