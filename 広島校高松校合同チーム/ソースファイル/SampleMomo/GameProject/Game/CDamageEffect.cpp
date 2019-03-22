#include "CDamageEffect.h"
#include "CAnimation.h"
#include "CGameScene.h"

enum {
	eEffectDamage=0,
	eEffectSlashX,
	eEffectSlashY,
};

CDamageEffect::CDamageEffect(CVector3D * _pos_p, CVector2D _offset_pos, CVector2D _size, double _count,int _effect_id = 0):CObject(0, DP_UI + 100)
{
	m_anim_p = new CAnimation();
	m_pos_p = _pos_p;
	m_offset_pos = _offset_pos;

	m_size = _size;

	SetPos(*m_pos_p);
	SetPosOld(m_pos);

	m_delete_cnt = _count;

	m_effect_id = _effect_id;

	LoadAnimImage();
}

CDamageEffect::~CDamageEffect()
{
	if(m_anim_p != nullptr) delete m_anim_p;
}

void CDamageEffect::Update()
{
	m_pos = *m_pos_p;
	printf("x %lf y %lf z %lf\n", m_pos.x, m_pos.y, m_pos.z);
	m_delete_cnt -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if (m_delete_cnt <= 0.0) {
		SetIsDelete();
		CGameScene::GetInstance()->EraseGameSceneObject(this);
	}
}

void CDamageEffect::Draw()
{
	m_anim_p->SetWillPlayAnim(0);
	m_anim_p->CheckWillPlayAnim();
	m_anim_p->PlayAnim();
	CImage* draw_image = m_anim_p->GetPlayAnimImage();

	draw_image->SetPos(CVector2D(m_pos.x + m_offset_pos.x,m_pos.y+m_pos.z + m_offset_pos.y) - GetScroll());
	draw_image->SetSize(m_size.x, m_size.y);
	draw_image->Draw();
}

void CDamageEffect::LoadAnimImage()
{
	m_anim_p->ReadAnimDataFile("Effect/EFFECT_ANIM_DATA.anim");
}

void CDamageEffect::ChangeAnim(int _anim_id)
{
	switch (_anim_id)
	{
	case eEffectDamage:
		m_anim_p->SetWillPlayAnim(eEffectDamage);
		break;
	case eEffectSlashX:
		m_anim_p->SetWillPlayAnim(eEffectSlashX);
		break;
	case eEffectSlashY:
		m_anim_p->SetWillPlayAnim(eEffectSlashY);
		break;
	default:
		break;
	}
}
