#include "Player.h"
#include "../GameProject/Game/Resource/Resource.h"
#include <stdio.h>
#define GRAVITY -4//重力
#define DEP_N 720//重力
#define JUMP_SPD 50

enum PlayerState
{
	eIdol,		//待機
	eMove,		//移動
	eJump,		//ジャンプ
	eSquat,		//しゃがみ
	eAttack01,	//
	eAttack02,	//
	eAttack03,	//
	eAttack04,	//
};
Player::Player() : CharacterBase(ePlayer),
m_Spd(4.0f),
m_Squat_flg(false),
m_Attack_flg(false),
m_Jump_flg(false),
m_Jumpvec(0)
{
	m_pos = CVector2D(1280/2, 540);
	m_img = COPY_RESOURCE("Player",CImage*);
	m_Depth = m_pos.y / DEP_N;

}

void Player::Move()
{
	
	if (m_Jump_flg != true) {
		if (CInput::GetState(0, CInput::eHold, CInput::eButton1) && m_Jump_flg == false) {
			m_Squat_flg = true;
			m_img.SetAng(DtoR(180));
			m_State = eSquat;
		}
		else
			m_Squat_flg = false;


		if (CInput::GetState(0, CInput::ePush, CInput::eButton2) && m_Attack_flg == false) {
			m_Attack_flg = true;
			m_img.SetAng(DtoR(90));
			m_State = eAttack01;
		}
		
		if (CInput::GetState(0, CInput::eHold, CInput::eButton3)) {
			m_Jump_flg = true;
			m_State = eJump;
		}
	}
	else 
		Jump();
	if (m_Squat_flg || m_Attack_flg)
		return;

	if (CInput::GetState(0, CInput::eHold, CInput::eUp)) {
		m_pos.y -= m_Spd;
		m_Depth = m_pos.y / DEP_N;
		m_State = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
		m_pos.y += m_Spd;
		m_Depth = m_pos.y / DEP_N;
		m_State = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eRight)) {
		m_pos.x += m_Spd;
		m_State = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_pos.x -= m_Spd;
		m_State = eMove;
	}
}

void Player::Jump()
{
	static float time = 1;
	m_Jumpvec = 0 + JUMP_SPD * time + GRAVITY * (time*time) / 2;
	m_Jumpvec *= -1;
	time += 0.5f;
	if (m_Jumpvec > 0) {
		time = 0;
		m_Jumpvec = 0;
		m_Jump_flg = false;
	}
}

void Player::Attack()
{
	static int k = 120;
	k--;
	m_img.SetAng(DtoR(90));
	if (k <= 0 || m_Squat_flg) {
		k = 120;
		m_Attack_flg = false;
	}
}


void Player::Update()
{
	if (m_Squat_flg == false && m_Attack_flg == false && m_Jump_flg == false)
		m_State = eIdol;
	m_img.SetAng(DtoR(0));
	m_pos_old = m_pos;
	Move();
	if (m_Attack_flg)
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

	
#define SAIZE 150
	m_img.SetSize(SAIZE *m_Depth, SAIZE *m_Depth);
	m_img.SetCenter(SAIZE * m_Depth / 2, SAIZE * m_Depth / 2);
	m_img.SetPos(m_pos+CVector2D(0,m_Jumpvec));
	m_img.Draw();
#define _DEBUG
	//Utility::DrawQuad(m_pos, CVector2D(50, 50), CVector4D(1.0f, 0, 0, 1));
}

