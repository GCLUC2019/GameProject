#include "CCharacterPlayer.h"

CCharacterPlayer::CCharacterPlayer() :CCharacter(eId_CharacterPlayer, eUp_CharacterPlayer, eRd_CharacterPlayer)
{
	LoadAnimImage();
}

CCharacterPlayer::~CCharacterPlayer()
{
}

void CCharacterPlayer::LoadAnimImage()
{
	ADD_RESOURCE("Player_Idle_Anim_0", CImage::LoadImage("momotaro_idle_anim_0.png"));
	m_player_image_p[ePlayerAnimIdle0] = GET_RESOURCE("Player_Idle_Anim_0", CImage*);

	ADD_RESOURCE("Player_Idle_Anim_1", CImage::LoadImage("momotaro_idle_anim_1.png"));
	m_player_image_p[ePlayerAnimIdle1] = GET_RESOURCE("Player_Idle_Anim_1", CImage*);

	ADD_RESOURCE("Player_Idle_Anim_2", CImage::LoadImage("momotaro_idle_anim_2.png"));
	m_player_image_p[ePlayerAnimIdle2] = GET_RESOURCE("Player_Idle_Anim_2", CImage*);

	ADD_RESOURCE("Player_Idle_Anim_3", CImage::LoadImage("momotaro_idle_anim_3.png"));
	m_player_image_p[ePlayerAnimIdle3] = GET_RESOURCE("Player_Idle_Anim_3", CImage*);
}




void CCharacterPlayer::Update(float delta_time)
{
	PlayAnim();
}

void CCharacterPlayer::SetAnim(int _anim_id)
{
	m_play_anim = _anim_id;
	m_play_anim_count = DEFAULT_ANIM_DELAY;
}

void CCharacterPlayer::PlayAnim()
{
	if (m_play_anim_count-- <= 0) {
		m_play_anim_count = DEFAULT_ANIM_DELAY;
		switch (m_play_anim) {
		case ePlayerAnimIdle0:
			m_play_anim = ePlayerAnimIdle1;
			break;
		case ePlayerAnimIdle1:
			m_play_anim = ePlayerAnimIdle2;
			break;
		case ePlayerAnimIdle2:
			m_play_anim = ePlayerAnimIdle3;
			break;
		case ePlayerAnimIdle3:
			m_play_anim = ePlayerAnimIdle0;
			break;
		}
	}

}

void CCharacterPlayer::Render()
{
	m_player_image_p[m_play_anim]->SetSize(m_size.x, m_size.y);
	m_player_image_p[m_play_anim]->SetPos(m_pos.x, m_pos.y + m_pos.z);
	m_player_image_p[m_play_anim]->Draw();
}
