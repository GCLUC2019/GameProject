#include "CCharacterPlayer.h"
#include "../Global.h"
#include "CGameScene.h"
#include "CAnimation.h"

#define PLAYER_SPEED (3.0f)

static CCharacterPlayer* s_instance_p = nullptr;

CCharacterPlayer::CCharacterPlayer() :CCharacter(eTaskIdPlayer, 0)
{
	s_instance_p = this;
	m_speed = PLAYER_SPEED;
	//m_anim_p->SetAnim(ePlayerAnimIdIdle);
	LoadAnimImage();

	SetSize(400, 400);
	SetIsShowShadow(true);
	SetShadowSize(CVector2D(100, 50));
	SetDrawAdjPos(CVector2D(-15, 20.0f));
	SetRads(75,200,10);


	//�̗͂̐ݒ�
	m_hit_point = 10.0f;
	m_hit_point_max = 10.0f;


	//�����蔻��̗D��x
	SetCollisionPriority(100);

	SetIsCalcScrollBaseObject(true);


}

CCharacterPlayer::~CCharacterPlayer()
{
	s_instance_p = nullptr;
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

	//�A�j���[�V�����f�[�^�̐ݒ�
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

void CCharacterPlayer::InputDash()
{
	if (m_is_landing_action_now == true) return;
	if (m_is_evasion == true) return;
	if (m_is_down == true) return;


	if (CInput::GetState(0, CInput::eHold, CInput::eButton3)) {
		m_is_dashing = true;
		m_speed = 6.0f;
	}
}

void CCharacterPlayer::InputAttack()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton2) || m_is_early_input_attack == true) {
		ClearEarlyInput();
		m_is_early_input_attack = true;
		if (m_is_landing_action_now == true) return;
		if (m_is_evasion == true) return;
		if (m_is_down == true) return;
		if (m_is_attacking == true) return;

		m_is_early_input_attack = false;

		//DEBUG_PRINT("�U��\n");
		ClearEarlyInput();
		m_is_attacking = true;
		if (m_attack_reserve_count > 0.0) m_attack_combo_count++;
		else m_attack_combo_count = 0;

		if (m_attack_combo_count > 2) m_attack_combo_count = 0;

		
		

		//�����ړ��L�[����͂��Ă�Ȃ�C�ӂ̍U�����o��
		if (CInput::GetState(0, CInput::eHold, CInput::eLeft) || (CInput::GetState(0, CInput::eHold, CInput::eRight))) {
			m_attack_combo_count = 0;
			printf("�P���U�� (�ړ��L�[�����Ȃ���ŔC�ӂ̍U�����o����)\n");
		}
		if (CInput::GetState(0, CInput::eHold, CInput::eUp) || (CInput::GetState(0, CInput::eHold, CInput::eDown))) {
			m_attack_combo_count = 1;
			printf("�P���U�� (�ړ��L�[�����Ȃ���ŔC�ӂ̍U�����o����)\n");
		}

		//�����󒆂ɂ���Ȃ�t�B�j�b�V�����[�V�����ɂ���(�W�����v�U��)
		if (m_is_landing == false) m_attack_combo_count = 2;

		printf("m_attack_combo_count %d\n", m_attack_combo_count);




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
			//�኱��ɏ㏸����
			m_vec.y = -20.0f;
			break;
		}
		m_attack_total_frame = m_attacking_count;


		for (int i = 0; i < MEMORY_HIT_ATTACKED_ENEMY_MAX; i++) {
			m_memory_hit_attacked_enemy_p[i] = nullptr;
			
		}
		m_memory_hit_attacked_enemy_num = 0;


		//�A�j���[�V�������Đ�
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
}




void CCharacterPlayer::CharacterBeforeUpdate()
{

}

