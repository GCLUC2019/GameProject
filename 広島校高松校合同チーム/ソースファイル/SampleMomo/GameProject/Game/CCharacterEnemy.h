#pragma once
#include "CCharacter.h"

class CBar;

#define ENEMY_SPEAR_FIND_LENGTH (3000.0f)
#define ENEMY_SPEAR_ATTACK_FRAME (30.0)
#define ENEMY_SPEAR_ATTACK_LENGTH CVector3D(200.0f,150.0f,75.0)
#define ENEMY_SPEAR_MOVE_END_LENGTH CVector3D(120.0f,150.0f,90.0)
#define ENEMY_SPEAR_ATTACK_POWER (1.0)
#define ENEMY_SPEAR_ATTACK_HIT_START_FRAME (15.0)
#define ENEMY_SPEAR_ATTACK_HIT_END_FRAME (30.0)
#define ENEMY_SPEAR_RECEIVE_DAMAGE_FRAME (50.0)
#define ENEMY_SPEAR_SPACE_LENGTH CVector3D(50,0,50)

#define ENEMY_AXE_FIND_LENGTH (3000.0f)
#define ENEMY_AXE_ATTACK_FRAME (30.0)
#define ENEMY_AXE_ATTACK_LENGTH CVector3D(200.0f,500.0f,75.0)
#define ENEMY_AXE_MOVE_END_LENGTH CVector3D(120.0f,500.0f,90.0)
#define ENEMY_AXE_ATTACK_POWER (1.0)
#define ENEMY_AXE_ATTACK_HIT_START_FRAME (15.0)
#define ENEMY_AXE_ATTACK_HIT_END_FRAME (30.0)
#define ENEMY_AXE_RECEIVE_DAMAGE_FRAME (50.0)
#define ENEMY_AXE_SPACE_LENGTH CVector3D(50,0,50)


#define ENEMY_GUN_FIND_LENGTH (3000.0f)
#define ENEMY_GUN_ATTACK_FRAME (120.0)
#define ENEMY_GUN_ATTACK_LENGTH CVector3D(1000.0f,150.0f,50.0f)
#define ENEMY_GUN_MOVE_END_LENGTH CVector3D(800.0f,150.0f,50.0f)
#define ENEMY_GUN_ATTACK_POWER (1.0)
#define ENEMY_GUN_ATTACK_HIT_START_FRAME (60.0)
#define ENEMY_GUN_ATTACK_HIT_END_FRAME (61.0)
#define ENEMY_GUN_RECEIVE_DAMAGE_FRAME (50.0)
#define ENEMY_GUN_SPACE_LENGTH CVector3D(300,0,50)

#define ENEMY_GUN_BULLET_DESTROY_LENGTH CVector3D(1000,50,50)

#define ENEMY_BULLET_ATTACK_LENGTH CVector3D(15,15,15)

#define ENEMY_KNOCK_BACK_FRAME (30.0)

/*
遠距離攻撃は、当たるのが確定したら撃つアニメーションを再生する。（わかりやすさのため)
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
	CCharacter* m_target_p = nullptr;//ターゲット 単純な話キャラならばいいので同士討ちも設定次第では可能か
	
	bool m_is_moving = false;

	//HPバー
	CBar* m_hit_point_bar_p = nullptr;
	CImage * m_hp_frame_image_p = nullptr;

	CVector3D m_attack_length;

	double m_attack_power = 0.0;
	double m_attacking_count = 0;
	double m_attack_frame = 0;
	double m_attacking_hit_start_frame = 0.0;
	double m_attacking_hit_end_frame = 0.0;
	

	bool m_is_range = false;

	bool m_is_attacking = false;

	bool m_is_hit_attack = false;

	//距離が設定値以下ならターゲットに向かって移動開始
	float m_find_length;

	//設定値以下なら止まる
	CVector3D m_move_end_length;

	//これ以上距離が近いなら離れる
	CVector3D m_space_length;

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

	void ReceiveKnockBack(CVector3D _from_pos, double _power);

	void EnemyMoving();
	void EnemyAttack();
	void Attacking();
	
	void DropItem();

	void AdjAnim();
};

/*
2019/03/17 クラス定義、機能実装。(スケジュール変動に合わせ、新規作成した為、テスト版のCCharacterEnemyとは別の物)  by shingai
*/
