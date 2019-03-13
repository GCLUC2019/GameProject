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

	m_anim_image_p[ePlayerAnimRun0] = GET_RESOURCE("Player_Run_Anim_0", CImage*);
	m_anim_image_p[ePlayerAnimRun1] = GET_RESOURCE("Player_Run_Anim_1", CImage*);
	m_anim_image_p[ePlayerAnimRun2] = GET_RESOURCE("Player_Run_Anim_2", CImage*);
	m_anim_image_p[ePlayerAnimRun3] = GET_RESOURCE("Player_Run_Anim_3", CImage*);
	m_anim_image_p[ePlayerAnimRun4] = GET_RESOURCE("Player_Run_Anim_4", CImage*);
	m_anim_image_p[ePlayerAnimRun5] = GET_RESOURCE("Player_Run_Anim_5", CImage*);

	//アニメーションデータの設定
	m_anim_info[ePlayerAnimIdIdle].image_num = 3;
	m_anim_info[ePlayerAnimIdIdle].image_id = ePlayerAnimIdle0;
	m_anim_info[ePlayerAnimIdIdle].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[ePlayerAnimIdMove].image_num = 8;
	m_anim_info[ePlayerAnimIdMove].image_id = ePlayerAnimMove0;
	m_anim_info[ePlayerAnimIdMove].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[ePlayerAnimIdRun].image_num = 6;
	m_anim_info[ePlayerAnimIdRun].image_id = ePlayerAnimRun0;
	m_anim_info[ePlayerAnimIdRun].delay = PLAYER_ANIM_RUN_DELAY;

	m_anim_info[ePlayerAnimIdAttack].image_num = 8;
	m_anim_info[ePlayerAnimIdAttack].image_id = ePlayerAnimMove0;
	m_anim_info[ePlayerAnimIdAttack].delay = 3;

}

void CCharacterPlayer::InputDash()
{
	if (CInput::GetState(0, CInput::eHold, CInput::eButton3)) {
		m_is_dashing = true;
		m_speed = 4.5f;
		m_size = CVector2D(100, 100);
	}
}

void CCharacterPlayer::InputAttack()
{
	if (m_is_attacking == true) return;
	if (CInput::GetState(0, CInput::eHold, CInput::eButton2)) {
		printf("攻撃\n");
		m_is_attacking = true;
		m_attacking_count = PLAYER_ATTACK_FRAME;
	}
}




void CCharacterPlayer::Update()
{
	//printf("x %lf y %lf z %lf\n", m_pos.x, m_pos.y, m_pos.z);
	m_will_play_anim_id = ePlayerAnimIdIdle;
	m_is_dashing = false;
	m_speed = PLAYER_SPEED;

	InputAttack();
	InputDash();
	InputMove();
	InputJump();


	//座標移動
	Gravity();
	Jumping();
	Move();
	MoveLimit();
	
	
	Attacking();

	CalcScroll();
	AdjAnim();
}

void CCharacterPlayer::InputMove()
{
	m_vec = CVector3D(0, 0, 0);
	
	bool is_move = false;
	if (CInput::GetState(0,CInput::eHold, CInput::eRight)) {
		m_is_flip = false;
		is_move = true;
		m_vec.x = 1;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_is_flip = true;
		is_move = true;
		m_vec.x = -1;
	}

	if (CInput::GetState(0, CInput::eHold, CInput::eUp)) {
		is_move = true;
		m_vec.z = -1;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
		is_move = true;
		m_vec.z = 1;
	}

	if (is_move == true) {
		if (m_is_dashing == true) SetWillPlayAnim(ePlayerAnimIdRun);
		else SetWillPlayAnim(ePlayerAnimIdMove);
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

void CCharacterPlayer::Attacking()
{
	if (m_is_attacking == false) return;
	if (m_attacking_count-- <= 0) {
		m_is_attacking = false;
	}
	SetWillPlayAnim(ePlayerAnimIdAttack);


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

void CCharacterPlayer::AdjAnim()
{
	switch (m_will_play_anim_id) {
	case ePlayerAnimIdRun:
		SetSize(350, 360);
		SetDrawAdjPos(CVector2D(-25, 30.0f));
		SetShadowPosAdj(CVector2D(-30,0));
		//SetDrawAdjPos(CVector2D(-25, 40.0f));
		//SetSize(350, 370);
		break;
	default:
		SetSize(400, 400);
		SetShadowPosAdj(CVector2D(0, 0));
		SetDrawAdjPos(CVector2D(-15, 20.0f));
		SetDrawAdjPos(CVector2D(-15, 20.0f));
		break;
	}
}

void CCharacterPlayer::CalcScroll()
{
	SetScroll(CVector2D(m_pos.x - 100,0));
}
