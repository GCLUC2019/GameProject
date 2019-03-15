#include "TutorialEnemy.h"
#include "../GameProject/Game/Character/Anim/AnimData.h"
#include "../GameProject/Game/CollitionBase.h"


TutorialEnemy::TutorialEnemy(CVector2D _pos) : EnemyBase(CharacterData::eTutorialEnemy)
{
	m_img = COPY_RESOURCE("Enemy02", CAnimImage*);
	m_img.ChangeAnimation(eEMove02);
	m_state = eMove;

	m_flip = false;
	m_hp = 100;
}

void TutorialEnemy::Move()
{
	m_img.ChangeAnimation(eEMove02);
}

void TutorialEnemy::Damage()
{
	if (m_hp <= 0) {
		m_img.ChangeAnimation(eEDeath02);
		if (m_img.CheckAnimationEnd())
			SetKill();
	}
	else {
		m_img.ChangeAnimation(eEDamage02);
		m_state = eMove;
	}
}

void TutorialEnemy::Update()
{
	switch (m_state) {
	case eMove:
		Move();
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
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}

void TutorialEnemy::HitCheck()
{
	if (CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack01)|| 
		CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack02)|| 
		CollitionBase::CollisionCheckRect(this, CharacterData::ePEffectShortAttack03)) 
	{
		m_hp -= 1;
		m_state = TutorialEnemyState::eDamage;
	}
}
