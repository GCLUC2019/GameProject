#include "CCharacterPlayer.h"
#include "../Global.h"
#include "CGameScene.h"
#include "CAnimation.h"
#include "CSubWeapon.h"

#define PLAYER_SPEED (3.0f)

static CCharacterPlayer* s_instance_p = nullptr;

CCharacterPlayer::CCharacterPlayer(CVector3D _pos) :CCharacter(eTaskIdPlayer, 0)
{
	s_instance_p = this;
	
	m_knock_back_frame = PLAYER_KNOCK_BACK_FRAME;

	m_speed = PLAYER_SPEED;
	//m_anim_p->SetAnim(ePlayerAnimIdIdle);
	LoadAnimImage();

	SetSize(400, 400);
	SetIsShowShadow(true);
	SetShadowSize(CVector2D(100, 50));
	SetDrawAdjPos(CVector2D(-15, 20.0f));
	SetRads(75,200,10);


	//初期位置設定
	SetPos(_pos);
	SetPosOld(_pos);

	//体力の設定
	m_hit_point = 10.0f;
	m_hit_point_max = 10.0f;


	//当たり判定の優先度
	SetCollisionPriority(100);

	SetIsCalcScrollBaseObject(true);

	//テスト用
	//m_equip_weapon_id = eWeaponAxe;
	//m_equip_endurance = ENDURANCE_MAX;
}

CCharacterPlayer::~CCharacterPlayer()
{
	if (s_instance_p == this) {
		s_instance_p = nullptr;
	}
}

