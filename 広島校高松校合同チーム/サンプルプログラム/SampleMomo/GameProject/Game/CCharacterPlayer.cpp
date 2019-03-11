#include "CCharacterPlayer.h"
#include "../Global.h"

#define PLAYER_SPEED (3.0f)

CCharacterPlayer::CCharacterPlayer() :CCharacter(eTaskIdPlayer, 0)
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



	ADD_RESOURCE("Player_Move_Anim_0", CImage::LoadImage("momotaro_move_anim_0.png"));
	m_player_image_p[ePlayerAnimMove0] = GET_RESOURCE("Player_Move_Anim_0", CImage*);

	ADD_RESOURCE("Player_Move_Anim_1", CImage::LoadImage("momotaro_move_anim_1.png"));
	m_player_image_p[ePlayerAnimMove1] = GET_RESOURCE("Player_Move_Anim_1", CImage*);

	ADD_RESOURCE("Player_Move_Anim_2", CImage::LoadImage("momotaro_move_anim_2.png"));
	m_player_image_p[ePlayerAnimMove2] = GET_RESOURCE("Player_Move_Anim_2", CImage*);

	ADD_RESOURCE("Player_Move_Anim_3", CImage::LoadImage("momotaro_move_anim_3.png"));
	m_player_image_p[ePlayerAnimMove3] = GET_RESOURCE("Player_Move_Anim_3", CImage*);

	ADD_RESOURCE("Player_Move_Anim_4", CImage::LoadImage("momotaro_move_anim_4.png"));
	m_player_image_p[ePlayerAnimMove4] = GET_RESOURCE("Player_Move_Anim_4", CImage*);

	ADD_RESOURCE("Player_Move_Anim_5", CImage::LoadImage("momotaro_move_anim_5.png"));
	m_player_image_p[ePlayerAnimMove5] = GET_RESOURCE("Player_Move_Anim_5", CImage*);	

	ADD_RESOURCE("Player_Move_Anim_6", CImage::LoadImage("momotaro_move_anim_6.png"));
	m_player_image_p[ePlayerAnimMove6] = GET_RESOURCE("Player_Move_Anim_6", CImage*);

	ADD_RESOURCE("Player_Move_Anim_7", CImage::LoadImage("momotaro_move_anim_7.png"));
	m_player_image_p[ePlayerAnimMove7] = GET_RESOURCE("Player_Move_Anim_7", CImage*);

}




void CCharacterPlayer::Update()
{
	m_will_play_anim_id = ePlayerAnimIdIdle;
	InputMove();
	InputJump();
	Gravity();
	Jumping();
	Move();
	MoveLimit();
	CalcScroll();

	SetAnim(m_will_play_anim_id);
	PlayAnim();
	SetDrawPriority(m_pos.z);
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
		m_play_anim_image = ePlayerAnimMove6;
		break;
	case ePlayerAnimMove6:
		m_play_anim_image = ePlayerAnimMove7;
		break;
	case ePlayerAnimMove7:
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

void CCharacterPlayer::InputJump()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton1) && m_is_jumping == false) {
		m_will_play_anim_id = ePlayerAnimIdMove;
		m_is_jumping = true;
		m_jumping_count = 30;
	}
}

void CCharacterPlayer::Jumping()
{
	if (m_is_jumping == true) {
		if (m_jumping_count-- <= 0) {
			m_is_jumping = false;
		}


		m_vec.y -= 0.1 + GRAVITY;
		if (m_vec.y <= -3.0) m_vec.y = -3.0;
	}
}

void CCharacterPlayer::Move()
{
	m_pos_old = m_pos;
	m_pos += m_vec * m_speed;
}

void CCharacterPlayer::Gravity()
{
	m_vec.y += GRAVITY;
	if (m_vec.y >= 3.0) m_vec.y = 3.0;
}

void CCharacterPlayer::Draw()
{
	m_player_image_p[m_play_anim_image]->SetFlipH(m_is_flip);
	m_player_image_p[m_play_anim_image]->SetSize(m_size.x, m_size.y);
	CVector2D draw_pos = CVector2D(m_pos.x, m_pos.y + m_pos.z) - GetScroll();
	m_player_image_p[m_play_anim_image]->SetPos(draw_pos);
	m_player_image_p[m_play_anim_image]->SetCenter(m_size.x / 2.0,m_size.y / 2.0);
	m_player_image_p[m_play_anim_image]->Draw();
}

void CCharacterPlayer::MoveLimit()
{
	//とりあえずテスト用なので
	if (m_pos.z <= 180.0f) m_pos.z = 180.0f;
	if (m_pos.z >= 480.0f) m_pos.z = 480.0f;

}

void CCharacterPlayer::CalcScroll()
{
	SetScroll(CVector2D(m_pos.x - 200,0));
}
