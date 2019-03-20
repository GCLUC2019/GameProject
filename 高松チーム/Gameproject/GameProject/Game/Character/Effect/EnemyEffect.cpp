#include "EnemyEffect.h"
#include "../Anim/AnimEnemyEffect.h"

#define EFFECT_SIZE 200
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
