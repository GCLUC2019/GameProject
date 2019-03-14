#include "CCharacterPlayer.h"
#include "../Global.h"
#include "CGameScene.h"

#define PLAYER_SPEED (3.0f)

CCharacterPlayer::CCharacterPlayer() :CCharacter(eTaskIdPlayer, 0)
{
	m_speed = PLAYER_SPEED;
	SetAnim(ePlayerAnimIdIdle);
	LoadAnimImage();

	SetSize(400, 400);
	SetIsShowShadow(true);
	SetShadowSize(CVector2D(100, 50));
	SetDrawAdjPos(CVector2D(-15, 20.0f));
	SetRads(75,200,10);


	//体力の設定
	m_hit_point = 5.0f;
	m_hit_point_max = 10.0f;
}

CCharacterPlayer::~CCharacterPlayer()
{
}

void CCharacterPlayer::LoadAnimImage()
{
	
	m_anim_image_p[ePlayerAnimIdle0] = GET_RESOURCE("Player_Idle_Anim_0", CImage*);
	m_anim_image_p[ePlayerAnimIdle1] = GET_RESOURCE("Player_Idle_Anim_1", CImage*);
	m_anim_image_p[ePlayerAnimIdle2] = GET_RESOURCE("Player_Idle_Anim_2", CImage*);
	m_anim_image_p[ePlayerAnimIdle3] = GET_RESOURCE("Player_Idle_Anim_3", CImage*);


	m_anim_image_p[ePlayerAnimMove0] = GET_RESOURCE("Player_Move_Anim_0", CImage*);
	m_anim_image_p[ePlayerAnimMove1] = GET_RESOURCE("Player_Move_Anim_1", CImage*);
	m_anim_image_p[ePlayerAnimMove2] = GET_RESOURCE("Player_Move_Anim_2", CImage*);
	m_anim_image_p[ePlayerAnimMove3] = GET_RESOURCE("Player_Move_Anim_3", CImage*);
	m_anim_image_p[ePlayerAnimMove4] = GET_RESOURCE("Player_Move_Anim_4", CImage*);
	m_anim_image_p[ePlayerAnimMove5] = GET_RESOURCE("Player_Move_Anim_5", CImage*);
	m_anim_image_p[ePlayerAnimMove6] = GET_RESOURCE("Player_Move_Anim_6", CImage*);
	m_anim_image_p[ePlayerAnimMove7] = GET_RESOURCE("Player_Move_Anim_7", CImage*);

	m_anim_image_p[ePlayerAnimRun0] = GET_RESOURCE("Player_Run_Anim_0", CImage*);
	m_anim_image_p[ePlayerAnimRun1] = GET_RESOURCE("Player_Run_Anim_1", CImage*);
	m_anim_image_p[ePlayerAnimRun2] = GET_RESOURCE("Player_Run_Anim_2", CImage*);
	m_anim_image_p[ePlayerAnimRun3] = GET_RESOURCE("Player_Run_Anim_3", CImage*);
	m_anim_image_p[ePlayerAnimRun4] = GET_RESOURCE("Player_Run_Anim_4", CImage*);
	m_anim_image_p[ePlayerAnimRun5] = GET_RESOURCE("Player_Run_Anim_5", CImage*);

	m_anim_image_p[ePlayerAnimJump0] = GET_RESOURCE("Player_Jump_Anim_0", CImage*);
	m_anim_image_p[ePlayerAnimJump1] = GET_RESOURCE("Player_Jump_Anim_1", CImage*);
	m_anim_image_p[ePlayerAnimJump2] = GET_RESOURCE("Player_Jump_Anim_2", CImage*);
	/*
	m_anim_image_p[ePlayerAnimJump3] = GET_RESOURCE("Player_Jump_Anim_3", CImage*);
	m_anim_image_p[ePlayerAnimJump4] = GET_RESOURCE("Player_Jump_Anim_4", CImage*);
	*/

	m_anim_image_p[ePlayerAnimAttack0] = GET_RESOURCE("Player_Attack_Anim_0", CImage*);
	m_anim_image_p[ePlayerAnimAttack1] = GET_RESOURCE("Player_Attack_Anim_1", CImage*);
	m_anim_image_p[ePlayerAnimAttack2] = GET_RESOURCE("Player_Attack_Anim_2", CImage*);
	
	
	m_anim_image_p[ePlayerAnimIdAttackReserve0] = GET_RESOURCE("Player_Attack_Anim_1", CImage*);
	m_anim_image_p[ePlayerAnimIdAttackReserve1] = GET_RESOURCE("Player_Attack_Anim_0", CImage*);

	m_anim_image_p[ePlayerAnimLand0] = GET_RESOURCE("Player_Jump_Anim_4", CImage*);


	m_anim_image_p[ePlayerAnimFall0] = GET_RESOURCE("Player_Jump_Anim_1", CImage*);
	m_anim_image_p[ePlayerAnimFall1] = GET_RESOURCE("Player_Jump_Anim_2", CImage*);
	m_anim_image_p[ePlayerAnimFall2] = GET_RESOURCE("Player_Jump_Anim_3", CImage*);
	m_anim_image_p[ePlayerAnimFall3] = GET_RESOURCE("Player_Jump_Anim_4", CImage*);

	m_anim_image_p[ePlayerAnimDamage0] = GET_RESOURCE("Player_Damage_Anim_0", CImage*);

	m_anim_image_p[ePlayerAnimEvasion0] = GET_RESOURCE("Player_Evasion_Anim_0", CImage*);
	m_anim_image_p[ePlayerAnimEvasion1] = GET_RESOURCE("Player_Evasion_Anim_1", CImage*);
	m_anim_image_p[ePlayerAnimEvasion2] = GET_RESOURCE("Player_Evasion_Anim_2", CImage*);
	m_anim_image_p[ePlayerAnimEvasion3] = GET_RESOURCE("Player_Evasion_Anim_3", CImage*);
	m_anim_image_p[ePlayerAnimEvasion4] = GET_RESOURCE("Player_Evasion_Anim_4", CImage*);
	m_anim_image_p[ePlayerAnimEvasion5] = GET_RESOURCE("Player_Evasion_Anim_5", CImage*);


	m_anim_image_p[ePlayerAnimDown0] = GET_RESOURCE("Player_Down_Anim_0", CImage*);
	m_anim_image_p[ePlayerAnimDown1] = GET_RESOURCE("Player_Down_Anim_1", CImage*);

	//アニメーションデータの設定
	m_anim_info[ePlayerAnimIdIdle].image_num = 4;
	m_anim_info[ePlayerAnimIdIdle].image_id = ePlayerAnimIdle0;
	m_anim_info[ePlayerAnimIdIdle].delay = PLAYER_ANIM_IDLE;

	m_anim_info[ePlayerAnimIdMove].image_num = 8;
	m_anim_info[ePlayerAnimIdMove].image_id = ePlayerAnimMove0;
	m_anim_info[ePlayerAnimIdMove].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[ePlayerAnimIdRun].image_num = 6;
	m_anim_info[ePlayerAnimIdRun].image_id = ePlayerAnimRun0;
	m_anim_info[ePlayerAnimIdRun].delay = PLAYER_ANIM_RUN_DELAY;

	m_anim_info[ePlayerAnimIdJump].image_num = 3;
	m_anim_info[ePlayerAnimIdJump].image_id = ePlayerAnimJump0;
	m_anim_info[ePlayerAnimIdJump].delay = 10;

	m_anim_info[ePlayerAnimIdLand].image_num = 1;
	m_anim_info[ePlayerAnimIdLand].image_id = ePlayerAnimLand0;
	m_anim_info[ePlayerAnimIdLand].delay = 14;

	m_anim_info[ePlayerAnimIdFall].image_num = 1;
	m_anim_info[ePlayerAnimIdFall].image_id = ePlayerAnimFall1;
	m_anim_info[ePlayerAnimIdFall].delay = 14;

	m_anim_info[ePlayerAnimIdAttack].image_num = 3;
	m_anim_info[ePlayerAnimIdAttack].image_id = ePlayerAnimAttack0;
	m_anim_info[ePlayerAnimIdAttack].delay = PLAYER_ATTACK_ANIM_DELAY;

	m_anim_info[ePlayerAnimIdAttackReserve].image_num = 2;
	m_anim_info[ePlayerAnimIdAttackReserve].image_id = ePlayerAnimIdAttackReserve0;
	m_anim_info[ePlayerAnimIdAttackReserve].delay = PLAYER_ATTACK_RESERVE_ANIM_DELAY;

	m_anim_info[ePlayerAnimIdDamage].image_num = 1;
	m_anim_info[ePlayerAnimIdDamage].image_id = ePlayerAnimDamage0;
	m_anim_info[ePlayerAnimIdDamage].delay = 14;

	m_anim_info[ePlayerAnimIdEvasionFast].image_num = 2;
	m_anim_info[ePlayerAnimIdEvasionFast].image_id = ePlayerAnimEvasion2;
	m_anim_info[ePlayerAnimIdEvasionFast].delay = PLAYER_EVASION_ANIM_DELAY;

	m_anim_info[ePlayerAnimIdEvasion].image_num = 6;
	m_anim_info[ePlayerAnimIdEvasion].image_id = ePlayerAnimEvasion0;
	m_anim_info[ePlayerAnimIdEvasion].delay = PLAYER_EVASION_ANIM_DELAY;


	m_anim_info[ePlayerAnimIdEvasionReserve].image_num = 2;
	m_anim_info[ePlayerAnimIdEvasionReserve].image_id = ePlayerAnimEvasion4;
	m_anim_info[ePlayerAnimIdEvasionReserve].delay = PLAYER_EVASION_ANIM_DELAY;

	m_anim_info[ePlayerAnimIdDown].image_num = 2;
	m_anim_info[ePlayerAnimIdDown].image_id = ePlayerAnimDown0;
	m_anim_info[ePlayerAnimIdDown].delay = 14;
		

	m_anim_info[ePlayerAnimIdDowned].image_num = 1;
	m_anim_info[ePlayerAnimIdDowned].image_id = ePlayerAnimDown1;
	m_anim_info[ePlayerAnimIdDowned].delay = PLAYER_DOWN_ANIM_DELAY;
}

