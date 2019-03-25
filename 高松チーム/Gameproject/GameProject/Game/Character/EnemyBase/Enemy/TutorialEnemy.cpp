#include "TutorialEnemy.h"
#include "../GameProject/Game/Character/Anim/AnimData.h"
#include "../GameProject/Game/CollitionBase.h"
#include "../GameProject/Game/GameData/GameData.h"


TutorialEnemy::TutorialEnemy(CVector2D _pos) : EnemyBase(CharacterData::eTutorialEnemy)
{
	m_img = COPY_RESOURCE("Enemy02", CAnimImage*);
	m_shadow = COPY_RESOURCE("Shadow", CImage*);
	m_img.ChangeAnimation(eEMove02);
	m_state = eMove;

	m_rect = CRect(-47.0f, -120.0f, 54.0f, -20.0f);
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
#ifdef _DEBUG
	//Utility::DrawQuad(CVector2D(0, 720 / 2), CVector2D(1280, 720), CVector4D(1.0f, 0, 0, 1));

	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));

#endif // _DEBUG

	m_shadow.SetSize(SAIZE_SD + m_depth / 5, 30);
	m_shadow.SetCenter((SAIZE_SD + m_depth / 5) / 2, 30);
	m_shadow.SetPos(CVector2D(m_pos.x, m_pos.y -g_game_data.m_scroll.y/3));

	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE);
	m_img.SetPos(m_pos - CVector2D(0, g_game_data.m_scroll.y/3));
	m_img.SetFlipH(m_flip);

	m_shadow.Draw();
	m_img.Draw();
}

void TutorialEnemy::HitCheck()
{
	if (CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack01, 50.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack02, 50.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack03, 50.0f))
	{
		SOUND("punch-middle2")->Play();
		m_state = TutorialEnemyState::eDamage;
	}
	if (CollitionBase::CollisionCheckRect(this, CharacterData::ePlayerSpecial)) {
		SOUND("punch-middle2")->Play();
		m_state = TutorialEnemyState::eDamage;
	}
}
