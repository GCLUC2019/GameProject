#include "CDamageEfect.h"

CDamageEfect::CDamageEfect(CVector3D _pos):CObject(0, DP_UI + 1)
{
	m_damage_p= GET_RESOURCE("GameOver", CImage*);
	m_damage_p->SetPos(_pos.x,_pos.y);
	m_damage_p->SetSize(100,100);
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
