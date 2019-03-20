#include "Boss.h"
#include "../GameProject/Game/Character/Effect/BossEffect.h"
#include "../GameProject/Game/Character/Anim/AnimBoss.h"
#include "../GameProject/Game/Character/EnemyBase/Boss/BossManager.h"
#include "../GameProject/Game/GameData/GameData.h"


#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

#define WIGHT_SIZE 1280
#define HEIGHT_SIZE 720

#define SHADOW_X_SIZE 174
#define SHADOW_Y_SIZE 45

#define PIE 3.14


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////頭クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
BossHead::BossHead(const CVector2D &player_pos, const int state) :EnemyBase(eBossHead)
{
	m_state = state;

	if (m_state == eIdle) {
		m_img = COPY_RESOURCE("Boss2", CAnimImage*);
		m_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 2.5f, HEIGHT_SIZE - BOSS_Y_SIZE / 3);
	} 
	else if (m_state == eFireAttackDown || m_state == eHeadAttackDown) {
		m_img = COPY_RESOURCE("Boss", CAnimImage*);
		m_pos = CVector2D((1280 - BOSS_X_SIZE / 3) + 100, 0);
	}
	/*m_img2 = COPY_RESOURCE("Boss", CImage*);
	m_img3 = COPY_RESOURCE("Boss2", CAnimImage*);*/
	m_shadow = COPY_RESOURCE("Shadow", CImage*);
	
	m_img.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);

	m_img.SetCenter(BOSS_Y_SIZE / 4, BOSS_Y_SIZE / 4);

	m_player_pos.x = player_pos.x;
	m_player_pos.y = player_pos.y - 50;

	m_idle_cnt = 0;

	m_anim_flag = true;
	m_draw_flag = false;
	m_approach_flag = true;
	m_shadow_flag = false;


	m_anim_cnt = 0;

	m_idle_cnt = 0;

	m_state = state;

	m_shadow_size = 0;

	m_shadow.SetColor(0.3f, 0.3f, 0.3f, 0.4f);

}

BossHead::~BossHead()
{
	Task * p = TaskManager::GetInstance()->FindObject(eGameTitle);
	if (p == nullptr)TaskManager::GetInstance()->AddTask(new BossManager());
}

void BossHead::Idle()
{
	m_shadow_flag = true;
	
	if (m_pos.x >= WIGHT_SIZE / 1.73f) {
		m_shadow_pos.x -= 0.5f;
		m_pos.x -= 0.5f;
	}
	else {
		m_shadow_size += 1;
		m_pos.y -= 5;
	}
	if (m_pos.y <  -BOSS_X_SIZE / 2)m_shadow_flag = false;
}

void BossHead::FireAttack()
{
	m_anim_cnt++;
	if (m_anim_flag == true) {
		TaskManager::GetInstance()->AddTask(new BossFireEffect(m_pos));
		m_anim_flag = false;
	}
	if (m_anim_cnt >= 120) {
		m_state = eUp;
	}
}
void BossHead::HeadAttack()
{
	if (m_approach_flag == true)m_pos.x += 10;
	else m_pos.x -= 20;

	if (m_pos.x >= 1280 - BOSS_X_SIZE / 4)m_approach_flag = false;

	if (m_pos.x < (1280 - BOSS_X_SIZE) / 3)
	{
		m_draw_flag = true;
		m_state = eUp;
	}
}	

void BossHead::UpMove()
{
	m_pos.y -= 5;
	if (m_pos.y < -BOSS_X_SIZE) SetKill();
}

void BossHead::FireDownMove()
{
	if(m_pos.y <= m_player_pos.y)m_pos.y += 5;
	//プレイヤーのY座標 m_player_pos.y
	if (m_pos.y > m_player_pos.y) {
		m_pos.y = m_player_pos.y;
		m_state = eFireAttack;
		
	}
}


void BossHead::HeadDownMove()
{
	m_rect = CRect(-100, -100, 100, 100);//攻撃時の矩形
	//プレイヤーの座標 m_player_pos.y
	if (m_pos.y <= m_player_pos.y) {
		m_pos.y += 5;
	}
	if (m_pos.y > m_player_pos.y) {
		m_pos.y = m_player_pos.y;
		m_state = eHeadAttack;
	}
}

