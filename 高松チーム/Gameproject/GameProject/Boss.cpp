#include "Boss.h"
#include "../GameProject/Game/Character/Effect/BossEffect.h"

#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

BossHead::BossHead():EnemyBase(eBossHead)
{
	m_img = COPY_RESOURCE("Boss", CImage*);
	m_img.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);
	//プレイヤー座標取得可能後
	//m_pos = CVector2D(1280 - BOSS_X_SIZE / 3, Player_pos.y);
	m_pos = CVector2D(1280 - BOSS_X_SIZE / 3, BOSS_Y_SIZE - BOSS_Y_SIZE /3);
	m_state = eIdle;
}


void BossHead::Update()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton1)) {
		m_state = eAttack;
	}
	switch (m_state) {
	case eIdle:
		Idle();
		break;
	case eAttack:
		Attack();
		break;
	default:
		break;
	}

	/*m_rot += 0.1;
	if (m_rot >= 6.28)m_rot = 0;
	m_pos = m_center + CVector2D(sin(m_rot), cos(m_rot))*r;*/
}

void BossHead::Idle()
{
	m_state = eIdle;
}

void BossHead::Attack()
{
	TaskManager::GetInstance()->AddTask(new BossEffect(m_pos));
	//m_state = eIdle;
}


void BossHead::Draw()
{
	if (m_state == eIdle) {
		m_img.SetRect(0, BOSS_Y_SIZE * 4, BOSS_X_SIZE, BOSS_Y_SIZE * 5);
		m_img.SetPos(m_pos);
		m_img.Draw();
	}
	if (m_state == eAttack) {
		m_img.SetRect(BOSS_X_SIZE, BOSS_Y_SIZE * 4, BOSS_X_SIZE * 2, BOSS_Y_SIZE * 5);
		m_img.SetPos(m_pos);
		m_img.Draw();
	}
}

