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
	m_hit_point = 10.0f;
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
	m_anim_image_p[ePlayerAnimJump3] = GET_RESOURCE("Player_Jump_Anim_3", CImage*);
	m_anim_image_p[ePlayerAnimJump4] = GET_RESOURCE("Player_Jump_Anim_4", CImage*);

	m_anim_image_p[ePlayerAnimLand0] = GET_RESOURCE("Player_Jump_Anim_4", CImage*);


	m_anim_image_p[ePlayerAnimFall0] = GET_RESOURCE("Player_Jump_Anim_2", CImage*);
	m_anim_image_p[ePlayerAnimFall1] = GET_RESOURCE("Player_Jump_Anim_3", CImage*);
	m_anim_image_p[ePlayerAnimFall2] = GET_RESOURCE("Player_Jump_Anim_4", CImage*);

	m_anim_image_p[ePlayerAnimDamage0] = GET_RESOURCE("Player_Damage_Anim_0", CImage*);

	m_anim_image_p[ePlayerAnimEvasion0] = GET_RESOURCE("Player_Jump_Anim_4", CImage*);

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

	m_anim_info[ePlayerAnimIdJump].image_num = 5;
	m_anim_info[ePlayerAnimIdJump].image_id = ePlayerAnimJump0;
	m_anim_info[ePlayerAnimIdJump].delay = 14;

	m_anim_info[ePlayerAnimIdLand].image_num = 1;
	m_anim_info[ePlayerAnimIdLand].image_id = ePlayerAnimLand0;
	m_anim_info[ePlayerAnimIdLand].delay = 14;

	m_anim_info[ePlayerAnimIdFall].image_num = 3;
	m_anim_info[ePlayerAnimIdFall].image_id = ePlayerAnimFall0;
	m_anim_info[ePlayerAnimIdFall].delay = 14;

	m_anim_info[ePlayerAnimIdAttack].image_num = 8;
	m_anim_info[ePlayerAnimIdAttack].image_id = ePlayerAnimMove0;
	m_anim_info[ePlayerAnimIdAttack].delay = 3;

	m_anim_info[ePlayerAnimIdDamage].image_num = 1;
	m_anim_info[ePlayerAnimIdDamage].image_id = ePlayerAnimDamage0;
	m_anim_info[ePlayerAnimIdDamage].delay = 14;

	m_anim_info[ePlayerAnimIdEvasion].image_num = 1;
	m_anim_info[ePlayerAnimIdEvasion].image_id = ePlayerAnimEvasion0;
	m_anim_info[ePlayerAnimIdEvasion].delay = 14;

}

void CCharacterPlayer::InputDash()
{
	if (m_is_evasion == true) return;

	if (CInput::GetState(0, CInput::eHold, CInput::eButton3)) {
		m_is_dashing = true;
		m_speed = 6.0f;
		m_size = CVector2D(100, 100);
	}
}

