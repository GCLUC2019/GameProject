#pragma once
#include "../Game/CGameSceneObject.h"
#include "CAnimation.h"
#include "../Global.h"

enum {
	eItemPeach,
	eItemFlag,
	eItemMax,
};

class CItem : public CGameSceneObject {
private:
	int m_item_id;
	static bool m_get_item_flag;
public:
	CItem(CVector3D pos, int _item_id);
	~CItem();

	void LoadAnimImage();			//�A�j���[�V�����ǂݍ���

	void GameSceneObjectUpdate();	//�X�V����

	void PlayerGetItem();	//�v���C���[�ɏE��ꂽ���ɌĂ΂��


};

