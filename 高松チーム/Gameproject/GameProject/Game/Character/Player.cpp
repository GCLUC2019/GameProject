#include "Player.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../Character/Anim/AnimDataPlayer.h"
#include <stdio.h>
#include"Effect/PlayerEffect.h"
#include"../GameData/GameData.h"
#include"../Scene/Title.h"
#include"../Item/Item.h"
#define GRAVITY -4//重力
#define DEP_N 540//奥行重石
#define JUMP_SPD 50


Player::Player() : CharacterBase(CharacterData::ePlayer),
m_speed(4.0f),
m_squat_flg(false),
m_attack_flg(false),
m_jump_flg(false),
m_flip(false),
m_special_flg(false),
m_damage_flg(false), 
m_death_flg(false),
m_jump_vec(0),
m_state(eIdle),
m_state_old(m_state),
m_HP(100),
m_special(0)
{
	m_pos = CVector2D(1280/2, 540);
	m_img = COPY_RESOURCE("Player",CAnimImage*);
	m_shadow= COPY_RESOURCE("Shadow", CImage*);
	m_depth = (m_pos.y - DEP_N)/3.5;
	SetAnim();
	m_shadow.SetColor(0.3f, 0.3f, 0.3f, 0.4f);
	m_rect = CRect(-50, -50, 50, 50);
}

void Player::HitCheck()
{
}

void Player::Move()
{
	if (m_death_flg) {
		m_squat_flg = false;
		return;
	}


	if (m_special_flg)
		return;
	if (m_jump_flg != true) {
		if (CInput::GetState(0, CInput::eHold, CInput::eButton1) && m_jump_flg == false && m_attack_flg == false) {
			m_squat_flg = true;

			m_state = eSquat;
		}
		else
			m_squat_flg = false;


		if (CInput::GetState(0, CInput::ePush, CInput::eButton2) && m_attack_flg == false && m_squat_flg == false && m_damage_flg == false) {
			m_attack_flg = true;
			m_state = eAttack01;
		}
		if (CInput::GetState(0, CInput::ePush, CInput::eButton4) && m_attack_flg == false && m_squat_flg == false && m_damage_flg == false) {
			m_attack_flg = true;
			m_state = eAttack04;
		}
		if (CInput::GetState(0, CInput::ePush, CInput::eButton3) && m_squat_flg == false && m_attack_flg == false) {
			m_jump_flg = true;
			m_state = eJumpUp;
		}
	}
	else 
		Jump();
	if (m_squat_flg || m_attack_flg)
		return;

	if (CInput::GetState(0, CInput::eHold, CInput::eUp)) {
		m_pos.y -= m_speed;
		m_depth =( m_pos.y - DEP_N)/3.5;
		if (m_jump_flg == false)
			m_state = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown)) {
		m_pos.y += m_speed;
		m_depth = (m_pos.y - DEP_N)/3.5;
		if (m_jump_flg == false)
			m_state = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eRight)) {
		m_pos.x += m_speed;
		m_flip = true;
		if (m_jump_flg == false)
			m_state = eMove;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft)) {
		m_pos.x -= m_speed;
		m_flip = false;
		if (m_jump_flg == false)
			m_state = eMove;
	}

	if (m_squat_flg == false && m_attack_flg == false && m_jump_flg == false && m_pos.x == m_pos_old.x&&m_pos.y == m_pos_old.y)
		m_state = eIdle;
}

void Player::Jump()
{
	static float time = 0;

	if (m_death_flg) {
		m_jump_flg = false;
		time = 0;
		return;
	}
	static int jump_vec_old = m_jump_vec;
	jump_vec_old = m_jump_vec;
	m_jump_vec = 0 + JUMP_SPD * time + GRAVITY * (time*time) / 2;
	m_jump_vec *= -1;
	if (jump_vec_old - m_jump_vec < 0)
		m_state = eJumpDown;
	time += 0.5f;
	if (m_jump_vec > 0) {
		time = 0;
		m_jump_vec = 0;
		m_jump_flg = false;
    }
	g_game_data.m_scroll.y =  m_jump_vec;
}