void CCharacterPlayer::InputDash()
{
	if (m_is_landing_action_now == true) return;
	if (m_is_evasion == true) return;
	if (m_is_down == true) return;


	if (CInput::GetState(0, CInput::eHold, CInput::eButton3)) {
		m_is_dashing = true;
		m_speed = 6.0f;
		m_size = CVector2D(100, 100);
	}
}

void CCharacterPlayer::InputAttack()
{
	if (m_is_landing_action_now == true) return;
	if (m_is_evasion == true) return;
	if (m_is_down == true) return;

	if (m_is_attacking == true) return;
	if (CInput::GetState(0, CInput::eHold, CInput::eButton2)) {
		//printf("攻撃\n");
		ClearEarlyInput();
		m_is_attacking = true;
		m_attacking_count = PLAYER_ATTACK_FRAME;


		for (int i = 0; i < MEMORY_HIT_ATTACKED_ENEMY_MAX; i++) {
			m_memory_hit_attacked_enemy_p[i] = nullptr;
			
		}
		m_memory_hit_attacked_enemy_num = 0;
	}
}




void CCharacterPlayer::CharacterBeforeUpdate()
{

}

void CCharacterPlayer::CharacterUpdate()
{
	//printf("x %lf y %lf z %lf\n", m_pos.x, m_pos.y, m_pos.z);
	
	
	if (m_landing_anim_count > 0) m_landing_anim_count--;

	if (m_is_landing_action_now == true) SetWillPlayAnim(ePlayerAnimIdLand);
	else if(m_will_play_anim_id == ePlayerAnimIdLand && m_landing_anim_count > 0) SetWillPlayAnim(ePlayerAnimIdLand);
	else if (m_evasion_reserve_count > 0) SetWillPlayAnim(ePlayerAnimIdEvasionReserve);
	else if (m_will_play_anim_id == ePlayerAnimIdAttackReserve && m_attack_reserve_count-- > 0) SetWillPlayAnim(ePlayerAnimIdAttackReserve);
	else if (m_will_play_anim_id == ePlayerAnimIdDamage && m_damage_anim_count-- > 0) {
		SetWillPlayAnim(ePlayerAnimIdDamage);
		//printf("ダメージモーション中 %d\n", m_damage_anim_count);
	}
	else m_will_play_anim_id = ePlayerAnimIdIdle;

	
	m_is_dashing = false;
	m_speed = PLAYER_SPEED;
	SetInvincible(false);
	m_vec.x = 0.0f;
	m_vec.z = 0.0f;


	InputAttack();
	InputDash();
	InputMove();
	InputJump();
	InputEvasion();

	//座標移動
	DoingLandingAction();
	DoingDown();
	DoingEvasion();
	Landing();
	Gravity();
	Jumping();
	Falling();
	Move();
	MoveLimit();
	
	
	AfterDamageInvincible();
	Attacking();

	CalcScroll();
	AdjAnim();
}

