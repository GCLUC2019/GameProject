#include "EnemyEffect.h"
#include "../Anim/AnimEnemyEffect.h"
#include "../../CollitionBase.h"
#include "../GameProject/Game/Character/Player.h"
#include "../../GameData/GameData.h"

#define EFFECT_SIZE 200
#define EFFECT_SIZE_E4_EX_X 1000
#define EFFECT_SIZE_E4_EX_Y 50
#define EFFECT_SIZE_E4_S 70
#define EFFECT_SIZE_E4_L 50

E2Effect::E2Effect(const CVector2D&pos) :Task(eE2AttackEffect)
{
    m_img = COPY_RESOURCE("Enemy2Effect", CAnimImage*);
    m_pos = pos;
    m_rect = CRect(-EFFECT_SIZE / 2, -EFFECT_SIZE / 4-g_game_data.m_scroll.y/3, EFFECT_SIZE / 2, EFFECT_SIZE / 4 - g_game_data.m_scroll.y / 3);
}

void E2Effect::Update()
{
    m_img.ChangeAnimation(E2EffectAnim::eE2Attack, false);
    if (m_img.CheckAnimationEnd()) {
        SetKill();
    }
    m_img.UpdateAnimation();
}

void E2Effect::Draw()
{
    m_img.SetPos(CVector2D(m_pos.x - g_game_data.m_scroll.x, m_pos.y - g_game_data.m_scroll.y / 3));
    m_img.SetCenter(EFFECT_SIZE , EFFECT_SIZE / 2);
    m_img.SetSize(EFFECT_SIZE*2, EFFECT_SIZE);
    m_img.Draw();
}

void E2Effect::HitCheck()
{
	Task*t = CollitionBase::GetCollisionCheckRectANDY(this, CharacterData::ePlayer, 50.0f);
    Player*p = dynamic_cast<Player*>(t);

    if (p != nullptr) {
        p->Damage(10);
    }
}

E4EffectEXAttack::E4EffectEXAttack(const CVector2D & pos) :Task(eE4AttackEffect)
{
	m_img = COPY_RESOURCE("Enemy04EffectEX", CAnimImage*);
	m_pos = CVector2D(1280 / 2, pos.y);
	m_img.ChangeAnimation(E4EffectAnim::eE4EXAttack, false);
	m_rect = CRect(-EFFECT_SIZE_E4_EX_X / 2, -EFFECT_SIZE_E4_EX_Y / 2, EFFECT_SIZE_E4_EX_X / 2, EFFECT_SIZE_E4_EX_Y / 2);
}

void E4EffectEXAttack::Update()
{
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
	m_img.UpdateAnimation();
}

void E4EffectEXAttack::Draw()
{
	m_img.SetPos(m_pos - CVector2D(g_game_data.m_scroll.x,0));
	m_img.SetCenter(EFFECT_SIZE_E4_EX_X/2, EFFECT_SIZE_E4_EX_Y / 2);
	m_img.SetSize(EFFECT_SIZE_E4_EX_X, EFFECT_SIZE_E4_EX_Y);
	m_img.Draw();
#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	#endif
}

void E4EffectEXAttack::HitCheck()
{
	Task*t = CollitionBase::GetCollisionCheckRectANDY(this, CharacterData::ePlayer,50.0f);
	Player*p = dynamic_cast<Player*>(t);

	if (p != nullptr) {
		p->Damage(10);
	}
}


E4EffectSAttack::E4EffectSAttack(const CVector2D & pos) :Task(eE4AttackEffect)
{
	m_img = COPY_RESOURCE("Enemy04EffectS", CAnimImage*);
	m_pos = pos;
	m_img.ChangeAnimation(E4EffectAnim::eE4SAttack, false);
	m_rect = CRect(-EFFECT_SIZE_E4_S / 2, -EFFECT_SIZE_E4_S / 2, EFFECT_SIZE_E4_S / 2, EFFECT_SIZE_E4_S / 2);
}

void E4EffectSAttack::Update()
{
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
	m_img.UpdateAnimation();
}

void E4EffectSAttack::Draw()
{
	m_img.SetPos(m_pos - CVector2D(0, 50));
	m_img.SetCenter(EFFECT_SIZE_E4_S, EFFECT_SIZE_E4_S);
	m_img.SetSize(EFFECT_SIZE_E4_S * 2, EFFECT_SIZE_E4_S * 2);
	m_img.Draw();
#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif
}

void E4EffectSAttack::HitCheck()
{
	Task*t = CollitionBase::GetCollisionCheckRectANDY(this, CharacterData::ePlayer,50.0f);
	Player*p = dynamic_cast<Player*>(t);

	if (p != nullptr) {
		p->Damage(5);
	}
}

E4EffectLAttack::E4EffectLAttack(const CVector2D & pos, const bool & _flip) :Task(eE4AttackEffect)
{
	m_flip = _flip;
	m_img = COPY_RESOURCE("Enemy04EffectL", CAnimImage*);
	m_pos = pos;
	m_img.ChangeAnimation(E4EffectAnim::eE4LAttack);
	m_rect = CRect(-EFFECT_SIZE_E4_L / 2, -EFFECT_SIZE_E4_L / 2, EFFECT_SIZE_E4_L / 2, EFFECT_SIZE_E4_L / 2);
}

void E4EffectLAttack::Update()
{
	if (m_flip)
		m_pos.x += 5;
	else
		m_pos.x -= 5;
	m_img.UpdateAnimation();
	if (m_pos.x < SCREEN_MIN_SIZE_X || m_pos.x > SCREEN_MAX_SIZE_X)
		SetKill();
	if (m_pos.y < SCREEN_MIN_SIZE_Y || m_pos.y > SCREEN_MAX_SIZE_Y)
		SetKill();
}

void E4EffectLAttack::Draw()
{
	m_img.SetPos(m_pos - CVector2D(g_game_data.m_scroll.x,0));
	m_img.SetCenter(EFFECT_SIZE_E4_L, EFFECT_SIZE_E4_L);
	m_img.SetSize(EFFECT_SIZE_E4_L * 2, EFFECT_SIZE_E4_L * 2);
	m_img.Draw();
#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif
}

void E4EffectLAttack::HitCheck()
{
	Task*t = CollitionBase::GetCollisionCheckRectANDY(this, CharacterData::ePlayer, 50.0f);
	Player*p = dynamic_cast<Player*>(t);

	if (p != nullptr) {
		p->Damage(5);
	}
}
