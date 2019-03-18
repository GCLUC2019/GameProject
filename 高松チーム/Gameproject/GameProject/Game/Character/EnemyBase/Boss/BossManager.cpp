#include "BossManager.h"
#include "../GameProject/Game/Character/Anim/AnimBoss.h"
#include "../GameProject/Boss.h"
#include "../GameProject/Game/GameData/GameData.h"

#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

#define WIGHT_SIZE 1280
#define HEIGHT_SIZE 720

//攻撃種類の数
#define ATTACK_NUM 5

BossManager::BossManager() : Task(eBossManager)
{
	m_img= COPY_RESOURCE("Boss", CImage*);
	
	m_pos = CVector2D(WIGHT_SIZE / 2 - BOSS_X_SIZE / 4, HEIGHT_SIZE / 2 - BOSS_Y_SIZE / 2);

	m_state = Manager::eIdle;

	m_player_pos = CVector2D(0, 0);

	m_boss_hp = 100;

	m_idle_cnt = 0;
	m_cnt = 0;

	m_boss_attack_type = 0;

	m_idle_flag = true;
	m_death_flag = false;
}

BossManager::~BossManager()
{
	//TaskManager::GetInstance()->AddTask(new BossManager());
}

void BossManager::Nothing()
{
}

void BossManager::Idle()
{
	if (m_idle_cnt <= 0 && m_idle_flag == true) {
		TaskManager::GetInstance()->AddTask(new BossHand(m_player_pos, Manager::eIdle));
		TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, Manager::eIdle));
		TaskManager::GetInstance()->AddTask(new BossTail(m_player_pos, Manager::eIdle));
	}

	m_idle_cnt++;

	if (m_idle_cnt >= 600) {
		m_idle_flag = false;
		m_state = Manager::eAttackDown;
	}
}

void BossManager::Attack()
{
	if (m_boss_attack_type == 0) {
		//プレイヤーの座標取得
		Task * p = TaskManager::GetInstance()->FindObject(ePlayer);
		if (p == nullptr)return;
		m_player_pos = p->GetPos();

		m_boss_attack_type = rand() % 100;
	}
	if (m_boss_attack_type > 80) m_boss_attack_type = 5;
	else if (m_boss_attack_type <= 80 && m_boss_attack_type > 60) m_boss_attack_type = 5;
	else if (m_boss_attack_type <= 60 && m_boss_attack_type > 40) m_boss_attack_type = 5;
	else if (m_boss_attack_type <= 40 && m_boss_attack_type > 20) m_boss_attack_type = 5;
	else if (m_boss_attack_type <= 20 && m_boss_attack_type > 0) m_boss_attack_type = 5;


	switch (m_boss_attack_type) {
	case 1:
		TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, Manager::eAttackDown));
		m_state = Manager::eNothing;
		break;
	case 2:
		TaskManager::GetInstance()->AddTask(new BossHand(m_player_pos, Manager::eAttackDown));
		m_state = Manager::eNothing;
		break;
	case 3:
		TaskManager::GetInstance()->AddTask(new BossTail(m_player_pos, Manager::eAttackDown));
		m_state = Manager::eNothing;
		break;
	case 4:
		TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, Manager::eAttackDown2));
		m_state = Manager::eNothing;
		break;
	case 5:
		TaskManager::GetInstance()->AddTask(new BossHand(m_player_pos, Manager::eAttackDown2));
		m_state = Manager::eNothing;
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
	m_img.SetRect(0, BOSS_Y_SIZE * 5, BOSS_X_SIZE, BOSS_Y_SIZE * 6);
	m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);

	switch (m_state) {
	case eDeath:
		m_img.Draw();
		break;
	default:
		break;
	}
}
