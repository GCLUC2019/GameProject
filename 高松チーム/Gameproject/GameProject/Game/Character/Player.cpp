#include "Player.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../Character/Anim/AnimDataPlayer.h"
#include <stdio.h>
#define GRAVITY -4//重力
#define DEP_N 1200//奥行重石
#define JUMP_SPD 50

enum PlayerState
{
	eIdle,		//待機
	eMove,		//移動
	eJump,		//ジャンプ
	eSquat,		//しゃがみ
	eAttack01,	//近距離攻撃
	eAttack02,	//
	eAttack03,	//
	eAttack04,	//遠距離攻撃
	eSpecial,	//必殺
};
Player::Player() : CharacterBase(ePlayer),
m_speed(4.0f),
m_squat_flg(false),
m_attack_flg(false),
m_jump_flg(false),
m_flip(false),
m_jump_vec(0),
m_state(eIdle),
m_state_old(m_state)
{
	m_pos = CVector2D(1280/2, 540);
	m_img = COPY_RESOURCE("Player",CAnimImage*);
	m_depth = m_pos.y / DEP_N;
	m_img.ChangeAnimation(ePIdle);

}

void Player::Move()
{
	if (m_special_flg)
		return;
	if (m_jump_flg != true) {
		if (CInput::GetState(0, CInput::eHold, CInput::eButton1) && m_jump_flg == false) {
			m_squat_flg = true;
			m_state = eSquat;
		}
		else
			m_squat_flg = false;


		if (CInput::GetState(0, CInput::ePush, CInput::eButton2) && m_attack_flg == false) {
			m_attack_flg = true;			
			m_state = eAttack01;
		}
		
		if (CInput::GetState(0, CInput::ePush, CInput::eButton3) && m_squat_flg == false && m_attack_flg == false) {
			m_jump_flg = true;
			m_state = eJump;
		}
	}
	else 
		Jump();
	if (m_squat_flg || m_attack_flg)
		return;

	if (CInput::GetState(0, CInput::eHold, CInput::eUp)) {
		m_pos.y -= m_speed;
		m_depth = m_pos.y / DEP_N;
		m_img.ChangeAnimation(ePRun);
		if (m_jump_flg == false)
			m_state = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
		m_pos.y += m_speed;
		m_depth = m_pos.y / DEP_N;
		m_img.ChangeAnimation(ePRun);
		if (m_jump_flg == false)
			m_state = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eRight)) {
		m_pos.x += m_speed;
		m_flip = true;
		m_img.ChangeAnimation(ePRun);
		if (m_jump_flg == false)
			m_state = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_pos.x -= m_speed;
		m_flip = false;
		m_img.ChangeAnimation(ePRun);
		if (m_jump_flg == false)
			m_state = eMove;
	}

	
}

void Player::Jump()
{
	static float time = 1;
	m_jump_vec = 0 + JUMP_SPD * time + GRAVITY * (time*time) / 2;
	m_jump_vec *= -1;
	time += 0.5f;
	if (m_jump_vec > 0) {
		time = 0;
		m_jump_vec = 0;
		m_jump_flg = false;
	}
}

