#include "CCharacterBoss.h"
#include "CCharacterPlayer.h"
#include "CAnimation.h"



CCharacterBoss::CCharacterBoss():CCharacter(eTaskIdEnemy,0)
{
	/*
	ADD_RESOURCE("Idle1", CImage::LoadImage("DogIdle1.png"));
	ADD_RESOURCE("Idle2", CImage::LoadImage("DogIdle2.png"));
	ADD_RESOURCE("Run1", CImage::LoadImage("DogRun1.png"));
	ADD_RESOURCE("Run2", CImage::LoadImage("DogRun2.png"));
	ADD_RESOURCE("Run3", CImage::LoadImage("DogRun3.png"));
	ADD_RESOURCE("Run4", CImage::LoadImage("DogRun4.png"));
	ADD_RESOURCE("Run5", CImage::LoadImage("DogRun5.png"));
	ADD_RESOURCE("Run6", CImage::LoadImage("DogRun6.png"));
	ADD_RESOURCE("Run7", CImage::LoadImage("DogRun7.png"));
	ADD_RESOURCE("Run8", CImage::LoadImage("DogRun8.png"));
	*/

	m_player_p  = dynamic_cast<CCharacterPlayer*>(TaskManager::GetInstance()->FindTask(eTaskIdPlayer));

	m_vec = CVector3D(0, 0, 0);
	//�����l��y���͒n�ʂɖ��܂�Ȃ��悤�ɏ�����������
	m_pos = CVector3D(1000, -160, 500);  

	m_rads = CVector3D(75, 120, 10);
	SetSize(500, 500);
	m_is_flip = false;

	LoadAnimImage();

	m_anim_p->SetAnim(eEnemyAnimBossIdIdle);
	SetIsShowShadow(true);
	SetShadowSize(CVector2D(300, 50));
	SetDrawAdjPos(CVector2D(-30.0, -90.0));
}

CCharacterBoss::~CCharacterBoss()
{
}

void CCharacterBoss::CharacterUpdate()
{
	m_player_pos = m_player_p->GetPos();
	ChangeFlip();
	ModeCount();
	ChangeState();
	Idle();
	Walk();
	Run();
	Away();
	AttackHub();
	CheckDist();
	//Move();
	//Gravity();
}

void CCharacterBoss::CharacterDraw()
{
	printf("x:%f y:%f", m_pos.x, m_pos.y);
}

void CCharacterBoss::LoadAnimImage()
{
	
	/*
	//�ҋ@�A�j���[�V�����̓ǂݍ���
	m_anim_image_p[eEnemyAnimBossIdle1] = GET_RESOURCE("Idle1", CImage*);
	m_anim_image_p[eEnemyAnimBossIdle2] = GET_RESOURCE("Idle2", CImage*);

	//����A�j���[�V�����̓ǂݍ���
	m_anim_image_p[eEnemyAnimBossRun1] = GET_RESOURCE("Run1", CImage*);
	m_anim_image_p[eEnemyAnimBossRun2] = GET_RESOURCE("Run2", CImage*);
	m_anim_image_p[eEnemyAnimBossRun3] = GET_RESOURCE("Run3", CImage*);
	m_anim_image_p[eEnemyAnimBossRun4] = GET_RESOURCE("Run4", CImage*);
	m_anim_image_p[eEnemyAnimBossRun5] = GET_RESOURCE("Run5", CImage*);
	m_anim_image_p[eEnemyAnimBossRun6] = GET_RESOURCE("Run6", CImage*);
	m_anim_image_p[eEnemyAnimBossRun7] = GET_RESOURCE("Run7", CImage*);
	m_anim_image_p[eEnemyAnimBossRun8] = GET_RESOURCE("Run8", CImage*);

	//�A�j���[�V�����f�[�^�̐ݒ�
	m_anim_info[eEnemyAnimBossIdIdle].image_num = 2;
	m_anim_info[eEnemyAnimBossIdIdle].image_id = eEnemyAnimBossIdle1;
	m_anim_info[eEnemyAnimBossIdIdle].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[eEnemyAnimBossIdRun].image_num = 8;
	m_anim_info[eEnemyAnimBossIdRun].image_id = eEnemyAnimBossRun1;
	m_anim_info[eEnemyAnimBossIdRun].delay = DEFAULT_ANIM_DELAY;
	*/

	m_anim_p->ReadAnimDataFile("BossDog/DOG_ANIM_DATA.anim");
}

