#include "PlayerEffect.h"
#include "../Anim/AnimDataPlayer.h"
#include "../GameProject/Game/Resource/Resource.h"

PlayerEffectLongAttack::PlayerEffectLongAttack(const CVector2D& pos) : Task(ePEffectLongAttack)
{
	m_pos = pos;
	m_vec = CVector2D(ZERO,ZERO);
	m_img = COPY_RESOURCE("PEffectLongAttack", CAnimImage*);
	

}

void PlayerEffectLongAttack::Update()
{
	m_vec.x = 5;

	m_pos += m_vec;
	m_img.ChangeAnimation(ePELongAttack);
	m_img.UpdateAnimation();
}

void PlayerEffectLongAttack::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(120,120);
	m_img.SetCenter(120 / 2, 120 / 2);
	m_img.SetPos(m_pos);
	m_img.Draw();
}



PlayerEffectShortAttack01::PlayerEffectShortAttack01(const CVector2D & pos) : Task(ePEffectShortAttack01)
{
	m_pos = pos;
	m_vec = CVector2D(ZERO, ZERO);
	m_img = COPY_RESOURCE("PEffectShortAttack", CAnimImage*);
}

void PlayerEffectShortAttack01::Update()
{

	m_img.ChangeAnimation(ePEShortAttack01);
	m_img.UpdateAnimation();
}

void PlayerEffectShortAttack01::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(120, 120);
	m_img.SetCenter(120 / 2, 120 / 2);
	m_img.SetPos(m_pos);
	m_img.Draw();
}


PlayerEffectShortAttack02::PlayerEffectShortAttack02(const CVector2D & pos) : Task(ePEffectShortAttack02)
{
	m_pos = pos;
	m_vec = CVector2D(ZERO, ZERO);
	m_img = COPY_RESOURCE("PEffectShortAttack", CAnimImage*);
}

void PlayerEffectShortAttack02::Update()
{
	m_img.ChangeAnimation(ePEShortAttack02);
	m_img.UpdateAnimation();
}

void PlayerEffectShortAttack02::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(120, 120);
	m_img.SetCenter(120 / 2, 120 / 2);
	m_img.SetPos(m_pos);
	m_img.Draw();
}

PlayerEffectShortAttack03::PlayerEffectShortAttack03(const CVector2D & pos) : Task(ePEffectShortAttack03)
{
	m_pos = pos;
	m_vec = CVector2D(ZERO, ZERO);
	m_img = COPY_RESOURCE("PEffectShortAttack", CAnimImage*);
}

void PlayerEffectShortAttack03::Update()
{
	m_img.ChangeAnimation(ePEShortAttack03);
	m_img.UpdateAnimation();
}

void PlayerEffectShortAttack03::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(120, 120);
	m_img.SetCenter(120 / 2, 120 / 2);
	m_img.SetPos(m_pos);
	m_img.Draw();
}


PlayerEffectSpecialAttack::PlayerEffectSpecialAttack(const CVector2D& pos) : Task(ePEffectSpecialAttack),
m_scale(CVector2D(1.0f,1.0f))
{
	m_img = COPY_RESOURCE("PESpecialAttack", CAnimImage*);
	m_img2 = COPY_RESOURCE("MagicCircle", CImage*);
}

void PlayerEffectSpecialAttack::Update()
{

}

void PlayerEffectSpecialAttack::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(120 * m_scale.x, 120 * m_scale.y);
	m_img.SetCenter((120 * m_scale.x) / 2, (120*m_scale.y) / 2);
	m_img.SetPos(m_pos);

	m_img2.SetSize(120*m_scale.x, 120*m_scale.y);
	m_img2.SetCenter((120 * m_scale.x) / 2, (120 * m_scale.y) / 2);
	m_img2.SetPos(m_pos);

	m_img2.Draw();
	m_img.Draw();
}
