#include "Boss.h"
#include "../GameProject/Game/Character/Effect/BossEffect.h"
#include "../GameProject/Game/Character/Anim/AnimBoss.h"

#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768
#define PIE 3.14

BossHead::BossHead() :EnemyBase(eBossHead)
{
	m_img = COPY_RESOURCE("Boss", CAnimImage*);
	m_img.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);
	//プレイヤー座標取得可能後
	//m_pos = CVector2D(1280 - BOSS_X_SIZE / 3, Player_pos.y);
	m_pos = CVector2D(1280 - BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);
	m_state = eIdle;
	m_r = 100.0;
	m_rot = 0;
	m_center = CVector2D(m_pos.x + m_r, m_pos.y);
}


void BossHead::Update()
{
	m_img.ChangeAnimation(eBossFireAttackMotion, false);
	m_img.UpdateAnimation();
	m_img.CheckAnimationEnd();
	//TaskManager::GetInstance()->AddTask(new BossEffect(m_pos));
	m_rot += 0.05;
	if (m_rot >= PIE * 2)m_rot = 0;
	m_pos = m_center + CVector2D(sin(m_rot), cos(m_rot))*m_r;
}



void BossHead::Attack()
{
	//TaskManager::GetInstance()->AddTask(new BossEffect(m_pos));
	//m_state = eIdle;
}


void BossHead::Draw()
{
	m_img.SetRect(BOSS_X_SIZE, BOSS_Y_SIZE * 4, BOSS_X_SIZE * 2, BOSS_Y_SIZE * 5);
	m_img.SetPos(m_pos);
	m_img.Draw();
}


//////////////////////////////////////////////////////////////
///////////////////////ボスの手クラス/////////////////////////
//////////////////////////////////////////////////////////////
BossHand::BossHand() :EnemyBase(eBossHead)
{
	m_img = COPY_RESOURCE("Boss", CImage*);
	m_img.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);
	m_pos = CVector2D(1280 - BOSS_X_SIZE, BOSS_Y_SIZE / 3);
}

void BossHand::Update()
{
}

void BossHand::Idle()
{
}

void BossHand::Attack()
{
}

void BossHand::Draw()
{
	m_img.SetRect(BOSS_X_SIZE, BOSS_Y_SIZE * 2, BOSS_X_SIZE * 3, BOSS_Y_SIZE * 3);
	m_img.SetPos(m_pos);
	m_img.Draw();
}