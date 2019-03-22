#include "Boss.h"
#include "../GameProject/Game/Character/Effect/BossEffect.h"
#include "../GameProject/Game/Character/Anim/AnimBoss.h"
#include "../GameProject/Game/Character/EnemyBase/Boss/BossManager.h"
#include "../GameProject/Game/GameData/GameData.h"
#include "../GameProject/Game/Stage/CollisionBox.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../GameProject/Game/Scene/Result.h"
#include "../GameProject/Game/Character/Player.h"


#define BOSS_X_SIZE 768
#define BOSS_Y_SIZE 768

#define WIGHT_SIZE 1280
#define HEIGHT_SIZE 720

#define SHADOW_X_SIZE 174
#define SHADOW_Y_SIZE 45

#define EFFECT_SIZE 192


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
		m_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 2.5f, HEIGHT_SIZE - BOSS_Y_SIZE / 5);
		m_shadow.SetPos(m_pos.x - 100 + m_shadow_x, m_shadow_y - g_game_data.m_scroll.y / 3);
		m_shadow_y = m_pos.y;
		m_shadow_x = 0;
	}
	else if (m_state == eFireAttackDown || m_state == eHeadAttackDown) {
		m_img = COPY_RESOURCE("Boss", CAnimImage*);
		m_pos = CVector2D((1280 - BOSS_X_SIZE / 3) + 100, 0);
		m_shadow_y = m_pos.y;
		m_shadow_x = 0;
	}

	m_shadow = COPY_RESOURCE("Shadow", CImage*);

	m_shadow_pos = CVector2D(0, 0);

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
	if (p == nullptr&& g_game_data.m_boss_hp >0 )TaskManager::GetInstance()->AddTask(new BossManager());

}

void BossHead::Idle()
{
	m_rect = CRect(-192, -210, 192, 130);

	if (m_pos.x >= WIGHT_SIZE / 1.73f) {
		m_shadow_pos.x -= 0.5f;
		m_shadow_y = m_pos.y + 25;
		m_pos.x -= 0.5f;
	}
	else {
		m_shadow_size += 2;
		m_shadow_x += 1;
		m_pos.y -= 5;
	}

	if (CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack01, 100.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack02, 100.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack03, 100.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectLongAttack, 100.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectSpecialAttack, 100.0f))
	{
		g_game_data.m_boss_hp -= 0.05f;
	}
	if (g_game_data.m_boss_hp <= 0) SetKill();
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
	m_rect = CRect(-100, -100, 100, 100);//攻撃時の矩形

	if (m_approach_flag == true) {
		m_pos.x += 10;
		//m_shadow_pos.x += m_pos.x;
	}
	else {
		m_pos.x -= 20;
		//m_shadow_pos.x -= m_pos.x;
	}

	if (m_pos.x >= 1280 - BOSS_X_SIZE / 4)m_approach_flag = false;

	if (m_pos.x < (1280 - BOSS_X_SIZE) / 3)
	{
		m_draw_flag = true;
		m_state = eUp;
	}

	Task*t = CollitionBase::GetCollisionCheckRectANDY(this, CharacterData::ePlayer, 50.0f);
	Player*p = dynamic_cast<Player*>(t);

	if (p != nullptr) {
		p->Damage(20);
	}
}

void BossHead::UpMove()
{
	m_pos.y -= 5;
	m_shadow_size += 2;
	m_shadow_x += 1;
	if (m_pos.y < -BOSS_X_SIZE / 1.5) SetKill();
}

void BossHead::HitCheck()
{
	
}

void BossHead::FireDownMove()
{
	m_shadow_y = m_player_pos.y + 50;
	if (m_pos.y <= m_player_pos.y) {
		m_pos.y += 5;
		m_shadow_size += 2;
		m_shadow_x += 1;
	}
	//プレイヤーのY座標 m_player_pos.y
	if (m_pos.y > m_player_pos.y) {
		m_pos.y = m_player_pos.y;
		m_state = eFireAttack;
		m_shadow_size = 0;
		m_shadow_x = 0;
	}
}


