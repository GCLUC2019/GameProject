#include "CCharacterEnemy.h"

CCharacterEnemy::CCharacterEnemy() :CCharacter(eId_CharacterPlayer, eUp_CharacterPlayer, eRd_CharacterPlayer)
{
	ADD_RESOURCE("Enemy", CImage::LoadImage("enemy.png"));
	m_enemy_img = COPY_RESOURCE("Enemy", CImage*);
}

CCharacterEnemy::~CCharacterEnemy()
{
}

void CCharacterEnemy::Update(float delta_time)
{
}

void CCharacterEnemy::Render()
{
	m_enemy_img.SetSize(200, 200);
	m_enemy_img.SetPos(800, 500);
	m_enemy_img.Draw();
}
