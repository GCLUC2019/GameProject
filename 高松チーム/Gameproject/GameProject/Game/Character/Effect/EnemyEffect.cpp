#include "EnemyEffect.h"
#include "../Anim/AnimEnemyEffect.h"
#include "../../CollitionBase.h"
#include "../GameProject/Game/Character/Player.h"
#define EFFECT_SIZE 200
#define EFFECT_SIZE_E4_EX_X 1000
#define EFFECT_SIZE_E4_EX_Y 50

E2Effect::E2Effect(const CVector2D&pos) :Task(eE2AttackEffect)
{
    m_img = COPY_RESOURCE("Enemy2Effect", CAnimImage*);
    m_pos = pos;
    m_rect = CRect(-EFFECT_SIZE / 2, -EFFECT_SIZE / 4, EFFECT_SIZE / 2, EFFECT_SIZE / 4);
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
    m_img.SetPos(m_pos);
    m_img.SetCenter(EFFECT_SIZE , EFFECT_SIZE / 2);
    m_img.SetSize(EFFECT_SIZE*2, EFFECT_SIZE);
    m_img.Draw();
}

void E2Effect::HitCheck()
{
    Task*t = CollitionBase::GetCollisionCheckRect(this, CharacterData::ePlayer);
    Player*p = dynamic_cast<Player*>(t);

    if (p != nullptr) {
        p->Damage(10);
    }
}

E4EffectEXAttack::E4EffectEXAttack(const CVector2D & pos) :Task(eE4AttackEffect)
{
	m_img = COPY_RESOURCE("Slash_EX", CAnimImage*);
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
	m_img.SetPos(m_pos);
	m_img.SetCenter(EFFECT_SIZE_E4_EX_X/2, EFFECT_SIZE_E4_EX_Y / 2);
	m_img.SetSize(EFFECT_SIZE_E4_EX_X, EFFECT_SIZE_E4_EX_Y);
	m_img.Draw();

	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));

}

void E4EffectEXAttack::HitCheck()
{
	Task*t = CollitionBase::GetCollisionCheckRect(this, CharacterData::ePlayer);
	Player*p = dynamic_cast<Player*>(t);

	if (p != nullptr) {
		p->Damage(10);
	}
}
