#include "CDamageEfect.h"
#include "CAnimation.h"

CDamageEfect::CDamageEfect(CVector3D * _pos_p):CGameSceneObject(0, DP_UI + 1)
{
	m_target_p = _pos_p;
	m_damage_p->SetPos(m_target_p->x, m_target_p->y);
	m_damage_p->SetSize(100,100);
	m_anim_p->SetWillPlayAnim(0);
}

CDamageEfect::~CDamageEfect()
{
}

void CDamageEfect::Update()
{
	m_delete_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if (m_delete_cnt > 60)SetIsDelete();
}

void CDamageEfect::Draw()
{
	m_damage_p->Draw();
}

void CDamageEfect::LoadAnimImage()
{
	m_anim_p->ReadAnimDataFile("Efect/Efect_ANIM_DATA.anim");
}