void CCharacterBoss::ChangeFlip()
{
	//�v���C���[�������������
	if (m_player_pos.x > m_pos.x + RANGE)m_is_flip = false;
	if (m_player_pos.x < m_pos.x - RANGE) m_is_flip = true;
}

void CCharacterBoss::ModeCount()
{
	if (m_boss_state == eEnemyBossStateIdle) {
		s_boss_mode.boss_idle += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}

	if (m_boss_state == eEnemyBossStateWalk) {
		s_boss_mode.boss_walk += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}

	if (m_boss_state == eEnemyBossStateRun) {
		s_boss_mode.boss_run += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}
}

void CCharacterBoss::ChangeDist()
{
	if (m_boss_state == eEnemyBossStateWalk)
		m_just_dist = NEXT_JUST_DIST2;
	else if (m_boss_state == eEnemyBossStateRun)
		m_just_dist = NEXT_JUST_DIST1;
}

void CCharacterBoss::ChangeState()
{
	if (s_boss_mode.boss_idle >= IDLE_LIMIT) {
		if (abs(m_player_pos.x - m_pos.x) >= PLAYER_DIST�QFAR)
			m_boss_state = eEnemyBossStateRun;
		else
			m_boss_state = eEnemyBossStateWalk;
		s_boss_mode.boss_idle = 0;
	}

	if (s_boss_mode.boss_walk >= WALK_LIMIT) {
		m_boss_state = eEnemyBossStateIdle;
		s_boss_mode.boss_walk = 0;
	}

	if (s_boss_mode.boss_run >= RUN_LIMIT) {
		m_boss_state = eEnemyBossStateIdle;
		s_boss_mode.boss_run = 0;
	}

}

void CCharacterBoss::Idle()
{
	//�ҋ@��ԁF���̏�œ����Ȃ�
	if (m_boss_state != eEnemyBossStateIdle) {
		return;
	}
		
	m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdIdle);
	m_vec = CVector3D(0, 0, 0);
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

	/*m_vec.y -= 50;*/
	if (m_is_flip == true)
		m_vec.x += 5;
	if (m_is_flip == false)
		m_vec.x -=5;

	if (abs(m_player_pos.x - m_pos.x) >= AWAY_DIST)m_boss_state = eEnemyBossStateIdle;
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



	if (abs(m_player_pos.x - m_pos.x) <= 300 && abs(m_player_pos.z - m_pos.z) <= 100 && m_is_attack) {
		m_is_attack = false;
		m_player_p->HitPointGainValue(-1.0);
		m_is_hit = true;
	}

}

void CCharacterBoss::Attack2()
{
	//���O�̏�Ԃ������ԂȂ���K
	if (m_befor_state != eEnemyBossStateRun)return;

	m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdBark);

	if (abs(m_player_pos.x - m_pos.x) <= 400 && abs(m_player_pos.z - m_pos.z) <= 300 && m_is_attack) {
		m_is_attack = false;
		m_player_p->HitPointGainValue(-4.0);
		m_is_hit = true;
	}
}

void CCharacterBoss::AttackHub()
{
	if (m_boss_state != eEnemyBossStateAttack) {
		return;
	}

	
	Attack1();
	Attack2();

	//�U����������ƁA������ԂɑJ��
	if(m_is_hit==true)m_boss_state = eEnemyBossStateAway;
	//������Ȃ�������A�ҋ@��Ԃɖ߂�
	else m_boss_state = eEnemyBossStateIdle;
}

void CCharacterBoss::Move()
{
	CheckDist();
	m_pos += m_vec*0.7;
	MoveLimit();
}

void CCharacterBoss::MoveLimit()
{
	//�Ƃ肠�����e�X�g�p�Ȃ̂�
	/*if (m_pos.x <= 0) m_pos.x = 0;
	if (m_pos.z <= 430.0f) m_pos.z = 430.0f;
	if (m_pos.x >= 1020.0f) m_pos.x = 1020.0f;*/
}

void CCharacterBoss::CheckDist()
{
	if (m_boss_state == eEnemyBossStateAway)return;

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

void CCharacterBoss::CharacterBeforeCollisionCheck()
{
	
}
