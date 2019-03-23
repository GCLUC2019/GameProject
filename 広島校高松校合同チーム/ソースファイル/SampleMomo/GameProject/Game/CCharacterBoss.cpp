#include "CCharacterBoss.h"
#include "CCharacterPlayer.h"
#include "CAnimation.h"
#include "CGameScene.h"
#include "CDamageEffect.h"

static CCharacterBoss* s_instance_p = nullptr;

CCharacterBoss::CCharacterBoss():CCharacter(eTaskIdEnemy,0)
{
	s_instance_p = this;
	//m_player_p  = dynamic_cast<CCharacterPlayer*>(TaskManager::GetInstance()->FindTask(eTaskIdPlayer));
	m_player_p = CCharacterPlayer::GetInstance();

	//�e�p�����[�^��������
	DefalutSet();

	m_knock_back_count = BOSS_KNOCK_BACK_FRAME;
}

CCharacterBoss::~CCharacterBoss()
{
	if (s_instance_p == this) {
		s_instance_p = nullptr;
	}
}

void CCharacterBoss::CharacterUpdate()
{
	if (m_is_knock_back == true) {
		DoingKnockBack();
		return;
	}

	m_player_pos = m_player_p->GetPos();
	
	ChangeFlip();
	ModeCount();
	ChangeState();
	Idle();
	Walk();
	Run();
	Away();
	Damage();
	AttackHub();
	MoveLimit();
	AdjAnim();
	//printf("State:%d\n", m_boss_state);
}

void CCharacterBoss::CharacterDraw()
{
	//printf("x:%f y:%f", m_pos.x, m_pos.y);
}

void CCharacterBoss::LoadAnimImage()
{
	m_anim_p->ReadAnimDataFile("BossDog/DOG_ANIM_DATA.anim");
}

void CCharacterBoss::ChangeFlip()
{
	//�v���C���[�������������
	if (m_player_pos.x > m_pos.x + RANGE)
		m_is_flip = false;
	//�K�E�Z�������͒ʂ�߂��Ă��U������Ȃ�
	if (m_player_pos.x < m_pos.x - RANGE && m_ex_attack_state != eExRashStep3)
		m_is_flip = true;
}

void CCharacterBoss::ModeCount()
{
	//�e��Ԃ��������Ă��鎞�Ԃ��L�^����
	if (m_boss_state == eEnemyBossStateIdle) {
		s_boss_mode.boss_idle += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}

	if (m_boss_state == eEnemyBossStateWalk) {
		s_boss_mode.boss_walk += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}

	if (m_boss_state == eEnemyBossStateRun) {
		s_boss_mode.boss_run += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}

	if (m_boss_state == eEnemyBossStateAway) {
		s_boss_mode.boss_away += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}

	if (m_ex_state == eEnemyBossStateRush) {
		s_boss_mode.boss_rush += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}

	if (m_ex_state == eEnemyBossStateDamage) {
		s_boss_mode.boss_damage += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}
}

void CCharacterBoss::ChangeDist()
{
	//�U�����J�n���鋗���̕ύX
	if (m_boss_state == eEnemyBossStateWalk)
		m_just_dist = NEXT_JUST_DIST2;
	else if (m_boss_state == eEnemyBossStateRun)
		m_just_dist = NEXT_JUST_DIST1;
}

void CCharacterBoss::ChangeState()
{
	//�o�߂������Ԃɂ���āA����̏�Ԃ�ς���
	if (s_boss_mode.boss_idle >= IDLE_LIMIT) {
		if (abs(m_player_pos.x - m_pos.x) >= PLAYER_DIST�QFAR)
			m_boss_state = eEnemyBossStateRun;
		else
			m_boss_state = eEnemyBossStateWalk;
		s_boss_mode.boss_idle = 0;
	}

	if (s_boss_mode.boss_walk >= WALK_LIMIT) {
		m_befor_state = m_boss_state;
		m_boss_state = eEnemyBossStateAttack;
		s_boss_mode.boss_walk = 0;
	}

	if (s_boss_mode.boss_run >= RUN_LIMIT) {
		m_befor_state = m_boss_state;
		m_boss_state = eEnemyBossStateAttack;
		s_boss_mode.boss_run = 0;
	}

	if (s_boss_mode.boss_away >= AWAY_LIMIT) {
		m_boss_state = eEnemyBossStateIdle;
		s_boss_mode.boss_away = 0;
	}

	if (s_boss_mode.boss_damage >= DAMAGE_LIMIT) {
		m_ex_state = 0;
		SetIsBlindDraw(false);
		s_boss_mode.boss_damage = 0;
	}

	if (m_ex_count == 5) {
		m_ex_state = eEnemyBossStateRush;
		m_ex_count = 0;
	}

	if (m_hit_count == 5) {
		m_boss_state = eEnemyBossStateAttack;
		m_hit_count = 0;
	}

}

