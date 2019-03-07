#pragma once
#include "CCharacter.h"


#define DEFAULT_ANIM_DELAY (10)

enum {
	ePlayerAnimIdIdle,
	ePlayerAnimIdMove,
};

enum {
	ePlayerAnimIdle0,
	ePlayerAnimIdle1,
	ePlayerAnimIdle2,
	ePlayerAnimIdle3,
	ePlayerAnimMove0,
	ePlayerAnimMove1,
	ePlayerAnimMove2,
	ePlayerAnimMove3,
	ePlayerAnimMove4,
	ePlayerAnimMove5,
	ePlayerAnimMax,
};
class CCharacterPlayer : public CCharacter {
private:
	int m_play_anim_id = ePlayerAnimIdIdle;
	int m_play_anim_image = ePlayerAnimIdle0;
	int m_play_anim_count = DEFAULT_ANIM_DELAY;
	CImage* m_player_image_p[ePlayerAnimMax];
	int m_will_play_anim_id = ePlayerAnimIdIdle;
public:
	CCharacterPlayer();
	~CCharacterPlayer();
	void LoadAnimImage();
	void SetAnim(int _anim_id);
	void PlayAnim();
	void PlayAnimIdle();
	void PlayAnimMove();
	void InputMove();
	void Move();
	void Update(float delta_time);
	void Draw();
	void MoveLimit();
};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
*/