void Player::Attack()
{
	static int k = 0;
	if (m_death_flg) {
		m_attack_flg = false;
		k = 0;
		return;
	}
	switch (m_state)
	{
	case eAttack01:
		if (k == 10) {
			if (m_flip)
				TaskManager::GetInstance()->AddTask(new PlayerEffectShortAttack01(m_pos + CVector2D(25, -20), m_flip));
			else
				TaskManager::GetInstance()->AddTask(new PlayerEffectShortAttack01(m_pos - CVector2D(25, -20), m_flip));
		}
		if (CInput::GetState(0, CInput::ePush, CInput::eButton2) && k > 11) {
			m_state = eAttack02;
			k = 0;
		}
		if (CInput::GetState(0, CInput::eHold, CInput::eButton1)) {
			k = 0;
			m_attack_flg = false;
			m_squat_flg = true;
			m_state = eSquat;
		}
		if (k >= 60 || m_squat_flg || m_damage_flg) {
			k = 0;
			m_attack_flg = false;
		}
		break;
	case eAttack02:
		if (k == 10) {
			if (m_flip)
				TaskManager::GetInstance()->AddTask(new PlayerEffectShortAttack02(m_pos + CVector2D(25, -20), m_flip));
			else
				TaskManager::GetInstance()->AddTask(new PlayerEffectShortAttack02(m_pos - CVector2D(25, -20), m_flip));
		}
		if (CInput::GetState(0, CInput::ePush, CInput::eButton2) && k > 11) {
			m_state = eAttack03;
			k = 0;
		}
		if (CInput::GetState(0, CInput::eHold, CInput::eButton1)) {
			k = 0;
			m_attack_flg = false;
			m_squat_flg = true;
			m_state = eSquat;
		}
		if (k >= 60 || m_squat_flg) {
			k = 0;
			m_attack_flg = false;
		}
		break;
	case eAttack03:
		if (k == 10) {
			if (m_flip)
				TaskManager::GetInstance()->AddTask(new PlayerEffectShortAttack03(m_pos + CVector2D(25, -20), m_flip));
			else
				TaskManager::GetInstance()->AddTask(new PlayerEffectShortAttack03(m_pos - CVector2D(25, -20), m_flip));
		}
		if (CInput::GetState(0, CInput::eHold, CInput::eButton1)) {
			k = 0;
			m_attack_flg = false;
			m_squat_flg = true;
			m_state = eSquat;
		}
		if (k >= 30 || m_squat_flg) {
			k = 0;
			m_attack_flg = false;
		}
		break;
	case eAttack04:
		if (k == 30) {
			if (m_flip)
				TaskManager::GetInstance()->AddTask(new PlayerEffectLongAttack((m_pos), m_flip));
			else
				TaskManager::GetInstance()->AddTask(new PlayerEffectLongAttack((m_pos), m_flip));
		}
		if (CInput::GetState(0, CInput::eHold, CInput::eButton1)) {
			k = 0;
			m_attack_flg = false;
			m_squat_flg = true;
			m_state = eSquat;
		}
		if (k >= 100 || m_squat_flg) {
			k = 0;
			m_attack_flg = false;
		}
		break;
	default:
		k = 0;
		m_attack_flg = false;
		break;
	}
	//if (m_damage_flg) {
	//	k = 0;
	//	m_attack_flg = false;
	//}

	k++;
}
void Player::Special()
{
	static int time = 300;
	if (time == 300) {
		TaskManager::GetInstance()->AddTask(new PlayerEffectSpecialAttack(m_pos));
		m_state = eSpecial;
		SetAnim();
	}



	time--;
	if (time <= 0) {
		time = 300;
		m_special_flg = false;

	}


}

void Player::SetAnim()
{
	switch (m_state)//状態デバック表示
	{
	case eIdle://待機
		m_img.ChangeAnimation(ePIdle);

	break;
	case	eMove://移動
		m_img.ChangeAnimation(ePRun);
	break;
	case	eJumpUp://ジャンプ
		m_img.ChangeAnimation(ePJumpUp);
	break;
	case	eJumpDown://ジャンプ
		m_img.ChangeAnimation(ePJumpDown);
		break;
	case	eSquat://しゃがみ
		m_img.ChangeAnimation(ePCrouch,false);
	break;
	case	eAttack01://近距離攻撃
		m_img.ChangeAnimation(ePShortAttack01,false);
	break;
	case	eAttack02:
		m_img.ChangeAnimation(ePShortAttack02, false);
	break;
	case	eAttack03:
		m_img.ChangeAnimation(ePShortAttack03, false);
	break;
	case	eAttack04://遠距離攻撃
		m_img.ChangeAnimation(ePLongAttack, false);
	break; 	
	case	eDamage://ダメージ
		m_img.ChangeAnimation(ePDamage, false);
		break;
	case	eDeath://死亡
		m_img.ChangeAnimation(ePDeath, false);
		break;
	case	eUp://起き上がり
		m_img.ChangeAnimation(ePUp, false);
		break;
	case	eSpecial://必殺
		m_img.ChangeAnimation(ePLongAttack, false);
		break;
	default:
		m_img.ChangeAnimation(ePIdle);
	break;
	}


}

