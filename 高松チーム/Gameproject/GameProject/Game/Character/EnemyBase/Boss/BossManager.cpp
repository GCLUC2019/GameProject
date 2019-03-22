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
	
	m_rect_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 2.5, HEIGHT_SIZE - BOSS_Y_SIZE / 2.5);

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
}

void BossManager::Nothing()
{
}

void BossManager::Idle()
{
	if (m_idle_cnt <= 0 && m_idle_flag == true) {
		TaskManager::GetInstance()->AddTask(new CollisionBox(CVector2D(m_rect_pos.x, m_rect_pos.y), CRect(-300, -100, 250, 300)));
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
	int a = 3;
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

void BossManager::HitCheck()
{
	if (CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack01, 50.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack02, 50.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack03, 50.0f)) {
		m_hp -= 1;
	}

	/*if (m_hp <= 0) {
		TaskManager::GetInstance()->AddTask(new BossDeath());
		SetKill();
	}*/
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
	default:
		break;
	}

	
}

void BossManager::Draw()
{
	
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
	Task* p = TaskManager::FindObject(eBossManager);
	BossManager* n = dynamic_cast<BossManager*>(p);
	if (n != nullptr)
		m_boss_hp_now = n->GetHP();

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
