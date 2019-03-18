#pragma once
#include "CCharacter.h"

//������250.0f�ȏ�ɂȂ�ƈړ����J�n����
#define ENEMY_MOVE_START_LENGTH (250.0f)

//�ړ����́A������200.0f�ȉ��ɂȂ�܂ŋ߂Â�
#define ENEMY_MOVE_END_LENGTH (200.0f)


#define ENEMY_ATTACK_FRAME (20.0)

#define ENEMY_ATTACK_LENGTH (300.0f)
#define ENEMY_ATTACK_POWER (1.0)

#define ENEMY_ATTACK_HIT_START_FRAME (10.0)
#define ENEMY_ATTACK_HIT_END_FRAME (20.0)

#define ENEMY_RECEIVE_DAMAGE_FRAME (30.0)

enum {
	eEnemyIdSpear,
};

enum {
	eEnemyAnimIdIdle,
	eEnemyAnimIdMove,
	eEnemyAnimIdAttack,
	eEnemyAnimIdDamage,
};

class CCharacterEnemy : public CCharacter {
private:
	int m_enemy_id;
	CCharacter* m_target_p = nullptr;//�^�[�Q�b�g �P���Șb�L�����Ȃ�΂����̂œ��m�������ݒ莟��ł͉\��
	
	bool m_is_moving = false;


	float m_attack_length;

	double m_attack_power = 0.0;
	double m_attacking_count = 0;
	double m_attack_frame = 0;
	double m_attacking_hit_start_frame = 0.0;
	double m_attacking_hit_end_frame = 0.0;
	
	bool m_is_attacking = false;

	bool m_is_hit_attack = false;

	float m_move_start_length;
	float m_move_end_length;


	bool m_is_receive_damage_now = false;
	double m_receive_damage_frame;
	double m_receive_damage_count;


public:
	CCharacterEnemy(int _enemy_id,CVector3D _enemy_pos);
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
	
	void AdjAnim();
};

/*
2019/03/17 �N���X��`�A�@�\�����B(�X�P�W���[���ϓ��ɍ��킹�A�V�K�쐬�����ׁA�e�X�g�ł�CCharacterEnemy�Ƃ͕ʂ̕�)  by shingai
*/
