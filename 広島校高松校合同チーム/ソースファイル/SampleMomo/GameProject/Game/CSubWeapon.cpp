#include "../Game/CSubWeapon.h"
#include "CCharacterPlayer.h"

bool CSubWeaponItem::m_get_flag = true;

CSubWeaponItem::CSubWeaponItem(CVector3D pos, int weapon_num) :CGameSceneObject(eTaskIdDropItem, 0)
{
	
	//m_equip_flag = false;
	m_weapon_num = weapon_num;

	SetPos(pos);
	SetSize(CVector2D(150,150));

	m_speed = 1.0f;
	m_energy = 100.0f;

	LoadAnimImage();

	SetIsShowShadow(true);
	SetRads(75, 150, 10);

	SetShadowSize(CVector2D(60, 15));
	SetDrawAdjPos(CVector2D(0, -375.0f));

	//当たり判定の優先度
	SetCollisionPriority(5);

	m_anim_p->SetWillPlayAnim(eItemAnimIdIdle);

	m_target_p = CCharacterPlayer::GetInstance();
}

CSubWeaponItem::~CSubWeaponItem()
{
	m_get_flag = true;

}

void CSubWeaponItem::LoadAnimImage()
{
	m_anim_p->SetAnimImage(eItemAnimIdle1, GET_RESOURCE("IconSpear", CImage*));
	//m_anim_image_p[eItemAnimIdle1] = GET_RESOURCE("Enemy_Damage_0", CImage*);

	AnimInfo* m_anim_info = m_anim_p->GetAnimInfoArray();
	m_anim_info[eItemAnimIdIdle].image_num = 1;
	m_anim_info[eItemAnimIdIdle].image_id = eItemAnimIdle1;
	m_anim_info[eItemAnimIdIdle].delay[0] = 30;

}

void CSubWeaponItem::GameSceneObjectUpdate()
{
	//m_anim_p->SetWillPlayAnim(eItemAnimIdIdle);

	if (CInput::GetState(0, CInput::ePush, CInput::eButton4) ){
		CVector3D player_pos = m_target_p->GetPos();
		float x = m_pos.x - player_pos.x;
		float z = m_pos.z - player_pos.z;
		
		if (m_get_flag && abs(x) < 100 && abs(z) < 50) {	//プレイヤーとの距離がX100Z50以内にいる場合拾えます
			m_get_flag = false;
			PlayerGetItem();
			SetIsDelete();
		}
	}
}

//ここでプレイヤーに武器の種類と残り使用回数を与えてやると良いと思います
void CSubWeaponItem::PlayerGetItem()
{
	m_get_flag = false;

}