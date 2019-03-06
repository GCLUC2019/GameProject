#pragma once
#include "CCharacter.h"

class CCharacterEnemy : public CCharacter {
private:
	CImage m_enemy_img;
public:
	CCharacterEnemy();
	~CCharacterEnemy();
	void Update(float delta_time);
	void Render();
};