#pragma once
#include "CCharacter.h"

/*
ジャンプ後の着地時に硬直追加
回避行動を着地直後のうまいタイミングで行えば硬直をキャンセルできるので
上手くやれば隙は生じにくいはず
*/


#define PLAYER_ATTACK_FRAME (20)
#define PLAYER_ATTACK_HIT_FRAME_START (11)
#define PLAYER_ATTACK_HIT_FRAME_END (20)

#define PLAYER_SIDE_ATTACK_FRAME (20)
#define PLAYER_SIDE_ATTACK_HIT_FRAME_START (11)
#define PLAYER_SIDE_ATTACK_HIT_FRAME_END (20)

#define PLAYER_FINISH_ATTACK_FRAME (42)
#define PLAYER_FINISH_ATTACK_HIT_FRAME_START (34)
#define PLAYER_FINISH_ATTACK_HIT_FRAME_END (42)


#define PLAYER_SPEAR_ATTACK_FRAME (20)
#define PLAYER_SPEAR_ATTACK_HIT_FRAME_START (11)
#define PLAYER_SPEAR_ATTACK_HIT_FRAME_END (20)


#define PLAYER_AXE_ATTACK_FRAME (20)
#define PLAYER_AXE_ATTACK_HIT_FRAME_START (8)
#define PLAYER_AXE_ATTACK_HIT_FRAME_END (20)



#define PLAYER_GUN_ATTACK_FRAME (40)
#define PLAYER_GUN_ATTACK_HIT_FRAME_START (21)
#define PLAYER_GUN_ATTACK_HIT_FRAME_END (22)

//予備動作のフレーム(これも攻撃ごとにしたほうがよい)
#define PLAYER_ATTACK_RESERVE_ANIM_FRAME (15)


//攻撃の設定
#define PLAYER_ATTACK_LENGTH CVector3D(200,100,200)
#define PLAYER_ATTACK_POWER (1.0)

#define PLAYER_SIDE_ATTACK_LENGTH CVector3D(150,100,250)
#define PLAYER_SIDE_ATTACK_POWER (1.0)

#define PLAYER_FINISH_ATTACK_LENGTH CVector3D(150,500,200)
#define PLAYER_FINISH_ATTACK_POWER (1.0)

#define PLAYER_SPEAR_ATTACK_LENGTH CVector3D(250,500,200)
#define PLAYER_SPEAR_ATTACK_POWER (1.5)


#define PLAYER_AXE_ATTACK_LENGTH CVector3D(150,500,300)
#define PLAYER_AXE_ATTACK_POWER (2.0)


#define PLAYER_GUN_ATTACK_LENGTH CVector3D(1200,200,50)
#define PLAYER_GUN_ATTACK_POWER (3.0)





//着地硬直時間
//0 15
#define PLAYER_LANDING_ACTION_FRAME (10)

//着地アニメが自動解除される時間
#define PLAYER_LANDING_ANIM_FRAME (20)


#define MEMORY_HIT_ATTACKED_ENEMY_MAX (1000)

#define PLAYER_EVASION_FRAME (36)
#define PLAYER_EVASION_ANIM_DELAY (PLAYER_EVASION_FRAME / 4)




#define PLAYER_EVASION_MOVE_START_FRAME (PLAYER_EVASION_ANIM_DELAY * 2)
#define PLAYER_RECEIVE_INPUT_EVASION_TIME (10 + 5)
#define PLAYER_RECEIVE_INPUT__EVASION_TIME_AFTER_EVASION (30 + 20 + 10)
#define PLAYER_EVASION_MOVE_VEC (10.0f)

//#define PLAYER_EVASION_MOVE_END_FRAME (PLAYER_EVASION_ANIM_DELAY * 5)


#define PLAYER_AFTER_DAMAGE_INVINCIBLE (40)
#define PLAYER_KNOCK_BACK_FRAME (30.0)
#define PLAYER_DAMAGE_FRAME (30.0)

#define PLAYER_EVASION_RESERVE_FRAME (PLAYER_EVASION_ANIM_DELAY * 2)

//回避の移動部分が終わった後はモーションキャンセル可能とする。

#define PLAYER_DOWN_FRAME (60 * 2)

#define PLAYER_DOWN_ANIM_DELAY (14)
#define PLAYER_DOWN_ANIM_FRAME (PLAYER_DOWN_ANIM_DELAY*2)


#define WEAPON_USE_ENDURANCE_DAMAGE (2.0f)


#define KEEP_FINAL_ATTACK_TIMEOUT (54)

//着地モーションから回避に派生した場合冒頭モーションをカット可能にする。

/*
着地モーションはジャンプ以外ではキャンセル不可にする。
*/

enum {
	eEvasionFlipRight,
	eEvasionFlipLeft,
	eEvasionFlipUp,
	eEvasionFlipDown,
};

