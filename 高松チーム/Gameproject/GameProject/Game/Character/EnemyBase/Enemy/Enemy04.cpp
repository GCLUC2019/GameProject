#include "Enemy04.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Global.h"
#include "../GameProject/Game/GameData/GameData.h"
#include "../../Effect/EnemyEffect.h"
#include "../../../CollitionBase.h"
#define DEP_N 1200
Enemy04::Enemy04() : EnemyBase(CharacterData::eEnemy04),
m_hight(0.0f)
{
	m_img = COPY_RESOURCE("Enemy04", CAnimImage*);
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_img.ChangeAnimation(Enemy04Anim::eEIdile04);
}

Enemy04::Enemy04(CVector2D _pos) : EnemyBase(CharacterData::eEnemy04),
m_hight(0.0f),
m_interval_flg(false),
m_attack_flg(false),
m_sattack_flg(false),
m_lattack_flg(false),
m_exattack_flg(false),
m_movetyp_flg(false),
m_movexy_flg(false),
m_cnt(0),
m_attack_cnt(0),
m_damage_cnt(0)
{
	m_img = COPY_RESOURCE("Enemy04", CAnimImage*);
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_img.ChangeAnimation(Enemy04Anim::eEIdile04);
	m_shadow = COPY_RESOURCE("Shadow", CImage*);
	m_pos = _pos;
	m_vec = CVector2D(0, 0);
	m_state = Enemy04State::eIdle;
	m_depth = m_pos.y / DEP_N;
	m_rect = CRect(-IMAGE_SIZE / 3, -IMAGE_SIZE , IMAGE_SIZE / 3, IMAGE_SIZE/3 );
	m_hp = 100;
}

void Enemy04::Update()
{
#ifdef _DEBUG
	/*if (CInput::GetState(0, CInput::ePush, CInput::eMouseL))
	Damage(50);*/
	if (CInput::GetState(0, CInput::ePush, CInput::eMouseR))
		TaskManager::GetInstance()->AddTask(new E4EffectEXAttack(m_pos));
#endif // _DEBUG

	m_pos_old = m_pos;
	m_state_old = m_state;
	m_distance = TaskManager::GetInstance()->FindObject(ePlayer)->GetPos() - m_pos;
	m_vec = m_distance.GetNormalize();
	if (m_distance.x > 0)
		m_flip = true;
	else
		m_flip = false;
	m_img.ChangeAnimation(Enemy04Anim::eEIdile04);	

	Move();

	//SetAnim();
	if (m_pos.x <0 || m_pos.x > 1280)
		m_pos.x = m_pos_old.x;
	if (m_pos.y < 480 || m_pos.y > 720)
		m_pos.y = m_pos_old.y;
}

void Enemy04::Draw()
{
#ifdef _DEBUG
	//Utility::DrawQuad(CVector2D(0, 720 / 2), CVector2D(1280, 720), CVector4D(1.0f, 0, 0, 1));

	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_left, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_top), CVector2D(4, 4), CVector4D(1, 0, 0, 1));
	Utility::DrawQuad(CVector2D(m_pos.x + m_rect.m_right, m_pos.y + m_rect.m_bottom), CVector2D(4, 4), CVector4D(1, 0, 0, 1));

#endif // _DEBUG

	m_img.UpdateAnimation();
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE );
	m_img.SetPos(m_pos + CVector2D(-g_game_data.m_scroll.x, -m_hight - g_game_data.m_scroll.y / 3));
	m_img.SetFlipH(m_flip);
	m_shadow.SetSize(SAIZE_SD, SAIZE_SD);
	m_shadow.SetCenter(SAIZE_SD / 2, SAIZE_SD / 2);
	m_shadow.SetPos(m_pos - CVector2D(-g_game_data.m_scroll.x,  g_game_data.m_scroll.y / 3));
	m_shadow.Draw();
	m_img.Draw();
}

