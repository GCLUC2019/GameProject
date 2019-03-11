#include "CCharacterEnemy.h"

CCharacterEnemy::CCharacterEnemy() :CCharacter(eTaskIdEnemy, 0)
{
	m_enemy_state = eEnemyStateIdle;
	m_enemy_hp = 100;


	m_vec = CVector3D(0, 0, 0);
	m_pos = CVector3D(800, -50, 500);
	m_rads = CVector3D(10,10,10);
	SetSize(300, 300);

	is_damage = true;
	m_AI_cnt = 0;
	LoadAnimImage();

	SetAnim(eEnemyAnimIdIdle);
	SetIsShowShadow(true);
	SetShadowSize(CVector2D(100, 50));
	SetShadowAdjPos(CVector2D(-8.0, -50.0));
}

CCharacterEnemy::~CCharacterEnemy()
{
	printf("削除されました");
}

void CCharacterEnemy::CharacterUpdate()
{
	m_AI_cnt++;
	switch (m_enemy_state) {
	case eEnemyStateIdle:
		Idle();
		break;
	case eEnemyStateMove:
		Move();
		break;
	case eEnemyStateAttack:
		Attack();
		break;
	case eEnemyStateDamage:
		Damage();
		break;
	default:
		break;
	}
	Gravity();
	MovePos();
	AiChange();
}

void CCharacterEnemy::CharacterDraw()
{	

}

void CCharacterEnemy::LoadAnimImage()
{
	m_anim_image_p[eEnemyAnimIdle0] = GET_RESOURCE("Enemy_Idle_0", CImage*);
	m_anim_image_p[eEnemyAnimMove0] = GET_RESOURCE("Enemy_Move_0", CImage*);
	m_anim_image_p[eEnemyAnimAttack0] = GET_RESOURCE("Enemy_Attack_0", CImage*);
	m_anim_image_p[eEnemyAnimDamage0] = GET_RESOURCE("Enemy_Damage_0", CImage*);

	//アニメーションデータの設定
	m_anim_info[eEnemyAnimIdIdle].image_num = 1;
	m_anim_info[eEnemyAnimIdIdle].image_id = eEnemyAnimIdle0;
	m_anim_info[eEnemyAnimIdIdle].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[eEnemyAnimIdMove].image_num = 1;
	m_anim_info[eEnemyAnimIdMove].image_id = eEnemyAnimMove0;
	m_anim_info[eEnemyAnimIdMove].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[eEnemyAnimIdAttack].image_num = 1;
	m_anim_info[eEnemyAnimIdAttack].image_id = eEnemyAnimAttack0;
	m_anim_info[eEnemyAnimIdAttack].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[eEnemyAnimIdDamage].image_num = 1;
	m_anim_info[eEnemyAnimIdDamage].image_id = eEnemyAnimDamage0;
	m_anim_info[eEnemyAnimIdDamage].delay = DEFAULT_ANIM_DELAY;
}

void CCharacterEnemy::Idle()
{
	SetWillPlayAnim(eEnemyAnimIdIdle);
	m_vec = CVector3D(0, m_vec.y, 0);
	
}

void CCharacterEnemy::Move()
{
	SetWillPlayAnim(eEnemyAnimIdMove);
	m_vec = CVector3D(-1, m_vec.y, -1);
	
}

void CCharacterEnemy::Attack()
{
	SetWillPlayAnim(eEnemyAnimIdAttack);
}

void CCharacterEnemy::Damage()
{
	SetWillPlayAnim(eEnemyAnimIdDamage);
	if (is_damage) {
		m_enemy_hp -= 30;
		is_damage = false;
	}
	if (m_enemy_hp < 0)SetIsDelete();
}

void CCharacterEnemy::MovePos()
{
	m_pos_old = m_pos;
	m_pos += m_vec;
}