void BossHead::HeadDownMove()
{
	m_shadow_y = m_player_pos.y + 50;
	//プレイヤーの座標 m_player_pos.y
	if (m_pos.y <= m_player_pos.y) {
		m_pos.y += 5;
		m_shadow_size += 2;
		m_shadow_x += 1;

	}
	if (m_pos.y > m_player_pos.y) {
		m_pos.y = m_player_pos.y;
		m_state = eHeadAttack;
		m_shadow_size = 0;
		m_shadow_x = 0;
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
	//m_shadow.SetRect(0 + m_shadow_size, 0, 174 - m_shadow_size, 45);
	//m_shadow.SetSize((SHADOW_X_SIZE * 1.5 - m_shadow_size), SHADOW_Y_SIZE);

	//150はソート順番調整のための数


	switch (m_state) {
	case Head::eIdle:
		m_img.SetPos(m_pos.x, m_pos.y - 150 - g_game_data.m_scroll.y / 3);
		m_shadow.SetSize((SHADOW_X_SIZE * 1.5 - m_shadow_size), SHADOW_Y_SIZE);
		m_shadow.SetPos(m_pos.x - 100 + m_shadow_x, m_shadow_y - g_game_data.m_scroll.y / 3);
		break;
	case Head::eUp:
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_shadow.SetSize((SHADOW_X_SIZE * 1.5 - m_shadow_size), SHADOW_Y_SIZE);
		m_shadow.SetPos(m_pos.x - 100 + m_shadow_x, m_shadow_y - g_game_data.m_scroll.y / 3);
		break;
	case Head::eFireAttackDown:
	case Head::eHeadAttackDown:
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_shadow.SetSize((SHADOW_X_SIZE / 1.5 + m_shadow_size), SHADOW_Y_SIZE);
		m_shadow.SetPos(m_pos.x - 50 - m_shadow_x, m_shadow_y - g_game_data.m_scroll.y / 3);
		break;
	case Head::eFireAttack:
	case Head::eHeadAttack:
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_shadow.SetSize((SHADOW_X_SIZE * 1.5 - m_shadow_size), SHADOW_Y_SIZE);
		m_shadow.SetPos(m_pos.x - 100, m_shadow_y - g_game_data.m_scroll.y / 3);
		break;
	default:
		break;
	}

	m_img.Draw();
	m_shadow.Draw();


#ifdef _DEBUG
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif

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
		m_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 1.6f, HEIGHT_SIZE - BOSS_Y_SIZE / 5.8f);
		m_center = CVector2D(m_pos.x + m_r, m_pos.y);
	}
	if (m_state == eDownAttack) {
		m_pos = CVector2D(1280 - BOSS_X_SIZE + 150, 0);
	}

	m_idle_cnt = 0;

	m_shadow_size = 0;

	m_shadow.SetColor(0.3f, 0.3f, 0.3f, 0.4f);
}

BossRightHand::~BossRightHand()
{
	Task * p = TaskManager::GetInstance()->FindObject(eGameTitle);
	if (p == nullptr&&m_hp>0)TaskManager::GetInstance()->AddTask(new BossManager());
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
	m_shadow_size += 2;
	m_shadow_x += 1;
	if (m_pos.y < -BOSS_Y_SIZE / 1.5) SetKill();
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

	if (g_game_data.m_boss_hp <= 0) SetKill();
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
		m_img.SetPos(m_pos.x + 50, m_pos.y - g_game_data.m_scroll.y / 3);
		m_img.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);
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
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
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
	m_shadow = COPY_RESOURCE("Shadow", CImage*);

	m_player_pos.x = player_pos.x + 100;
	m_player_pos.y = player_pos.y - 200;

	m_cnt = 0;

	m_r = 25.0;
	m_rot = 0;

	m_slash_flag = false;

	m_state = state;

	if (m_state == eIdle) {
		m_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 2.4, HEIGHT_SIZE - BOSS_Y_SIZE / 6);
		m_shadow_y = m_pos.y;
		m_shadow_x = 0;
		m_center = CVector2D(m_pos.x + m_r, m_pos.y);
	}
	if (m_state == eDownAttack) {
		m_pos = CVector2D(1280 - BOSS_X_SIZE + 200, 0);
		m_shadow_y = m_pos.y;
		m_shadow_x = 0;
	}

	m_idle_cnt = 0;

	m_ang = 90;

	m_shadow_size = 0;

	m_shadow.SetColor(0.3f, 0.3f, 0.3f, 0.4f);
}

BossLeftHand::~BossLeftHand()
{
	Task * p = TaskManager::GetInstance()->FindObject(eGameTitle);
	if (p == nullptr&&m_hp>0)TaskManager::GetInstance()->AddTask(new BossManager());
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
	m_shadow_size += 2;
	m_shadow_x += 1;
	if (m_pos.y < -BOSS_X_SIZE / 1.5) SetKill();
}

