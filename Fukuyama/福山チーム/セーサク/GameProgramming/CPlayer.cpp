#include "CPlayer.h"
#include "CKey.h"
//#include "CBlock.h"

//�v���C���[�ړ����x
#define VELOCITY_P 2
//�W�����v����
#define VELOCITY_JUMP 15
//�d�͉����x
#define GRAVITY 1
//�d�͉����x
#define GRAV0ITY GRAVITY

//UV�}�b�s���O �v���C���[�̕���
#define UVPLAYERWALK1 136, 156, 158, 130
#define UVPLAYERWALK2 168, 188, 158, 130
#define UVPLAYERWALK1L 156, 136, 158, 130
#define UVPLAYERWALK2L 188, 168, 158, 130
//�v���C���[����
#define UVPLAYERCRY 196, 216, 158, 130

//�v���C���[�̃C���X�^���X
CPlayer *CPlayer::spInstance = 0;
//float Gravity = 0.5;
float Gravity = (GRAV0ITY);
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
	if (CKey::Push('D')) {
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
	if (CKey::Push('A')) {
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
	if (CKey::Once(' ') && mState == ERUN) {
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
	mGravityV -= GRAVITY;
}

/*
�v���C���[�̏Փˏ���
*/
bool CPlayer::Collision(CCharacter *m, CCharacter *yo) {
	//int dx, dy;
	////����ƏՓ˂��Ă��邩����
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
	//	case EBLOCK: //���肪�u���b�N
	//		//�u���b�N�N���X�փL���X�g
	//		CBlock *b = (CBlock*)yo;
	//		//���֒����̎�
	//		if (dx < 0) {
	//			//�����󂢂Ă��邩����
	//			if ((b->mType & 0x08) == 0) {
	//				//�󂢂Ă��Ȃ��ꍇ
	//				dx = w*2;//�傫���l����
	//			}
	//		}
	//		//�E�֒����̎�
	//		else if (dx > 0) {
	//			//�E���󂢂Ă��邩����
	//			if ((b->mType & 0x02) == 0) {
	//				//�󂢂Ă��Ȃ��ꍇ
	//				dx = w * 2;//�傫���l����
	//			}
	//		}
	//		//���֒����̏ꍇ
	//		if (dy < 0) {
	//			//�����󂢂Ă��邩����
	//			if ((b->mType & 0x04) == 0) {
	//				dy = h*2;
	//			}
	//		}
	//		//��֒����̏ꍇ
	//		else if (dy > 0) {
	//			//�オ�󂢂Ă��邩����
	//			if ((b->mType & 0x01) == 0) {
	//				dy = h*2;
	//			}
	//		}
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
	////�Փ˂��Ă��Ȃ�
	return false;
}