void CCharacterBoss::ChengeStateIdleOrAway()
{
	//�U����������ƁA������ԂɑJ��
	if (m_is_hit == true)m_boss_state = eEnemyBossStateAway;
	//������Ȃ�������A�ҋ@��Ԃɖ߂�
	else if (m_is_hit == false) m_boss_state = eEnemyBossStateIdle;
}

void CCharacterBoss::ChangeAttackState(int _state, int attack_time)
{
	//�U���A�j���[�V�����ƁA�U���A�j���[�V�������������鎞�Ԃ�ύX������
	m_anim_p->SetWillPlayAnim(_state);
	m_attack_complete = attack_time;
}

void CCharacterBoss::Idle()
{
	//�ҋ@��ԁF���̏�œ����Ȃ�
	if (m_boss_state != eEnemyBossStateIdle) {
		return;
	}
		
	m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdIdle);
	
	m_vec.x = 0;
	m_vec.z = 0;

	m_is_attack = true;
	m_is_hit = false;
}

void CCharacterBoss::Run()
{
	//�����ԁF�����ăv���C���[�ɋ߂Â�
	if (m_boss_state != eEnemyBossStateRun) {
		return;
	}

	m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdRun);
	CloseToPlayer();
}

void CCharacterBoss::Walk()
{
	//���s��ԁG�����ăv���C���[�ɋ߂Â�
	if (m_boss_state != eEnemyBossStateWalk) {
		return;
	}

	m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdWalk);
	CloseToPlayer();
}

void CCharacterBoss::Away()
{
	//������ԁF�U���𓖂Ă�Ƃ��̏�ԂɑJ��
	//�{�X�̌���ɒ���
	if (m_boss_state != eEnemyBossStateAway)return;

	m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdJump);

	if (m_away_flg == false) {
	/*	m_vec.y -= JUMP_POWER;*/
		m_away_flg = true;
	}

	if (m_is_flip == true)
		m_vec.x += JUMP_POWER_X;
	if (m_is_flip == false)
		m_vec.x -= JUMP_POWER_X;

	if (abs(m_player_pos.x - m_pos.x) >= AWAY_DIST) {
		m_boss_state = eEnemyBossStateIdle;
		m_away_flg = false;
	}
}

void CCharacterBoss::CloseToPlayer()
{
	//�v���C���[�ɋ߂Â������i�����Ă��邩�A�����Ă��邩�ő��x���Ⴄ�j
	float Speed = DEF_SPEED;
	if(m_boss_state==eEnemyBossStateRun) 
		Speed = RUN_SPEED;

	CVector3D vec = m_player_pos - m_pos;
	float ang = atan2(vec.x, vec.z);
	CVector2D dir = CVector2D(sin(ang), cos(ang));

	m_vec = CVector3D(dir.x*Speed, 0, dir.y*Speed);
}

void CCharacterBoss::Attack1()
{
	//���O�̏�Ԃ����s��ԂȂ�A�Ђ������U��
	if (m_befor_state != eEnemyBossStateWalk)return;
	if (m_ex_state == eEnemyBossStateRush)return;
	if (m_is_attack == false)return;

	ChangeAttackState(eEnemyAnimBossIdBite, BITE_TIME);
	
	//�v���C���[���͈͓��ɂ���ƃ_���[�W��^����
	if (float length = CheckAttackRange() <= ATTACK1_RANGE_BITE) {
		m_is_attack = false;
		m_player_p->HitPointGainValue(-ATTACK);
		m_player_p->ReceiveKnockBack(m_pos, 5.0);
		m_player_p->ReceiveAttack();

		//�U����������ƁA�J�E���g����
		m_ex_count++;
		m_is_hit = true;
	}

}