enum {
	ePlayerAnimIdIdle,
	ePlayerAnimIdMove,
	ePlayerAnimIdRun,
	ePlayerAnimIdJump,
	ePlayerAnimIdAttack,
	ePlayerAnimIdAttackReserve,
	ePlayerAnimIdLand,
	ePlayerAnimIdFall,
	ePlayerAnimIdDamage,
	ePlayerAnimIdEvasion,
	ePlayerAnimIdEvasionFast,//最初のしゃがむモーションをカットした省略版
	ePlayerAnimIdEvasionReserve,
	ePlayerAnimIdDown,
	ePlayerAnimIdDowned,
	ePlayerAnimIdSideAttack,
	ePlayerAnimIdFinishAttack,
	ePlayerAnimIdSideAttackReserve,
	ePlayerAnimIdFinishAttackKeepSlash,
	ePlayerAnimIdSpearAttack,
	ePlayerAnimIdSpearAttackReserve,
	ePlayerAnimIdAxeAttack,
	ePlayerAnimIdAxeAttackReserve,
	ePlayerAnimIdGunAttack,
	ePlayerAnimIdGunAttackReserve,
	ePlayerAnimIdMoveRight,
	ePlayerAnimIdMoveLeft,
	ePlayerAnimIdJumpRight,
	ePlayerAnimIdJumpLeft,
	ePlayerAnimIdLandRight,
	ePlayerAnimIdLandLeft,
	ePlayerAnimIdFallRight,
	ePlayerAnimIdFallLeft,
	ePlayerAnimIdIdleRight,
	ePlayerAnimIdIdleLeft,
	ePlayerAnimIdEvasionRight,
	ePlayerAnimIdEvasionFastRight,
	ePlayerAnimIdEvasionReserveRight,
	ePlayerAnimIdEvasionLeft,
	ePlayerAnimIdEvasionFastLeft,
	ePlayerAnimIdEvasionReserveLeft,
	ePlayerAnimIdVerticalAttack,
	ePlayerAnimIdVerticalAttackReserve,
	ePlayerAnimIdMax,
};


//このenumの使用頻度もだいぶ減った。無くしていったほうがすっきりしそうではある
enum {
	ePlayerAnimIdle0,
	ePlayerAnimIdle1,
	ePlayerAnimIdle2,
	ePlayerAnimIdle3,
	ePlayerAnimMove0,
	ePlayerAnimMove1,
	ePlayerAnimMove2,
	ePlayerAnimMove3,
	ePlayerAnimMove4,
	ePlayerAnimMove5,
	ePlayerAnimMove6,
	ePlayerAnimMove7,
	ePlayerAnimRun0,
	ePlayerAnimRun1,
	ePlayerAnimRun2,
	ePlayerAnimRun3,
	ePlayerAnimRun4,
	ePlayerAnimRun5,
	ePlayerAnimJump0,
	ePlayerAnimJump1,
	ePlayerAnimJump2,
	ePlayerAnimJump3,
	ePlayerAnimJump4,
	ePlayerAnimLand0,
	ePlayerAnimFall0,
	ePlayerAnimFall1,
	ePlayerAnimFall2,
	ePlayerAnimFall3,
	ePlayerAnimAttack0,
	ePlayerAnimAttack1,
	ePlayerAnimAttack2,
	ePlayerAnimIdAttackReserve0,
	ePlayerAnimIdAttackReserve1,
	ePlayerAnimDamage0,
	ePlayerAnimEvasion0,
	ePlayerAnimEvasion1,
	ePlayerAnimEvasion2,
	ePlayerAnimEvasion3,
	ePlayerAnimEvasion4,
	ePlayerAnimEvasion5,
	ePlayerAnimDown0,
	ePlayerAnimDown1,
	ePlayerAnimSideAttack0,
	ePlayerAnimSideAttack1,
	ePlayerAnimSideAttack2,
	ePlayerAnimSideAttack3,
	ePlayerAnimFinishAttack0,
	ePlayerAnimFinishAttack1,
	ePlayerAnimFinishAttack2,
	ePlayerAnimFinishAttack3,
	ePlayerAnimFinishAttack4,
	ePlayerAnimFinishAttack5,
	ePlayerAnimIdSideAttackReserve0,
	ePlayerAnimIdSideAttackReserve1,
	ePlayerAnimIdSideAttackReserve2,
	ePlayerAnimMax,
};




class CCharacterPlayer : public CCharacter {
private:
	
	CVector3D m_attack_length;
	double m_attack_power;
	int m_attack_total_frame;
	int m_attack_hit_frame_start;
	int m_attack_hit_frame_end;
	
	bool m_is_jumping = false;
	double m_jumping_count = 0.0;

	bool m_is_attacking = false;
	double m_attacking_count = 0.0;
	int m_attack_combo_count = 0;


	//攻撃中の武器の情報
	int m_attack_weapon_id = -1;

	//武器の情報
	int m_equip_weapon_id = -1;

	//武器耐久値
	float m_equip_endurance = 0.0f;

