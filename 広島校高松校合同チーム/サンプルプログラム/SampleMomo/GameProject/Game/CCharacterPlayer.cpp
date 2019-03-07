#include "CCharacterPlayer.h"
#include "../Global.h"

#define PLAYER_SPEED (3.0f)

CCharacterPlayer::CCharacterPlayer() :CCharacter(eTaskManagerIdGeneral, eTaskIdPlayer, 0, 0)
{
	m_speed = PLAYER_SPEED;
	SetAnim(ePlayerAnimIdIdle);
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



	ADD_RESOURCE("Player_Move_Anim_0", CImage::LoadImage("momotaro_run_anim_0.png"));
	m_player_image_p[ePlayerAnimMove0] = GET_RESOURCE("Player_Move_Anim_0", CImage*);

	ADD_RESOURCE("Player_Move_Anim_1", CImage::LoadImage("momotaro_run_anim_1.png"));
	m_player_image_p[ePlayerAnimMove1] = GET_RESOURCE("Player_Move_Anim_1", CImage*);

	ADD_RESOURCE("Player_Move_Anim_2", CImage::LoadImage("momotaro_run_anim_2.png"));
	m_player_image_p[ePlayerAnimMove2] = GET_RESOURCE("Player_Move_Anim_2", CImage*);

	ADD_RESOURCE("Player_Move_Anim_3", CImage::LoadImage("momotaro_run_anim_3.png"));
	m_player_image_p[ePlayerAnimMove3] = GET_RESOURCE("Player_Move_Anim_3", CImage*);

	ADD_RESOURCE("Player_Move_Anim_4", CImage::LoadImage("momotaro_run_anim_4.png"));
	m_player_image_p[ePlayerAnimMove4] = GET_RESOURCE("Player_Move_Anim_4", CImage*);

	ADD_RESOURCE("Player_Move_Anim_5", CImage::LoadImage("momotaro_run_anim_5.png"));
	m_player_image_p[ePlayerAnimMove5] = GET_RESOURCE("Player_Move_Anim_5", CImage*);	
}




void CCharacterPlayer::Update(float delta_time)
{
	
	m_will_play_anim_id = ePlayerAnimIdIdle;
	
	InputMove();
	Move();
	MoveLimit();

	SetAnim(m_will_play_anim_id);
	PlayAnim();
}

void CCharacterPlayer::SetAnim(int _anim_id)
{
	if (m_play_anim_id == _anim_id) return;
	m_play_anim_id = _anim_id;
	m_play_anim_count = 0;
}

void CCharacterPlayer::PlayAnim()
{
	if (m_play_anim_count-- <= 0) {
		m_play_anim_count = DEFAULT_ANIM_DELAY;
		switch (m_play_anim_id) {
		case ePlayerAnimIdIdle:
			PlayAnimIdle();
			break;
		case ePlayerAnimIdMove:
			PlayAnimMove();
			break;
		}
	}

}

void CCharacterPlayer::PlayAnimIdle()
{
	switch (m_play_anim_image) {
	case ePlayerAnimIdle0:
		m_play_anim_image = ePlayerAnimIdle1;
		break;
	case ePlayerAnimIdle1:
		m_play_anim_image = ePlayerAnimIdle2;
		break;
	case ePlayerAnimIdle2:
		m_play_anim_image = ePlayerAnimIdle3;
		break;
	case ePlayerAnimIdle3:
		m_play_anim_image = ePlayerAnimIdle0;
		break;
	default:
		m_play_anim_image = ePlayerAnimIdle0;
		break;
	}
}

void CCharacterPlayer::PlayAnimMove()
{
	switch (m_play_anim_image) {
	case ePlayerAnimMove0:
		m_play_anim_image = ePlayerAnimMove1;
		break;
	case ePlayerAnimMove1:
		m_play_anim_image = ePlayerAnimMove2;
		break;
	case ePlayerAnimMove2:
		m_play_anim_image = ePlayerAnimMove3;
		break;
	case ePlayerAnimMove3:
		m_play_anim_image = ePlayerAnimMove4;
		break;
	case ePlayerAnimMove4:
		m_play_anim_image = ePlayerAnimMove5;
		break;
	case ePlayerAnimMove5:
		m_play_anim_image = ePlayerAnimMove0;
		break;
	default:
		m_play_anim_image = ePlayerAnimMove0;
		break;
	}
}

void CCharacterPlayer::InputMove()
{
	m_vec = CVector3D(0, 0, 0);
	m_speed = PLAYER_SPEED;
	if (CInput::GetState(0,CInput::eHold, CInput::eRight)) {
		m_is_flip = false;
		m_will_play_anim_id =ePlayerAnimIdMove;
		m_vec.x = 1;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_is_flip = true;
		m_will_play_anim_id = ePlayerAnimIdMove;
		m_vec.x = -1;
	}

	if (CInput::GetState(0, CInput::eHold, CInput::eUp)) {
		m_will_play_anim_id = ePlayerAnimIdMove;
		m_vec.z = -1;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
		m_will_play_anim_id = ePlayerAnimIdMove;
		m_vec.z = 1;
	}

}

void CCharacterPlayer::Move()
{
	m_pos += m_vec * m_speed;
}

void CCharacterPlayer::Draw()
{
	m_player_image_p[m_play_anim_image]->SetFlipH(m_is_flip);
	m_player_image_p[m_play_anim_image]->SetSize(m_size.x, m_size.y);
	m_player_image_p[m_play_anim_image]->SetPos(m_pos.x, m_pos.y + m_pos.z);
	m_player_image_p[m_play_anim_image]->SetCenter(m_size.x / 2.0,m_size.y / 2.0);
	m_player_image_p[m_play_anim_image]->Draw();
}

void CCharacterPlayer::MoveLimit()
{
	//とりあえずテスト用なので

	if (m_pos.x <= 180.0f) m_pos.x = 180.0f;
	if (m_pos.x >= 1100.0f) m_pos.x = 1100.0f;

	if (m_pos.z <= 180.0f) m_pos.z = 180.0f;
	if (m_pos.z >= 480.0f) m_pos.z = 480.0f;

}
