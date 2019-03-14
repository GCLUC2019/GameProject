#include "BossManager.h"
#include "../GameProject/Game/Character/Anim/AnimBoss.h"
#include "../GameProject/Boss.h"

#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

#define WIGHT_SIZE 1280
#define HEIGHT_SIZE 720

BossManager::BossManager() : Task(eBossManager)
{
	m_img= COPY_RESOURCE("Boss", CImage*);
	m_pos = CVector2D(WIGHT_SIZE / 2 - BOSS_X_SIZE / 4, HEIGHT_SIZE / 2 - BOSS_Y_SIZE / 2);
	m_state = eAttackDown;

	m_player_pos = CVector2D(640, 300);//‰¼

	m_boss_hp = 100;

	m_idle_cnt = 0;

}

void BossManager::Nothing()
{
	//m_idle_cnt++;

	/*if (m_idle_cnt >= 300) {
		m_state = BossMana::eAttackDown;
	}*/
}

void BossManager::Idle()
{
	TaskManager::GetInstance()->AddTask(new BossHand(0));
	TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, 0));
	TaskManager::GetInstance()->AddTask(new BossTail(m_player_pos, 0));
	m_state = eNothing;
}

void BossManager::Attack()
{
	
	//TaskManager::GetInstance()->AddTask(new BossHand(eAttackDown));
	//TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, 2));
	//TaskManager::GetInstance()->AddTask(new BossTail(m_player_pos, eAttackDown));

	m_state = eNothing;
}

void BossManager::Death()
{
	m_death_flag = true;
	m_pos.y -= 3;
}

void BossManager::Update()
{
	switch (m_state) {
	case eNothing:
		Nothing();
		break;
	case eIdle:
		Idle();
		break;
	case eAttackDown:
		Attack();
		break;
	case eDeath:
		Death();
		break;
	default:
		break;
	}

	if (m_boss_hp <= 0)m_state = eDeath;
}

void BossManager::Draw()
{
	m_img.SetPos(m_pos);

	m_img.SetRect(0, BOSS_Y_SIZE * 5, BOSS_X_SIZE, BOSS_Y_SIZE * 6);

	if (m_death_flag == true) {
		m_img.Draw();
	}
}
