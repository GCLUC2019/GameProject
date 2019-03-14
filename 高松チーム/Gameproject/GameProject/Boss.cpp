#include "Boss.h"
#include "../GameProject/Game/Character/Effect/BossEffect.h"
#include "../GameProject/Game/Character/Anim/AnimBoss.h"
#include "../GameProject/Game/Character/EnemyBase/Boss/BossManager.h"


#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

#define WIGHT_SIZE 1280
#define HEIGHT_SIZE 720

#define PIE 3.14


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////お頭クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
BossHead::BossHead(const CVector2D &player_pos, const int state) :EnemyBase(eBossHead)
{
	m_img = COPY_RESOURCE("Boss", CAnimImage*);
	m_img2 = COPY_RESOURCE("Boss", CImage*);
	m_img3 = COPY_RESOURCE("Boss", CAnimImage*);
	
	m_img.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);
	m_img2.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);
	m_img3.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);

	m_pos = CVector2D(1280 - BOSS_X_SIZE / 3, 0);
	m_pos2 = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 1.6, HEIGHT_SIZE - BOSS_Y_SIZE / 1.5);

	m_player_pos = player_pos;

	m_state = state;

	m_idle_cnt = 0;

	m_anim_flag = true;
	m_move_flag = false;
	m_draw_flag = false;
	m_idle_flag = false;
	m_approach_flag = true;

	m_anim_cnt = 0;

	m_idle_cnt = 0;

	m_state = state;

}

BossHead::~BossHead()
{
	TaskManager::GetInstance()->AddTask(new BossManager());
}

void BossHead::Idle()
{
	m_idle_flag = true;

	if (m_pos2.x >= WIGHT_SIZE / 2.2) {
		m_pos2.x -= 0.5;
	}
}

void BossHead::FireAttack()
{
	m_anim_cnt++;
	if (m_anim_flag == true) {
		TaskManager::GetInstance()->AddTask(new BossFireEffect(m_pos));
		m_anim_flag = false;
	}
	if (m_anim_cnt >= 120) {
		m_state = eUp;
	}
}
void BossHead::HeadAttack()
{
	if (m_approach_flag == true)m_pos.x += 10;
	else m_pos.x -= 20;

	if (m_pos.x >= 1280 - BOSS_X_SIZE / 4)m_approach_flag = false;

	if (m_pos.x < (1280 - BOSS_X_SIZE) / 8)
	{
		m_draw_flag = true;
		m_state = eUp;
	}
}	

void BossHead::UpMove()
{
	m_draw_flag = true;
	m_pos.y -= 5;

}

void BossHead::FireDownMove()
{
	m_pos.y += 5;
	//300はプレイヤーのY座標（仮）m_player_pos.y
	if (m_pos.y > m_player_pos.y) {
		m_state = eFireAttack;
		m_anim_flag = true;
	}
}


void BossHead::HeadDownMove()
{
	//３００=プレイヤーの座標（仮）m_player_pos.y
	if (m_pos.y <= m_player_pos.y) {
		m_pos.y += 5;
	}
	if (m_pos.y > m_player_pos.y) {
		m_state = eHeadAttack;
	}
}

void BossHead::Update()
{
	switch (m_state) {
	case eIdle:
		Idle();
	case eUp:
		UpMove();
		break;
	case eFireAttackDown:
		FireDownMove();
		break;
	case eHeadAttackDown:
		HeadDownMove();
		break;
	case eFireAttack:
		FireAttack();
		break;
	case eHeadAttack:
		HeadAttack();
		break;
	default:
		break;
	}
		m_img.ChangeAnimation(eBossFireAttackMotion,false);
		m_img.UpdateAnimation();

		m_img3.ChangeAnimation(eBossHeadAnim);
		m_img3.UpdateAnimation();

}

void BossHead::Draw()
{
	
	m_img2.SetRect(0, BOSS_Y_SIZE * 4, BOSS_X_SIZE, BOSS_Y_SIZE * 5);

	
	m_img.SetPos(m_pos - m_scroll);
	m_img2.SetPos(m_pos - m_scroll);
	m_img3.SetPos(m_pos2 - m_scroll);
	
	if (m_draw_flag == false && m_idle_flag == false)m_img.Draw();
	if(m_draw_flag == true && m_idle_flag == false)m_img2.Draw();
	if (m_idle_flag == true)m_img3.Draw();
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////お手クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

BossHand::BossHand(const int state) :EnemyBase(eBossHund)
{
	m_img = COPY_RESOURCE("Boss", CImage*);
	m_img2 = COPY_RESOURCE("Boss", CImage*);
	m_img3 = COPY_RESOURCE("Boss", CImage*);

	m_img.SetCenter(BOSS_X_SIZE / 4, BOSS_Y_SIZE / 4);

	m_img.SetSize(BOSS_X_SIZE / 3 + 300, BOSS_Y_SIZE / 3);
	m_img2.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
	m_img3.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);

	m_pos = CVector2D(1280 - BOSS_X_SIZE + 200, 0);
	m_pos2 = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 1.2, HEIGHT_SIZE - BOSS_Y_SIZE / 2.1);
	m_pos3 = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 2.4, HEIGHT_SIZE - BOSS_Y_SIZE / 1.9);

	m_center = CVector2D(m_pos2.x + m_r, m_pos2.y);
	m_center2 = CVector2D(m_pos3.x + m_r, m_pos3.y);

	m_cnt = 0;

	m_r = 25.0;
	m_rot = 0;

	m_anim_flag = true;
	m_move_flag = false;
	m_idle_flag = false;
	m_draw_flag = false;

	m_state = state;

	m_idle_cnt = 0;
}

BossHand::~BossHand()
{
	TaskManager::GetInstance()->AddTask(new BossManager());
}

