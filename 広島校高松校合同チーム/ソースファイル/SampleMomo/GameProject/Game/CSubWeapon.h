#pragma once
#include "../Game/CGameSceneObject.h"
#include "CAnimation.h"
#include "../Global.h"

class CCharacterPlayer;

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
	
	//bool m_equip_flag;		//�v���C���[�����̕���𑕔����Ă��邩�̃t���O
	int m_weapon_num;		//����̎��
	float m_energy;			//����̑ϋv�l
	
	CCharacterPlayer* m_target_p;	//�v���C���[�̃|�C���^

	static bool m_get_flag;	//������E���邩�ǂ����̃t���O(�d�Ȃ�������𓯎��ɏE���Ȃ��悤�ɂ���t���O)
public:
	CSubWeaponItem(CVector3D pos, int weapon_num);
	~CSubWeaponItem();

	void LoadAnimImage();			//�A�j���[�V�����ǂݍ���

	void GameSceneObjectUpdate();	//�X�V����

	void PlayerGetItem();	//�v���C���[�ɏE��ꂽ���ɌĂ΂��


};

