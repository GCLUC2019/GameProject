#pragma once
#include "CharacterBase.h"

class Player : public CharacterBase {
private:
	CImage m_Shadow;
public:
	Player();
	void Update();
	void Draw();
};