void CCharacterPlayer::CharacterBeforeCollisionCheck()
{

}

void CCharacterPlayer::InputMove()
{
	if (m_is_evasion == true) return;
	if (m_is_down == true) return;
	if (m_is_landing_action_now == true) return;
	
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
		m_vec.z = -1 * m_speed;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
		ClearEarlyInput();
		is_move = true;
		m_vec.z = 1 * m_speed;
	}

	if (is_move == true) {
		if (m_is_dashing == true) SetWillPlayAnim(ePlayerAnimIdRun);
		else SetWillPlayAnim(ePlayerAnimIdMove);
	}

}

void CCharacterPlayer::InputJump()
{
	if (m_is_evasion == true) return;
	if (m_is_down == true) return;


	if (CInput::GetState(0, CInput::eHold, CInput::eButton1) && m_is_jumping == false && m_is_landing == true) {
		ClearEarlyInput();
		SetWillPlayAnim(ePlayerAnimIdJump);
		m_is_jumping = true;
		m_jumping_count = 30;
		m_vec.y = -30.0f;
		m_is_landing = false;
	}
}

void CCharacterPlayer::AfterDamageInvincible()
{
	if (m_after_damage_invincible_count > 0) {


		m_after_damage_invincible_count--;
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
		if (m_landing_action_count-- <= 0) {
			m_is_landing_action_now = false;
		}
	}
}