void CCharacterPlayer::LoadAnimImage()
{
	m_anim_p->ReadAnimDataFile("PlayerAnim/PLAYER_ANIM_DATA.anim");

	/*
	m_anim_p->SetAnimImage(ePlayerAnimIdle0, GET_RESOURCE("Player_Idle_Anim_0", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimIdle1, GET_RESOURCE("Player_Idle_Anim_1", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimIdle2, GET_RESOURCE("Player_Idle_Anim_2", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimIdle3, GET_RESOURCE("Player_Idle_Anim_3", CImage*));

	m_anim_p->SetAnimImage(ePlayerAnimMove0, GET_RESOURCE("Player_Move_Anim_0", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimMove1, GET_RESOURCE("Player_Move_Anim_1", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimMove2, GET_RESOURCE("Player_Move_Anim_2", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimMove3, GET_RESOURCE("Player_Move_Anim_3", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimMove4, GET_RESOURCE("Player_Move_Anim_4", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimMove5, GET_RESOURCE("Player_Move_Anim_5", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimMove6, GET_RESOURCE("Player_Move_Anim_6", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimMove7, GET_RESOURCE("Player_Move_Anim_7", CImage*));

	m_anim_p->SetAnimImage(ePlayerAnimRun0, GET_RESOURCE("Player_Run_Anim_0", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimRun1, GET_RESOURCE("Player_Run_Anim_1", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimRun2, GET_RESOURCE("Player_Run_Anim_2", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimRun3, GET_RESOURCE("Player_Run_Anim_3", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimRun4, GET_RESOURCE("Player_Run_Anim_4", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimRun5, GET_RESOURCE("Player_Run_Anim_5", CImage*));

	m_anim_p->SetAnimImage(ePlayerAnimJump0, GET_RESOURCE("Player_Jump_Anim_0", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimJump1, GET_RESOURCE("Player_Jump_Anim_1", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimJump2, GET_RESOURCE("Player_Jump_Anim_2", CImage*));


	m_anim_p->SetAnimImage(ePlayerAnimAttack0, GET_RESOURCE("Player_Attack_Anim_0", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimAttack1, GET_RESOURCE("Player_Attack_Anim_1", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimAttack2, GET_RESOURCE("Player_Attack_Anim_2", CImage*));
	
	m_anim_p->SetAnimImage(ePlayerAnimIdAttackReserve0, GET_RESOURCE("Player_Attack_Anim_1", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimIdAttackReserve1, GET_RESOURCE("Player_Attack_Anim_0", CImage*));


	m_anim_p->SetAnimImage(ePlayerAnimLand0, GET_RESOURCE("Player_Jump_Anim_4", CImage*));


	m_anim_p->SetAnimImage(ePlayerAnimFall0, GET_RESOURCE("Player_Jump_Anim_1", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimFall1, GET_RESOURCE("Player_Jump_Anim_2", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimFall2, GET_RESOURCE("Player_Jump_Anim_3", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimFall3, GET_RESOURCE("Player_Jump_Anim_4", CImage*));


	m_anim_p->SetAnimImage(ePlayerAnimDamage0, GET_RESOURCE("Player_Damage_Anim_0", CImage*));


	m_anim_p->SetAnimImage(ePlayerAnimEvasion0, GET_RESOURCE("Player_Evasion_Anim_0", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimEvasion1, GET_RESOURCE("Player_Evasion_Anim_1", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimEvasion2, GET_RESOURCE("Player_Evasion_Anim_2", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimEvasion3, GET_RESOURCE("Player_Evasion_Anim_3", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimEvasion4, GET_RESOURCE("Player_Evasion_Anim_4", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimEvasion5, GET_RESOURCE("Player_Evasion_Anim_5", CImage*));


	m_anim_p->SetAnimImage(ePlayerAnimDown0, GET_RESOURCE("Player_Down_Anim_0", CImage*));
	m_anim_p->SetAnimImage(ePlayerAnimDown1, GET_RESOURCE("Player_Down_Anim_1", CImage*));

	//アニメーションデータの設定
	int anim_delay_array[ANIMATION_DELAY_MAX];


	anim_delay_array[0] = PLAYER_ANIM_IDLE;
	anim_delay_array[1] = PLAYER_ANIM_IDLE;
	anim_delay_array[2] = PLAYER_ANIM_IDLE;
	anim_delay_array[3] = PLAYER_ANIM_IDLE;
	m_anim_p->SetAnimInfo(ePlayerAnimIdIdle, ePlayerAnimIdle0, 4, anim_delay_array);
	

	anim_delay_array[0] = DEFAULT_ANIM_DELAY;
	anim_delay_array[1] = DEFAULT_ANIM_DELAY;
	anim_delay_array[2] = DEFAULT_ANIM_DELAY;
	anim_delay_array[3] = DEFAULT_ANIM_DELAY;
	anim_delay_array[4] = DEFAULT_ANIM_DELAY;
	anim_delay_array[5] = DEFAULT_ANIM_DELAY;
	anim_delay_array[6] = DEFAULT_ANIM_DELAY;
	anim_delay_array[7] = DEFAULT_ANIM_DELAY;
	m_anim_p->SetAnimInfo(ePlayerAnimIdMove, ePlayerAnimMove0, 8, anim_delay_array);
	



	anim_delay_array[0] = PLAYER_ANIM_RUN_DELAY;
	anim_delay_array[1] = PLAYER_ANIM_RUN_DELAY;
	anim_delay_array[2] = PLAYER_ANIM_RUN_DELAY;
	anim_delay_array[3] = PLAYER_ANIM_RUN_DELAY;
	anim_delay_array[4] = PLAYER_ANIM_RUN_DELAY;
	anim_delay_array[5] = PLAYER_ANIM_RUN_DELAY;
	m_anim_p->SetAnimInfo(ePlayerAnimIdRun, ePlayerAnimRun0, 6, anim_delay_array);

	anim_delay_array[0] = 10;
	anim_delay_array[1] = 10;
	anim_delay_array[2] = 10;
	m_anim_p->SetAnimInfo(ePlayerAnimIdJump, ePlayerAnimJump0, 3, anim_delay_array);
	


	anim_delay_array[0] = 14;
	m_anim_p->SetAnimInfo(ePlayerAnimIdLand, ePlayerAnimLand0, 1, anim_delay_array);

	anim_delay_array[0] = 14;
	m_anim_p->SetAnimInfo(ePlayerAnimIdFall, ePlayerAnimFall1, 1, anim_delay_array);




	anim_delay_array[0] = PLAYER_ATTACK_ANIM_DELAY;
	anim_delay_array[1] = PLAYER_ATTACK_ANIM_DELAY;
	anim_delay_array[2] = PLAYER_ATTACK_ANIM_DELAY;
	m_anim_p->SetAnimInfo(ePlayerAnimIdAttack, ePlayerAnimAttack0, 3, anim_delay_array);


	anim_delay_array[0] = PLAYER_ATTACK_RESERVE_ANIM_DELAY;
	anim_delay_array[1] = PLAYER_ATTACK_RESERVE_ANIM_DELAY;
	m_anim_p->SetAnimInfo(ePlayerAnimIdAttackReserve, ePlayerAnimIdAttackReserve0, 2, anim_delay_array);

	anim_delay_array[0] = 14;
	m_anim_p->SetAnimInfo(ePlayerAnimIdDamage, ePlayerAnimDamage0, 1, anim_delay_array);


	anim_delay_array[0] = PLAYER_EVASION_ANIM_DELAY;
	anim_delay_array[1] = PLAYER_EVASION_ANIM_DELAY;
	m_anim_p->SetAnimInfo(ePlayerAnimIdEvasionFast, ePlayerAnimEvasion2, 2, anim_delay_array);
	

	anim_delay_array[0] = PLAYER_EVASION_ANIM_DELAY;
	anim_delay_array[1] = PLAYER_EVASION_ANIM_DELAY;
	anim_delay_array[2] = PLAYER_EVASION_ANIM_DELAY;
	anim_delay_array[3] = PLAYER_EVASION_ANIM_DELAY;
	anim_delay_array[4] = PLAYER_EVASION_ANIM_DELAY;
	anim_delay_array[5] = PLAYER_EVASION_ANIM_DELAY;
	m_anim_p->SetAnimInfo(ePlayerAnimIdEvasion, ePlayerAnimEvasion0, 6, anim_delay_array);

	anim_delay_array[0] = PLAYER_EVASION_ANIM_DELAY;
	anim_delay_array[1] = PLAYER_EVASION_ANIM_DELAY;
	m_anim_p->SetAnimInfo(ePlayerAnimIdEvasionReserve, ePlayerAnimEvasion4, 2, anim_delay_array);

	anim_delay_array[0] = 14;
	anim_delay_array[1] = 14;
	m_anim_p->SetAnimInfo(ePlayerAnimIdDown, ePlayerAnimDown0, 2, anim_delay_array);

	anim_delay_array[0] = PLAYER_DOWN_ANIM_DELAY;
	m_anim_p->SetAnimInfo(ePlayerAnimIdDowned, ePlayerAnimDown1, 1, anim_delay_array);
	*/
}

void CCharacterPlayer::InputDestroyWeapon()
{
	if (m_is_knock_back == true) return;
	if (m_is_freeze == true) return;
	if (CInput::GetState(0, CInput::ePush, CInput::eButton10) && m_equip_weapon_id != -1) {
		PlayerDestroyEquip();
	}
}

void CCharacterPlayer::InputDash()
{
	if (m_is_knock_back == true) return;
	if (m_is_landing_action_now == true) return;
	if (m_is_evasion == true) return;
	if (m_is_down == true) return;
	if (m_is_freeze == true) return;

	if (CInput::GetState(0, CInput::eHold, CInput::eButton3)) {
		m_is_dashing = true;
		m_speed = 7.0f;
	}
}

