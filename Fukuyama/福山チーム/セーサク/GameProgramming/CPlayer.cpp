#include "CPlayer.h"



//�v���C���[�ړ����x
#define VELOCITY_P 2
//�W�����v����
#define VELOCITY_JUMP 15
//�d�͉����x
#define GRAVITY 1
#define GRAVITY2 0

//UV�}�b�s���O �v���C���[�̕���
#define UVPLAYERWALK1 136, 156, 158, 130
#define UVPLAYERWALK2 168, 188, 158, 130
#define UVPLAYERWALK1L 156, 136, 158, 130
#define UVPLAYERWALK2L 188, 168, 158, 130
//�v���C���[����
#define UVPLAYERCRY 196, 216, 158, 130

int NotAttack = 0;  //�ǉ��@���c�@�@

//�v���C���[�̃C���X�^���X
CPlayer *CPlayer::spInstance = 0;

CPlayer::CPlayer(CTexture *t, int x, int y, int w, int h, int u0, int u1, int v0, int v1)
: CCharacter(t, x, y, w, h, u0, u1, v0, v1)
, mGravityV(0)
, mStartX(x)
{
	mTag = CCharacter::EPLAYER;
	//�C���X�^���X�|�C���^�ɐݒ�
	spInstance = this;
	//�T�E���h���[�h
	mSound.Load("jump.mp3");
}

/*
�v���C���[�̍X�V����
*/
void CPlayer::Update() {
	//�E�ֈړ�
	if (GetKeyState('D') & 0x8000) {
		x += VELOCITY_P;
		//X���W�ɂ���ĉ摜��ς���
		if (x % 30 < 15) {
			//�E�摜1
			SetUv(UVPLAYERWALK1);
		}
		else {
			//�E�摜2
			SetUv(UVPLAYERWALK2);
		}
	}
	//���ֈړ�
	if (GetKeyState('A') & 0x8000) {
		//�J�n�ʒu��荶�֍s�����Ȃ�
		if (mStartX < x)
			x -= VELOCITY_P;
		//X���W�ɂ���ĉ摜��ς���
		if (x % 30 < 15) {
			//���摜1
			SetUv(UVPLAYERWALK1L);
		}
		else {
			//���摜2
			SetUv(UVPLAYERWALK2L);
		}
	}
	//�W�����v����
	if (GetKeyState(' ') & 0x8000 && mState == ERUN) {
		mGravityV = VELOCITY_JUMP;
		//�W�����v��
		mState = EJUMPUP;
		//1��Đ�
		mSound.Play();
	}
	if (mGravityV < -GRAVITY)
		//�W�����v��
		mState = EJUMPDOWN;
	//�d�͑��x���ړ�
	y += mGravityV;
	//�d�͑��x�X�V
	mGravityV -= GRAVITY2;
}

/*
�v���C���[�̏Փˏ���
*/
bool CPlayer::Collision(CCharacter *m, CCharacter *yo) {
	//int dx, dy;
	//����ƏՓ˂��Ă��邩����
	//if (CRectangle::Collision(yo, &dx, &dy)) {
	//	switch (yo->mTag) {
	//	case EENEMY: //���肪�G�̎�
	//		switch (yo->mState) {
	//		case ERUN:
	//			if (mState == ERUN) {
	//				mState = ECRY;
	//				SetUv(UVPLAYERCRY);
	//			}
	//			break;
	//		case ECRY:
	//			//�߂肪���������֖߂�
	//			if (abs(dx) < abs(dy)) {
	//				x += dx;
	//			}
	//			else {
	//				y += dy;
	//				//�d�͏�����
	//				mGravityV = 0;
	//				//����
	//				mState = ERUN;
	//			}
	//			break;
	//		}
	//		break;
	//		//�߂肪���������֖߂�
	//		if (abs(dx) < abs(dy)) {
	//			x += dx;
	//		}
	//		else {
	//			y += dy;
	//			//�d�͏�����
	//			mGravityV = 0;
	//			//����
	//			mState = ERUN;
	//		}
	//		break;
	//	}
	//	//�Փ˂��Ă���
	//	return true;
	//}
	//�Փ˂��Ă��Ȃ�
	return false;
}
