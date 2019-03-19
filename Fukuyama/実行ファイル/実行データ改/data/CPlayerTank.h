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
	CBoxCollider*mpBoxCollider;
	CRectangle mPlayer;
	CTexture mTexture;
	static CTexture mTexImage;
	int mFireInterval;
	int p_Jump;
	int JumpCount;
	int EffectCount;
	int EffectCount2;
	int AttackSide;
	CHpBar mHpBar;


	void Render();

};
#endif