#ifndef CPLAYER2_H
#define CPLAYER2_H

#include "CCharacter.h"
#include "CSound.h"
#include "CTexture.h"

/*
�v���C���[�N���X
*/
class CPlayer : public CCharacter {
private:
	int mGravityV; //�d�͑��x
	int mStartX; //�X�^�[�gX���W
	CSound mSound;
public:
	static CPlayer *spInstance; //�C���X�^���X�̃|�C���^
	CPlayer(CTexture *t, int x, int y, int w, int h, int u0, int u1, int v0, int v1);
	//�X�V����
	void Update();
	//�Փˏ���
	bool Collision(CCharacter *m, CCharacter *y);
};


#endif
