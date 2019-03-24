#include "CItem.h"
#include "CCharacterPlayer.h"
#include "CGameScene.h"

bool CItem::m_get_item_flag = true;

enum {	//アニメーションの種類の番号
	eItemAnimIdIdle,
	eItemyAnimIdMax,
};

enum {	//アニメーションの画像を入れる番号
	eItemAnimIdle1,
	eItemAnimMax,
};



CItem::CItem(CVector3D pos, int _item_id) :CGameSceneObject(eTaskIdDropItem, 0)
{
	m_item_id = _item_id;

	SetPos(pos);
	SetPosOld(pos);
	SetSize(CVector2D(50, 50));

	m_speed = 1.0f;

	LoadAnimImage();

	SetIsShowShadow(true);
	SetRads(75, 15, 10);

	SetShadowSize(CVector2D(60, 15));
	SetDrawAdjPos(CVector2D(0, -10.0f));

	//当たり判定の優先度
	SetCollisionPriority(5);

	m_anim_p->SetWillPlayAnim(eItemAnimIdIdle);

	//他のオブジェクトの壁にはならない
	SetIsCollisionOthers(false);
}

CItem::~CItem()
{
	m_get_item_flag = true;
}

void CItem::LoadAnimImage()
{
	switch (m_item_id) {
	case eItemPeach:
		m_anim_p->SetAnimImage(eItemAnimIdle1, GET_RESOURCE("Peach", CImage*));
		break;
	case eItemFlag:
		m_anim_p->SetAnimImage(eItemAnimIdle1, GET_RESOURCE("Flag", CImage*));
		break;
	}

	AnimInfo* m_anim_info = m_anim_p->GetAnimInfoArray();
	m_anim_info[eItemAnimIdIdle].image_num = 1;
	m_anim_info[eItemAnimIdIdle].image_id = eItemAnimIdle1;
	m_anim_info[eItemAnimIdIdle].delay[0] = 30;
}

void CItem::GameSceneObjectUpdate()
{
	CCharacterPlayer * player_p = CCharacterPlayer::GetInstance();
	if (player_p == nullptr) {
		//printf("プレイヤーいません！ SubWeapon\n");
		return;
	}

	if (CInput::GetState(0, CInput::ePush, CInput::eButton4)) {
		CVector3D player_pos = player_p->GetPos();
		float x = m_pos.x - player_pos.x;
		float z = m_pos.z - player_pos.z;

		if (m_get_item_flag && abs(x) < 100 && abs(z) < 100) {
			m_get_item_flag = false;
			PlayerGetItem();
			SetIsDelete();
			CGameScene::GetInstance()->EraseGameSceneObject(this);
		}
	}
}


void CItem::PlayerGetItem()
{
	CSound::GetInstance()->GetSound("SE_Take")->Play();
	m_get_item_flag = false;

	if (m_item_id== eItemPeach) {
		float hp_max = CCharacterPlayer::GetInstance()->GetHitPointMax();
		float recover = hp_max / 2;
		CCharacterPlayer::GetInstance()->HitPointGainValue(recover);
	}

	if (m_item_id == eItemFlag) {
		*CGameScene::GetInstance()->GetReserveNumPointer() += 1;
	}
}
