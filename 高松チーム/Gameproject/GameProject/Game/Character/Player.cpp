#include "Player.h"
#include "../GameProject/Game/Resource/Resource.h"

Player::Player() : CharacterBase(ePlayer)
{
	m_pos = CVector2D(200, 200);
	m_img = COPY_RESOURCE("Player",CImage*);

}


void Player::Update()
{
}

void Player::Draw()
{
	m_img.SetSize(200,200);
	m_img.SetPos(m_pos);
	m_img.Draw();
#define _DEBUG
	//Utility::DrawQuad(m_pos, CVector2D(50, 50), CVector4D(1.0f, 0, 0, 1));
}