void BossHead::Update()
{
	switch (m_state) {
	case eIdle:
		Idle();
		break;
	case eUp:
		UpMove();
		break;
	case eFireAttackDown:
		FireDownMove();
		break;
	case eHeadAttackDown:
		HeadDownMove();
		break;
	case eFireAttack:
		FireAttack();
		break;
	case eHeadAttack:
		HeadAttack();
		break;
	default:
		break;
	}
	if (m_state == Head::eIdle) {
		m_img.ChangeAnimation(Motion1::eBossHeadAnim);
		m_img.UpdateAnimation();
	}

	if (m_state == Head::eFireAttackDown) {
		m_img.ChangeAnimation(Motion2::eBossFireAttackMotion, false);
		m_img.UpdateAnimation();
	}

	if (m_state == Head::eHeadAttackDown) {
		m_img.ChangeAnimation(Motion2::eBossFireAttackMotion, false);
		m_img.UpdateAnimation();
	}

}

void BossHead::Draw()
{
	m_shadow.SetSize((SHADOW_X_SIZE * 1.5 - m_shadow_size), SHADOW_Y_SIZE);

	m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
	m_img.Draw();
#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif
	//m_img2.SetRect(0, BOSS_Y_SIZE * 4, BOSS_X_SIZE, BOSS_Y_SIZE * 5);
//影表示してません
}




//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////migi手クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

BossRightHand::BossRightHand(const CVector2D &player_pos, const int state) :EnemyBase(eBossRightHand)
{
	m_img = COPY_RESOURCE("Boss2", CImage*);

	m_img.SetCenter(BOSS_X_SIZE / 4, BOSS_Y_SIZE / 4);

	m_player_pos.x = player_pos.x + 100;
	m_player_pos.y = player_pos.y - 200;

	m_cnt = 0;

	m_r = 25.0;
	m_rot = 0;

	m_anim_flag = true;
	m_move_flag = false;
	m_idle_flag = false;

	m_state = state;

	if (m_state == eIdle) {
		m_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 1.6, HEIGHT_SIZE - BOSS_Y_SIZE / 5);
		m_center = CVector2D(m_pos.x + m_r, m_pos.y);
	}
	if(m_state== eDownAttack)m_pos = CVector2D(1280 - BOSS_X_SIZE + 150, 0);

	m_idle_cnt = 0;
<<<<<<< HEAD
=======

	m_shadow_size = 0;

	m_shadow.SetColor(0.3f, 0.3f, 0.3f, 0.4f);
>>>>>>> 2031a647a46d984b3d00de2dd3b56f00d24ecdef
}

BossRightHand::~BossRightHand()
{
	Task * p = TaskManager::GetInstance()->FindObject(eGameTitle);
	if (p == nullptr)TaskManager::GetInstance()->AddTask(new BossManager());
}

void BossRightHand::Idle()
{
	m_idle_flag = true;

	if (m_pos.x >= WIGHT_SIZE / 2.2) {
		m_center.x -= 0.5;

		m_rot += 0.06;
		if (m_rot >= PIE * 2)m_rot = 0;

		m_pos = m_center + CVector2D(sin(m_rot), cos(m_rot))*m_r;

	}
	else {
		m_pos.y -= 5;
		if (m_pos.y <  -BOSS_X_SIZE / 2)m_idle_flag = false;
	}
	
	
	
}

void BossRightHand::Attack()
{
	m_cnt++;
	if (m_anim_flag == true) {
		TaskManager::GetInstance()->AddTask(new BossLazerEffect(m_pos));
		m_anim_flag = false;
	}
	if (m_cnt >= 180) {
		m_state = eUp;
	}
}

void BossRightHand::UpMove()
{
	m_pos.y -= 5;
	if (m_pos.y < -BOSS_Y_SIZE) SetKill();
}