void CCharacterPlayer::Landing()
{
	if (m_is_landing == true & m_is_landing_old == false) {
		//printf("着地\n");
		if(m_will_play_anim_id ==  ePlayerAnimIdIdle) SetWillPlayAnim(ePlayerAnimIdLand);
		m_landing_action_count = PLAYER_LANDING_ACTION_FRAME;
		m_landing_anim_count = PLAYER_LANDING_ANIM_FRAME;
		m_is_landing_action_now = true;


		//もし硬直時間が0ならfalseに
		if (m_landing_action_count == 0) m_is_landing_action_now = false;
	}
}



void CCharacterPlayer::InputEvasion()
{
	int receive_input_time = PLAYER_RECEIVE_INPUT_EVASION_TIME;
	
	if(m_evasion_reserve_count > 0 || m_is_evasion == true) receive_input_time = PLAYER_RECEIVE_INPUT__EVASION_TIME_AFTER_EVASION;

	printf("receive_input %d\n", receive_input_time);

	if (m_receive_input_evasion_time_count_r > 0) m_receive_input_evasion_time_count_r--;
	if (m_receive_input_evasion_time_count_l > 0) m_receive_input_evasion_time_count_l--;



	if (CInput::GetState(0, CInput::ePush, CInput::eRight) && m_receive_input_evasion_time_count_r <= 0) {
		m_receive_input_evasion_time_count_l = 0;
		m_receive_input_evasion_time_count_r = receive_input_time;
	}
	else if (CInput::GetState(0, CInput::ePush, CInput::eRight) && m_receive_input_evasion_time_count_r > 0) {
		m_is_input_evasion_flip = false;
		BeginEvasion();
	}



	if (CInput::GetState(0, CInput::ePush, CInput::eLeft) && m_receive_input_evasion_time_count_l <= 0) {
		m_receive_input_evasion_time_count_r = 0;
		m_receive_input_evasion_time_count_l = receive_input_time;
	}
	else if (CInput::GetState(0, CInput::ePush, CInput::eLeft) && m_receive_input_evasion_time_count_l > 0) {
		m_is_input_evasion_flip = true;
		BeginEvasion();
	}


	printf("m_is_input_evasion %d\n", m_is_input_evasion);
	if (m_is_input_evasion == true) {
		BeginEvasion();
	}


}

