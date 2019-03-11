#pragma once
#include "CCharacter.h"
#include "../Global.h"



enum {
	eEnemyAnimIdIdle,
	eEnemyAnimIdMove,
	eEnemyAnimIdAttack,
	eEnemyAnimIdDamage,
	eEnemyAnimIdMax,
};

enum {
	eEnemyAnimIdle1,
	eEnemyAnimIdle2,
	eEnemyAnimIdle3,
	eEnemyAnimIdle4,
	eEnemyAnimMove1,
	eEnemyAnimMove2,
	eEnemyAnimMove3,
	eEnemyAnimMove4,
	eEnemyAnimMove5,
	eEnemyAnimMove6,
	eEnemyAnimMove7,
	eEnemyAnimMove8,
	eEnemyAnimAttack1,
	eEnemyAnimAttack2,
	eEnemyAnimDamage1,
	eEnemyAnimMax,
};


class CCharacterEnemy : public CCharacter {
private:
	enum {
		eEnemyStateIdle,
		eEnemyStateMove,
		eEnemyStateAttack,
		eEnemyStateDamage
	};
	int m_enemy_state;
	int m_old_enemy_state;   //�_���[�W���󂯂����ɋL�����钼�O�̏��
	int m_enemy_hp;
	int m_AI_cnt;            //��Ԃ��ω�����܂ł̃J�E���g
	bool is_damage;          //�_���[�W���󂯂Ă������ǂ����̃t���O
	bool m_attack_chance;    //�U���������鋗�����̃t���O
	CVector3D p_pos;		 //�v���C���[�̍��W���L��
	CVector2D p_vec;         //�v���C���[�����ւ̃x�N�g��
public:
	CCharacterEnemy();
	~CCharacterEnemy();
	void CharacterUpdate();
	void CharacterDraw();

	void LoadAnimImage();
	void Idle();
	void Move();
	void Attack();
	void Damage();
	void MovePos();

	void AiChange(int ai_cnt);
	void CharacterBeforeCollisionCheck();
};
/*
2019/03/06 �N���X��`�B by shingai
2019/03/11 �N���X��`�B by �x��
*/