void CCharacterPlayer::InputAttack()
{
	

	if (CInput::GetState(0, CInput::ePush, CInput::eButton2) || m_is_early_input_attack == true) {
		ClearEarlyInput();
		m_is_early_input_attack = true;
		if (m_is_knock_back == true) return;
		if (m_is_landing_action_now == true) return;
		if (m_is_evasion == true) return;
		if (m_is_down == true) return;
		if (m_is_attacking == true) return;
		if (m_is_freeze == true) return;

		m_is_early_input_attack = false;
		m_is_range_attack = false;
		m_is_hit_range_attack = false;
		m_keep_final_attack_timeout = KEEP_FINAL_ATTACK_TIMEOUT;


		//攻撃した敵のデータを初期化
		for (int i = 0; i < MEMORY_HIT_ATTACKED_ENEMY_MAX; i++) {
			m_memory_hit_attacked_enemy_p[i] = nullptr;

		}
		m_memory_hit_attacked_enemy_num = 0;



		//DEBUG_PRINT("攻撃\n");
		ClearEarlyInput();
		m_is_attacking = true;
		if (m_attack_reserve_count > 0.0) m_attack_combo_count++;
		else m_attack_combo_count = 0;

		if (m_attack_combo_count > 2) m_attack_combo_count = 0;

		
		

		//もし移動キーを入力してるなら任意の攻撃を出す
		if (CInput::GetState(0, CInput::eHold, CInput::eLeft) || (CInput::GetState(0, CInput::eHold, CInput::eRight))) {
			m_attack_combo_count = 0;
			//printf("単発攻撃 (移動キー押しながらで任意の攻撃が出せる)\n");
		}
		if (CInput::GetState(0, CInput::eHold, CInput::eUp) || (CInput::GetState(0, CInput::eHold, CInput::eDown))) {
			m_attack_combo_count = 1;
			//printf("単発攻撃 (移動キー押しながらで任意の攻撃が出せる)\n");
		}

		//もし空中にいるならフィニッシュモーションにする(ジャンプ攻撃)
		if (m_is_landing == false) m_attack_combo_count = 2;

		//printf("m_attack_combo_count %d\n", m_attack_combo_count);



		//武器攻撃の場合の処理
		m_is_weapon_attacking = false;

		m_attack_weapon_id = m_equip_weapon_id;
		//もし地上にいて武器をもっているなら武器攻撃を行う
		if (m_is_landing == true) {
			switch (m_attack_weapon_id) {
			case eWeaponSpear:
				m_attack_hit_frame_start = PLAYER_SPEAR_ATTACK_HIT_FRAME_START;
				m_attack_hit_frame_end = PLAYER_SPEAR_ATTACK_HIT_FRAME_END;
				m_attacking_count = PLAYER_SPEAR_ATTACK_FRAME;
				m_attack_power = PLAYER_SPEAR_ATTACK_POWER;
				m_attack_length = PLAYER_SPEAR_ATTACK_LENGTH;
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdSpearAttack);
				m_is_weapon_attacking = true;
				m_equip_endurance -= WEAPON_USE_ENDURANCE_DAMAGE;
				break;
			case eWeaponAxe:
				m_attack_hit_frame_start = PLAYER_AXE_ATTACK_HIT_FRAME_START;
				m_attack_hit_frame_end = PLAYER_AXE_ATTACK_HIT_FRAME_END;
				m_attacking_count = PLAYER_AXE_ATTACK_FRAME;
				m_attack_power = PLAYER_AXE_ATTACK_POWER;
				m_attack_length = PLAYER_AXE_ATTACK_LENGTH;
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdAxeAttack);
				m_is_weapon_attacking = true;
				m_equip_endurance -= WEAPON_USE_ENDURANCE_DAMAGE;
				break;
			case eWeaponGun:
				m_attack_hit_frame_start = PLAYER_GUN_ATTACK_HIT_FRAME_START;
				m_attack_hit_frame_end = PLAYER_GUN_ATTACK_HIT_FRAME_END;
				m_attacking_count = PLAYER_GUN_ATTACK_FRAME;
				m_attack_power = PLAYER_GUN_ATTACK_POWER;
				m_attack_length = PLAYER_GUN_ATTACK_LENGTH;
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdGunAttack);
				m_is_weapon_attacking = true;
				m_is_range_attack = true;
				m_equip_endurance -= WEAPON_USE_ENDURANCE_DAMAGE;
				break;
			}

			
		}

		//武器攻撃しない場合
		if (m_is_weapon_attacking == false) {
			switch (m_attack_combo_count) {
			case 0:
				m_attack_hit_frame_start = PLAYER_ATTACK_HIT_FRAME_START;
				m_attack_hit_frame_end = PLAYER_ATTACK_HIT_FRAME_END;
				m_attacking_count = PLAYER_ATTACK_FRAME;
				m_attack_power = PLAYER_ATTACK_POWER;
				m_attack_length = PLAYER_ATTACK_LENGTH;
				break;
			case 1:
				m_attack_hit_frame_start = PLAYER_SIDE_ATTACK_HIT_FRAME_START;
				m_attack_hit_frame_end = PLAYER_SIDE_ATTACK_HIT_FRAME_END;
				m_attacking_count = PLAYER_SIDE_ATTACK_FRAME;
				m_attack_power = PLAYER_SIDE_ATTACK_POWER;
				m_attack_length = PLAYER_SIDE_ATTACK_LENGTH;
				break;
			case 2:
				m_attack_hit_frame_start = PLAYER_FINISH_ATTACK_HIT_FRAME_START;
				m_attack_hit_frame_end = PLAYER_FINISH_ATTACK_HIT_FRAME_END;
				m_attacking_count = PLAYER_FINISH_ATTACK_FRAME;
				m_attack_power = PLAYER_FINISH_ATTACK_POWER;
				m_attack_length = PLAYER_FINISH_ATTACK_LENGTH;
				//若干上に上昇する
				m_vec.y = -20.0f;
				break;
			}

			//アニメーションを再生
			switch (m_attack_combo_count) {
			case 0:
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdAttack);
				break;
			case 1:
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdSideAttack);
				break;
			case 2:
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdFinishAttack);
				break;
			}
		}

		
		if (m_is_range_attack == false) CSound::GetInstance()->GetSound("SE_Slash1")->Play();
		else if (m_is_range_attack == true) CSound::GetInstance()->GetSound("SE_Shot1")->Play();

		//合計フレーム記録
		m_attack_total_frame = m_attacking_count;
		
	}
}




