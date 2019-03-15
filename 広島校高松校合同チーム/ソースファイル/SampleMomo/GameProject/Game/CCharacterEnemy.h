#pragma once
#include "CCharacter.h"
#include "../Global.h"



enum {	//�A�j���[�V�����̎�ނ̔ԍ�
	eEnemyAnimIdIdle,
	eEnemyAnimIdMove,
	eEnemyAnimIdAttack,
	eEnemyAnimIdDamage,
	eEnemyAnimIdMax,
};

enum {	//�A�j���[�V�����̉摜������ԍ�
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
	enum {	//�G�l�~�[�̏��
		eEnemyStateIdle,	//�ҋ@���
		eEnemyStateMove,	//�ړ����
		eEnemyStateAttack,	//�U�����
		eEnemyStateDamage	//�_���[�W���
	};
	enum {  //�G�l�~�[�̃^�C�v
		eEnemyTypeSpear,	//��
		eEnemyTypeAxe,		//��
		eEnemyTypeGun		//�e
	};
	int m_enemy_type;        //�G�l�~�[�̃^�C�v�ł�
	int m_enemy_state;       //�G�l�~�[�̏��
	int m_old_enemy_state;   //�G�l�~�[���_���[�W���󂯂����ɋL�����钼�O�̏��
	int m_AI_cnt;            //��Ԃ��ω�����܂ł̃J�E���g
	bool m_is_damage;        //�G�l�~�[���_���[�W���󂯂Ă������ǂ����̃t���O
	int m_damage_chance;     //�v���C���[�̍U���𓖂Ă�ꂽ��
	bool m_attack_chance;    //�G�l�~�[�̍U���������鋗�����̃t���O
	CVector2D m_attack_pos;      //�K���˒�����
	CVector3D m_player_pos;		 //�v���C���[�̍��W���L��
	CVector2D m_player_vec;      //�v���C���[�����ւ̃x�N�g��

	bool is_attack;          //�G�l�~�[�̍U���𓖂Ă����ǂ����̃t���O

public:
	CCharacterEnemy();
	~CCharacterEnemy();
	void CharacterUpdate();
	void CharacterDraw();
	void ReceiveAttack();
	void CharacterOutHitPoint();

	void LoadAnimImage();
	void Idle();         //�ҋ@��Ԃ̊֐�
	void Move();		 //�ړ���Ԃ̊֐�
	void Attack();		 //�U����Ԃ̊֐�
	void Damage();		 //�_���[�W��Ԃ̊֐�
	void MovePos();		 //�ړ�����

	void AiChange(int ai_cnt);				//��Ԃ�ύX���鎞�̊֐�
	void CharacterBeforeCollisionCheck();	//�v���C���[�Ƃ̈ʒu�֌W�𒲂ׂ�֐�
};
/*
2019/03/11 �N���X��`�B by �x��
*/