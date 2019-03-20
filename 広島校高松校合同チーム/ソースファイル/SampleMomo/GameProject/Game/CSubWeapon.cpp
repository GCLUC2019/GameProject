#include "../Game/CSubWeapon.h"
#include "CCharacterPlayer.h"

bool CSubWeaponItem::m_get_flag = true;

CSubWeaponItem::CSubWeaponItem(CVector3D pos, int weapon_num) :CGameSceneObject(eTaskIdDropItem, 0)
{
	
	//m_equip_flag = false;
	m_weapon_id = weapon_num;

	SetPos(pos);
	SetPosOld(pos);
	SetSize(CVector2D(150,150));

	m_speed = 1.0f;
	m_endurance = ENDURANCE_MAX;

	LoadAnimImage();

	SetIsShowShadow(true);
	SetRads(75, 15, 10);

	SetShadowSize(CVector2D(60, 15));
	SetDrawAdjPos(CVector2D(0, -68.0f));

	//当たり判定の優先度
	SetCollisionPriority(5);

	m_anim_p->SetWillPlayAnim(eItemAnimIdIdle);


	//他のオブジェクトの壁にはならない
	SetIsCollisionOthers(false);
}

CSubWeaponItem::~CSubWeaponItem()
{
	m_get_flag = true;

}

void CSubWeaponItem::LoadAnimImage()
{
	switch (m_weapon_id) {
	case eWeaponSpear:
		m_anim_p->SetAnimImage(eItemAnimIdle1, GET_RESOURCE("IconSpear", CImage*));
		break;
	case eWeaponAxe:
		m_anim_p->SetAnimImage(eItemAnimIdle1, GET_RESOURCE("IconAxe", CImage*));
		break;
	case eWeaponGun:
		m_anim_p->SetAnimImage(eItemAnimIdle1, GET_RESOURCE("IconGun", CImage*));
		break;
	}
	

	AnimInfo* m_anim_info = m_anim_p->GetAnimInfoArray();
	m_anim_info[eItemAnimIdIdle].image_num = 1;
	m_anim_info[eItemAnimIdIdle].image_id = eItemAnimIdle1;
	m_anim_info[eItemAnimIdIdle].delay[0] = 30;

}

void CSubWeaponItem::GameSceneObjectUpdate()
{
	CCharacterPlayer * player_p = CCharacterPlayer::GetInstance();
	if (player_p == nullptr) {
		printf("プレイヤーいません！ SubWeapon\n");
		return;
	}

	if (CInput::GetState(0, CInput::ePush, CInput::eButton4) ){
		CVector3D player_pos = player_p->GetPos();
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
	CCharacterPlayer::GetInstance()->PlayerGainEquip(m_weapon_id,m_endurance);
}