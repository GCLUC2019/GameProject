#pragma once
#include "CCharacter.h"

#define ENEMY_SPEAR_MOVE_START_LENGTH (250.0f)
#define ENEMY_SPEAR_MOVE_END_LENGTH (200.0f)
#define ENEMY_SPEAR_ATTACK_FRAME (20.0)
#define ENEMY_SPEAR_ATTACK_LENGTH (300.0f)
#define ENEMY_SPEAR_ATTACK_POWER (1.0)
#define ENEMY_SPEAR_ATTACK_HIT_START_FRAME (10.0)
#define ENEMY_SPEAR_ATTACK_HIT_END_FRAME (20.0)
#define ENEMY_SPEAR_RECEIVE_DAMAGE_FRAME (30.0)


#define ENEMY_AXE_MOVE_START_LENGTH (250.0f)
#define ENEMY_AXE_MOVE_END_LENGTH (200.0f)
#define ENEMY_AXE_ATTACK_FRAME (20.0)
#define ENEMY_AXE_ATTACK_LENGTH (300.0f)
#define ENEMY_AXE_ATTACK_POWER (1.0)
#define ENEMY_AXE_ATTACK_HIT_START_FRAME (10.0)
#define ENEMY_AXE_ATTACK_HIT_END_FRAME (20.0)
#define ENEMY_AXE_RECEIVE_DAMAGE_FRAME (30.0)

enum {
	eEnemyIdSpear,
	eEnemyIdAxe,
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
	CCharacter* m_target_p = nullptr;//ターゲット 単純な話キャラならばいいので同士討ちも設定次第では可能か
	
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
2019/03/17 クラス定義、機能実装。(スケジュール変動に合わせ、新規作成した為、テスト版のCCharacterEnemyとは別の物)  by shingai
*/
