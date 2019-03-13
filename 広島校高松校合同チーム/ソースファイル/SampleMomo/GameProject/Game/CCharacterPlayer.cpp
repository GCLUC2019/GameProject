#include "CCharacterPlayer.h"
#include "../Global.h"

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


	//�̗͂̐ݒ�
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

	//�A�j���[�V�����f�[�^�̐ݒ�
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


}

void CCharacterPlayer::InputDash()
{
	if (CInput::GetState(0, CInput::eHold, CInput::eButton3)) {
		m_is_dashing = true;
		m_speed = 6.0f;
		m_size = CVector2D(100, 100);
	}
}

void CCharacterPlayer::InputAttack()
{
	if (m_is_attacking == true) return;
	if (CInput::GetState(0, CInput::eHold, CInput::eButton2)) {
		printf("�U��\n");
		m_is_attacking = true;
		m_attacking_count = PLAYER_ATTACK_FRAME;
	}
}




void CCharacterPlayer::Update()
{
	//printf("x %lf y %lf z %lf\n", m_pos.x, m_pos.y, m_pos.z);
	
	//�������n���[�V���������Đ����ĂȂ��Ȃ�
	if (m_will_play_anim_id == ePlayerAnimIdLand) SetWillPlayAnim(ePlayerAnimIdLand);
	else m_will_play_anim_id = ePlayerAnimIdIdle;
	
	m_is_dashing = false;
	m_speed = PLAYER_SPEED;

	InputAttack();
	InputDash();
	InputMove();
	InputJump();


	//���W�ړ�
	Landing();
	Gravity();
	Jumping();
	Falling();
	Move();
	MoveLimit();
	
	
	Attacking();

	CalcScroll();
	AdjAnim();
}

void CCharacterPlayer::InputMove()
{
	m_vec.x = 0.0f;
	m_vec.z = 0.0f;
	
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
	if (CInput::GetState(0, CInput::eHold, CInput::eButton1) && m_is_jumping == false && m_is_landing == true) {
		SetWillPlayAnim(ePlayerAnimIdJump);
		m_is_jumping = true;
		m_jumping_count = 30;
		m_vec.y = -30.0f;
		m_is_landing = false;
	}
}

void CCharacterPlayer::Landing()
{
	if (m_is_landing == true & m_is_landing_old == false) {
		printf("���n������\n");
		SetWillPlayAnim(ePlayerAnimIdLand);
	}
}

void CCharacterPlayer::Attacking()
{
	if (m_is_attacking == false) return;
	if (m_attacking_count-- <= 0) {
		m_is_attacking = false;

		//�U������𔭐�������B

		//��������Ă���S�ẴG�l�~�[�̃|�C���^���擾
		Task** enemy_array = TaskManager::GetInstance()->FindTaskArray(eTaskIdEnemy);

		int i = 0;
		while (true) {
			if (enemy_array[i] == nullptr) break;
			CCharacter* enemy_p = dynamic_cast<CCharacter*>(enemy_array[i]);
			if (enemy_p == nullptr) {
				i++;
				continue;
			}
			//printf("�G�l�~�[�������\n");

			//�ʒu�֌W���擾
			CVector3D enemy_pos = enemy_p->GetPos();
			CVector3D player_pos = GetPos();


			//�����x�N�g��(�ʒu�̍�)���v�Z
			CVector3D length = enemy_pos - player_pos;

			//��΋������v�Z
			CVector3D length_abs;
			length_abs.x = abs(length.x);
			length_abs.y = abs(length.y);
			length_abs.z = abs(length.z);

			//�U���͈�
			CVector3D attack_length = PLAYER_ATTACK_LENGTH;

			//�G�������ɂ��Ď�����������
			//�������͓G���E���ɂ��āA�������E�����Ȃ�
			if (length.x <= 0.0f && m_is_flip == true
				|| length.x >= 0.0f && m_is_flip == false) {
				//printf("length.x %lf length.y %lf length.z %lf \n", length.x, length.y, length.z);

				//�U���͈͓��ɓG������Ȃ�
				if (length_abs.x <= attack_length.x&& length_abs.y <= attack_length.y&&length_abs.z <= attack_length.z) {
					//�������Ă���̂�
					enemy_p->ReceiveAttack();
					*enemy_p->GetHitPointPointer() -= PLAYER_ATTACK_POWER;
					printf("enemy hp %lf\n", *enemy_p->GetHitPointPointer());
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
	//�W�����v�Ŏg����̂͏㏸���̃A�j���[�V�������炢���B

	if (m_is_jumping == true) {
		if (m_is_landing == true || m_jumping_count-- <= 0) {
			m_is_jumping = false;
			//printf("�W�����v����");
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
		//printf("�t�@�[��\n");
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
	//��ʏ�̍��W
	//CVector2D screen_pos = CVector2D(m_pos.x,m_pos.z + m_pos.y);
	//sscreen_pos -= GetScroll();

	CVector2D scroll_pos = GetScroll();


	//�X�N���[���̒��ɋ���ꍇ�Ȃɂ����Ȃ�


	if (m_pos.x >= scroll_pos.x + 1280.0f) {
		SetScroll(CVector2D(m_pos.x - 1280.0f, 0));
	}
	else if (m_pos.x <= scroll_pos.x) {
		SetScroll(CVector2D(m_pos.x,0));
	}


	
	//if (scroll_pos.x > 0.0f) SetScroll(CVector2D(m_pos.x - 1280, 0));

	//������ʒ[�Ƀv���C���[������Ȃ�X�N���[������
	//SetScroll(CVector2D(m_pos.x - 100,0));
}

void CCharacterPlayer::ReceiveAttack()
{
	SetWillPlayAnim(ePlayerAnimIdDamage);
}
