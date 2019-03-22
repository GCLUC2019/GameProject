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
	m_state = Manager::eIdle;

	m_player_pos = CVector2D(0, 0);

	m_idle_cnt = 0;

	m_cnt = 0;

	m_boss_attack_type = 0;

	m_idle_flag = true;
}

BossManager::~BossManager()
{
}

void BossManager::Nothing()
{
}

void BossManager::Idle()
{
	if (m_idle_cnt <= 0 && m_idle_flag == true) {

		TaskManager::GetInstance()->AddTask(new BossLeftHand(m_player_pos, Manager::eIdle));
		TaskManager::GetInstance()->AddTask(new BossRightHand(m_player_pos, Manager::eIdle));
		TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, Manager::eIdle));
		TaskManager::GetInstance()->AddTask(new BossTail(m_player_pos, Manager::eIdle));
	}

	m_idle_cnt++;

	if (m_idle_cnt >= 600) {
		m_idle_flag = false;
		m_state = Manager::eAttackDown;
	}
	m_pos.x -= 0.5f;
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
	int a = 1;
	if (m_boss_attack_type > 80) m_boss_attack_type = a;
	else if (m_boss_attack_type <= 80 && m_boss_attack_type > 60) m_boss_attack_type = a;
	else if (m_boss_attack_type <= 60 && m_boss_attack_type > 40) m_boss_attack_type = a;
	else if (m_boss_attack_type <= 40 && m_boss_attack_type > 20) m_boss_attack_type = a;
	else if (m_boss_attack_type <= 20 && m_boss_attack_type > 0) m_boss_attack_type = a;


	switch (m_boss_attack_type) {
	case 1:
		TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, Manager::eAttackDown));
		m_state = Manager::eNothing;
		break;

	case 2:
		TaskManager::GetInstance()->AddTask(new BossRightHand(m_player_pos, Manager::eAttackDown));
		m_state = Manager::eNothing;//ok
		break;

	case 3:
		TaskManager::GetInstance()->AddTask(new BossTail(m_player_pos, Manager::eAttackDown));
		m_state = Manager::eNothing;
		break;

	case 4:
		TaskManager::GetInstance()->AddTask(new BossHead(m_player_pos, Manager::eAttackDown2));
		m_state = Manager::eNothing;//ok
		break;

	case 5:
		TaskManager::GetInstance()->AddTask(new BossLeftHand(m_player_pos, Manager::eAttackDown));
		m_state = Manager::eNothing;//ok
		break;

	default:
		break;
	}
}

void BossManager::Death()
{
	TaskManager::GetInstance()->AddTask(new BossDeath());
	m_state = Manager::eNothing;
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
	case Manager::eNothing:
		Nothing();
		break;
	case Manager::eDeath:
		Death();
		break;
	default:
		break;
	}

	if (g_game_data.m_boss_hp <= 0 && m_state != Manager::eNothing) {
		m_state = Manager::eDeath;
	}
}

void BossManager::Draw()
{
	m_img.SetPos(m_pos.x, m_pos.y - 150 - g_game_data.m_scroll.y / 3);
	m_img.SetRect(0, BOSS_Y_SIZE, BOSS_X_SIZE, BOSS_Y_SIZE * 2);
	m_img.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE /2);

	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
}


//ゲージベース
BossGageBaseUI::BossGageBaseUI() :UI(eBossGageBaseUI)
{
	m_img = COPY_RESOURCE("BossHPBack", CImage*);
	m_pos = CVector2D(100, 690);
}

void BossGageBaseUI::Update()
{
}

void BossGageBaseUI::Draw()
{
	m_img.SetSize(CVector2D(1080, 20));
	m_img.SetPos(m_pos);
	m_img.Draw();
}


//HPゲージ
BossHpUI::BossHpUI() : UI(eBossHpUI)
{
	m_img = COPY_RESOURCE("BossHP", CImage*);
	m_pos = CVector2D(100, 690);

	hp_width = 1085;
    m_boss_hp_max = 100;
}

void BossHpUI::Update()
{
	Task* p = TaskManager::FindObject(eBossHead);
	BossHead* n = dynamic_cast<BossHead*>(p);
	if (n != nullptr)
		m_boss_hp_now = g_game_data.m_boss_hp;

	m_boss_hp_now = m_boss_hp_now / m_boss_hp_max;

	printf("%f\n", m_boss_hp_now);
	if (m_boss_hp_now <= 0) m_boss_hp_now = 0;
}

void BossHpUI::Draw()
{
	m_img.SetSize(CVector2D(m_boss_hp_now * hp_width, 20));
	m_img.SetPos(m_pos);
	m_img.Draw();
}