void BossRightHand::DownMove()
{
	if (m_pos.y < (BOSS_Y_SIZE / 3) - BOSS_X_SIZE / 12 && m_move_flag == false) {
		m_pos.y += 5;
	}

	if (m_pos.y >= (BOSS_Y_SIZE / 3) - BOSS_X_SIZE / 12) {
		m_pos.y = (BOSS_Y_SIZE / 3) - BOSS_X_SIZE / 12;
		m_state = eLazerAttack;
	}

}

void BossRightHand::Update()
{
	switch (m_state) {
	case eIdle:
		Idle();
		break;
	case eUp:
		UpMove();
		break;
	case eDownAttack:
		DownMove();
		break; 
	case eLazerAttack:
		Attack();
		break;
	default:
		break;
	}
}

void BossRightHand::Draw()
{
	m_img.SetRect(BOSS_X_SIZE, BOSS_Y_SIZE * 2, BOSS_X_SIZE * 2, BOSS_Y_SIZE * 3);
	switch (m_state) {
	case BossRightHand::eIdle:
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_img.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
		break;
	case BossRightHand::eDownAttack:
	case BossRightHand::eLazerAttack:
	case BossRightHand::eUp:
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_img.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
		break;
	default:
		break;
	}
	m_img.Draw();
	/*switch (m_state) {
	case BossRightHand::eIdle:
		
		break;
	case BossRightHand::eDownAttack:
	case BossRightHand::eUp:
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_img.SetSize(BOSS_X_SIZE / 2 , BOSS_Y_SIZE / 2);
		m_img.Draw();
		break;
	default:
		break;*/

#ifdef _DEBUG
		/*Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
		Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
		Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
		Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));*/
#endif
}


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////hidariteクラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


BossLeftHand::BossLeftHand(const CVector2D & player_pos, const int state) :EnemyBase(eBossLeftHand)
{

	m_img = COPY_RESOURCE("Boss2", CImage*);

	m_player_pos.x = player_pos.x + 100;
	m_player_pos.y = player_pos.y - 200;

	m_cnt = 0;

	m_r = 25.0;
	m_rot = 0;

	m_slash_flag = false;

	m_state = state;

	if (m_state == eIdle) {
		m_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 2.4, HEIGHT_SIZE - BOSS_Y_SIZE / 1.9);
		m_center = CVector2D(m_pos.x + m_r, m_pos.y);
	}
	if(m_state== eDownAttack)m_pos = CVector2D(1280 - BOSS_X_SIZE + 200, 0);

	m_idle_cnt = 0;

	m_ang = 90;
<<<<<<< HEAD
=======

	m_shadow_size = 0;

	m_shadow.SetColor(0.3f, 0.3f, 0.3f, 0.4f);
>>>>>>> 2031a647a46d984b3d00de2dd3b56f00d24ecdef
}

BossLeftHand::~BossLeftHand()
{
	Task * p = TaskManager::GetInstance()->FindObject(eGameTitle);
	if (p == nullptr)TaskManager::GetInstance()->AddTask(new BossManager());
}

void BossLeftHand::Idle()
{
	if (m_pos.x >= BOSS_X_SIZE - WIGHT_SIZE / 30) {
		m_center.x -= 0.5;

		m_rot += 0.05;
		if (m_rot >= PIE * 2)m_rot = 0;
		m_pos = m_center + CVector2D(sin(m_rot), cos(m_rot))*m_r;
	}
	else {
		m_pos.y -= 5;
	}
}

void BossLeftHand::Attack()
{
	m_cnt++;
	if (m_cnt <= 30 && m_cnt > 0) {
		m_ang -= DtoR(5);
		if (m_slash_flag == false) {
			TaskManager::GetInstance()->AddTask(new BossSlashEffect(m_pos));
			m_slash_flag = true;
		}
	}
	if (m_cnt > 60) {
		m_slash_flag = false;
		m_state = eUp;
	}
}

void BossLeftHand::UpMove()
{
	m_pos.y -= 5;
	if (m_pos.y < -BOSS_X_SIZE) SetKill();
}

