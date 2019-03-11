#include "CCharacterEnemy.h"

CCharacterEnemy::CCharacterEnemy() :CCharacter(eTaskIdEnemy, 0)
{
	ADD_RESOURCE("EnemyIdle1", CImage::LoadImage("Enemy_idle1.png"));
	ADD_RESOURCE("EnemyMove1", CImage::LoadImage("Enemy_move1.png"));
	ADD_RESOURCE("EnemyAttack1", CImage::LoadImage("Enemy_attack1.png"));
	ADD_RESOURCE("EnemyDamage1", CImage::LoadImage("Enemy_damage1.png"));
	m_enemy_img = COPY_RESOURCE("EnemyIdle1", CImage*);
	m_enemy_state = eEnemyStateIdle;
	m_enemy_hp = 100;
	m_enemy_vec = CVector3D(0, 0, 0);
	m_enemy_pos = CVector3D(800, 500, 0);
	is_damage = true;
	m_AI_cnt = 0;
}

CCharacterEnemy::~CCharacterEnemy()
{
	printf("çÌèúÇ≥ÇÍÇ‹ÇµÇΩ");
}

void CCharacterEnemy::Update()
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
	AiChange();
}

void CCharacterEnemy::Draw()
{	
	m_enemy_img.SetPos(m_enemy_pos.x, m_enemy_pos.y + m_enemy_pos.z);
	m_enemy_img.SetSize(300, 300);
	m_enemy_img.SetCenter(150, 150);
	m_enemy_img.Draw();
}

void CCharacterEnemy::Idle()
{
	m_enemy_img = COPY_RESOURCE("EnemyIdle1", CImage*);
	m_vec = CVector3D(0, 0, 0);
	
}

void CCharacterEnemy::Move()
{
	m_enemy_img = COPY_RESOURCE("EnemyMove1", CImage*);
	m_vec = CVector3D(-50, 10, 0);
	
}

void CCharacterEnemy::Attack()
{
	m_enemy_img = COPY_RESOURCE("EnemyAttack1", CImage*);
}

void CCharacterEnemy::Damage()
{
	m_enemy_img = COPY_RESOURCE("EnemyDamage1", CImage*);
	if (is_damage) {
		m_enemy_hp -= 30;
		is_damage = false;
	}
	if (m_enemy_hp < 0)SetIsDelete();
}