void CCharacterPlayer::BeginEvasion()
{
	ClearEarlyInput();
	m_is_input_evasion = true;

	if (m_is_down == true) return;

	//回避中かつ予備動作中でないならなにもしない
	if (m_is_evasion == true && m_evasion_reserve_count <= 0) return;

	//回避予備動作中だが入力した方角が違う場合なにもしない
	if (m_is_evasion == true && m_evasion_reserve_count > 0 && m_is_flip != m_is_input_evasion_flip) return;

	//空中にいるなら回避しない
	if (m_is_landing == false) return;
	//攻撃をやめる
	m_is_attacking = false;
	//m_is_jumping = false;


	printf("回避開始\n");
	m_receive_input_evasion_time_count_l = 0;
	m_receive_input_evasion_time_count_r = 0;
	m_is_evasion = true;
	m_evasion_count = PLAYER_EVASION_FRAME;
	m_is_input_evasion = false;
	m_evasion_reserve_count = 0;


	m_is_flip = m_is_input_evasion_flip;

	//もし着地モーションから派生した場合冒頭モーションの短縮を行う
	if (m_will_play_anim_id == ePlayerAnimIdLand) {
		m_is_fast_evasion = true;
		m_evasion_count = PLAYER_EVASION_FRAME - (PLAYER_EVASION_ANIM_DELAY * 2);
	}

	//printf("m_is_input_evasion false\n");


}

void CCharacterPlayer::DoingEvasion()
{
	if (m_is_evasion == false) return;


	//予備動作が終わると完了する(回避予備動作は回避行動ならキャンセルできる)

	if (m_evasion_reserve_count > 0) {
		SetWillPlayAnim(ePlayerAnimIdEvasionReserve);
		if (--m_evasion_reserve_count <= 0) {
			m_evasion_reserve_count = 0;
			m_is_evasion = false;
			SetInvincible(false);
		}
	}
	else if (--m_evasion_count <= 0) {
		m_is_fast_evasion = false;
		/*
		m_is_evasion = false;
		SetInvincible(false);
		*/

		SetWillPlayAnim(ePlayerAnimIdEvasionReserve);
		m_evasion_reserve_count = PLAYER_EVASION_RESERVE_FRAME;
	}
	else {
		
		//移動開始フレームになったら移動する
		//if (m_evasion_count <= PLAYER_EVASION_FRAME - PLAYER_EVASION_MOVE_START_FRAME && m_evasion_count > PLAYER_EVASION_FRAME - PLAYER_EVASION_MOVE_END_FRAME) {
		if (m_evasion_count <= PLAYER_EVASION_FRAME - PLAYER_EVASION_MOVE_START_FRAME) {
			double moving_vec = 3.5 / SPF;
			//向きに応じて移動
			if (m_is_flip == false) {
				m_vec.x = moving_vec * CFPS::GetDeltaTime();
			}
			else if (m_is_flip == true) {
				m_vec.x = -moving_vec * CFPS::GetDeltaTime();
			}
		}

		printf("回避 %d\n", m_evasion_count);
		SetInvincible(true);

		if(m_is_fast_evasion == true) SetWillPlayAnim(ePlayerAnimIdEvasionFast);
		else SetWillPlayAnim(ePlayerAnimIdEvasion);
	}

	
	
}

