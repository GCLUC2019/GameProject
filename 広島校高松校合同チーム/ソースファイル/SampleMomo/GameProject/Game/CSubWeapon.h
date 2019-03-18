#pragma once
#include "../Game/CGameSceneObject.h"

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

	void PlayerGetItem();	//�v���C���[�ɏE��ꂽ���ɌĂ΂��


};

