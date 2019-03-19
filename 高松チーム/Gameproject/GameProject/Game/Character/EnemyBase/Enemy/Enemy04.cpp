#include "Enemy04.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Global.h"
#include "../GameProject/Game/GameData/GameData.h"
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
m_movetyp_flg(false),
m_cnt(0),
m_attack_cnt(0)
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
}

void Enemy04::Update()
{
	m_pos_old = m_pos;
	m_state_old = m_state;
	m_distance = TaskManager::GetInstance()->FindObject(ePlayer)->GetPos() - m_pos;
	m_vec = m_distance.GetNormalize();
	if (m_distance.x > 0)
		m_flip = true;
	else
		m_flip = false;
	m_img.ChangeAnimation(Enemy04Anim::eEIdile04);
	
	
	if (m_attack_flg == false) {
		if (m_cnt >= 0) {
			m_cnt--;
			if (m_cnt == 0) {
				m_cnt = -60;
				m_movetyp_flg = !m_movetyp_flg;
			}
				
		}

		if (m_cnt <= 0) {
			m_cnt++;
			Move();
			if (m_cnt == 0)
				m_cnt = 60;
		}
	}
	

	//SetAnim();
	if (m_pos.x <-30 || m_pos.x > 1310)
		m_pos.x = m_pos_old.x;
	/*if (m_pos.y < 480 || m_pos.y > 720)
		m_pos.y = m_pos_old.y;*/
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
	m_img.SetPos(m_pos + CVector2D(0, -m_hight));//(CVector2D(m_pos.x - g_game_data.m_scroll.x, m_pos.y + m_hight - g_game_data.m_scroll.y / 3));
	m_img.SetFlipH(m_flip);
	m_shadow.SetSize(SAIZE_SD, SAIZE_SD);
	m_shadow.SetCenter(SAIZE_SD / 2, SAIZE_SD / 2);
	m_shadow.SetPos(m_pos);
	m_shadow.Draw();
	m_img.Draw();
}

void Enemy04::EXAttack()
{
	m_attack_flg = true;
	if (m_interval_flg) {
		m_flip = !m_flip;
		m_img.ChangeAnimation(Enemy04Anim::eAttackCat02);
		if (m_attack_cnt > 30) {
			m_cnt = 120;
			m_attack_cnt = 0;
			m_interval_flg = false;
			m_attack_flg = false;
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
				m_pos.x = 50;
			else if (m_pos.x < 150)
				m_pos.x = 1250;
			m_img.ChangeAnimation(Enemy04Anim::eAttackCat02);
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
	if (m_interval_flg) {
		m_img.ChangeAnimation(Enemy04Anim::eAttackCat01);
		if (m_attack_cnt > 20) {
			m_cnt = 120;
			m_attack_cnt = 0;
			m_interval_flg = false;
			m_attack_flg = false;
		}
	}
	else {
		m_hight--;
		m_img.ChangeAnimation(Enemy04Anim::eAttackCat02);
		if (m_attack_cnt > 30) {
			m_img.ChangeAnimation(Enemy04Anim::eAttackCat01);
			m_pos.x += m_vec.x * -20;
			m_attack_cnt = 0;
			m_interval_flg = true;
			m_hight = 0;
		}
	}
	m_attack_cnt++;
}

void Enemy04::SAttack()
{
	
	m_attack_flg = true;
	if (m_interval_flg) {
		m_img.ChangeAnimation(Enemy04Anim::eAttackCat02);
		if (m_attack_cnt > 40) {
			m_cnt = 120;
			m_attack_cnt = 0;
			m_interval_flg = false;
			m_attack_flg = false;
		}
	}
	else {
		m_img.ChangeAnimation(Enemy04Anim::eAttackCat01);
		m_pos.x += m_vec.x * 15;
		if (m_attack_cnt > 40 || m_distance.x < 30 && m_distance.x > -30) {
			m_img.ChangeAnimation(Enemy04Anim::eAttackCat02);
			m_attack_cnt = 0;
			m_interval_flg = true;
		}
	}
	m_attack_cnt++;
}

void Enemy04::Damage()
{
}

void Enemy04::Move()
{
	if (m_movetyp_flg)
		Alignment_y();
	else
		AttackControl();

			
}

void Enemy04::AttackControl()
{
	float p = m_distance.x;
	if (p<3.1f&&p>-3.1f)
		return;
	if (p > 0) {
		m_img.ChangeAnimation(Enemy04Anim::eEMove04);
		m_pos.x += 3.0f;
	}
	else {
		m_img.ChangeAnimation(Enemy04Anim::eEMove04);
		m_pos.x -= 3.0f;
	}

}

void Enemy04::Alignment_y()
{
	float p = m_distance.y;
	if (p<3.1f&&p>-3.1f)
		return;
	if (p > 0) {
		m_img.ChangeAnimation(Enemy04Anim::eEMove04);
		m_pos.y += 3.0f;
	}
	else {
		m_img.ChangeAnimation(Enemy04Anim::eEMove04);
		m_pos.y -= 3.0f;
	}

}