void Enemy04::EXAttack()
{
	m_attack_flg = true;
	m_exattack_flg = true;
	if (m_interval_flg) {
		m_flip = !m_flip;
		m_img.ChangeAnimation(Enemy04Anim::eAttackCat02);
		if (m_attack_cnt > 30) {
			m_img.ChangeAnimation(Enemy04Anim::eEMove04);
			m_pos.x += m_vec.x * 2;
			m_flip = !m_flip;
		}
		if (m_attack_cnt > 60) {
			m_cnt = 90;
			m_attack_cnt = 0;
			m_interval_flg = false;
			m_attack_flg = false;
			m_exattack_flg = false;
			return;
		}
		
	}
	else {
		if (m_attack_cnt < 30) {
			m_pos.x -= m_vec.x;
			m_hight++;
			Alignment_y();
			m_img.ChangeAnimation(Enemy04Anim::eAttackCat01);
		}
		if (m_attack_cnt >= 30) {
	
			if (m_pos.x > 1200)
				m_pos.x = 200;
			else if (m_pos.x < 150)
				m_pos.x = 1150;
			m_img.ChangeAnimation(Enemy04Anim::eAttackCat02);
			TaskManager::GetInstance()->AddTask(new E4EffectEXAttack(m_pos));
			m_hight = 0;
			m_flip = !m_flip;
			m_attack_cnt = 0;	
			m_interval_flg = true;
		}
	}
	m_attack_cnt++;
}

void Enemy04::LAttack()
{
	m_attack_flg = true;
	m_lattack_flg = true;
	if (m_interval_flg) {
		m_img.ChangeAnimation(Enemy04Anim::eAttackCat01);
		if (m_attack_cnt > 20) {
			m_cnt = 30;
			m_attack_cnt = 0;
			m_interval_flg = false;
			m_attack_flg = false;
			m_lattack_flg = false;
		}
	}
	else {
		m_hight--;
		m_img.ChangeAnimation(Enemy04Anim::eAttackCat02);
		if (m_attack_cnt > 30) {
			m_img.ChangeAnimation(Enemy04Anim::eAttackCat01);
			m_pos.x += m_vec.x * -20;
			TaskManager::GetInstance()->AddTask(new E4EffectLAttack(m_pos, m_flip));
			m_attack_cnt = 0;
			m_interval_flg = true;
			m_hight = 0;
		}
	}
	m_attack_cnt++;
}

void Enemy04::SAttack()
{
	m_sattack_flg = true;
	m_attack_flg = true;
	if (m_interval_flg) {
		m_img.ChangeAnimation(Enemy04Anim::eAttackCat02);
		if (m_attack_cnt > 30) {
			m_img.ChangeAnimation(Enemy04Anim::eEIdile04);
			m_pos.x -= m_vec.x * 2;
			m_hight = -20;
			if (m_attack_cnt > 90) {
				m_hight = 0;
				m_cnt = 60;
				m_attack_cnt = 0;
				m_interval_flg = false;
				m_attack_flg = false;
				m_sattack_flg = false;
			}
		}
		
	}
	else {
		m_img.ChangeAnimation(Enemy04Anim::eAttackCat01);
		m_pos.x += m_vec.x * 15;
		if (m_attack_cnt > 40 || m_distance.x < 30 && m_distance.x > -30) {
			if (m_flip)
				TaskManager::GetInstance()->AddTask(new E4EffectSAttack(m_pos + CVector2D(20, 0)));
			else
				TaskManager::GetInstance()->AddTask(new E4EffectSAttack(m_pos + CVector2D(-20, 0)));
			m_img.ChangeAnimation(Enemy04Anim::eAttackCat02);
			m_attack_cnt = 0;
			m_interval_flg = true;
		}
	}
	m_attack_cnt++;
}

void Enemy04::Damage(const float& _damage)
{
	if (m_damage_flg)
		return;
	m_hp -= _damage;
	m_damage_flg = true;
	if (m_hp <= 0)
		m_damage_cnt = 60;
	else
		m_damage_cnt = 30;

}

