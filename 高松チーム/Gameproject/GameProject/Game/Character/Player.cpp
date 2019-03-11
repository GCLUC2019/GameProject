#include "Player.h"
#include "../GameProject/Game/Resource/Resource.h"
#include <stdio.h>
#define GRAVITY -4//重力
#define DEP_N 1200//奥行重石
#define JUMP_SPD 50

enum PlayerState
{
	eIdol,		//待機
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
m_jump_vec(0)
{
	m_pos = CVector2D(1280/2, 540);
	m_img = COPY_RESOURCE("Player",CImage*);
	m_depth = m_pos.y / DEP_N;

}

void Player::Move()
{
	if (m_special_flg)
		return;
	if (m_jump_flg != true) {
		if (CInput::GetState(0, CInput::eHold, CInput::eButton1) && m_jump_flg == false) {
			m_squat_flg = true;
#ifdef _DEBUG//後でアニメーション設定に変更
			m_img.SetAng(DtoR(180));
#endif // _DEBUG
			m_state = eSquat;
		}
		else
			m_squat_flg = false;


		if (CInput::GetState(0, CInput::ePush, CInput::eButton2) && m_attack_flg == false) {
			m_attack_flg = true;
#ifdef _DEBUG//後でアニメーション設定に変更
			m_img.SetAng(DtoR(90));
#endif // _DEBUG
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
		m_state = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
		m_pos.y += m_speed;
		m_depth = m_pos.y / DEP_N;
		m_state = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eRight)) {
		m_pos.x += m_speed;
		m_state = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_pos.x -= m_speed;
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
	static int k = 120;
	switch (m_state)
	{
	case eAttack01:
		break;
	case eAttack02:
		break;
	case eAttack03:
		break;
	case eAttack04:
		break;
	default:
		printf("null");
		break;
	}
#ifdef _DEBUG//後でアニメーション設定に変更
	m_img.SetAng(DtoR(90));
#endif // _DEBUG
	if (k <= 0 || m_squat_flg) {
		k = 120;
		m_attack_flg = false;
	}
	k--;
}


void Player::Special()
{
}

void Player::Update()
{
#ifdef _DEBUG
	m_img.SetAng(DtoR(0));
#endif // _DEBUG
	if (m_special_flg)
		Special();
	if (m_squat_flg == false && m_attack_flg == false && m_jump_flg == false)
		m_state = eIdol;
	m_pos_old = m_pos;
	Move();
	if (m_attack_flg)
		Attack();
	if (m_pos.x < 0 || m_pos.x > 1280)
		m_pos.x = m_pos_old.x;
	if (m_pos.y < 720 / 2 || m_pos.y > 720)
		m_pos.y = m_pos_old.y;
}

void Player::Draw()
{
#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(0, 720 / 2), CVector2D(1280, 720), CVector4D(1.0f, 0, 0, 1));
	/*switch (m_State)//状態デバック表示
	{
	case eIdol:
		printf("eIdol");
		break;
	case	eMove:
		printf("eMove");
		break;
	case	eJump:
		printf("eJump");
		break;
	case	eSquat:	
		printf("eSquat");
		break;
	case	eAttack01:	
		printf("eAttack01");
		break;
	case	eAttack02:	
		printf("eAttack02");
		break;
	case	eAttack03:	
		printf("eAttack03");
		break;
	case	eAttack04:	
		printf("eAttack04");
		break;
	default:
		printf("null");
		break;
	}*/
	
#endif // _DEBUG

	
#define SAIZE 200
	m_img.SetSize(SAIZE *m_depth, SAIZE *m_depth);
	m_img.SetCenter(SAIZE * m_depth / 2, SAIZE * m_depth / 2);
	m_img.SetPos(m_pos+CVector2D(0, m_jump_vec));
	m_img.Draw();
#define _DEBUG
	//Utility::DrawQuad(m_pos, CVector2D(50, 50), CVector4D(1.0f, 0, 0, 1));
}