void BossLeftHand::DownMove()
{
	m_pos.x = m_player_pos.x;
	if (m_pos.y < m_player_pos.y) {
		m_pos.y += 5;
	}

	if (m_pos.y >= m_player_pos.y) {
		m_pos.y = m_player_pos.y;
		m_state = eHandAttack;
	}
}

void BossLeftHand::Update()
{
	switch (m_state) {
	case eIdle:
		Idle();
		break;
	case eUp:
		UpMove();
		break;
	case eDownAttack:
		DownMove();
		break;
	case eHandAttack:
		Attack();
		break;
	default:
		break;
	}
}

void BossLeftHand::Draw()
{
	m_img.SetRect(0, BOSS_Y_SIZE * 2, BOSS_X_SIZE, BOSS_Y_SIZE * 3);
	switch (m_state) {
	case BossLeftHand::eIdle:
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_img.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
		break;
	case BossLeftHand::eDownAttack:
	case BossLeftHand::eUp:
	case BossLeftHand::eHandAttack:
		m_img.SetAng(m_ang);
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_img.SetCenter(BOSS_X_SIZE / 4, BOSS_Y_SIZE / 4);
		m_img.SetSize(BOSS_X_SIZE / 2, BOSS_Y_SIZE / 2);
		break;
	default:
		break;
	}

	m_img.Draw();

#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif
}





//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////尻尾クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

BossTail::BossTail(const CVector2D & player_pos, const int state):EnemyBase(eBossTail)
{
	m_state = state;

	if (m_state == Tail::eIdle) {
		m_img = COPY_RESOURCE("Boss", CAnimImage*);
		m_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 1.6, HEIGHT_SIZE - BOSS_Y_SIZE / 3);
	}

	if (m_state == Tail::eDown) {
		m_img = COPY_RESOURCE("Boss2", CAnimImage*);
		m_img.SetCenter(BOSS_X_SIZE / 4, BOSS_Y_SIZE / 4);
		m_pos = CVector2D(player_pos.x, 0);
	}

	m_player_pos.x = player_pos.x + BOSS_X_SIZE / 6;
	m_player_pos.y = player_pos.y;
	

	m_anim_cnt = 0;

<<<<<<< HEAD
=======
	m_shadow_size = 0;

	m_shadow.SetColor(0.3f, 0.3f, 0.3f, 0.4f);

>>>>>>> 2031a647a46d984b3d00de2dd3b56f00d24ecdef
}

BossTail::~BossTail()
{
	Task * p = TaskManager::GetInstance()->FindObject(eGameTitle);
	if (p == nullptr)TaskManager::GetInstance()->AddTask(new BossManager());
}

void BossTail::Update()
{
	switch (m_state) {
	case eIdle:
		Idle();
		break;
	case eUp:
		UpMove();
		break;
	case eDown:
		DownMove();
		break;
	case eTailAttack:
		TailAttack();
		break;
	default:
		break;
	}



	
	m_img.ChangeAnimation(Motion2::eBossTailAnim);
	m_img.UpdateAnimation();


	/*m_img.ChangeAnimation(Motion1::eBossTailAttackMotion, false);
	m_img.UpdateAnimation();*/

	
}

void BossTail::Idle()
{
	if (m_pos.x >= WIGHT_SIZE / 2.3) {
		m_pos.x -= 0.5;
	}
	else m_pos.y -= 5;
}

void BossTail::TailAttack()
{
	m_anim_cnt++;
	
	if(m_anim_cnt > 120)m_state = eUp;
}

void BossTail::UpMove()
{
	m_pos.y -= 5;
	if (m_pos.y < -BOSS_X_SIZE) SetKill();
}

void BossTail::DownMove()
{
	m_rect = CRect(-80, -100, 80, 10);

	if (m_pos.y < m_player_pos.y) {
		m_pos.y += 5;
	}
	if (m_pos.y >= m_player_pos.y) {
		m_state = eTailAttack;
	}
}

void BossTail::HitCheck(Task * _t)
{
}

void BossTail::Draw()
{

#ifdef _DEBUG
#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif
#endif
	m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
	m_img.SetSize(BOSS_X_SIZE / 2.5, BOSS_Y_SIZE / 2.5);
	m_img.Draw();

}