void CCharacterPlayer::CharacterUpdate()
{
	//DEBUG_PRINT("x %lf y %lf z %lf\n", m_pos.x, m_pos.y, m_pos.z);
	
	
	if (m_landing_anim_count > 0.0) m_landing_anim_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
	
	if (m_damage_anim_count > 0.0) m_damage_anim_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;

	if (m_is_landing_action_now == true) m_anim_p->SetWillPlayAnim(ePlayerAnimIdLand);
	else if(m_anim_p->GetWillPlayAnim() == ePlayerAnimIdLand && m_landing_anim_count > 0)  m_anim_p->SetWillPlayAnim(ePlayerAnimIdLand);
	else if (m_evasion_reserve_count > 0.0) m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasionReserve);
	else if (m_anim_p->GetWillPlayAnim() == ePlayerAnimIdDamage && m_damage_anim_count > 0) {
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdDamage);
		//DEBUG_PRINT("�_���[�W���[�V������ %d\n", m_damage_anim_count);
	}
	else m_anim_p->SetWillPlayAnim(ePlayerAnimIdIdle);


	ReserveAttacking();
	
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

	//���W�ړ�
	DoingLandingAction();
	DoingDown();
	DoingEvasion();
	Landing();
	Jumping();
	Falling();

	//Gravity();
	
	//Move();
	//MoveLimit();
	
	
	AfterDamageInvincible();
	Attacking();

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
	if (m_attack_reserve_count > 0.0) return;
	if (m_is_attacking == true) return;
	if (m_is_evasion == true) return;
	if (m_is_down == true) return;


	if (CInput::GetState(0, CInput::eHold, CInput::eButton1) && m_is_jumping == false && m_is_landing == true) {
		ClearEarlyInput();
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdJump);
		m_is_jumping = true;
		m_jumping_count = 30;
		m_vec.y = -30.0f;
		m_is_landing = false;
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
	if (m_is_landing == true & m_is_landing_old == false) {
		//DEBUG_PRINT("���n\n");
		if(m_anim_p->GetWillPlayAnim() ==  ePlayerAnimIdIdle) m_anim_p->SetWillPlayAnim(ePlayerAnimIdLand);
		m_landing_action_count = PLAYER_LANDING_ACTION_FRAME;
		m_landing_anim_count = PLAYER_LANDING_ANIM_FRAME;
		m_is_landing_action_now = true;
		printf("���n\n");

		//�����d�����Ԃ�0�Ȃ�false��
		if (m_landing_action_count == 0.0) m_is_landing_action_now = false;
	}
}

void CCharacterPlayer::ReserveAttacking()
{
	if (m_attack_reserve_count > 0.0) {
		m_attack_reserve_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
		//�\��������Đ�
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
	}
}



void CCharacterPlayer::InputEvasion()
{

	int receive_input_time = PLAYER_RECEIVE_INPUT_EVASION_TIME;
	
	if(m_evasion_reserve_count > 0 || m_is_evasion == true) receive_input_time = PLAYER_RECEIVE_INPUT__EVASION_TIME_AFTER_EVASION;

	//DEBUG_PRINT("receive_input %d\n", receive_input_time);

	if (m_receive_input_evasion_time_count_r > 0) m_receive_input_evasion_time_count_r -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
	if (m_receive_input_evasion_time_count_l > 0) m_receive_input_evasion_time_count_l -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;



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


	//DEBUG_PRINT("m_is_input_evasion %d\n", m_is_input_evasion);
	if (m_is_input_evasion == true) {
		BeginEvasion();
	}


}

void CCharacterPlayer::BeginEvasion()
{
	ClearEarlyInput();
	m_is_input_evasion = true;

	if (m_attack_reserve_count > 0.0) return;

	if (m_is_down == true) return;

	//��𒆂��\�����쒆�łȂ��Ȃ�Ȃɂ����Ȃ�
	if (m_is_evasion == true && m_evasion_reserve_count <= 0) return;

	//���\�����쒆�������͂������p���Ⴄ�ꍇ�Ȃɂ����Ȃ�
	if (m_is_evasion == true && m_evasion_reserve_count > 0 && m_is_flip != m_is_input_evasion_flip) return;

	//�󒆂ɂ���Ȃ������Ȃ�
	if (m_is_landing == false) return;
	//�U������߂�
	m_is_attacking = false;
	//m_is_jumping = false;


	//DEBUG_PRINT("����J�n\n");
	m_receive_input_evasion_time_count_l = 0;
	m_receive_input_evasion_time_count_r = 0;
	m_is_evasion = true;
	m_evasion_count = PLAYER_EVASION_FRAME;
	m_is_input_evasion = false;
	m_evasion_reserve_count = 0;
	m_is_landing_action_now = false;

	m_is_flip = m_is_input_evasion_flip;

	//�������n���[�V��������h�������ꍇ�`�����[�V�����̒Z�k���s��
	if (m_anim_p->GetWillPlayAnim() == ePlayerAnimIdLand) {
		m_is_fast_evasion = true;
		m_evasion_count = PLAYER_EVASION_FRAME - (PLAYER_EVASION_ANIM_DELAY * 2);
	}

	//DEBUG_PRINT("m_is_input_evasion false\n");


	//�A�j���[�V������ݒ�
	if (m_is_fast_evasion == true) m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasionFast);
	else m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasion);
}