void Enemy04::Move()
{

	if (m_attack_flg ) {
		if (m_interval_flg)
			DamageState();

		if (m_sattack_flg)
			SAttack();
		if (m_lattack_flg)
			LAttack();
		if (m_exattack_flg)
			EXAttack();
	}
	else {
		if (m_damage_flg) {
			DamageState();
			return;
		}

		if (m_cnt >= 0) {
			m_cnt--;
			if (m_cnt == 0) {
				m_cnt = -60;
				m_movetyp_flg = !m_movetyp_flg;
				m_movexy_flg = Utility::Rand(0, 5000) % 2;
			}

		}

		if (m_cnt <= 0) {
			m_cnt++;

			if (m_movetyp_flg)
				Alignment_y();
			else
				AttackControl();
			if (m_cnt == 0)
				m_cnt = 60;
		}
	}
	



}

void Enemy04::AttackControl()
{
	float py = m_distance.y;
	float px = m_distance.x;
	/*if (py < 40.0f && py > -40.0f) {//‚Ê‚é‚¯‚ê‚ÎŽg‚¤
		if (m_pos.x > 1200 || m_pos.x < 150) {
			m_attack_flg = true;
			m_exattack_flg = true;
			return;
		}
		if (px < 400.0f && px > -400.0f) {
			m_attack_flg = true;
			m_sattack_flg = true;
			return;
		}
		if (px > 400.0f || px < -400.0f) {
			m_attack_flg = true;
			m_lattack_flg = true;
			return;
		}
	}*/
	
	if (px < 200.0f && px > -200.0f)
		m_movexy_flg = false;
	if (px > 600.0f || px < -600.0f)
		m_movexy_flg = true;
	/*if (px<3.1f&&px>-3.1f)
		return;*/

	if(m_movexy_flg)
		m_pos.x += 3.0f;
	else
		m_pos.x -= 3.0f;
	m_img.ChangeAnimation(Enemy04Anim::eEMove04);
	/*if (px > 0) {
		m_img.ChangeAnimation(Enemy04Anim::eEMove04);
		m_pos.x -= 3.0f;
	}
	else {
		m_img.ChangeAnimation(Enemy04Anim::eEMove04);
		m_pos.x += 3.0f;
	}*/

}

void Enemy04::Alignment_y()
{
	float py = m_distance.y;
	float px = m_distance.x;
	if (py < 40.0f && py > -40.0f) {
		if (m_pos.x > 1200 || m_pos.x < 150) {
			m_attack_flg = true;
			m_exattack_flg = true;
			return;
		}
		if (px < 400.0f && px > -400.0f) {
			m_attack_flg = true;
			m_sattack_flg = true;
			return;
		}
		if (px > 400.0f || px < -400.0f) {
			m_attack_flg = true;
			m_lattack_flg = true;
			return;
		}
	}

	if (py<3.1f&&py>-3.1f)
		return;
	if (py > 0) {
		m_img.ChangeAnimation(Enemy04Anim::eEMove04);
		m_pos.y += 3.0f;
	}
	else {
		m_img.ChangeAnimation(Enemy04Anim::eEMove04);
		m_pos.y -= 3.0f;
	}

}

void Enemy04::DamageState()
{
	if (m_damage_cnt <= 0) {
		if (m_hp <= 0)
			SetKill();
		m_damage_flg = false;
	}
	
	m_img.ChangeAnimation(Enemy04Anim::eEDamage04);
	if (m_hp <= 0&& m_damage_cnt <= 30)
		m_img.ChangeAnimation(Enemy04Anim::eEDeath04);
	m_damage_cnt--;
}

void Enemy04::HitCheck()
{
	if (CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack01, 50.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack02, 50.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectShortAttack03, 50.0f) ||
		CollitionBase::CollisionCheckRectANDY(this, CharacterData::ePEffectLongAttack, 50.0f))
	{
		Damage(10);
	}
}


