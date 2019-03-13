#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
�S��
�Ԟ��@Boss.cppp,h
*/
class BossHead :public EnemyBase {
private:

	bool m_anim_flag;//�A�j���[�V�����t���O
	bool m_move_flag;//�ړ��t���O
protected:


public:
	BossHead();

	void Update();

	void Draw();

};


class BossHand :public EnemyBase {
private:

	CVector2D m_center;

	int m_cnt;//�G�t�F�N�g�p�Ɏg���Ă܂�

	bool m_anim_flag;//�A�j���[�V�����t���O
	bool m_move_flag;//�ړ��t���O

protected:


public:
	BossHand();

	void Update();

	void Draw();

};