void CCharacterPlayer::DoingDown()
{
	if (m_is_down == false) return;
	

	m_down_count--;
	
	if(m_down_count >= PLAYER_DOWN_FRAME -PLAYER_DOWN_ANIM_FRAME) SetWillPlayAnim(ePlayerAnimIdDown);
	else SetWillPlayAnim(ePlayerAnimIdDowned);


	if (m_down_count <= 0) {
		m_is_down  = false;
		//ゲームオーバー呼び出しとゲームシーンオブジェクトの削除
		SetIsDelete();
	}
}


void CCharacterPlayer::Attacking()
{
	if (m_is_attacking == false) return;
	m_attacking_count--;


	if (m_attacking_count < 0) {
		m_is_attacking = false;

		m_attack_reserve_count = PLAYER_ATTACK_RESERVE_ANIM_FRAME;
		//予備動作を再生
		SetWillPlayAnim(ePlayerAnimIdAttackReserve);
		return;
	}
	else if (m_attacking_count <= PLAYER_ATTACK_FRAME - PLAYER_ATTACK_HIT_FRAME_START && m_attacking_count >  PLAYER_ATTACK_FRAME - PLAYER_ATTACK_HIT_FRAME_END) {
		//攻撃判定を発生させる。

		//生成されている全てのエネミーのポインタを取得
		Task** enemy_array = TaskManager::GetInstance()->FindTaskArray(eTaskIdEnemy);

		int i = 0;
		while (true) {
			if (enemy_array[i] == nullptr) {
				break;
			}

			CCharacter* enemy_p = dynamic_cast<CCharacter*>(enemy_array[i]);
			if (enemy_p == nullptr) {
				i++;
				continue;
			}



			//printf("エネミーいたよね\n");

			//位置関係を取得
			CVector3D enemy_pos = enemy_p->GetPos();
			CVector3D player_pos = GetPos();


			//距離ベクトル(位置の差)を計算
			CVector3D length = enemy_pos - player_pos;

			//絶対距離を計算
			CVector3D length_abs;
			length_abs.x = abs(length.x);
			length_abs.y = abs(length.y);
			length_abs.z = abs(length.z);

			//攻撃範囲
			CVector3D attack_length = PLAYER_ATTACK_LENGTH;


			//printf("攻撃!!!!\n");
			//敵が左側にいて自分が左向き
			//もしくは敵が右側にいて、自分が右向きなら
			if (length.x <= 0.0f && m_is_flip == true
				|| length.x >= 0.0f && m_is_flip == false) {
				//printf("length.x %lf length.y %lf length.z %lf \n", length.x, length.y, length.z);

				//攻撃範囲内に敵がいるなら
				if (length_abs.x <= attack_length.x&& length_abs.y <= attack_length.y&&length_abs.z <= attack_length.z) {
					
					
					bool is_aready_hit = false;
					//当たっているので攻撃判定が既にされているオブジェクトかどうかチェック
					for (int i = 0; i < m_memory_hit_attacked_enemy_num; i++) {
						if (m_memory_hit_attacked_enemy_p[i] == enemy_p) {
							is_aready_hit = true;
							//printf("もう攻撃していたのでなにもしない\n");
							break;
						}
					}
					
					
					//まだ攻撃を当たった扱いになってないなら攻撃判定を行う
					if (is_aready_hit == false) {
						enemy_p->ReceiveAttack();
						*enemy_p->GetHitPointPointer() -= PLAYER_ATTACK_POWER;
						//printf("enemy hp %lf\n", *enemy_p->GetHitPointPointer());
						m_memory_hit_attacked_enemy_p[m_memory_hit_attacked_enemy_num++] = enemy_p;
					}
				}

			}

			i++;
		}


		free(enemy_array);
		
	}
	printf("攻撃 %d\n", m_attacking_count);
	SetWillPlayAnim(ePlayerAnimIdAttack);


}