void CCharacterPlayer::CharacterBeforeUpdate()
{

}

void CCharacterPlayer::CharacterUpdate()
{
	//DEBUG_PRINT("x %lf y %lf z %lf\n", m_pos.x, m_pos.y, m_pos.z);
	
	
	if (m_landing_anim_count > 0.0) m_landing_anim_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
	
	//if (m_damage_anim_count > 0.0) m_damage_anim_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;

	if (m_is_landing_action_now == true) m_anim_p->SetWillPlayAnim(ePlayerAnimIdLand);
	else if(m_anim_p->GetWillPlayAnim() == ePlayerAnimIdLand && m_landing_anim_count > 0)  m_anim_p->SetWillPlayAnim(ePlayerAnimIdLand);
	else if (m_evasion_reserve_count > 0.0) m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasionReserve);
	/*
	else if (m_anim_p->GetWillPlayAnim() == ePlayerAnimIdDamage && m_damage_anim_count > 0) {
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdDamage);
		//DEBUG_PRINT("ダメージモーション中 %d\n", m_damage_anim_count);
	}
	*/
	else m_anim_p->SetWillPlayAnim(ePlayerAnimIdIdle);


	/*
	if (m_is_in_screen == true) {
		//printf("スクリーンの中にいる\n");
	}
	*/

	ReserveAttacking();
	
	m_is_dashing = false;
	m_speed = PLAYER_SPEED;
	SetInvincible(false);
	
	if (m_is_knock_back == false) {
		m_vec.x = 0.0f;
		m_vec.z = 0.0f;
	}

	

	InputDestroyWeapon();
	InputAttack();
	InputDash();
	InputMove();
	InputJump();
	InputEvasion();


	//座標移動
	
	DoingDamage();
	DoingLandingAction();
	DoingDown();
	DoingEvasion();
	Landing();
	Jumping();
	Falling();
	Freezing();
	DoingKnockBack();

	//Gravity();
	
	//Move();
	//MoveLimit();
	
	
	AfterDamageInvincible();
	Attacking();


	CheckEquipEndurance();

	//CalcScroll();
	AdjAnim();
}

void CCharacterPlayer::CharacterBeforeCollisionCheck()
{

}

void CCharacterPlayer::InputMove()
{
	if (m_attack_reserve_count > 0.0) return;
	if (m_is_attacking == true) return;
	if (m_is_evasion == true) return;
	if (m_is_down == true) return;
	if (m_is_landing_action_now == true) return;
	if (m_is_freeze == true) return;
	
	bool is_move = false;
	if (CInput::GetState(0,CInput::eHold, CInput::eRight)) {
		ClearEarlyInput();
		m_is_flip = false;
		is_move = true;
		m_vec.x = 1 * m_speed;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		ClearEarlyInput();
		m_is_flip = true;
		is_move = true;
		m_vec.x = -1 * m_speed;
	} 

	if (CInput::GetState(0, CInput::eHold, CInput::eUp)) {
		ClearEarlyInput();
		is_move = true;
		m_vec.z = -1 * m_speed ;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
		ClearEarlyInput();
		is_move = true;
		m_vec.z = 1 * m_speed;
	}

	if (is_move == true) {
		if (m_is_dashing == true) m_anim_p->SetWillPlayAnim(ePlayerAnimIdRun);
		else m_anim_p->SetWillPlayAnim(ePlayerAnimIdMove);
	}

}

void CCharacterPlayer::InputJump()
{
	if (m_is_knock_back == true) return;
	if (m_attack_reserve_count > 0.0) return;
	if (m_is_attacking == true) return;
	if (m_is_evasion == true) return;
	if (m_is_down == true) return;
	if (m_is_freeze == true) return;

	if (CInput::GetState(0, CInput::ePush, CInput::eButton1) && m_is_jumping == false && m_is_landing == true) {
		ClearEarlyInput();
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdJump);
		m_is_jumping = true;
		m_jumping_count = 30;
		m_vec.y = -30.0f;
		m_is_landing = false;
		CSound::GetInstance()->GetSound("SE_Jump")->Play();
	}
}

void CCharacterPlayer::AfterDamageInvincible()
{
	if (m_after_damage_invincible_count > 0) {


		m_after_damage_invincible_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
		if (m_after_damage_invincible_count <= 0) {
			SetInvincible(false);
			SetIsBlindDraw(false);

		}
		else {
			SetInvincible(true);
		}
		
		
	}
}

void CCharacterPlayer::DoingLandingAction()
{
	if (m_is_landing_action_now == true) {
		if (m_landing_action_count <= 0.0) {
			m_is_landing_action_now = false;
		}
		else {
			m_landing_action_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
		}
	}
}


void CCharacterPlayer::Landing()
{
	if (m_is_knock_back == true) return;

	if (m_is_landing == true & m_is_landing_old == false) {
		//DEBUG_PRINT("着地\n");
		if(m_anim_p->GetWillPlayAnim() ==  ePlayerAnimIdIdle) m_anim_p->SetWillPlayAnim(ePlayerAnimIdLand);
		m_landing_action_count = PLAYER_LANDING_ACTION_FRAME;
		m_landing_anim_count = PLAYER_LANDING_ANIM_FRAME;
		m_is_landing_action_now = true;
		//printf("着地\n");

		CSound::GetInstance()->GetSound("SE_Landing")->Play();
		//もし硬直時間が0ならfalseに
		if (m_landing_action_count == 0.0) m_is_landing_action_now = false;
	}
}

void CCharacterPlayer::ReserveAttacking()
{
	if (m_attack_reserve_count > 0.0) {
		m_attack_reserve_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
		//予備動作を再生
		switch (m_attack_combo_count) {
		case 0:
			m_anim_p->SetWillPlayAnim(ePlayerAnimIdAttackReserve);
			break;
		case 1:
			m_anim_p->SetWillPlayAnim(ePlayerAnimIdSideAttackReserve);
			break;
		case 2:
			m_anim_p->SetWillPlayAnim(ePlayerAnimIdAttackReserve);
			break;
		}

		//武器の場合の予備動作
		if (m_is_weapon_attacking == true) {
			switch (m_attack_weapon_id) {
			case eWeaponSpear:
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdSpearAttackReserve);
				break;
			case eWeaponAxe:
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdAxeAttackReserve);
				break;
			case eWeaponGun:
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdGunAttackReserve);
				break;
			}
		}
	}
}



