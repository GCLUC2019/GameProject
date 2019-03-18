#pragma once
#include "../Game/CGameSceneObject.h"
#include "CAnimation.h"
#include "../Global.h"

enum {	//�A�j���[�V�����̎�ނ̔ԍ�
	eItemAnimIdIdle,
	eItemyAnimIdMax,
};

enum {	//�A�j���[�V�����̉摜������ԍ�
	eItemAnimIdle1,
	eEnemyAnimMax,
};

enum {  //�T�u����̃^�C�v
	eWeaponSpear,	//��
	eWeaponAxe,		//��
	eWeaponGun		//�e
};

class CSubWeaponItem : public CGameSceneObject {
private:
	bool m_equip_flag;		//����𑕔����Ă��邩�̃t���O
	int m_weapon_num;		//����̎��
	float m_energy;			//����̑ϋv�l
public:
	CSubWeaponItem(CVector3D pos, int weapon_num);
	~CSubWeaponItem();
	void LoadAnimImage();

	void GameSceneObjectUpdate();

	void PlayerGetItem();	//�v���C���[�ɏE��ꂽ���ɌĂ΂��


};

