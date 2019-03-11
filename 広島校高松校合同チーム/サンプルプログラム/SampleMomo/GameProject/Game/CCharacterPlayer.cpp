#include "CCharacterPlayer.h"
#include "../Global.h"

#define PLAYER_SPEED (3.0f)

CCharacterPlayer::CCharacterPlayer() :CCharacter(eTaskIdPlayer, 0)
{
	m_speed = PLAYER_SPEED;
	SetAnim(ePlayerAnimIdIdle);
	LoadAnimImage();

	SetIsShowShadow(true);
	SetShadowSize(CVector2D(100, 50));
	SetDrawAdjPos(CVector2D(-15, 20.0f));
	SetRads(75,200,10);
}

CCharacterPlayer::~CCharacterPlayer()
{
}

void CCharacterPlayer::LoadAnimImage()
{
	
	m_anim_image_p[ePlayerAnimIdle0] = GET_RESOURCE("Player_Idle_Anim_0", CImage*);

	m_anim_image_p[ePlayerAnimIdle1] = GET_RESOURCE("Player_Idle_Anim_1", CImage*);

	m_anim_image_p[ePlayerAnimIdle2] = GET_RESOURCE("Player_Idle_Anim_2", CImage*);

	m_anim_image_p[ePlayerAnimMove0] = GET_RESOURCE("Player_Move_Anim_0", CImage*);

	m_anim_image_p[ePlayerAnimMove1] = GET_RESOURCE("Player_Move_Anim_1", CImage*);

	m_anim_image_p[ePlayerAnimMove2] = GET_RESOURCE("Player_Move_Anim_2", CImage*);

	m_anim_image_p[ePlayerAnimMove3] = GET_RESOURCE("Player_Move_Anim_3", CImage*);

	m_anim_image_p[ePlayerAnimMove4] = GET_RESOURCE("Player_Move_Anim_4", CImage*);

	m_anim_image_p[ePlayerAnimMove5] = GET_RESOURCE("Player_Move_Anim_5", CImage*);

	m_anim_image_p[ePlayerAnimMove6] = GET_RESOURCE("Player_Move_Anim_6", CImage*);

	m_anim_image_p[ePlayerAnimMove7] = GET_RESOURCE("Player_Move_Anim_7", CImage*);


	//アニメーションデータの設定
	m_anim_info[ePlayerAnimIdIdle].image_num = 3;
	m_anim_info[ePlayerAnimIdIdle].image_id = ePlayerAnimIdle0;
	m_anim_info[ePlayerAnimIdIdle].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[ePlayerAnimIdMove].image_num = 8;
	m_anim_info[ePlayerAnimIdMove].image_id = ePlayerAnimMove0;
	m_anim_info[ePlayerAnimIdMove].delay = DEFAULT_ANIM_DELAY;

}




void CCharacterPlayer::Update()
{
	//printf("x %lf y %lf z %lf\n", m_pos.x, m_pos.y, m_pos.z);
	m_will_play_anim_id = ePlayerAnimIdIdle;
	InputMove();
	InputJump();
	Gravity();
	Jumping();
	Move();
	MoveLimit();
	CalcScroll();
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
	if (CInput::GetState(0, CInput::ePush, CInput::eButton1) && m_is_jumping == false && m_is_landing == true) {
		//SetIsDelete();
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

void CCharacterPlayer::CharacterDraw()
{
	
	
}

void CCharacterPlayer::CalcScroll()
{
	SetScroll(CVector2D(m_pos.x - 100,0));
}
