#include "Player.h"
#include "../GameProject/Game/Resource/Resource.h"

enum PlayerState
{
	eIdol,		//‘Ò‹@
	eMove,		//ˆÚ“®
	eJump,		//ƒWƒƒƒ“ƒv
	eSquat,		//‚µ‚á‚ª‚Ý
	eAttack01,	//
	eAttack02,	//
	eAttack03,	//
	eAttack04,	//
};
Player::Player() : CharacterBase(ePlayer),
m_Spd(2.0f),
m_Squat_flg(false),
m_Attack_flg(false),
m_Jump_flg(false)
{
	m_pos = CVector2D(1280/2, 720/2);
	m_img = COPY_RESOURCE("Player",CImage*);

}

void Player::Move()
{
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


	if (m_Squat_flg || m_Attack_flg)
		return;

	if (CInput::GetState(0, CInput::eHold, CInput::eUp)) {
		m_pos.y -= m_Spd;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
		m_pos.y += m_Spd;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eRight)) {
		m_pos.x += m_Spd;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_pos.x -= m_Spd;
	}
}


void Player::Update()
{
	Move();
}

void Player::Draw()
{
	m_img.SetSize(50,50);
	m_img.SetPos(m_pos);
	m_img.Draw();
#define _DEBUG
	//Utility::DrawQuad(m_pos, CVector2D(50, 50), CVector4D(1.0f, 0, 0, 1));
}

