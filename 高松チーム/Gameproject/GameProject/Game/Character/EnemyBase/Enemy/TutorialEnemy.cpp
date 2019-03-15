#include "TutorialEnemy.h"
#include "../GameProject/Game/Character/Anim/AnimData.h"
#include "../GameProject/Game/CollitionBase.h"


TutorialEnemy::TutorialEnemy(CVector2D _pos) : EnemyBase(CharacterData::eTutorialEnemy)
{
	m_img = COPY_RESOURCE("Enemy02", CAnimImage*);
	m_shadow = COPY_RESOURCE("Shadow", CImage*);
	m_img.ChangeAnimation(eEMove02);
	m_state = eMove;

	m_rect = CRect(-47.0f, -17.0f, 54.0f, 82.0f);
	m_pos = _pos;
	m_flip = false;
}

void TutorialEnemy::Damage()
{
	m_img.ChangeAnimation(eEDamage02);

	m_state = eMove;
}

void TutorialEnemy::Update()
{
	switch (m_state) {
	case eMove:
		m_img.ChangeAnimation(eEMove02);
		break;
	case eDamage:
		Damage();
		break;
	default:
		break;
	}

	MoveControl();
	m_img.UpdateAnimation();
}

void TutorialEnemy::Draw()
{
	m_shadow.SetSize(SAIZE_SD + m_depth / 5, 30);
	m_shadow.SetCenter((SAIZE_SD + m_depth / 5) / 2, 30);
	m_shadow.SetPos(CVector2D(m_pos.x, m_pos.y + 90));

	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_img.SetPos(m_pos);
	m_img.SetFlipH(m_flip);

	m_shadow.Draw();
	m_img.Draw();
}

void TutorialEnemy::HitCheck()
{
	if (CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack01)|| 
		CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack02)|| 
		CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack03)) 
	{
		m_state = TutorialEnemyState::eDamage;
	}
}
