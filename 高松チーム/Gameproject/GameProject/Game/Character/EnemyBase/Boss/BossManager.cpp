#include "BossManager.h"
#include "../GameProject/Game/Character/Anim/AnimBoss.h"
#include "../GameProject/Boss.h"
#include "../GameProject/Game/GameData/GameData.h"
#include "../GameProject/Game/Stage/CollisionBox.h"

#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

#define EFFECT_SIZE 192


#define WIGHT_SIZE 1280
#define HEIGHT_SIZE 720

//攻撃種類の数
#define ATTACK_NUM 5

BossManager::BossManager() : Task(eBossManager)
{
	m_img= COPY_RESOURCE("Boss", CImage*);
	m_img2 = COPY_RESOURCE("BossDeathEffect1", CAnimImage*);
	m_img3 = COPY_RESOURCE("BossDeathEffect2", CAnimImage*);
	
	m_img.SetSize(BOSS_X_SIZE / 1.5f, BOSS_Y_SIZE / 1.5f);
	m_img2.SetSize(EFFECT_SIZE * 4, EFFECT_SIZE *  2.8f);
	m_img3.SetSize(EFFECT_SIZE * 4, EFFECT_SIZE *  2.8f);

	m_pos = CVector2D(WIGHT_SIZE / 2 - BOSS_X_SIZE / 4, HEIGHT_SIZE - BOSS_Y_SIZE / 1.5f);
	m_pos2 = CVector2D(WIGHT_SIZE / 2 - BOSS_X_SIZE / 2.5, HEIGHT_SIZE - BOSS_Y_SIZE / 2.8f);
	m_pos3 = CVector2D(WIGHT_SIZE / 2 - BOSS_X_SIZE / 2.5, HEIGHT_SIZE - BOSS_Y_SIZE / 2.8f);
	m_rect_pos= CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 2.5, HEIGHT_SIZE - BOSS_Y_SIZE / 2.5);

	m_img3.SetCenter(BOSS_Y_SIZE / 4, BOSS_Y_SIZE / 4);

	m_state = Manager::eIdle;

	m_player_pos = CVector2D(0, 0);

	m_boss_hp = 100;

	m_idle_cnt = 0;
	m_cnt = 0;

	m_boss_attack_type = 0;

	m_idle_flag = true;
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
	//if (m_idle_cnt <= 0 && m_idle_flag == true) {
	//	//TaskManager::GetInstance()->AddTask(new CollisionBox(CVector2D(m_rect_pos.x, m_rect_pos.y), CRect(-300, -100, 250, 300)));
	//	TaskManager::GetInstance()->AddTask(new BossLeftHand(m_player_pos, Manager::eIdle));
	//	TaskManager::GetInstance()->AddTask(new BossRightHand(m_player_pos, Manager::eIdle));
	//	TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, Manager::eIdle));
	//	TaskManager::GetInstance()->AddTask(new BossTail(m_player_pos, Manager::eIdle));
	//}

	//m_idle_cnt++;

	//if (m_idle_cnt >= 600) {
	//	m_idle_flag = false;
	//	m_state = Manager::eAttackDown;
	//}
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
	if (m_boss_attack_type > 80) m_boss_attack_type = 2;
	else if (m_boss_attack_type <= 80 && m_boss_attack_type > 60) m_boss_attack_type = 2;
	else if (m_boss_attack_type <= 60 && m_boss_attack_type > 40) m_boss_attack_type = 2;
	else if (m_boss_attack_type <= 40 && m_boss_attack_type > 20) m_boss_attack_type = 2;
	else if (m_boss_attack_type <= 20 && m_boss_attack_type > 0) m_boss_attack_type = 2;


	switch (m_boss_attack_type) {
	case 1:
		TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, Manager::eAttackDown));
		m_state = Manager::eNothing;
		break;
	case 2:
		TaskManager::GetInstance()->AddTask(new BossRightHand(m_player_pos, Manager::eAttackDown));
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
		TaskManager::GetInstance()->AddTask(new BossLeftHand(m_player_pos, Manager::eAttackDown));
		m_state = Manager::eNothing;
		break;
	default:
		break;
	}
}

void BossManager::Death()
{
	m_pos.y -= 6;
}

void BossManager::Update()
{
	switch (m_state) {
	case Manager::eIdle:
		Idle();
		break;
	case Manager::eAttackDown:
		Attack();
		break;
	case Manager::eDeath:
		Death();
		break;
	case Manager::eNothing:
		Nothing();
		break;
	default:
		break;
	}


	if (m_boss_hp <= 0)m_state = Manager::eDeath;

	if (m_state == Manager::eDeath) {
		m_img2.ChangeAnimation(eBossDeathEffect1);
		m_img2.UpdateAnimation();
		m_img3.ChangeAnimation(eBossDeathEffect2);
		m_img3.UpdateAnimation();
	}
}

void BossManager::Draw()
{
//#ifdef _DEBUG
//	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
//	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos2.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
//	Utility::DrawQuad(CVector2D(m_pos2.x + m_rect.m_right, m_pos2.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
//	Utility::DrawQuad(CVector2D(m_pos2.x + m_rect.m_right, m_pos2.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
//#endif
	m_img.SetRect(0, BOSS_Y_SIZE * 5, BOSS_X_SIZE, BOSS_Y_SIZE * 6);
	m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
	m_img2.SetPos(m_pos2.x, m_pos2.y - g_game_data.m_scroll.y / 3);
	m_img3.SetPos(m_pos3.x, m_pos3.y - g_game_data.m_scroll.y / 3);

	switch (m_state) {
	case Manager::eDeath:
		m_img.Draw();
		m_img2.Draw();
		m_img3.Draw();
		break;
	default:
		break;
	}
}
