#pragma once
#include "CCharacter.h"

class CCharacterEnemy : public CCharacter {
private:
public:
	CCharacterEnemy();
	~CCharacterEnemy();
	void Update(float delta_time);
	void Render();
};