void CCharacterPlayer::InputAttack()
{
	if (m_is_evasion == true) return;

	if (m_is_attacking == true) return;
	if (CInput::GetState(0, CInput::eHold, CInput::eButton2)) {
		//printf("攻撃\n");
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
	
	//もし着地モーション等を再生してないなら
	if (m_will_play_anim_id == ePlayerAnimIdLand && m_landing_anim_count-- > 0) SetWillPlayAnim(ePlayerAnimIdLand);
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
	
	bool is_move = false;
	if (CInput::GetState(0,CInput::eHold, CInput::eRight)) {
		m_is_flip = false;
		is_move = true;
		m_vec.x = 1 * m_speed;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_is_flip = true;
		is_move = true;
		m_vec.x = -1 * m_speed;
	}

	if (CInput::GetState(0, CInput::eHold, CInput::eUp)) {
		is_move = true;
		m_vec.z = -1 * m_speed;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
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

	if (CInput::GetState(0, CInput::eHold, CInput::eButton1) && m_is_jumping == false && m_is_landing == true) {
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

void CCharacterPlayer::Landing()
{
	if (m_is_landing == true & m_is_landing_old == false) {
		//printf("着地したて\n");
		SetWillPlayAnim(ePlayerAnimIdLand);
		m_landing_anim_count = PLAYER_LANDING_ANIM_FRAME;
	}
}



void CCharacterPlayer::InputEvasion()
{
	const int receive_input_time = 10;



	if (m_receive_input_evasion_time_count_r > 0) m_receive_input_evasion_time_count_r--;
	if (m_receive_input_evasion_time_count_l > 0) m_receive_input_evasion_time_count_l--;



	if (CInput::GetState(0, CInput::ePush, CInput::eRight) && m_receive_input_evasion_time_count_r <= 0) {
		m_receive_input_evasion_time_count_l = 0;
		m_receive_input_evasion_time_count_r = receive_input_time;
	}
	else if (CInput::GetState(0, CInput::ePush, CInput::eRight) && m_receive_input_evasion_time_count_r > 0) {
		BeginEvasion();
	}



	if (CInput::GetState(0, CInput::ePush, CInput::eLeft) && m_receive_input_evasion_time_count_l <= 0) {
		m_receive_input_evasion_time_count_r = 0;
		m_receive_input_evasion_time_count_l = receive_input_time;
	}
	else if (CInput::GetState(0, CInput::ePush, CInput::eLeft) && m_receive_input_evasion_time_count_l > 0) {
		BeginEvasion();
	}



}

void CCharacterPlayer::BeginEvasion()
{
	//攻撃・ジャンプをやめる
	m_is_attacking = false;
	m_is_jumping = false;

	printf("回避\n");
	m_receive_input_evasion_time_count_l = 0;
	m_receive_input_evasion_time_count_r = 0;
	m_is_evasion = true;
	m_evasion_count = 30;


}

void CCharacterPlayer::DoingEvasion()
{
	if (m_is_evasion == false) return;

	if (--m_evasion_count <= 0) {
		m_is_evasion = false;
		SetInvincible(false);
	}
	else {
		//
		printf("回避 %d\n", m_evasion_count);
		SetInvincible(true);

		double moving_vec = 10 / SPF;
		//向きに応じて移動
		if (m_is_flip == false) {
			m_vec.x = moving_vec * CFPS::GetDeltaTime();
		}
		else if (m_is_flip == true) {
			m_vec.x = -moving_vec * CFPS::GetDeltaTime();
		}
		SetWillPlayAnim(ePlayerAnimIdEvasion);
	}

	
	
}


void CCharacterPlayer::Attacking()
{
	if (m_is_attacking == false) return;
	m_attacking_count--;


	if (m_attacking_count <= 0) {
		m_is_attacking = false;
	}


	else if (m_attacking_count <= PLAYER_ATTACK_HIT_FRAME_START && m_attacking_count > PLAYER_ATTACK_HIT_FRAME_END) {
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
	SetWillPlayAnim(ePlayerAnimIdAttack);


}

void CCharacterPlayer::Jumping()
{
	//ジャンプで使われるのは上昇時のアニメーションくらいか。

	if (m_is_jumping == true) {
		if (m_is_landing == true || m_jumping_count-- <= 0) {
			m_is_jumping = false;
			//printf("ジャンプ解除");
		}

		SetWillPlayAnim(ePlayerAnimIdJump);


		/*
		m_vec.y -= 0.1 + GRAVITY;
		if (m_vec.y <= -3.0) m_vec.y = -3.0;
		*/
	}

	
	
}

void CCharacterPlayer::Falling()
{
	if (m_is_landing == false && m_is_jumping == false) {
		SetWillPlayAnim(ePlayerAnimIdFall);
		//printf("ファール\n");
	}
}

void CCharacterPlayer::Move()
{
	m_pos_old = m_pos;
	m_pos += m_vec;
}

void CCharacterPlayer::CharacterDraw()
{
	
	
}

void CCharacterPlayer::CollisionCheckCharacter(Task * _collision_task)
{

}

void CCharacterPlayer::AdjAnim()
{
	switch (m_will_play_anim_id) {
	case ePlayerAnimIdRun:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(-30.0f, 10.0f));
		SetShadowPosAdj(CVector2D(-30,0));
		break;
	default:
		SetSize(400, 400);
		SetDrawAdjPos(CVector2D(-30.0f, 10.0f));
		SetShadowPosAdj(CVector2D(0, 0));
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
	//無敵ならなにもしない
	if (GetInvincible() == true) return;

	SetWillPlayAnim(ePlayerAnimIdDamage);
	m_damage_anim_count = PLAYER_DAMAGE_ANIM_FRAME;
	

	//無敵時間点灯
	SetIsBlindDraw(true);
	m_after_damage_invincible_count = PLAYER_AFTER_DAMAGE_INVINCIBLE;
}