void Player::Update()
{
#ifdef _DEBUG
	if (CInput::GetState(0, CInput::eHold, CInput::eMouseL))
		Damage(50);
	if (CInput::GetState(0, CInput::eHold, CInput::eMouseR))
		ItemGet(ItemList::eKoban);
#endif // _DEBUG

	if (m_death_flg) {
		Death();
		return;
	}
		
	m_img.SetColor(1, 1, 1, 1);
	if (CInput::GetState(0, CInput::eHold, CInput::eButton5) && m_attack_flg == false)
		m_special_flg = true;
	m_state_old = m_state;
	m_pos_old = m_pos;
	if (m_special_flg) {
		Special();
		return;
	}
		
	if (m_damage_flg)
		DamageState();
	else
		Move();
	if (m_attack_flg)
		Attack();
	if (m_pos.x < 0 || m_pos.x > 1280)
		m_pos.x = m_pos_old.x;
	if (m_pos.y < 480 || m_pos.y > 720)
		m_pos.y = m_pos_old.y;
	
	if (m_state != m_state_old)
		SetAnim();
	
}
void Player::DamageState()
{
	m_img.SetColor(0.5f, 0.5f, 0.5f, 1);
	static int time = 60;
	time--;
	m_state = eDamage;
	/*if (m_HP < 0) {
		m_state = eDeath;
		SetAnim();
	}*/
	if (time < 30)
		Move();
	if (time < 0) {
		time = 60;
		m_damage_flg = false;	
	}
}
void Player::Death()
{
	static int time = 300;
	if (time == 299) {
		Attack();
		Jump();
		Move();
	}
	time--;
	if (time <= 0)
	{
		TaskManager::GetInstance()->KillAll();
		TaskManager::GetInstance()->AddTask(new Title());
		time = 300;
	}
}
void Player::Draw()
{
#ifdef _DEBUG
	//Utility::DrawQuad(CVector2D(0, 720 / 2), CVector2D(1280, 720), CVector4D(1.0f, 0, 0, 1));
	
#endif // _DEBUG

	
#define SAIZE 150
#define SAIZE_SD 100
	
	m_img.UpdateAnimation();
    g_game_data.m_scroll.x = m_pos.x;
    if(g_game_data.m_scroll.x<0)g_game_data.m_scroll.x = 0;

	m_img.SetSize(SAIZE + m_depth, SAIZE + m_depth);
	m_img.SetCenter((SAIZE + m_depth) / 2, (SAIZE + m_depth));
	m_img.SetPos(m_pos+CVector2D(0, m_jump_vec));
	m_img.SetFlipH(m_flip);
	m_shadow.SetSize(SAIZE_SD + m_depth+m_jump_vec/5, SAIZE_SD + m_depth + m_jump_vec / 5);
	m_shadow.SetCenter((SAIZE_SD + m_depth + m_jump_vec / 5) / 2, (SAIZE_SD + m_depth + m_jump_vec / 5) / 2);
    m_shadow.SetPos(m_pos.x, m_pos.y - g_game_data.m_scroll.y);
	m_shadow.Draw();
	m_img.Draw();
		
}

void Player::ItemGet(int _itemTyp)
{
	
	switch (_itemTyp)
	{
	case ItemList::eHyoutan:
		if (m_HP < 100)
			m_HP += 10;
		if (m_HP > 100)
			m_HP = 100;
		break;
	case ItemList::eInari:
		g_game_data.m_score += 10;

		break;
	case ItemList::eKakera:
		

		break;
	case ItemList::eKoban:

		g_game_data.m_score += 1;
		break;

	default:
		break;
	}

}


void Player::Damage(int _damage)
{
	if (m_damage_flg || m_special_flg)
		return;
	m_HP -= _damage;
	if (m_HP <= 0) {
		m_state = eDeath;
		m_death_flg = true;
		SetAnim();
		return;
	}
	m_damage_flg = true;
}
