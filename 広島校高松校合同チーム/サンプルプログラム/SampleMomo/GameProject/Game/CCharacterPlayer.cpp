#include "CCharacterPlayer.h"

CCharacterPlayer::CCharacterPlayer() :CCharacter(eId_CharacterPlayer, eUp_CharacterPlayer, eRd_CharacterPlayer)
{
	ADD_RESOURCE("Player_Idle_Anim_1",CImage::LoadImage("momotaro_idle_anim_2.png"));
	m_player_image_p = GET_RESOURCE("Player_Idle_Anim_1",CImage*);
}

CCharacterPlayer::~CCharacterPlayer()
{
}

void CCharacterPlayer::Update(float delta_time)
{

}

void CCharacterPlayer::Render()
{
	m_player_image_p->SetSize(m_size.x, m_size.y);
	m_player_image_p->SetPos(m_pos.x, m_pos.y + m_pos.z);
	m_player_image_p->Draw();
}
