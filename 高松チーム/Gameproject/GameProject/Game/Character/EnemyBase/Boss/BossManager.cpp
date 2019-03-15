#include "BossManager.h"
#include "../GameProject/Game/Character/Anim/AnimBoss.h"
#include "../GameProject/Boss.h"

#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

#define WIGHT_SIZE 1280
#define HEIGHT_SIZE 720

//�U����ނ̐�
#define ATTACK_NUM 4

BossManager::BossManager() : Task(eBossManager)
{
	m_img= COPY_RESOURCE("Boss", CImage*);
	m_pos = CVector2D(WIGHT_SIZE / 2 - BOSS_X_SIZE / 4, HEIGHT_SIZE / 2 - BOSS_Y_SIZE / 2);
	//m_state = B::eIdle;

	m_player_pos = CVector2D(640, 300);//��

	m_boss_hp = 100;

	m_idle_cnt = 0;

	m_boss_attack_type = 2;

	m_idle_flag = false;
	m_death_flag = false;
}

BossManager::~BossManager()
{
	//TaskManager::GetInstance()->AddTask(new BossManager());
}

void BossManager::Nothing()
{
	m_idle_cnt = 0;
	m_idle_flag = false;
	m_boss_attack_type = 0;
	
	//m_state = B::eIdle;
}

void BossManager::Idle()
{
	/*if (m_idle_cnt <= 0 && m_idle_flag == false) {
		TaskManager::GetInstance()->AddTask(new BossHand(m_player_pos,B::eIdle));
		TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, B::eIdle));
		TaskManager::GetInstance()->AddTask(new BossTail(m_player_pos, B::eIdle));
	}

	m_idle_cnt++;

	if (m_idle_cnt >= 60) {
		m_idle_flag = true;
		m_state = B::eAttackDown;
	}*/
}

void BossManager::Attack()
{
	m_boss_attack_type = rand() % 100;

	if (m_boss_attack_type > 75) m_boss_attack_type = 2;
	else if (m_boss_attack_type <= 75 && m_boss_attack_type > 50) m_boss_attack_type = 2;
	else if (m_boss_attack_type <= 50 && m_boss_attack_type > 25) m_boss_attack_type = 2;
	else if (m_boss_attack_type <= 25 && m_boss_attack_type > 0) m_boss_attack_type = 2;


	switch (m_boss_attack_type) {
	case 1:
		TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, B::eAttackDown));
		m_state = B::eNothing;
		break;
	case 2:
		TaskManager::GetInstance()->AddTask(new BossHand(m_player_pos, B::eAttackDown2));
		m_state = B::eNothing;
		break;
	case 3:
		TaskManager::GetInstance()->AddTask(new BossTail(m_player_pos, B::eAttackDown));
		m_state = B::eNothing;
		break;
	case 4:
		TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, B::eAttackDown2));
		m_state = B::eNothing;
		break;
	default:
		break;
	}
	
	
}

void BossManager::Death()
{
	m_death_flag = true;
	m_pos.y -= 3;
}

void BossManager::Update()
{

	switch (m_state) {
	case eIdle:
		Idle();
		break;
	case eAttackDown:
		Attack();
		break;
	case eDeath:
		Death();
		break;
	case eNothing:
		Nothing();
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