	//武器攻撃しているかのステート
	bool m_is_weapon_attacking = false;

	//遠距離攻撃か
	bool m_is_range_attack = false;
	
	//遠距離攻撃を既にいずれかの敵に当てているか(今の場合は一発につき1体の敵なので、貫通なし)
	bool m_is_hit_range_attack = false;

	bool m_is_dashing = false;

	bool m_is_damage = false;
	double m_damage_count = 0;

	bool m_is_landing_action_now = false;
	double m_landing_anim_count = 0;
	double m_landing_action_count = 0;

	//攻撃した敵を記憶しておくポインタ配列
	int m_memory_hit_attacked_enemy_num = 0;
	Task* m_memory_hit_attacked_enemy_p[MEMORY_HIT_ATTACKED_ENEMY_MAX];

	//ジャンプ攻撃中は何も行動ができないので、このときに敵にはさまると詰みになるので
	double m_keep_final_attack_timeout = 0;

	bool m_is_input_evasion_flip = 0;
	
	
	bool m_is_input_evasion = false;

	bool m_is_evasion = false;

	bool m_is_early_input_attack = false;

	double m_evasion_count = 0;
	double m_evasion_reserve_count = 0;
	bool m_is_fast_evasion = false;

	int m_evasion_dir_type = 0;
	int m_will_evasion_dir_type = 0;

	double m_receive_input_evasion_time_count_l = 0;
	double m_receive_input_evasion_time_count_r = 0;

	double m_receive_input_evasion_time_count_u = 0;
	double m_receive_input_evasion_time_count_d = 0;

	double m_after_damage_invincible_count = 0;

	double m_attack_reserve_count = 0;

	bool m_is_down = false;
	double m_down_count = 0;

	bool m_is_move = false;

	bool m_is_sended_miss = false;
	
	

	//ボスの特殊攻撃などによる硬直
	bool m_is_freeze = false;
	double m_freeze_count = 0.0;

	bool m_is_show_attack_effect = false;

public:
	CCharacterPlayer(CVector3D _pos);
	~CCharacterPlayer();
	void LoadAnimImage();


	void InputDestroyWeapon();
	void InputDash();
	void InputAttack();
	void InputMove();
	void InputJump();
	void InputEvasion();
	void BeginEvasion();


	void DoingEvasion();
	void DoingDown();
	void DoingDamage();



	void AfterDamageInvincible();
	void DoingLandingAction();
	void Landing();
	void ReserveAttacking();
	
	void Attacking();
	void AttackingHitFrame();

	void Jumping();
	void Falling();
	void Move();

	void CharacterOutHitPoint();

	
	void CharacterBeforeUpdate();
	void CharacterUpdate();
	void CharacterBeforeCollisionCheck();
	void CollisionCheckCharacter(Task* _collision_task);
	void CharacterDraw();

	

	//新たな入力をした場合、あらかじめ入力しておいたものを破棄する
	void ClearEarlyInput();


	void AdjAnim();

	void ReceiveAttack();
	void ReceiveKnockBack(CCharacter *_from, double _power);


	void CheckEquipEndurance();

	void PlayerGainEquip(int _equip_id, float _equip_endurance) {
		m_equip_weapon_id = _equip_id;
		m_equip_endurance = _equip_endurance;
	};


	void SetFreeze(int _count) {
		m_is_freeze = true;
		m_freeze_count = _count;
		m_is_attacking = false;
		m_is_evasion = false;
		m_is_jumping = false;
	};

	void Freezing();
	

	void PlayerDestroyEquip() {
		m_equip_weapon_id = -1;
		m_equip_endurance = 0.0f;
	}

	int GetPlayerEquipWeaponId() { return m_equip_weapon_id; };
	int* GetPlayerEquipWeaponIdPointer() { return &m_equip_weapon_id; };
	float* GetPlayerEquipWeaponEndurancePointer() { return &m_equip_endurance; };


	static CCharacterPlayer* GetInstance();


	//チュートリアル用フラグ用入手
	bool GetIsMoving() { return m_is_move; };
	bool GetIsEvasion() { return m_is_evasion; };
	bool GetIsJumping() { return m_is_jumping; };
	bool GetIsAttacking() { return m_is_attacking; };
	bool GetIsDashing() { return m_is_dashing; };
	bool GetIsWeaponAttacking() { return m_is_weapon_attacking; };

};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
2019/03/11 移動、ジャンプ等、スクロール機能等実装。 by shingai
～2019/03/17 色々な機能を実装 by shingai
攻撃は移動入力なしでコンボ攻撃（3種類の技を繰り出す)

横移動入力で攻撃1(X軸に判定が広い)
縦移動入力で攻撃2(Z軸に判定が広い)
空中にいる状態で入力で攻撃3(Y軸に判定が広く、着地まで攻撃判定がある)
を繰り出すことができる。（コンボをせずに同じ攻撃を連続することも可能)

*/