void CCharacterPlayer::InputEvasion()
{
	if (m_is_freeze == true) return;

	int receive_input_time = PLAYER_RECEIVE_INPUT_EVASION_TIME;
	
	if(m_evasion_reserve_count > 0 || m_is_evasion == true) receive_input_time = PLAYER_RECEIVE_INPUT__EVASION_TIME_AFTER_EVASION;

	//DEBUG_PRINT("receive_input %d\n", receive_input_time);

	if (m_receive_input_evasion_time_count_r > 0) m_receive_input_evasion_time_count_r -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
	if (m_receive_input_evasion_time_count_l > 0) m_receive_input_evasion_time_count_l -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
	if (m_receive_input_evasion_time_count_u > 0) m_receive_input_evasion_time_count_u -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
	if (m_receive_input_evasion_time_count_d > 0) m_receive_input_evasion_time_count_d -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;

	if (CInput::GetState(0, CInput::ePush, CInput::eUp) && m_receive_input_evasion_time_count_u <= 0) {
		m_receive_input_evasion_time_count_r = 0;
		m_receive_input_evasion_time_count_l = 0;
		m_receive_input_evasion_time_count_d = 0;
		m_receive_input_evasion_time_count_u = receive_input_time;
	}
	else if (CInput::GetState(0, CInput::ePush, CInput::eUp) && m_receive_input_evasion_time_count_u > 0) {
		m_will_evasion_dir_type = eEvasionFlipUp;
		BeginEvasion();
	}

	if (CInput::GetState(0, CInput::ePush, CInput::eDown) && m_receive_input_evasion_time_count_d <= 0) {
		m_receive_input_evasion_time_count_r = 0;
		m_receive_input_evasion_time_count_l = 0;
		m_receive_input_evasion_time_count_u = 0;
		m_receive_input_evasion_time_count_d = receive_input_time;
	}
	else if (CInput::GetState(0, CInput::ePush, CInput::eDown) && m_receive_input_evasion_time_count_d > 0) {
		m_will_evasion_dir_type = eEvasionFlipDown;
		BeginEvasion();
	}



	if (CInput::GetState(0, CInput::ePush, CInput::eRight) && m_receive_input_evasion_time_count_r <= 0) {
		m_receive_input_evasion_time_count_u = 0;
		m_receive_input_evasion_time_count_d = 0;
		m_receive_input_evasion_time_count_l = 0;
		m_receive_input_evasion_time_count_r = receive_input_time;
	}
	else if (CInput::GetState(0, CInput::ePush, CInput::eRight) && m_receive_input_evasion_time_count_r > 0) {
		m_is_input_evasion_flip = false;
		m_will_evasion_dir_type = eEvasionFlipRight;
		BeginEvasion();
	}



	if (CInput::GetState(0, CInput::ePush, CInput::eLeft) && m_receive_input_evasion_time_count_l <= 0) {
		m_receive_input_evasion_time_count_u = 0;
		m_receive_input_evasion_time_count_d = 0;
		m_receive_input_evasion_time_count_r = 0;
		m_receive_input_evasion_time_count_l = receive_input_time;
	}
	else if (CInput::GetState(0, CInput::ePush, CInput::eLeft) && m_receive_input_evasion_time_count_l > 0) {
		m_is_input_evasion_flip = true;
		m_will_evasion_dir_type = eEvasionFlipLeft;
		BeginEvasion();
	}


	//DEBUG_PRINT("m_is_input_evasion %d\n", m_is_input_evasion);
	if (m_is_input_evasion == true) {
		BeginEvasion();
	}


}

void CCharacterPlayer::BeginEvasion()
{
	ClearEarlyInput();
	m_is_input_evasion = true;

	if (m_is_knock_back == true) return;

	if (m_attack_reserve_count > 0.0) return;

	if (m_is_down == true) return;

	//回避中かつ予備動作中でないならなにもしない
	if (m_is_evasion == true && m_evasion_reserve_count <= 0) return;

	//回避予備動作中だが入力した方角が違う場合なにもしない
	if (m_is_evasion == true && m_evasion_reserve_count > 0 && m_is_flip != m_is_input_evasion_flip) return;

	if (m_is_freeze == true) return;

	//空中にいるなら回避しない
	if (m_is_landing == false) return;
	//攻撃をやめる
	m_is_attacking = false;
	//m_is_jumping = false;


	//DEBUG_PRINT("回避開始\n");
	m_evasion_dir_type = m_will_evasion_dir_type;
	m_receive_input_evasion_time_count_l = 0;
	m_receive_input_evasion_time_count_r = 0;
	m_receive_input_evasion_time_count_u = 0;
	m_receive_input_evasion_time_count_d = 0;
	m_is_evasion = true;
	m_evasion_count = PLAYER_EVASION_FRAME;
	m_is_input_evasion = false;
	m_evasion_reserve_count = 0;
	m_is_landing_action_now = false;


	
	if(m_evasion_dir_type == eEvasionFlipLeft || m_evasion_dir_type == eEvasionFlipRight) m_is_flip = m_is_input_evasion_flip;
	



	//もし着地モーションから派生した場合冒頭モーションの短縮を行う
	if (m_anim_p->GetWillPlayAnim() == ePlayerAnimIdLand) {
		m_is_fast_evasion = true;
		m_evasion_count = PLAYER_EVASION_FRAME - (PLAYER_EVASION_ANIM_DELAY * 2);
	}

	//DEBUG_PRINT("m_is_input_evasion false\n");


	//アニメーションを設定
	if (m_is_fast_evasion == true) m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasionFast);
	else m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasion);

	//無敵判定
	SetInvincible(true);
}