void CCharacterBoss::Attack2()
{
	//���O�̏�Ԃ������ԂȂ���K
	if (m_befor_state != eEnemyBossStateRun)return;
	if (m_ex_state == eEnemyBossStateRush)return;
	if (m_is_attack == false)return;

	ChangeAttackState(eEnemyAnimBossIdBark, BARK_TIME);


	//�v���C���[���͈͓��ɂ���ƁA�Ђ�܂���
	if (float length= CheckAttackRange() <= ATTACK1_RANGE_BARK) {
		m_is_attack = false;
		m_player_p->SetFreeze(BARK_FREEZE_TIME);

		//�U����������ƁA�J�E���g����
		m_ex_count++;
		m_is_hit = true;
	}
}

void CCharacterBoss::SpecialAttack1()
{
	if (m_ex_state != eEnemyBossStateRush)return;


	//�X�e�b�v���Ƃɏ������Ⴄ
	switch (m_ex_attack_state)
	{
	//���i�K�F��Ɍ������Ē��􂷂�
	case eExStepStart:
		ChangeAttackState(eEnemyAnimBossIdJump, RASH_TIME);
		m_vec.y -= RASH_JIMP_POWER;
		m_ex_attack_state = eExRashStep1;
		break;
	//���i�K�F��ʍ��[�Ɉړ�����
	case eExRashStep1:
		if (s_boss_mode.boss_rush <= RASH_STEP1_TIME) {
			m_pos.x = -10.0;
			m_ex_attack_state = eExRashStep2;
		}
		break;
	//��O�i�K�F�����W�����肷��
	case eExRashStep2:
		if (s_boss_mode.boss_rush <= RASH_STEP2_TIME) {
			m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdRun);
			if (m_pos.z > m_player_pos.z + RANGE_Z)m_vec.z -= RASH_Z_SPEED;
			if (m_pos.z < m_player_pos.z - RANGE_Z)m_vec.z += RASH_Z_SPEED;
			//printf("attack:%f ex:%f\n", s_boss_mode.boss_attack, s_boss_mode.boss_rush);
		}
		else if (s_boss_mode.boss_rush > RASH_STEP2_TIME) {
			m_ex_attack_state = eExRashStep3;
		}
		break;
	//��l�i�K�F�v���C���[�Ɍ������ēːi����
	case eExRashStep3:
		if (s_boss_mode.boss_rush < RASH_STEP3_TIME) {
			m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdRush);
			m_pos.x += RASH_SPEED;
			//if (float length = CheckAttackRange() <= EX1_RANGE_RASH && m_is_attack == true  ) {
			if (float length = CheckAttackRange() <= EX1_RANGE_RASH) {
				m_is_attack = false;
				m_player_p->HitPointGainValue(-RASH_ATTACK);
				m_player_p->ReceiveKnockBack(m_pos, 5.0);
				m_player_p->ReceiveAttack();
			}
		}
		else if (s_boss_mode.boss_rush > RASH_STEP3_TIME) {
			m_ex_attack_state = eExRashStep4;
		}
		break;
	//��ܒi�K�G�ːi�I����A�����l�ɖ߂�
	case eExRashStep4:
		s_boss_mode.boss_rush = 0;
		m_is_hit = true;
		m_ex_state = 0;
		m_ex_attack_state = eExStepStart;
		break;
	default:
		break;
	}
}

void CCharacterBoss::AttackHub()
{
	if (m_boss_state != eEnemyBossStateAttack) {
		return;
	}


	Attack1();
	Attack2();
	SpecialAttack1();
	s_boss_mode.boss_attack += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	printf("attack:%f comp:%f\n", s_boss_mode.boss_attack, m_attack_complete);

	//�U���̓��삪�I���ƁA�ҋ@�������Ɉڍs����
	if (s_boss_mode.boss_attack >= m_attack_complete) {
		s_boss_mode.boss_attack = 0;
		ChengeStateIdleOrAway();
	}
}

void CCharacterBoss::Damage()
{
	if (m_ex_state != eEnemyBossStateDamage)return;

	if ((int)m_hit_point % 6 == 0)m_boss_state = eEnemyBossStateAway;
}



