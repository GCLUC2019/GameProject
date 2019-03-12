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

	m_pos = CVector2D(1280 - BOSS_X_SIZE / 3, 0);
	m_center = CVector2D(m_pos.x + m_r, m_pos.y);

	m_anim_flag = true;
	m_move_flag = false;

	m_r = 100.0;
	m_rot = 0;
}


void BossHead::Update()
{
	//300はプレイヤーのY座標（仮）
	if (m_pos.y < 300 && m_move_flag == false) m_pos.y += 5;
	if (m_pos.y >= 300) {
		m_anim_flag = false;
	}

	m_img.ChangeAnimation(eBossFireAttackMotion, false);
	m_img.UpdateAnimation();
	if (m_anim_flag == false && m_img.CheckAnimationEnd()) {
		//TaskManager::GetInstance()->AddTask(new BossFireEffect(m_pos));
		m_anim_flag = true;
		m_move_flag = true;
	}

	if (m_move_flag == true)m_pos.y -= 3;
	m_rot += 0.05;
	if (m_rot >= PIE * 2)m_rot = 0;
	/*if(m_anim_flag==false)
	m_pos = m_center + CVector2D(sin(m_rot), cos(m_rot))*m_r;*/
}

void BossHead::Draw()
{
	m_img.SetRect(0, BOSS_Y_SIZE * 4, BOSS_X_SIZE * 2, BOSS_Y_SIZE * 5);
	m_img.SetPos(m_pos);
	m_img.Draw();
}


//////////////////////////////////////////////////////////////
///////////////////////ボスの手クラス/////////////////////////
//////////////////////////////////////////////////////////////
BossHand::BossHand() :EnemyBase(eBossHead)
{
	m_img = COPY_RESOURCE("Boss", CImage*);
	m_img.SetSize(BOSS_X_SIZE / 3 + 200, BOSS_Y_SIZE / 3);
	m_pos = CVector2D(1280 - BOSS_X_SIZE, 0);

	m_cnt = 0;

	m_anim_flag = false;
	m_move_flag = false;
}

void BossHand::Update()
{
	
	if (m_pos.y < (BOSS_Y_SIZE / 3) - BOSS_X_SIZE / 12 && m_move_flag == false) {
		m_pos.y += 5;
	}

	if (m_pos.y >= (BOSS_Y_SIZE / 3) - BOSS_X_SIZE / 12) {
		m_pos.y = (BOSS_Y_SIZE / 3) - BOSS_X_SIZE / 12;
		m_anim_flag = true;
	}

	if (m_anim_flag == true) {
		//TaskManager::GetInstance()->AddTask(new BossLazerEffect(m_pos));
		m_cnt++;
		if (m_cnt > 180) {
			m_move_flag = true;
		}

		if (m_move_flag == true)m_pos.y -= 5;
	}
}

void BossHand::Draw()
{
	m_img.SetRect(BOSS_X_SIZE, BOSS_Y_SIZE * 2, BOSS_X_SIZE * 3, BOSS_Y_SIZE * 3);
	m_img.SetPos(m_pos);
	m_img.Draw();
}