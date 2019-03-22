#ifndef CPLAYERTANK_H
#define CPLAYERTANK_H

#include"CTank.h"
#include"CHpBar.h"
#include"CSound.h"

class CPlayerTank :public CTank{
private:
	int mGravityV; //�d�͑��x
	int mStartX; //�X�^�[�gX���W
	CSound mSound;
	//CRectangle mPlayer;
public:
	static CPlayerTank *spInstance;
	//CPlayerTank()
	//	:mPlayer()
	//	,mGravityV(0)
	//{}
	float p_max_hp;	//�X�e�[�^�X�ޒǉ�	�{��
	float p_max_sp;
	float p_min_sp;


	void Init();
	void Update();
	void OnCollision(CCollider*p);
	void OnCollision(CBoxCollider*p);

	CBoxCollider*mpBoxCollider;
	CRectangle mPlayer;
	CTexture mTexture;
	static CTexture mTexImage;
	static CTexture mTexImage2;
	static CTexture mTexImage3;
	static CTexture mPlayerface;
	static CTexture mPlayerfaceD;
	int mFireInterval;
	float j_Prev;  //�W�����v�O�̍��W
	float j_Temp;  //�W�����v��̍��W
	float p_Jump;
	int JumpCount;
	int EffectCount;
	int EffectCount2;
	int EffectCount3;
	int AttackSide;
	CHpBar mHpBar;
	CHpBar mSpBar;
	int strengthen;
	int Invincible;

	void Render();

};
#endif