void BossLeftHand::DownMove()
{
	m_shadow_y = m_player_pos.y + 180;

	m_pos.x = m_player_pos.x;
	if (m_pos.y <= m_player_pos.y) {
		m_pos.y += 5;
		m_shadow_size += 2;
		m_shadow_x += 1;
	}

	if (m_pos.y > m_player_pos.y) {
		m_pos.y = m_player_pos.y;
		m_state = eHandAttack;
		m_shadow_size = 0;
		m_shadow_x = 0;
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

	if (g_game_data.m_boss_hp <= 0) SetKill();
}

void BossLeftHand::Draw()
{
	m_img.SetRect(0, BOSS_Y_SIZE * 2, BOSS_X_SIZE, BOSS_Y_SIZE * 3);
	switch (m_state) {
	case BossLeftHand::eIdle:
		m_img.SetPos(m_pos.x, m_pos.y - 300 - g_game_data.m_scroll.y / 3);
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


	switch (m_state) {
	case LeftHand::eUp:
		m_shadow.SetSize((SHADOW_X_SIZE * 1.5 - m_shadow_size), SHADOW_Y_SIZE);
		m_shadow.SetPos(m_pos.x - 100 + m_shadow_x, m_shadow_y - g_game_data.m_scroll.y / 3);
		m_shadow.Draw();
		break;
	case LeftHand::eDownAttack:
		m_shadow.SetSize((SHADOW_X_SIZE / 1.5 + m_shadow_size), SHADOW_Y_SIZE);
		m_shadow.SetPos(m_pos.x - 50 - m_shadow_x, m_shadow_y - g_game_data.m_scroll.y / 3);
		m_shadow.Draw();
		break;
	case LeftHand::eHandAttack:
		m_shadow.SetSize((SHADOW_X_SIZE * 1.5 - m_shadow_size), SHADOW_Y_SIZE);
		m_shadow.SetPos(m_pos.x - 100, m_shadow_y - g_game_data.m_scroll.y / 3);
		m_shadow.Draw();
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

BossTail::BossTail(const CVector2D & player_pos, const int state) :EnemyBase(eBossTail)
{
	m_state = state;

	if (m_state == Tail::eIdle) {
		m_img = COPY_RESOURCE("Boss", CAnimImage*);
		m_shadow = COPY_RESOURCE("Shadow", CImage*);
		m_pos = CVector2D(WIGHT_SIZE - BOSS_X_SIZE / 1.6, HEIGHT_SIZE - BOSS_Y_SIZE / 15);
		m_shadow_y = m_pos.y;
		m_shadow_x = 0;
		m_img.ChangeAnimation(Motion2::eBossTailAnim);
	}

	if (m_state == Tail::eDown) {
		m_img = COPY_RESOURCE("Boss2", CImage*);
		m_shadow = COPY_RESOURCE("Shadow", CImage*);
		m_img.SetCenter(BOSS_X_SIZE / 4, BOSS_Y_SIZE / 4);
		m_pos = CVector2D(player_pos.x, 0);
		m_shadow_y = m_pos.y;
		m_shadow_x = 0;
		m_img.ChangeAnimation(Motion1::eBossTailAttackMotion, false);

	}

	m_player_pos.x = player_pos.x + BOSS_X_SIZE / 6;
	m_player_pos.y = player_pos.y;

	m_anim_cnt = 0;

	m_shadow_size = 0;

	m_shadow.SetColor(0.3f, 0.3f, 0.3f, 0.4f);

	m_attack_flag = false;
	m_idle_flag = false;

}

BossTail::~BossTail()
{
	Task * p = TaskManager::GetInstance()->FindObject(eGameTitle);
	if (p == nullptr&&m_hp>0)TaskManager::GetInstance()->AddTask(new BossManager());
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

	if (g_game_data.m_boss_hp <= 0) SetKill();
	m_img.UpdateAnimation();
}

void BossTail::Idle()
{
	m_idle_flag = true;

	if (m_pos.x >= WIGHT_SIZE / 2.26f) {
		m_pos.x -= 0.5;
	}
	else m_pos.y -= 5;
}

void BossTail::TailAttack()
{
	m_anim_cnt++;

	m_img.ChangeAnimation(Motion1::eBossTailAttackMotion, false);

	if (m_img.CheckAnimationEnd()) m_state = eUp;
	//if (m_anim_cnt > 120)m_state = eUp;
}

void BossTail::UpMove()
{
	m_pos.y -= 5;
	m_shadow_size += 2;
	m_shadow_x += 1;
	if (m_pos.y < -BOSS_X_SIZE) SetKill();
}

void BossTail::DownMove()
{
	m_rect = CRect(-80, -100, 80, 10);
	m_shadow_y = m_player_pos.y + 180;

	if (m_pos.y < m_player_pos.y) {
		m_pos.y += 5;
		m_shadow_size += 2;
		m_shadow_x += 1;
	}
	if (m_pos.y >= m_player_pos.y) {
		m_state = eTailAttack;
		m_shadow_size = 0;
		m_shadow_x = 0;
	}
}

void BossTail::HitCheck(Task * _t)
{
}

void BossTail::Draw()
{

#ifdef _DEBUG
#ifdef _DEBUG
	//Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	//Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	//Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	//Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
#endif
#endif

	m_img.SetSize(BOSS_X_SIZE / 3, BOSS_Y_SIZE / 3);

	switch (m_state) {
	case Tail::eIdle:
		m_img.SetPos(m_pos.x, m_pos.y - 200 - g_game_data.m_scroll.y / 3);
		break;
	case Tail::eUp:
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_shadow.SetSize((SHADOW_X_SIZE * 1.5 - m_shadow_size), SHADOW_Y_SIZE);
		m_shadow.SetPos(m_pos.x - 100 + m_shadow_x, m_shadow_y - g_game_data.m_scroll.y / 3);
		break;
	case Tail::eDown:
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_img.SetRect(0, 728, 728, 728 * 2);
		m_shadow.SetSize((SHADOW_X_SIZE / 1.5 + m_shadow_size), SHADOW_Y_SIZE);
		m_shadow.SetPos(m_pos.x - 50 - m_shadow_x, m_shadow_y - g_game_data.m_scroll.y / 3);
		break;
	case Tail::eTailAttack:
		m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
		m_shadow.SetSize((SHADOW_X_SIZE * 1.5 - m_shadow_size), SHADOW_Y_SIZE);
		m_shadow.SetPos(m_pos.x - 100, m_shadow_y - g_game_data.m_scroll.y / 3);
		break;
	default:
		break;
	}

	m_img.Draw();

}

BossDeath::BossDeath() :EnemyBase(eBossTail)
{
	m_img = COPY_RESOURCE("Boss", CImage*);
	m_img2 = COPY_RESOURCE("BossDeathEffect1", CAnimImage*);
	//m_img3 = COPY_RESOURCE("BossDeathEffect2", CAnimImage*);

	m_img.SetSize(BOSS_X_SIZE / 1.5f, BOSS_Y_SIZE / 1.5f);
	m_img2.SetSize(EFFECT_SIZE * 3, EFFECT_SIZE *  2.8f);
	m_img3.SetSize(EFFECT_SIZE * 3, EFFECT_SIZE *  2.8f);

	m_pos = CVector2D(WIGHT_SIZE / 2 - BOSS_X_SIZE / 4, HEIGHT_SIZE - BOSS_Y_SIZE / 1.5f);
	m_pos2 = CVector2D(WIGHT_SIZE / 2 - BOSS_X_SIZE / 2.5, HEIGHT_SIZE - BOSS_Y_SIZE / 2.8f);
	m_pos3 = CVector2D(WIGHT_SIZE / 2 - BOSS_X_SIZE / 2.5, HEIGHT_SIZE - BOSS_Y_SIZE / 2.8f);

	m_img3.SetCenter(BOSS_Y_SIZE / 4, BOSS_Y_SIZE / 4);
}

BossDeath::~BossDeath()
{
	TaskManager::GetInstance()->AddTask(new GameClear());
}

void BossDeath::Update()
{
	m_img2.ChangeAnimation(eBossDeathEffect1);
	m_img2.UpdateAnimation();
	m_img3.ChangeAnimation(eBossDeathEffect2);
	m_img3.UpdateAnimation();

	m_pos.y -= 6;
	if (m_pos.y < -BOSS_Y_SIZE / 1.5f)SetKill();
}

void BossDeath::Draw()
{
	#ifdef _DEBUG
		Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
		Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos2.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
		Utility::DrawQuad(CVector2D(m_pos2.x + m_rect.m_right, m_pos2.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
		Utility::DrawQuad(CVector2D(m_pos2.x + m_rect.m_right, m_pos2.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	#endif

	m_img.SetRect(0, BOSS_Y_SIZE * 2, BOSS_X_SIZE, BOSS_Y_SIZE * 3);
	m_img.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y / 3);
	m_img2.SetPos(m_pos2.x + 50, m_pos2.y - 200 - g_game_data.m_scroll.y / 3);
	m_img3.SetPos(m_pos3.x, m_pos3.y - g_game_data.m_scroll.y / 3);

	m_img.Draw();
	m_img2.Draw();
	//m_img3.Draw();
}