void CCharacterPlayer::DoingEvasion()
{
	if (m_is_evasion == false) return;


	//予備動作が終わると完了する(回避予備動作は回避行動ならキャンセルできる)

	if (m_evasion_count > 0.0) {
		m_evasion_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
	}

	if (m_evasion_reserve_count > 0.0) {
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasionReserve);
		m_evasion_reserve_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;

		//無敵判定
		SetInvincible(true);

		//printf("m_evasion_reserve_count %lf\n", CFPS::GetDeltaTime() * GAME_BASE_FPS);
		if (m_evasion_reserve_count <= 0) {
			m_evasion_reserve_count = 0;
			m_is_evasion = false;
			//SetInvincible(false);
			//printf("回避予備動作終了\n");
		}
	}
	else if (m_evasion_count <= 0.0) {
		m_is_fast_evasion = false;
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasionReserve);
		m_evasion_reserve_count = PLAYER_EVASION_RESERVE_FRAME;
		//printf("回避予備動作開始\n");
	}
	else {
		
		//移動開始フレームになったら移動する
		//if (m_evasion_count <= PLAYER_EVASION_FRAME - PLAYER_EVASION_MOVE_START_FRAME && m_evasion_count > PLAYER_EVASION_FRAME - PLAYER_EVASION_MOVE_END_FRAME) {
		if (m_evasion_count <= PLAYER_EVASION_FRAME - PLAYER_EVASION_MOVE_START_FRAME) {
			const double moving_vec = PLAYER_EVASION_MOVE_VEC;
			//向きに応じて移動

			switch (m_evasion_dir_type) {
			case eEvasionFlipRight:
				m_vec.x = moving_vec;
				break;
			case eEvasionFlipLeft:
				m_vec.x = -moving_vec;
				break;
			case eEvasionFlipUp:
				m_vec.z = -moving_vec / 2.0;
				break;
			case eEvasionFlipDown:
				m_vec.z = moving_vec / 2.0;
				break;
			}
		}

		//DEBUG_PRINT("回避 %d\n", m_evasion_count);
		
		//無敵判定
		SetInvincible(true);

		if(m_is_fast_evasion == true) m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasionFast);
		else m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasion);
	}

	
	
}

void CCharacterPlayer::DoingDown()
{
	if (m_is_down == false) return;
	

	m_down_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
	
	if(m_down_count >= PLAYER_DOWN_FRAME -PLAYER_DOWN_ANIM_FRAME) m_anim_p->SetWillPlayAnim(ePlayerAnimIdDown);
	else m_anim_p->SetWillPlayAnim(ePlayerAnimIdDowned);


	if (m_down_count <= 0.0 && m_is_sended_miss == false) {
		//m_is_down  = false;
		m_is_sended_miss = true;
		CGameScene::GetInstance()->Miss();

	}
}

void CCharacterPlayer::DoingDamage()
{
	if (m_is_damage == false) return;
	m_damage_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
	m_anim_p->SetWillPlayAnim(ePlayerAnimIdDamage);
	if (m_damage_count <= 0.0) {
		m_is_damage = false;
	}
}




void CCharacterPlayer::Attacking()
{
	if (m_is_attacking == false) return;
	m_attacking_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;



	bool is_keep_finish_attack = false;
	//空中にいてなおかつフィニッシュ攻撃なら着地するまでは攻撃判定を継続させる
	if (m_is_landing == false && m_attack_combo_count == 2) {
		m_keep_final_attack_timeout -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
		printf("time_out %lf\n", m_keep_final_attack_timeout);
		
		if (m_keep_final_attack_timeout <= 0.0) {
			SetPos(CGameScene::GetInstance()->GetCheckPoint() - CVector3D(0,50,0));
			m_is_attacking = false;
		}

		is_keep_finish_attack = true;
	}

	if (m_attacking_count < 0 && is_keep_finish_attack == false) {

		for (int i = 0; i < m_memory_hit_attacked_enemy_num; i++) {
			m_memory_hit_attacked_enemy_p[i] = nullptr;
		}
		m_memory_hit_attacked_enemy_num = 0;
		
		m_is_attacking = false;

		m_attack_reserve_count = PLAYER_ATTACK_RESERVE_ANIM_FRAME;
		switch (m_attack_combo_count) {
		case 0:
			m_anim_p->SetWillPlayAnim(ePlayerAnimIdAttackReserve);
			break;
		case 1:
			m_anim_p->SetWillPlayAnim(ePlayerAnimIdSideAttackReserve);
			break;
		case 2:
			m_anim_p->SetWillPlayAnim(ePlayerAnimIdAttackReserve);
			break;
		}

		if (m_is_weapon_attacking == true) {
			switch (m_attack_weapon_id) {
			case eWeaponSpear:
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdSpearAttackReserve);
				break;
			case eWeaponAxe:
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdAxeAttackReserve);
				break;
			case eWeaponGun:
				m_anim_p->SetWillPlayAnim(ePlayerAnimIdGunAttackReserve);
				break;
			}
		}
		return;
	}

	//攻撃判定が出現するフレームの場合の処理
	if (m_attacking_count <= m_attack_total_frame - m_attack_hit_frame_start && m_attacking_count > m_attack_total_frame - m_attack_hit_frame_end
		|| is_keep_finish_attack == true && m_attacking_count <= m_attack_total_frame - m_attack_hit_frame_start) {
		AttackingHitFrame();
	}
	
	
		


	switch (m_attack_combo_count) {
	case 0:
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdAttack);
		break;
	case 1:
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdSideAttack);
		break;
	case 2:
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdFinishAttack);
		break;
	}



	if (m_is_weapon_attacking == true) {
		switch (m_attack_weapon_id) {
		case eWeaponSpear:
			m_anim_p->SetWillPlayAnim(ePlayerAnimIdSpearAttack);
			break;
		case eWeaponAxe:
			m_anim_p->SetWillPlayAnim(ePlayerAnimIdAxeAttack);
			break;
		case eWeaponGun:
			m_anim_p->SetWillPlayAnim(ePlayerAnimIdGunAttack);
			break;
		}
	}

}