void CCharacterPlayer::DoingEvasion()
{
	if (m_is_evasion == false) return;


	//�\�����삪�I���Ɗ�������(���\������͉���s���Ȃ�L�����Z���ł���)

	if (m_evasion_count > 0.0) {
		m_evasion_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
	}

	if (m_evasion_reserve_count > 0.0) {
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasionReserve);
		m_evasion_reserve_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
		printf("m_evasion_reserve_count %lf\n", CFPS::GetDeltaTime() * GAME_BASE_FPS);
		if (m_evasion_reserve_count <= 0) {
			m_evasion_reserve_count = 0;
			m_is_evasion = false;
			SetInvincible(false);
			printf("���\������I��\n");
		}
	}
	else if (m_evasion_count <= 0.0) {
		m_is_fast_evasion = false;
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdEvasionReserve);
		m_evasion_reserve_count = PLAYER_EVASION_RESERVE_FRAME;
		printf("���\������J�n\n");
	}
	else {
		
		//�ړ��J�n�t���[���ɂȂ�����ړ�����
		//if (m_evasion_count <= PLAYER_EVASION_FRAME - PLAYER_EVASION_MOVE_START_FRAME && m_evasion_count > PLAYER_EVASION_FRAME - PLAYER_EVASION_MOVE_END_FRAME) {
		if (m_evasion_count <= PLAYER_EVASION_FRAME - PLAYER_EVASION_MOVE_START_FRAME) {
			const double moving_vec = PLAYER_EVASION_MOVE_VEC;
			//�����ɉ����Ĉړ�
			if (m_is_flip == false) {
				m_vec.x = moving_vec;
			}
			else if (m_is_flip == true) {
				m_vec.x = -moving_vec;
			}
		}

		//DEBUG_PRINT("��� %d\n", m_evasion_count);
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


	if (m_down_count <= 0) {
		m_is_down  = false;
		//�Q�[���I�[�o�[�Ăяo���ƃQ�[���V�[���I�u�W�F�N�g�̍폜
		SetIsDelete();
	}
}


