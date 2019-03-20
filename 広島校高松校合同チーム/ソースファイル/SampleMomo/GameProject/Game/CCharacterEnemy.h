#pragma once
#include "CCharacter.h"

#define ENEMY_SPEAR_FIND_LENGTH (3000.0f)
#define ENEMY_SPEAR_ATTACK_FRAME (30.0)
#define ENEMY_SPEAR_ATTACK_LENGTH CVector3D(300.0f,150.0f,150.0)
#define ENEMY_SPEAR_MOVE_END_LENGTH CVector3D(270.0f,150.0f,90.0)
#define ENEMY_SPEAR_ATTACK_POWER (1.0)
#define ENEMY_SPEAR_ATTACK_HIT_START_FRAME (15.0)
#define ENEMY_SPEAR_ATTACK_HIT_END_FRAME (30.0)
#define ENEMY_SPEAR_RECEIVE_DAMAGE_FRAME (50.0)
#define ENEMY_SPEAR_SPACE_LENGTH (200.0)

#define ENEMY_AXE_FIND_LENGTH (3000.0f)
#define ENEMY_AXE_ATTACK_FRAME (30.0)
#define ENEMY_AXE_ATTACK_LENGTH CVector3D(300.0f,1000.0f,150.0)
#define ENEMY_AXE_MOVE_END_LENGTH CVector3D(270.0f,1000.0f,90.0)
#define ENEMY_AXE_ATTACK_POWER (1.0)
#define ENEMY_AXE_ATTACK_HIT_START_FRAME (15.0)
#define ENEMY_AXE_ATTACK_HIT_END_FRAME (30.0)
#define ENEMY_AXE_RECEIVE_DAMAGE_FRAME (50.0)
#define ENEMY_AXE_SPACE_LENGTH (200.0)


#define ENEMY_GUN_FIND_LENGTH (3000.0f)
#define ENEMY_GUN_ATTACK_FRAME (120.0)
#define ENEMY_GUN_ATTACK_LENGTH CVector3D(1000.0f,150.0f,50.0f)
#define ENEMY_GUN_MOVE_END_LENGTH CVector3D(800.0f,150.0f,50.0f)
#define ENEMY_GUN_ATTACK_POWER (1.0)
#define ENEMY_GUN_ATTACK_HIT_START_FRAME (60.0)
#define ENEMY_GUN_ATTACK_HIT_END_FRAME (61.0)
#define ENEMY_GUN_RECEIVE_DAMAGE_FRAME (50.0)
#define ENEMY_GUN_SPACE_LENGTH (300.0)

/*
�������U���́A������̂��m�肵���猂�A�j���[�V�������Đ�����B�i�킩��₷���̂���)
*/

enum {
	eEnemyIdSpear,
	eEnemyIdAxe,
	eEnemyIdGun,
};

enum {
	eEnemyAnimIdIdle,
	eEnemyAnimIdMove,
	eEnemyAnimIdAttack,
	eEnemyAnimIdDamage,
	eEnemyAnimIdShot,
};

class CCharacterEnemy : public CCharacter {
private:
	int m_enemy_id;
	CCharacter* m_target_p = nullptr;//�^�[�Q�b�g �P���Șb�L�����Ȃ�΂����̂œ��m�������ݒ莟��ł͉\��
	
	bool m_is_moving = false;


	CVector3D m_attack_length;

	double m_attack_power = 0.0;
	double m_attacking_count = 0;
	double m_attack_frame = 0;
	double m_attacking_hit_start_frame = 0.0;
	double m_attacking_hit_end_frame = 0.0;
	

	bool m_is_range = false;

	bool m_is_attacking = false;

	bool m_is_hit_attack = false;

	//�������ݒ�l�ȉ��Ȃ�^�[�Q�b�g�Ɍ������Ĉړ��J�n
	float m_find_length;

	//�ݒ�l�ȉ��Ȃ�~�܂�
	CVector3D m_move_end_length;

	//����ȏ㋗�����߂��Ȃ痣���
	float m_space_length;

	bool m_is_receive_damage_now = false;
	double m_receive_damage_frame;
	double m_receive_damage_count;


public:
	CCharacterEnemy(int _enemy_id,CVector3D _enemy_pos,CGameSceneWave* _from_wave = nullptr);
	~CCharacterEnemy();

	void LoadAnimImage();

	void CharacterBeforeUpdate();
	void CharacterUpdate();
	void CharacterBeforeCollisionCheck();
	void CollisionCheckCharacter(Task* _collision_task);
	void CharacterDraw();
	void CharacterOutHitPoint();
	void ReceiveAttack();
	
	void ReceiveDamageNow();

	void EnemyMoving();
	void EnemyAttack();
	void Attacking();
	
	void DropItem();

	void AdjAnim();
};

/*
2019/03/17 �N���X��`�A�@�\�����B(�X�P�W���[���ϓ��ɍ��킹�A�V�K�쐬�����ׁA�e�X�g�ł�CCharacterEnemy�Ƃ͕ʂ̕�)  by shingai
*/