//攻撃判定が発生するフレームの場合呼ばれる
void CCharacterPlayer::AttackingHitFrame()
{
	//ローカル変数定義
	register const CVector3D& player_pos = GetPos();//プレイヤーの位置

	register CVector3D length;//距離ベクトル(位置の差)を計算
	register CVector3D length_abs;//絶対距離
	register const CVector3D& attack_length = m_attack_length; //攻撃範囲

															   //生成されている全てのエネミーのポインタを取得
	register Task** enemy_array = TaskManager::GetInstance()->FindTaskArray(eTaskIdEnemy);

	if (enemy_array != nullptr) {

		register CCharacter* range_attack_enemy_p = nullptr;
		register double range_target_enemy_length;

		//カウンタ
		register int i = 0;

		//敵のポインタ取得用
		CCharacter* enemy_p = nullptr;

		while (true) {
			//printf("攻撃用ループ\n");
			if (enemy_array[i] == nullptr) {
				break;
			}

			enemy_p = dynamic_cast<CCharacter*>(enemy_array[i]);
			if (enemy_p == nullptr) {
				i++;
				continue;
			}

			//位置関係を取得

			//敵のポジションを取得
			register const CVector3D& enemy_pos = enemy_p->GetPos();//敵の位置



																	//距離ベクトル(位置の差)を計算
			length = enemy_pos - player_pos;

			//絶対距離を計算
			length_abs.x = abs(length.x);
			length_abs.y = abs(length.y);
			length_abs.z = abs(length.z);

			//敵が左側にいて自分が左向き
			//もしくは敵が右側にいて、自分が右向きなら
			if (length.x <= 0.0f && m_is_flip == true
				|| length.x >= 0.0f && m_is_flip == false) {
				//DEBUG_PRINT("length.x %lf length.y %lf length.z %lf \n", length.x, length.y, length.z);



				//printf("attack.x %lf attack.y %lf attack.z %lf\n", attack_length.x, attack_length.y, attack_length.z);
				//攻撃範囲内に敵がいるなら
				if (length_abs.x <= attack_length.x&& length_abs.y <= attack_length.y&&length_abs.z <= attack_length.z) {


					register bool is_aready_hit = false;
					//当たっているので攻撃判定が既にされているオブジェクトかどうかチェック
					for (int i = 0; i < m_memory_hit_attacked_enemy_num; i++) {
						if (m_memory_hit_attacked_enemy_p[i] == enemy_p) {
							is_aready_hit = true;
							break;
						}
					}


					//まだ攻撃を当たった扱いになってないなら攻撃判定を行う
					if (is_aready_hit == false && m_is_range_attack == false) {
						//ヒットストップ
						SetStop(5);
						enemy_p->SetStop(5);

						//ノックバックを与える
						enemy_p->ReceiveKnockBack(this, 5.0);
						*enemy_p->GetHitPointPointer() -= m_attack_power;
						enemy_p->ReceiveAttack();
						m_memory_hit_attacked_enemy_p[m_memory_hit_attacked_enemy_num++] = enemy_p;
					}
					else if (is_aready_hit == false && m_is_range_attack == true) {

						double length_enemy = length_abs.x + length_abs.y + length_abs.z;
						if (range_attack_enemy_p == nullptr) {
							range_attack_enemy_p = enemy_p;
							range_target_enemy_length = length_enemy;
						}
						else if (range_attack_enemy_p != nullptr && range_target_enemy_length > length_enemy) {
							range_attack_enemy_p = enemy_p;
							range_target_enemy_length = length_enemy;
						}
					}
				}
			}

			//インクリメント
			i++;
		}

		//ループ終了後(ブロックがわかりにくいのでリファクタリングの余地あり)
		if (m_is_range_attack == true && m_is_hit_range_attack == false) {
			if (range_attack_enemy_p != nullptr) {
				range_attack_enemy_p->ReceiveAttack();
				*range_attack_enemy_p->GetHitPointPointer() -= m_attack_power;
				m_memory_hit_attacked_enemy_p[m_memory_hit_attacked_enemy_num++] = range_attack_enemy_p;
				m_is_hit_range_attack = true;
			}
		}

		free(enemy_array);
	}
	
}

void CCharacterPlayer::Jumping()
{
	
	//ジャンプで使われるのは上昇時のアニメーションくらいか。

	if (m_is_jumping == true) {
		if (m_is_landing == true || m_jumping_count <= 0) {
			m_is_jumping = false;
		}
		else {
			m_jumping_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
		}

		m_anim_p->SetWillPlayAnim(ePlayerAnimIdJump);
	}

	
	
}

void CCharacterPlayer::Falling()
{
	if (m_is_landing == false && m_is_jumping == false && m_is_damage == false) {
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdFall);
	}
}

void CCharacterPlayer::Move()
{
	//MovePos();
	//m_pos_old = m_pos; //親クラスで行ってるので必要なくなったはず 動きは変わらないはずだが……
	//m_pos += m_vec;
	//移動機能は、親クラスで移動は定義された
}

void CCharacterPlayer::CharacterOutHitPoint()
{
	if (m_is_down == true) return;
	m_after_damage_invincible_count = 0;
	SetIsBlindDraw(false);
	m_is_down = true;
	m_down_count = PLAYER_DOWN_FRAME;
	m_anim_p->SetWillPlayAnim(ePlayerAnimIdDown);
	CSound::GetInstance()->GetSound("SE_Down")->Play();
}

void CCharacterPlayer::CharacterDraw()
{
	
	
}

void CCharacterPlayer::CollisionCheckCharacter(Task * _collision_task)
{

}

void CCharacterPlayer::ClearEarlyInput()
{
	m_is_input_evasion = false;
	m_is_early_input_attack = false;
}

