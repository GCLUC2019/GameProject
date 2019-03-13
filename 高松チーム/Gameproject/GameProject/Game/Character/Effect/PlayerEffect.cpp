#include "PlayerEffect.h"
#include "../Anim/AnimDataPlayer.h"
#include "../GameProject/Game/Resource/Resource.h"

#define IMAGE_SIZE 200

PlayerEffectLongAttack::PlayerEffectLongAttack(const CVector2D& pos, bool _flip) : Task(ePEffectLongAttack)
{
	m_flip = _flip;
	m_pos = pos;
	m_vec = CVector2D(ZERO,ZERO);
	m_img = COPY_RESOURCE("PEffectLongAttack", CAnimImage*);
	m_img.SetFlipH(m_flip);

}

void PlayerEffectLongAttack::Update()
{
	if(m_flip == true)
	m_vec.x = 8.5f;
	else m_vec.x = -8.5f;

	m_pos += m_vec;
	m_img.ChangeAnimation(ePELongAttack);
	m_img.UpdateAnimation();
}

void PlayerEffectLongAttack::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(70,70);
	m_img.SetCenter(70 / 2, 70 / 2);
	m_img.SetPos(m_pos-CVector2D(0,70));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}



PlayerEffectShortAttack01::PlayerEffectShortAttack01(const CVector2D & pos, bool _flip) : Task(ePEffectShortAttack01)
{
	m_flip = _flip;
	m_pos = pos;
	m_vec = CVector2D(ZERO, ZERO);
	m_img = COPY_RESOURCE("PEffectShortAttack", CAnimImage*);
	m_img.SetFlipH(m_flip);
}

void PlayerEffectShortAttack01::Update()
{
	if (m_flip == true)
		m_vec.x = 0;
	else m_vec.x = -0.01f;

	m_img.ChangeAnimation(ePEShortAttack01,false);
	if (m_img.CheckAnimationEnd())
		SetKill();
	m_img.UpdateAnimation();
}

void PlayerEffectShortAttack01::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(120, 120);
	m_img.SetCenter(120 / 2, 120 / 2);
	m_img.SetPos(m_pos - CVector2D(0, 80));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}


PlayerEffectShortAttack02::PlayerEffectShortAttack02(const CVector2D & pos, bool _flip) : Task(ePEffectShortAttack02)
{
	m_flip = _flip;
	m_pos = pos;
	m_vec = CVector2D(ZERO, ZERO);
	m_img = COPY_RESOURCE("PEffectShortAttack", CAnimImage*);
	m_img.SetFlipH(m_flip);
}

void PlayerEffectShortAttack02::Update()
{
	if (m_flip == true)
		m_vec.x = 0;
	else m_vec.x = -0.01f;

	m_img.ChangeAnimation(ePEShortAttack02,false);
	if (m_img.CheckAnimationEnd())
		SetKill();
	m_img.UpdateAnimation();
}

void PlayerEffectShortAttack02::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(120, 120);
	m_img.SetCenter(120 / 2, 120 / 2);
	m_img.SetPos(m_pos - CVector2D(0, 80));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}

PlayerEffectShortAttack03::PlayerEffectShortAttack03(const CVector2D & pos, bool _flip) : Task(ePEffectShortAttack03)
{
	m_flip = _flip;
	m_pos = pos;
	m_vec = CVector2D(ZERO, ZERO);
	m_img = COPY_RESOURCE("PEffectShortAttack", CAnimImage*);
	m_img.SetFlipH(m_flip);
}

void PlayerEffectShortAttack03::Update()
{
	if (m_flip == true)
		m_vec.x = 0;
	else m_vec.x = -0.01f;

	m_img.ChangeAnimation(ePEShortAttack03, false);
	if (m_img.CheckAnimationEnd())
		SetKill();
	m_img.UpdateAnimation();
}

void PlayerEffectShortAttack03::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(120, 120);
	m_img.SetCenter(120 / 2, 120 / 2);
	m_img.SetPos(m_pos-CVector2D(0,90));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}


PlayerEffectSpecialAttack::PlayerEffectSpecialAttack(const CVector2D& pos) : Task(ePEffectSpecialAttack),
m_scale(CVector2D(1.0f,1.0f))
{
	m_pos = pos;
	m_img = COPY_RESOURCE("PESpecialAttack", CAnimImage*);
	m_img2 = COPY_RESOURCE("MagicCircle", CImage*);
}

void PlayerEffectSpecialAttack::Update()
{
	++m_cnt;
	if (m_cnt >= 60 && m_cnt <= 180) {
		m_scale += CVector2D(0.03f, 0.03f);
	}
	if (m_cnt >= 300) SetKill();

}

void PlayerEffectSpecialAttack::Draw()
{
	//サイズ指定と描画
	m_img.SetSize(IMAGE_SIZE * m_scale.x, 250);
	m_img.SetCenter((IMAGE_SIZE * m_scale.x) / 2, 250/ 2);
	m_img.SetPos(m_pos-CVector2D(0,50));

	m_img2.SetSize((IMAGE_SIZE/2.7f)*m_scale.x, 70);
	m_img2.SetCenter(((IMAGE_SIZE/ 2.7f) * m_scale.x) / 2, 50/ 2);
	m_img2.SetPos(m_pos-CVector2D(0,20));

	m_img2.Draw();
	m_img.Draw();
}
