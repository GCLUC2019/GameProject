#pragma once
#include "CCharacter.h"


#define DEFAULT_ANIM_DELAY (10)

enum {
	ePlayerAnimIdle0,
	ePlayerAnimIdle1,
	ePlayerAnimIdle2,
	ePlayerAnimIdle3,
	ePlayerAnimMax,
};
class CCharacterPlayer : public CCharacter {
private:
	int m_play_anim = ePlayerAnimIdle0;
	int m_play_anim_count = DEFAULT_ANIM_DELAY;
	CImage* m_player_image_p[ePlayerAnimMax];
public:
	CCharacterPlayer();
	~CCharacterPlayer();
	void LoadAnimImage();
	void SetAnim(int _anim_id);
	void PlayAnim();
	void Update(float delta_time);
	void Render();
};