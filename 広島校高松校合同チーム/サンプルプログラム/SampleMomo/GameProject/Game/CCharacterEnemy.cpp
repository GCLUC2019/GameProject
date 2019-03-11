#include "CCharacterEnemy.h"

CCharacterEnemy::CCharacterEnemy() :CCharacter(eTaskIdEnemy, 0)
{
	ADD_RESOURCE("Enemy", CImage::LoadImage("enemy.png"));
	m_enemy_img = COPY_RESOURCE("Enemy", CImage*);
	m_enemy_state = eEnemyStateIdle;
	m_enemy_vec = CVector3D(0, 0, 0);
	m_enemy_pos = CVector3D(800, 500, 0);
	m_enemy_img.SetSize(200, 200);
	m_enemy_img.SetCenter(100, 100);
}

CCharacterEnemy::~CCharacterEnemy()
{
	printf("çÌèúÇ≥ÇÍÇ‹ÇµÇΩ");
}

void CCharacterEnemy::Update()
{

	switch (m_enemy_state) {
	case eEnemyStateIdle:
		break;
	case eEnemyStateAttack:
		break;
	case eEnemyStateDamage:
		break;
	default:
		break;
	}

	Gravity();
}

void CCharacterEnemy::Draw()
{	
	m_enemy_img.SetPos(m_enemy_pos.x, m_enemy_pos.y + m_enemy_pos.z);
	m_enemy_img.Draw();
}