void BossHand::Idle()
{
	m_idle_flag = true;

	if (m_pos2.x >= WIGHT_SIZE / 3) {
		m_center.x -= 0.5;
		m_center2.x -= 0.5;
		
	}
	m_rot += 0.05;
	if (m_rot >= PIE * 2)m_rot = 0;

	m_pos2 = m_center + CVector2D(sin(m_rot), cos(m_rot))*m_r;
	m_pos3 = m_center2 + CVector2D(cos(m_rot), sin(m_rot))*m_r;

	
}

void BossHand::Attack()
{
	m_draw_flag = true;
	m_cnt++;
	if (m_anim_flag == true) {
		TaskManager::GetInstance()->AddTask(new BossLazerEffect(m_pos));
		m_anim_flag = false;
	}
	if (m_cnt >= 120) {
		m_state = eUp;
	}
}

void BossHand::UpMove()
{
	m_pos.y -= 5;
}

void BossHand::DownMove()
{
	if (m_pos.y < (BOSS_Y_SIZE / 3) - BOSS_X_SIZE / 12 && m_move_flag == false) {
		m_pos.y += 5;
	}

	if (m_pos.y >= (BOSS_Y_SIZE / 3) - BOSS_X_SIZE / 12) {
		m_pos.y = (BOSS_Y_SIZE / 3) - BOSS_X_SIZE / 12;
		m_state = eAttack;
	}

}

void BossHand::Update()
{
	switch (m_state) {
	case eIdle:
		Idle();
	case eUp:
		UpMove();
		break;
	case eDownAttack:
		DownMove();
		break;
	case eAttack:
		Attack();
		break;
	default:
		break;
	}
}

void BossHand::Draw()
{
	m_img.SetRect(BOSS_X_SIZE, BOSS_Y_SIZE * 2, BOSS_X_SIZE * 3, BOSS_Y_SIZE * 3);
	m_img2.SetRect(BOSS_X_SIZE, BOSS_Y_SIZE * 2, BOSS_X_SIZE * 2, BOSS_Y_SIZE * 3);
	m_img3.SetRect(0, BOSS_Y_SIZE * 2, BOSS_X_SIZE, BOSS_Y_SIZE * 3);

	m_img.SetPos(m_pos - m_scroll);
	m_img2.SetPos(m_pos2 - m_scroll);
	m_img3.SetPos(m_pos3 - m_scroll);

	if (m_idle_flag == true) {
		m_img2.Draw();
		m_img3.Draw();
	}
	
	if(m_idle_flag == false)m_img.Draw();

}


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////尻尾クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

BossTail::BossTail(const CVector2D & player_pos, const int state):EnemyBase(eBossHead/*eBossTail*/)
{
	m_img = COPY_RESOURCE("Boss", CAnimImage*);//待機状態のとき
	m_img2 = COPY_RESOURCE("Boss", CAnimImage*);//攻撃するとき
	m_img3 = COPY_RESOURCE("Boss", CImage*);

	m_img2.SetCenter(BOSS_X_SIZE / 4, BOSS_Y_SIZE / 4);
	m_img3.SetCenter(BOSS_X_SIZE / 4, BOSS_Y_SIZE / 4);

	//待機状態の時の座標
	m_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 1.4, HEIGHT_SIZE - BOSS_Y_SIZE / 3);
	//攻撃状態の座標
	m_player_pos.x = player_pos.x + BOSS_X_SIZE / 6;
	m_player_pos.y = player_pos.y;
	m_pos2 = CVector2D(player_pos.x, 0);

	m_state = state;

	m_anim_cnt = 0;

	m_draw_flag = false;
	m_idle_flag = false;
	m_anim_flag = false;
}

BossTail::~BossTail()
{
	TaskManager::GetInstance()->AddTask(new BossManager());
}

void BossTail::Update()
{
	switch (m_state) {
	case eIdle:
		Idle();
	case eUp:
		UpMove();
		break;
	case eDown:
		DownMove();
		break;
	case eTailAttack:
		TailAttack();
		break;
	default:
		break;
	}
	m_img.ChangeAnimation(eBossTailAnim);
	m_img.UpdateAnimation();

}

void BossTail::Idle()
{
	m_idle_flag = true;

	if (m_pos.x >= WIGHT_SIZE / 2.5) {
		m_pos.x -= 0.5;
	}
}

void BossTail::TailAttack()
{
	m_anim_cnt++;
	m_anim_flag = true;
	m_draw_flag = false;
	m_img2.ChangeAnimation(eBossTailAttackMotion, false);
	m_img2.UpdateAnimation();
	if(m_anim_cnt > 120)m_state = eUp;
}

void BossTail::UpMove()
{
	m_pos2.y -= 5;
}

void BossTail::DownMove()
{
	m_draw_flag = true;
	if (m_pos2.y < m_player_pos.y) {
		m_pos2.y += 5;
	}
	if (m_pos2.y >= m_player_pos.y) {
		m_state = eTailAttack;
	}
}

void BossTail::HitCheck(Task * _t)
{
}

void BossTail::Draw()
{
	m_img.SetPos(m_pos - m_scroll);
	m_img2.SetPos(m_pos2 - m_scroll);
	m_img3.SetPos(m_pos2 - m_scroll);

	m_img.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
	m_img2.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
	m_img3.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
	
	m_img3.SetRect(0, BOSS_Y_SIZE * 3, BOSS_X_SIZE, BOSS_Y_SIZE * 4);

	if (m_idle_flag == true) {
		m_img.Draw();
		m_idle_flag = false;
	}

	if (m_draw_flag == true) {
		m_img3.Draw();
	}

	if (m_anim_flag == true) {
		m_img2.Draw();
	}
}
