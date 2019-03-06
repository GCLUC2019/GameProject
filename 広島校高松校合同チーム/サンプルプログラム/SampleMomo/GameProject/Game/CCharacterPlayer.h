#pragma once
#include "CCharacter.h"

class CCharacterPlayer : public CCharacter {
private:
	CImage* m_player_image_p;
public:
	CCharacterPlayer();
	~CCharacterPlayer();
	void Update(float delta_time);
	void Render();
};