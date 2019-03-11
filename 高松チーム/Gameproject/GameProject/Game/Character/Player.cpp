#include "Player.h"
#include "../GameProject/Game/Resource/Resource.h"
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
		if (CInput::GetState(0, CInput::eHold, CInput::eButton1)) {
			m_Squat_flg = true;
		}
		else
			m_Squat_flg = false;


		if (CInput::GetState(0, CInput::eHold, CInput::eButton2)) {
			m_Attack_flg = true;
		}
		else
			m_Attack_flg = false;
		if (CInput::GetState(0, CInput::eHold, CInput::eButton3)) {
			m_Jump_flg = true;
		}
	}
	else 
		Jump();
	if (m_Squat_flg || m_Attack_flg)
		return;

	if (CInput::GetState(0, CInput::eHold, CInput::eUp)) {
		m_pos.y -= m_Spd;
		m_Depth = m_pos.y / DEP_N;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
		m_pos.y += m_Spd;
		m_Depth = m_pos.y / DEP_N;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eRight)) {
		m_pos.x += m_Spd;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_pos.x -= m_Spd;
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


void Player::Update()
{
	m_pos_old = m_pos;
	Move();
	if (m_pos.x < 0 || m_pos.x > 1280)
		m_pos.x = m_pos_old.x;
	if (m_pos.y < 720 / 2 || m_pos.y > 720)
		m_pos.y = m_pos_old.y;
}

void Player::Draw()
{
#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(0, 720 / 2), CVector2D(1280, 720), CVector4D(1.0f, 0, 0, 1));
#endif // _DEBUG

	
#define SAIZE 150
	m_img.SetSize(SAIZE *m_Depth, SAIZE *m_Depth);
	m_img.SetCenter(SAIZE * m_Depth / 2, SAIZE * m_Depth / 2);
	m_img.SetPos(m_pos+CVector2D(0,m_Jumpvec));
	m_img.Draw();
#define _DEBUG
	//Utility::DrawQuad(m_pos, CVector2D(50, 50), CVector4D(1.0f, 0, 0, 1));
}