void CCharacterPlayer::AdjAnim()
{
	switch (m_anim_p->GetWillPlayAnim()) {
	case ePlayerAnimIdEvasion:
	case ePlayerAnimIdEvasionFast:
	case ePlayerAnimIdEvasionReserve:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(20.0f, 50.0f));
		SetShadowPosAdj(CVector2D(0, 0));
		SetShadowSize(CVector2D(100, 50));
		break;
	case ePlayerAnimIdRun:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(-30.0f, 10.0f));
		SetShadowPosAdj(CVector2D(-30,0));
		SetShadowSize(CVector2D(100, 50));
		break;
	case ePlayerAnimIdAttackReserve:
	case ePlayerAnimIdAttack:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(-30.0f, 10.0f));
		SetShadowPosAdj(CVector2D(-65.0f, 0));
		SetShadowSize(CVector2D(150, 50));
		break;
	case ePlayerAnimIdSideAttackReserve:
	case ePlayerAnimIdSideAttack:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(-30.0f, 10.0f));
		SetShadowPosAdj(CVector2D(-25.0f, 0));
		SetShadowSize(CVector2D(170, 50));
		break;
	case ePlayerAnimIdFinishAttack:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(-30.0f, 10.0f));
		SetShadowPosAdj(CVector2D(-30.0f, 0));
		SetShadowSize(CVector2D(100, 50));
		break;
	case ePlayerAnimIdSpearAttack:
	case ePlayerAnimIdSpearAttackReserve:
		SetSize(500, 400);
		SetDrawAdjPos(CVector2D(75.0f, 10.0f));
		SetShadowPosAdj(CVector2D(-25.0f, 0));
		SetShadowSize(CVector2D(170, 50));
		break;
	case ePlayerAnimIdAxeAttack:
	case ePlayerAnimIdAxeAttackReserve:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(5.0f, 10.0f));
		SetShadowPosAdj(CVector2D(-25.0f, 0));
		SetShadowSize(CVector2D(170, 50));
		break;
	case ePlayerAnimIdGunAttack:
	case ePlayerAnimIdGunAttackReserve:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(5.0f, 10.0f));
		SetShadowPosAdj(CVector2D(-25.0f, 0));
		SetShadowSize(CVector2D(170, 50));
		break;
	case ePlayerAnimIdDown:
	case ePlayerAnimIdDowned:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(-30.0f, 10.0f + 50.0f));
		SetShadowPosAdj(CVector2D(0, -50 + 50.0f));
		SetShadowSize(CVector2D(300, 50));
		break;
	default:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(-30.0f, 10.0f));
		SetShadowPosAdj(CVector2D(0, 0));
		SetShadowSize(CVector2D(100, 50));
		break;
	}
}

/*
void CCharacterPlayer::CalcScroll()
{
	//画面上の座標

	const CVector2D& scroll_pos = GetScroll();
	CVector2D calc_scroll_pos = scroll_pos;

	register const float offset_x = - 120.0f;
	register const float offset_y = -200.0f;

	//スクロール限界値を設定
	register const double max_x = CGameScene::GetInstance()->GetGameSceneLimitPosMax().x - 1280.0f;

	//キャラ描画位置
	register double draw_pos_y = m_pos.y + m_pos.z;


	if (m_pos.x >= scroll_pos.x + 1280.0f + offset_x) {
		calc_scroll_pos.x = m_pos.x - 1280.0f - offset_x;
	}

	else if (m_pos.x <= scroll_pos.x - offset_x) {
		calc_scroll_pos.x = m_pos.x + offset_x;
	}
	
	
	if (calc_scroll_pos.x >= CGameScene::GetInstance()->GetGameSceneLimitPosMax().x  + offset_x) {
		calc_scroll_pos.x = CGameScene::GetInstance()->GetGameSceneLimitPosMax().x - offset_x;
	}

	
	if (calc_scroll_pos.x > max_x) calc_scroll_pos.x = max_x;

	if (draw_pos_y <= scroll_pos.y - offset_y) {
		calc_scroll_pos.y = draw_pos_y + offset_y;
	}
	else if (scroll_pos.y < 0) {
		calc_scroll_pos.y = draw_pos_y + offset_y;
	}

	if (calc_scroll_pos.y > 0.0f) calc_scroll_pos.y = 0.0f;

	SetScroll(calc_scroll_pos);

}
*/

void CCharacterPlayer::ReceiveAttack()
{
	//ダウンしているなら何もしない
	if (m_is_down == true) return;
	//無敵ならなにもしない
	if (GetInvincible() == true) return;

	m_anim_p->SetWillPlayAnim(ePlayerAnimIdDamage);
	m_is_damage = true;
	m_damage_count = PLAYER_DAMAGE_FRAME;
	
	
	//無敵時間点灯
	SetIsBlindDraw(true);
	m_after_damage_invincible_count = PLAYER_AFTER_DAMAGE_INVINCIBLE;
	CSound::GetInstance()->GetSound("SE_Damage")->Play();
}

void CCharacterPlayer::ReceiveKnockBack(CCharacter * _from, double _power)
{
	if (m_is_knock_back == true) return;
	if (m_is_invincible == true) return;
	if (m_is_down == true) return;

	SetKnockBack(_from,_power);

	//動作中断
	m_is_evasion = false;
	m_is_attacking = false;
	m_is_jumping = false;

	//Y軸の値は利用されない点に注意
}

void CCharacterPlayer::CheckEquipEndurance()
{
	if (m_equip_weapon_id == -1) return;
	//printf("m_equip_endurance %lf\n", m_equip_endurance);
	if (m_equip_endurance <= 0.0) {
		PlayerDestroyEquip();
	}
}

void CCharacterPlayer::Freezing()
{
	if (m_is_freeze == false) return;
	m_freeze_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if (m_freeze_count <= 0) {
		m_is_freeze = false;
	}
	m_anim_p->SetWillPlayAnim(ePlayerAnimIdDown);
}

CCharacterPlayer * CCharacterPlayer::GetInstance()
{
	return s_instance_p;
}
