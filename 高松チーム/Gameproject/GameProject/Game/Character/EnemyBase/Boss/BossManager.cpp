#include "BossManager.h"
#include "../GameProject/Game/Character/Anim/AnimBoss.h"
#include "../GameProject/Boss.h"


#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

#define WIGHT_SIZE 1280
#define HEIGHT_SIZE 720

#define PIE 3.14

BossManager::BossManager() : Task(eBossManager)
{
	m_img = COPY_RESOURCE("Boss", CAnimImage*);
	m_img2 = COPY_RESOURCE("Boss", CImage*);
	m_img3 = COPY_RESOURCE("Boss", CImage*);
	m_img4 = COPY_RESOURCE("Boss", CAnimImage*);
	m_img5 = COPY_RESOURCE("Boss", CImage*);

	m_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 1.6, HEIGHT_SIZE - BOSS_Y_SIZE / 1.5);
	m_pos2 = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 1.2, HEIGHT_SIZE - BOSS_Y_SIZE / 2.1);
	m_pos3 = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 2.4, HEIGHT_SIZE - BOSS_Y_SIZE / 1.9);
	m_pos4 = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 1.4, HEIGHT_SIZE - BOSS_Y_SIZE / 3);
	m_pos5 = CVector2D(WIGHT_SIZE/2 - BOSS_X_SIZE / 4, HEIGHT_SIZE/2 - BOSS_Y_SIZE / 2);

	m_boss_hp = 100;
	m_r = 25.0;
	m_rot = 0;

	m_center = CVector2D(m_pos2.x + m_r, m_pos2.y);
	m_center2 = CVector2D(m_pos3.x + m_r, m_pos3.y);

	m_state = eDeath;

	m_death_flag = false;
	m_idle_flag = false;
	m_attack_flag = false;
}

void BossManager::Idle()
{
	m_idle_flag = true;

	m_img.ChangeAnimation(eBossHeadAnim);
	m_img4.ChangeAnimation(eBossTailAnim);

	m_img.UpdateAnimation();
	m_img4.UpdateAnimation();

	if (m_pos.x >= WIGHT_SIZE / 2) {

		m_center.x -= 0.5;
		m_center2.x -= 0.5;

		m_pos.x -= 0.5;
		m_pos4.x -= 0.5;
	}

	m_rot += 0.05;
	if (m_rot >= PIE * 2)m_rot = 0;

	m_pos2 = m_center + CVector2D(sin(m_rot), cos(m_rot))*m_r;
	m_pos3 = m_center2 + CVector2D(cos(m_rot), sin(m_rot))*m_r;
}

void BossManager::Attack()
{

}

void BossManager::Death()
{
	m_death_flag = true;
	m_pos5.y -= 3;
}

void BossManager::Update()
{
	switch (m_state) {
	case eIdle:
		Idle();
		break;
	case eAttack:
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
	m_img2.SetPos(m_pos2);
	m_img3.SetPos(m_pos3);
	m_img4.SetPos(m_pos4);
	m_img5.SetPos(m_pos5);

	m_img.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
	m_img2.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
	m_img3.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
	m_img4.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
	m_img5.SetSize(BOSS_X_SIZE / 1.5, BOSS_Y_SIZE / 1.5);

	m_img.SetRect(0, 0, BOSS_X_SIZE, BOSS_Y_SIZE);
	m_img2.SetRect(BOSS_X_SIZE, BOSS_Y_SIZE * 2, BOSS_X_SIZE * 2, BOSS_Y_SIZE * 3);
	m_img3.SetRect(0, BOSS_Y_SIZE * 2, BOSS_X_SIZE, BOSS_Y_SIZE * 3);
	m_img4.SetRect(0, BOSS_Y_SIZE, BOSS_X_SIZE, BOSS_Y_SIZE * 2);
	m_img5.SetRect(0, BOSS_Y_SIZE * 5, BOSS_X_SIZE, BOSS_Y_SIZE * 6);

	if (m_death_flag == true) {
		m_idle_flag = false;
		m_img5.Draw();
	}

	if (m_idle_flag == true) {
		m_img2.Draw();
		m_img3.Draw();
		m_img4.Draw();
		m_img.Draw();
	}
	/*if(m_attack_flag==true)*/
}
