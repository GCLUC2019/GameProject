#include "CCharacter.h"

//�R���X�g���N�^
CCharacter::CCharacter(CTexture *t, int ax, int ay, int aw, int ah, int u0, int u1, int v0, int v1)
: mState(ERUN) //�ړ����
, mEnabled(true)
{
	x = ax; //X���W
	y = ay; //Y���W
	w = aw; //��
	h = ah; //����
	mpTexture = t;
	mU[0] = u0; //UV��
	mU[1] = u1; //UV�E
	mV[0] = v0; //UV��
	mV[1] = v1; //UV��
}


//�e�N�X�`���}�b�s���O�̐ݒ�
void CCharacter::SetUv(int u0, int u1, int v0, int v1) {
	mU[0] = u0;
	mU[1] = u1;
	mV[0] = v0;
	mV[1] = v1;
}