void Player::Attack()
{
	static int k = 0;
	switch (m_state)
	{
	case eAttack01:
		if (k <= 10) {
			if (m_flip)
				Utility::DrawQuad(m_pos + CVector2D(25, 0), CVector2D(50, 50), CVector4D(1.0f, 0, 0, 1));
			else
				Utility::DrawQuad(m_pos - CVector2D(25, 0), CVector2D(50, 50), CVector4D(1.0f, 0, 0, 1));
		}
		if (CInput::GetState(0, CInput::ePush, CInput::eButton2)&&k>10) {
			m_state = eAttack02;
			k = 0;
		}
		if (k >= 60 || m_squat_flg) {
			k = 0;
			m_attack_flg = false;
		}
		break;
	case eAttack02:
		if (k <= 30) {
			if (m_flip)
				Utility::DrawQuad(m_pos + CVector2D(25, 0), CVector2D(50, 50), CVector4D(1.0f, 0, 1, 1));
			else
				Utility::DrawQuad(m_pos - CVector2D(25, 0), CVector2D(50, 50), CVector4D(1.0f, 0, 1, 1));
		}
		if (CInput::GetState(0, CInput::ePush, CInput::eButton2) && k>10) {
			m_state = eAttack03;
			k = 0;
		}
		if (k >= 60 || m_squat_flg) {
			k = 0;
			m_attack_flg = false;
		}
		break;
	case eAttack03:
		if (k <= 30) {
			if (m_flip)
				Utility::DrawQuad(m_pos + CVector2D(25, 0), CVector2D(50, 50), CVector4D(1.0f, 1, 0, 1));
			else
				Utility::DrawQuad(m_pos - CVector2D(25, 0), CVector2D(50, 50), CVector4D(1.0f, 1, 0, 1));
		}
	
		if (k >= 60 || m_squat_flg) {
			k = 0;
			m_attack_flg = false;
		}
		break;
	case eAttack04:
		if (k <= 3) {
			if (m_flip)
				Utility::DrawQuad(m_pos + CVector2D(25, 0), CVector2D(100, 100), CVector4D(1.0f, 1, 1, 1));
			else
				Utility::DrawQuad(m_pos - CVector2D(25, 0), CVector2D(100, 100), CVector4D(1.0f, 1, 1, 1));
		}

		if (k >= 100 || m_squat_flg) {
			k = 0;
			m_attack_flg = false;
		}
		break;
	default:
		printf("null");
		break;
	}
#ifdef _DEBUG//後でアニメーション設定に変更
	//m_img.SetAng(DtoR(90));
#endif // _DEBUG
	
	k++;
}


void Player::Special()
{
}

void Player::SetAnim()
{
	switch (m_state)//状態デバック表示
	{
	case eIdle://待機
		m_img.ChangeAnimation(ePIdle);

	break;
	case	eMove://移動
		m_img.ChangeAnimation(ePRun);
	break;
	case	eJump://ジャンプ
		m_img.ChangeAnimation(ePJumpUp);
	break;
	case	eSquat://しゃがみ
		m_img.ChangeAnimation(ePCrouch);
	break;
	case	eAttack01://近距離攻撃
		m_img.ChangeAnimation(ePShortAttack01,false);
	break;
	case	eAttack02:
		m_img.ChangeAnimation(ePShortAttack02, false);
	break;
	case	eAttack03:
		m_img.ChangeAnimation(ePShortAttack03, false);
	break;
	case	eAttack04://遠距離攻撃
		m_img.ChangeAnimation(ePLongAttack, false);
	break;
	default:
		m_img.ChangeAnimation(ePIdle);
	break;
	}


}

void Player::Update()
{
	if (m_special_flg)
		Special();
	m_state_old = m_state;
	m_pos_old = m_pos;
	Move();
	if (m_attack_flg)
		Attack();
	if (m_pos.x < 0 || m_pos.x > 1280)
		m_pos.x = m_pos_old.x;
	if (m_pos.y < 720 / 2 || m_pos.y > 720)
		m_pos.y = m_pos_old.y;
	if (m_squat_flg == false && m_attack_flg == false && m_jump_flg == false&& m_pos.x == m_pos_old.x&&m_pos.y == m_pos_old.y)
	{
		m_state = eIdle;
	}
	if (m_state != m_state_old)
		SetAnim();
	
}

void Player::Draw()
{
#ifdef _DEBUG
	//Utility::DrawQuad(CVector2D(0, 720 / 2), CVector2D(1280, 720), CVector4D(1.0f, 0, 0, 1));
	
#endif // _DEBUG

	
#define SAIZE 200
	m_img.UpdateAnimation();
	m_img.SetSize(SAIZE *m_depth, SAIZE *m_depth);
	m_img.SetCenter(SAIZE * m_depth / 2, SAIZE * m_depth / 2);
	m_img.SetPos(m_pos+CVector2D(0, m_jump_vec));
	m_img.SetFlipH(m_flip);
	m_img.Draw();

	
}

