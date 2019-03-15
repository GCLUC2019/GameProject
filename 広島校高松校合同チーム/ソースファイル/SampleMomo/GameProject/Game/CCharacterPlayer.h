#pragma once
#include "CCharacter.h"

/*
ジャンプ後の着地時に硬直追加
回避行動を着地直後のうまいタイミングで行えば硬直をキャンセルできるので
上手くやれば隙は生じにくいはず
*/

#define PLAYER_ATTACK_FRAME (30)

#define PLAYER_ATTACK_ANIM_DELAY (PLAYER_ATTACK_FRAME / 3)



//攻撃判定が発生するフレーム
#define PLAYER_ATTACK_HIT_FRAME_START (PLAYER_ATTACK_ANIM_DELAY * 1)
//攻撃判定が終了するフレーム
#define PLAYER_ATTACK_HIT_FRAME_END (PLAYER_ATTACK_ANIM_DELAY * 3)


//予備動作のディレイ
#define PLAYER_ATTACK_RESERVE_ANIM_DELAY (PLAYER_ATTACK_ANIM_DELAY * 2)
//予備動作のフレーム
#define PLAYER_ATTACK_RESERVE_ANIM_FRAME (PLAYER_ATTACK_RESERVE_ANIM_DELAY * 2)

#define PLAYER_ATTACK_LENGTH CVector3D(300,50,75)

#define PLAYER_ATTACK_POWER (1.0f)



#define PLAYER_DAMAGE_ANIM_FRAME (20)


//着地硬直時間
//0 15
#define PLAYER_LANDING_ACTION_FRAME (10)

//着地アニメが自動解除される時間
#define PLAYER_LANDING_ANIM_FRAME (20)


#define MEMORY_HIT_ATTACKED_ENEMY_MAX (1000)

#define PLAYER_EVASION_FRAME (36)
#define PLAYER_EVASION_ANIM_DELAY (PLAYER_EVASION_FRAME / 4)
#define PLAYER_AFTER_DAMAGE_INVINCIBLE (60)
#define PLAYER_EVASION_MOVE_START_FRAME (PLAYER_EVASION_ANIM_DELAY * 2)
#define PLAYER_RECEIVE_INPUT_EVASION_TIME (10)
#define PLAYER_RECEIVE_INPUT__EVASION_TIME_AFTER_EVASION (30 + 20)

//#define PLAYER_EVASION_MOVE_END_FRAME (PLAYER_EVASION_ANIM_DELAY * 5)


#define PLAYER_EVASION_RESERVE_FRAME (PLAYER_EVASION_ANIM_DELAY * 2)

//回避の移動部分が終わった後はモーションキャンセル可能とする。

#define PLAYER_DOWN_FRAME (60 * 5)

#define PLAYER_DOWN_ANIM_DELAY (14)
#define PLAYER_DOWN_ANIM_FRAME (PLAYER_DOWN_ANIM_DELAY*2)


//着地モーションから回避に派生した場合冒頭モーションをカット可能にする。

/*
着地モーションはジャンプ以外ではキャンセル不可にする。
*/


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
	ePlayerAnimIdMax,
};

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
	ePlayerAnimMax,
};




class CCharacterPlayer : public CCharacter {
private:
	
	
	bool m_is_jumping = false;
	int m_jumping_count = 0;

	bool m_is_attacking = false;
	int m_attacking_count = 0;
	
	bool m_is_dashing = false;

	int m_damage_anim_count = 0;

	bool m_is_landing_action_now = false;
	int m_landing_anim_count = 0;
	int m_landing_action_count = 0;

	//攻撃した敵を記憶しておくポインタ配列
	int m_memory_hit_attacked_enemy_num = 0;
	Task* m_memory_hit_attacked_enemy_p[MEMORY_HIT_ATTACKED_ENEMY_MAX];


	bool m_is_input_evasion_flip = false;
	bool m_is_input_evasion = false;
	bool m_is_evasion = false;
	int m_evasion_count = 0;
	int m_evasion_reserve_count = 0;
	bool m_is_fast_evasion = false;


	int m_receive_input_evasion_time_count_l = 0;
	int m_receive_input_evasion_time_count_r = 0;

	int m_after_damage_invincible_count = 0;

	int m_attack_reserve_count = 0;

	bool m_is_down = false;
	int m_down_count = 0;

public:
	CCharacterPlayer();
	~CCharacterPlayer();
	void LoadAnimImage();

	void InputDash();
	void InputAttack();
	void InputMove();
	void InputJump();
	void InputEvasion();
	void BeginEvasion();

	void DoingEvasion();
	void DoingDown();

	void AfterDamageInvincible();
	void DoingLandingAction();
	void Landing();
	void Attacking();
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
	//void CalcScroll();

	void ReceiveAttack();
};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
2019/03/11 移動、ジャンプ等、スクロール機能等実装。
*/