void CCharacterPlayer::Jumping()
{
	//ジャンプで使われるのは上昇時のアニメーションくらいか。

	if (m_is_jumping == true) {
		if (m_is_landing == true || m_jumping_count-- <= 0) {
			m_is_jumping = false;
		}

		SetWillPlayAnim(ePlayerAnimIdJump);
		printf("ジャンプ！\n");
	}

	
	
}

void CCharacterPlayer::Falling()
{
	if (m_is_landing == false && m_is_jumping == false) {

		SetWillPlayAnim(ePlayerAnimIdFall);
		//ある程度の高度なら落ちるモーションをそうでないなら着地モーションを再生
		//if(m_pos.y <= -330) SetWillPlayAnim(ePlayerAnimIdFall);
		//else SetWillPlayAnim(ePlayerAnimIdLand);
		
		printf("ファール\n");
	}
}

void CCharacterPlayer::Move()
{
	m_pos_old = m_pos;
	m_pos += m_vec;
}

void CCharacterPlayer::CharacterOutHitPoint()
{
	if (m_is_down == true) return;
	m_after_damage_invincible_count = 0;
	SetIsBlindDraw(false);
	m_is_down = true;
	m_down_count = PLAYER_DOWN_FRAME;
	SetWillPlayAnim(ePlayerAnimIdDown);
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
}

void CCharacterPlayer::AdjAnim()
{
	switch (m_will_play_anim_id) {
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

void CCharacterPlayer::CalcScroll()
{
	//画面上の座標

	CVector2D scroll_pos = GetScroll();
	
	//	float offset_x = -100.0f;
	float offset_x = - 120.0f;

	CVector2D calc_scroll_pos = GetScroll();

	if (m_pos.x >= scroll_pos.x + 1280.0f + offset_x) {
		calc_scroll_pos.x = m_pos.x - 1280.0f - offset_x;
	}
	else if (m_pos.x <= scroll_pos.x - offset_x) {
		calc_scroll_pos.x = m_pos.x + offset_x;
	}
	
	
	if (calc_scroll_pos.x >= CGameScene::GetInstance()->GetGameSceneLimitPosMax().x  + offset_x) {
		calc_scroll_pos.x = CGameScene::GetInstance()->GetGameSceneLimitPosMax().x - offset_x;
	}

	//スクロール限界値を設定
	double max_x = CGameScene::GetInstance()->GetGameSceneLimitPosMax().x - 1280.0f;
	if (calc_scroll_pos.x > max_x) calc_scroll_pos.x = max_x;
	//printf("max_x %lf calc_scroll_pos.x %lf\n", max_x,calc_scroll_pos.x);

	//Y軸スクロール
	float offset_y = -200.0f;

	double draw_pos_y = m_pos.y + m_pos.z;

	if (draw_pos_y <= scroll_pos.y - offset_y) {
		calc_scroll_pos.y = draw_pos_y + offset_y;
	}
	else if (scroll_pos.y < 0) {
		calc_scroll_pos.y = draw_pos_y + offset_y;
	}

	if (calc_scroll_pos.y > 0.0f) calc_scroll_pos.y = 0.0f;

	//printf("calc_scroll_pos.y %lf\n", calc_scroll_pos.y);




	SetScroll(calc_scroll_pos);

}

void CCharacterPlayer::ReceiveAttack()
{
	//ダウンしているなら何もしない
	if (m_is_down == true) return;
	//無敵ならなにもしない
	if (GetInvincible() == true) return;

	SetWillPlayAnim(ePlayerAnimIdDamage);
	m_damage_anim_count = PLAYER_DAMAGE_ANIM_FRAME;
	

	//無敵時間点灯
	SetIsBlindDraw(true);
	m_after_damage_invincible_count = PLAYER_AFTER_DAMAGE_INVINCIBLE;
}
