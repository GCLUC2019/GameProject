#ifndef CCHARACTER_H
#define CCHARACTER_H
//�l�p�`�N���X�̃C���N���[�h
#include "CRectangle.h"

/*
�L�����N�^�N���X
*/
class CCharacter : public CRectangle {
public:
	//�L�������t���O
	bool mEnabled;//true:�L�� false:����
	//�񋓌^�̒�`
	enum ETag {
		EBLOCK,			//�u���b�N
		EPLAYERBULLET,	//�v���C���[�e
		EPLAYER,		//�v���C���[
		EENEMY,			//�G
	};
	ETag mTag;	//�L�����̎���

	//��Ԏ��ʎq
	enum EState {
		ERUN,		//�ړ���
		EJUMPUP,	//�W�����v��
		EJUMPDOWN,	//�W�����v��
		ECRY,		//�����Ă���
	};
	EState mState; //���

	//�R���X�g���N�^
	CCharacter(CTexture *t, int ax, int ay, int aw, int ah, int u0, int u1, int v0, int v1);

	//���z�֐� �`�揈��
	virtual void Render() {
		//�摜�`��
		Draw(*mpTexture, mU[0], mU[1], mV[0], mV[1]);
	}

	//���z�֐� �X�V����
	virtual void Update() {}

	//�Փˏ���
	virtual bool Collision(CCharacter *m, CCharacter *y) { return false; };

	//�e�N�X�`���}�b�s���O�̐ݒ�
	void SetUv(int u0, int u1, int v0, int v1);
};

#endif