void CCharacterPlayer::Attacking()
{
	if (m_is_attacking == false) return;
	m_attacking_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;



	bool is_keep_finish_attack = false;
	//�󒆂ɂ��ĂȂ����t�B�j�b�V���U���Ȃ璅�n����܂ł͍U��������p��������
	if (m_is_landing == false && m_attack_combo_count == 2) {
		is_keep_finish_attack = true;
		//printf("is_keeep!\n");
	}



	if (m_attacking_count < 0 && is_keep_finish_attack == false) {

		for (int i = 0; i < m_memory_hit_attacked_enemy_num; i++) {
			m_memory_hit_attacked_enemy_p[i] = nullptr;
		}
		m_memory_hit_attacked_enemy_num = 0;
		printf("�������[���Z�b�g\n");

		m_is_attacking = false;

		m_attack_reserve_count = PLAYER_ATTACK_RESERVE_ANIM_FRAME;
		printf("�\������Đ�\n");
		//�\��������Đ�
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
		return;
	}
	else if (m_attacking_count <= m_attack_total_frame - m_attack_hit_frame_start && m_attacking_count > m_attack_total_frame - m_attack_hit_frame_end 
		|| is_keep_finish_attack == true && m_attacking_count <= m_attack_total_frame - m_attack_hit_frame_start) {
		//�U������𔭐�������B
		//printf("�U�����蒆\n");

		//���[�J���ϐ���`
		register const CVector3D& player_pos = GetPos();//�v���C���[�̈ʒu
		
		register CVector3D length;//�����x�N�g��(�ʒu�̍�)���v�Z
		register CVector3D length_abs;//��΋���
		register const CVector3D& attack_length = m_attack_length; //�U���͈�

		//��������Ă���S�ẴG�l�~�[�̃|�C���^���擾
		Task** enemy_array = TaskManager::GetInstance()->FindTaskArray(eTaskIdEnemy);

		//�J�E���^
		register int i = 0;

		//�G�̃|�C���^�擾�p
		register CCharacter* enemy_p;

		while (true) {
			if (enemy_array[i] == nullptr) {
				break;
			}

			enemy_p = dynamic_cast<CCharacter*>(enemy_array[i]);
			if (enemy_p == nullptr) {
				i++;
				continue;
			}

			//�ʒu�֌W���擾

			//�G�̃|�W�V�������擾
			register const CVector3D& enemy_pos = enemy_p->GetPos();//�G�̈ʒu
			


			//�����x�N�g��(�ʒu�̍�)���v�Z
			length = enemy_pos - player_pos;

			//��΋������v�Z
			length_abs.x = abs(length.x);
			length_abs.y = abs(length.y);
			length_abs.z = abs(length.z);
			
			//�G�������ɂ��Ď�����������
			//�������͓G���E���ɂ��āA�������E�����Ȃ�
			if (length.x <= 0.0f && m_is_flip == true
				|| length.x >= 0.0f && m_is_flip == false) {
				//DEBUG_PRINT("length.x %lf length.y %lf length.z %lf \n", length.x, length.y, length.z);


				//�U���͈͓��ɓG������Ȃ�
				if (length_abs.x <= attack_length.x&& length_abs.y <= attack_length.y&&length_abs.z <= attack_length.z) {
					
					
					register bool is_aready_hit = false;
					//�������Ă���̂ōU�����肪���ɂ���Ă���I�u�W�F�N�g���ǂ����`�F�b�N
					for (int i = 0; i < m_memory_hit_attacked_enemy_num; i++) {
						if (m_memory_hit_attacked_enemy_p[i] == enemy_p) {
							is_aready_hit = true;
							break;
						}
					}


					//�܂��U���𓖂����������ɂȂ��ĂȂ��Ȃ�U��������s��
					if (is_aready_hit == false) {
						enemy_p->ReceiveAttack();
						*enemy_p->GetHitPointPointer() -= PLAYER_ATTACK_POWER;
						m_memory_hit_attacked_enemy_p[m_memory_hit_attacked_enemy_num++] = enemy_p;
					}
				}

			}

			i++;
		}
		free(enemy_array);
		
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
	


}

void CCharacterPlayer::Jumping()
{
	
	//�W�����v�Ŏg����̂͏㏸���̃A�j���[�V�������炢���B

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
	if (m_is_landing == false && m_is_jumping == false) {
		m_anim_p->SetWillPlayAnim(ePlayerAnimIdFall);
	}
}

void CCharacterPlayer::Move()
{
	//MovePos();
	//m_pos_old = m_pos; //�e�N���X�ōs���Ă�̂ŕK�v�Ȃ��Ȃ����͂� �����͕ς��Ȃ��͂������c�c
	//m_pos += m_vec;
	//�ړ��@�\�́A�e�N���X�ňړ��͒�`���ꂽ
}

void CCharacterPlayer::CharacterOutHitPoint()
{
	if (m_is_down == true) return;
	m_after_damage_invincible_count = 0;
	SetIsBlindDraw(false);
	m_is_down = true;
	m_down_count = PLAYER_DOWN_FRAME;
	m_anim_p->SetWillPlayAnim(ePlayerAnimIdDown);
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
	//��ʏ�̍��W

	const CVector2D& scroll_pos = GetScroll();
	CVector2D calc_scroll_pos = scroll_pos;

	register const float offset_x = - 120.0f;
	register const float offset_y = -200.0f;

	//�X�N���[�����E�l��ݒ�
	register const double max_x = CGameScene::GetInstance()->GetGameSceneLimitPosMax().x - 1280.0f;

	//�L�����`��ʒu
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
	//�_�E�����Ă���Ȃ牽�����Ȃ�
	if (m_is_down == true) return;
	//���G�Ȃ�Ȃɂ����Ȃ�
	if (GetInvincible() == true) return;

	m_anim_p->SetWillPlayAnim(ePlayerAnimIdDamage);
	m_damage_anim_count = PLAYER_DAMAGE_ANIM_FRAME;
	

	//���G���ԓ_��
	SetIsBlindDraw(true);
	m_after_damage_invincible_count = PLAYER_AFTER_DAMAGE_INVINCIBLE;
}

CCharacterPlayer * CCharacterPlayer::GetInstance()
{
	return s_instance_p;
}
