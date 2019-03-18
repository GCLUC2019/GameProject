#include "CCharacterBoss.h"
#include "CCharacterPlayer.h"
#include "CAnimation.h"



CCharacterBoss::CCharacterBoss():CCharacter(eTaskIdEnemy,0)
{
	m_player_p  = dynamic_cast<CCharacterPlayer*>(TaskManager::GetInstance()->FindTask(eTaskIdPlayer));

	DefalutSet();
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
	MoveLimit();
	printf("State:%d\n", m_boss_state);
}

void CCharacterBoss::CharacterDraw()
{
	printf("x:%f y:%f", m_pos.x, m_pos.y);
}

void CCharacterBoss::LoadAnimImage()
{
	m_anim_p->ReadAnimDataFile("BossDog/DOG_ANIM_DATA.anim");
}

void CCharacterBoss::ChangeFlip()
{
	//プレイヤーがいる方を向く
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

	if (m_boss_state == eEnemyBossStateAway) {
		s_boss_mode.boss_away += CFPS::GetDeltaTime() * GAME_BASE_FPS;
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
		if (abs(m_player_pos.x - m_pos.x) >= PLAYER_DIST＿FAR)
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

}

void CCharacterBoss::ChengeStateIdleOrAway()
{
	//攻撃が当たると、逃げ状態に遷移
	if (m_is_hit == true)m_boss_state = eEnemyBossStateAway;
	//当たらなかったら、待機状態に戻る
	else if (m_is_hit == false) m_boss_state = eEnemyBossStateIdle;
}

void CCharacterBoss::ChangeAttackState(int _state, int attack_time)
{
	m_anim_p->SetWillPlayAnim(_state);
	m_attack_complete = attack_time;
}

void CCharacterBoss::Idle()
{
	//待機状態：その場で動かない
	if (m_boss_state != eEnemyBossStateIdle) {
		return;
	}
		
	m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdIdle);
	m_vec.x = 0;
	m_vec.z = 0;
	m_is_attack = true;
	m_is_hit = false;
	m_away_flg = false;
}

void CCharacterBoss::Run()
{
	//走り状態：走ってプレイヤーに近づく
	if (m_boss_state != eEnemyBossStateRun) {
		return;
	}

	m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdRun);
	CloseToPlayer();
}

void CCharacterBoss::Walk()
{
	//歩行状態；歩いてプレイヤーに近づく
	if (m_boss_state != eEnemyBossStateWalk) {
		return;
	}

	m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdWalk);
	CloseToPlayer();
}

void CCharacterBoss::Away()
{
	//逃げ状態：攻撃を当てるとこの状態に遷移
	//ボスの後方に跳ぶ
	if (m_boss_state != eEnemyBossStateAway)return;

	m_anim_p->SetWillPlayAnim(eEnemyAnimBossIdJump);

	if (m_away_flg == false) {
		m_vec.y -= JUMP_POWER;
		m_away_flg = true;
	}

	if (m_is_flip == true)
		m_vec.x += JUMP_POWER_X;
	if (m_is_flip == false)
		m_vec.x -= JUMP_POWER_X;

	if (abs(m_player_pos.x - m_pos.x) >= AWAY_DIST)
		m_boss_state = eEnemyBossStateIdle;
}

void CCharacterBoss::CloseToPlayer()
{
	//プレイヤーに近づく処理（走っているか、歩いているかで速度が違う）
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
	//直前の状態が歩行状態なら、ひっかき攻撃
	if (m_befor_state != eEnemyBossStateWalk)return;
	if (m_is_attack == false)return;

	ChangeAttackState(eEnemyAnimBossIdBite, BITE_TIME);
	
	if (float length = CheckAttackRange() <= ATTACK1_RANGE_BITE) {
		m_is_attack = false;
		m_player_p->ReceiveAttack();
		m_player_p->HitPointGainValue(-1.0);
		m_is_hit = true;
	}

}

void CCharacterBoss::Attack2()
{
	//直前の状態が走り状態なら咆哮
	if (m_befor_state != eEnemyBossStateRun)return;

	ChangeAttackState(eEnemyAnimBossIdBark, BARK_TIME);

	if (float length= CheckAttackRange() <= ATTACK1_RANGE_BARK) {
		m_is_attack = false;
		m_player_p->ReceiveAttack();
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
	s_boss_mode.boss_attack += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	printf("attack:%f comp:%f\n", s_boss_mode.boss_idle, m_attack_complete);

	if (s_boss_mode.boss_attack >= m_attack_complete) {
		s_boss_mode.boss_attack = 0;
		ChengeStateIdleOrAway();
	}
}



void CCharacterBoss::MoveLimit()
{
	CheckDist();
	m_vec.x *= FLICTION;
	m_vec.x = min(max(m_vec.x, -MAX_SPEED), MAX_SPEED);

	//とりあえずテスト用なので
	/*if (m_pos.x <= 0) m_pos.x = 0;
	if (m_pos.z <= 430.0f) m_pos.z = 430.0f;
	if (m_pos.x >= 1020.0f) m_pos.x = 1020.0f;*/
}

void CCharacterBoss::CheckDist()
{
	if (m_boss_state == eEnemyBossStateAway)return;

	ChangeDist();

	//攻撃範囲に近づきが完了すると、攻撃状態に
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
	m_hit_point -= 1.0;
	if (m_hit_point < 0)SetIsDelete();
}

void CCharacterBoss::DefalutSet()
{
	m_vec = DEF_BOSS_VEC;
	//初期値のy軸は地面に埋まらないように少し浮かせる
	m_pos = DEF_BOSS_POS;

	m_rads = CVector3D(75, 120, 10);
	SetSize(BOSS_SIZE);
	m_is_flip = false;

	m_hit_point = BOSS_HP;
	m_hit_point_max = BOSS_HP;

	LoadAnimImage();

	m_anim_p->SetAnim(eEnemyAnimBossIdIdle);
	SetIsShowShadow(true);
	SetShadowSize(BOSS_SHADOW_SIZE);
	SetDrawAdjPos(CVector2D(-30.0, -90.0));
}

void CCharacterBoss::CharacterBeforeCollisionCheck()
{
	
}