void CCharacterBoss::MoveLimit()
{
	CheckDist();
	m_vec.x *= FLICTION;
	m_vec.z *= FLICTION;
	m_vec.x = min(max(m_vec.x, -MAX_SPEED), MAX_SPEED);
	m_vec.z = min(max(m_vec.z, -MAX_SPEED), MAX_SPEED);

	//�Ƃ肠�����e�X�g�p�Ȃ̂�
	if (m_ex_state != eEnemyBossStateRush) {
		if (m_player_pos.x<m_pos.x - 1000) m_pos.x = m_player_pos.x + 900;
		if (m_player_pos.x>m_pos.x + 1000) m_pos.x == m_player_pos.x - 100;
	}

}

void CCharacterBoss::CheckDist()
{
	if (m_boss_state == eEnemyBossStateAway)return;
	
	if (m_ex_state == eEnemyBossStateRush) {
		m_boss_state = eEnemyBossStateAttack;
		return;
	}

	ChangeDist();

	//�U���͈͂ɋ߂Â�����������ƁA�U����Ԃ�
	if (abs(m_player_pos.x - m_pos.x) <= m_just_dist) {
		m_vec.x = 0;
		if (abs(m_player_pos.z - m_pos.z) <= JUST_DIST_Z) {
			m_vec.z = 0;
			m_befor_state = m_boss_state;
			m_boss_state = eEnemyBossStateAttack;
		}
	}
}

float CCharacterBoss::CheckAttackRange()
{
	CVector3D target_vec = m_player_pos - m_pos;
	float target_length = sqrt(target_vec.x * target_vec.x + target_vec.y * target_vec.y + target_vec.z * target_vec.z);
	return target_length;
}

void CCharacterBoss::ReceiveAttack()
{
	//���G�Ȃ�Ȃɂ����Ȃ�
	if (GetInvincible() == true) return;
	m_ex_state = eEnemyBossStateDamage;
	SetIsBlindDraw(true);
	m_hit_count++;
	CSound::GetInstance()->GetSound("SE_Damage")->Play();
	CGameScene::GetInstance()->AddGameSceneObject(new CDamageEffect(&m_pos, CVector2D(-200, -210), CVector2D(500, 500), 30));

}

void CCharacterBoss::DefalutSet()
{
	m_vec = DEF_BOSS_VEC;
	//�����l��y���͒n�ʂɖ��܂�Ȃ��悤�ɏ�����������
	m_pos = DEF_BOSS_POS;
	m_pos_old = m_pos;

	//��щz����Ȃ����炢�̍����ɂ͂��Ă���
	m_rads = CVector3D(75, 300, 10);
	
	m_is_flip = false;

	m_hit_point = BOSS_HP;
	m_hit_point_max = BOSS_HP;

	LoadAnimImage();

	m_anim_p->SetAnim(eEnemyAnimBossIdIdle);
	SetIsShowShadow(true);

	/*
	SetSize(BOSS_SIZE);
	SetShadowSize(BOSS_SHADOW_SIZE);
	SetDrawAdjPos(CVector2D(-30.0, -90.0));
	*/
}

void CCharacterBoss::ReceiveKnockBack(CVector3D _from_pos, double _power)
{
	if (m_is_knock_back == true) return;
	if (m_is_invincible == true) return;

	SetKnockBack(_from_pos, _power);
}

void CCharacterBoss::AdjAnim()
{
	switch (m_anim_p->GetWillPlayAnim()) {
	case eEnemyAnimBossIdJump:
		SetSize(400,650);
		SetShadowSize(BOSS_SHADOW_SIZE);
		SetDrawAdjPos(CVector2D(-20.0, -15.0 - 125 + 140));
		break;
	default:
		SetSize(400, 400);
		SetShadowSize(BOSS_SHADOW_SIZE);
		SetDrawAdjPos(CVector2D(-20.0, -15.0 + 140));
		break;
	}
}

void CCharacterBoss::CharacterBeforeCollisionCheck()
{
	
}

void CCharacterBoss::CharacterOutHitPoint()
{
	CGameScene::GetInstance()->StageClear();
}

CCharacterBoss * CCharacterBoss::GetInstance()
{
	return s_instance_p;
}
