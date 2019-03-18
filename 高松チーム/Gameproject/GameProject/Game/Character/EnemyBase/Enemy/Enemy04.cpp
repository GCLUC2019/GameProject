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
m_cnt(0),
m_exattack_flg(false),
 m_sattack_flg(false),
 m_lattack_flg(false)
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

}

void Enemy04::Update()
{
	m_pos_old = m_pos;
	m_state_old = m_state;
	m_distance = TaskManager::GetInstance()->FindObject(ePlayer)->GetPos() - m_pos;
	m_vec = m_distance.GetNormalize();
	
	if (m_distance.x < 0)
		m_flip = false;
	else
		m_flip = true;

	if (m_exattack_flg)
		EXAttack();
	else if (m_sattack_flg)
		SAttack();
	else if (m_lattack_flg)
		LAttack();
	else
		MoveControl();
	
	AttackControl();
	if (m_interval_flg)
		m_cnt--;
	if (m_cnt < 0);
		m_interval_flg = false;


	
	//SetAnim();
	if (m_pos.x <0 || m_pos.x > 1280)
		m_pos.x = m_pos_old.x;
	/*if (m_pos.y < 480 || m_pos.y > 720)
		m_pos.y = m_pos_old.y;*/
}

void Enemy04::Draw()
{
	m_img.UpdateAnimation();
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE );
	m_img.SetPos(m_pos);//(CVector2D(m_pos.x - g_game_data.m_scroll.x, m_pos.y + m_hight - g_game_data.m_scroll.y / 3));
	m_img.SetFlipH(m_flip);
	m_shadow.SetSize(SAIZE_SD, SAIZE_SD);
	m_shadow.SetCenter(SAIZE_SD / 2, SAIZE_SD / 2);
	m_shadow.SetPos(m_pos);
	m_shadow.Draw();
	m_img.Draw();
}

void Enemy04::EXAttack()
{
	
}

void Enemy04::LAttack()
{
	m_pos.x += m_vec.x;
	m_cnt++;
	printf("LAttack\n");
	if (m_cnt > 30) {
		m_cnt = 120;
		m_sattack_flg = false;

	}
}

void Enemy04::SAttack()
{
	m_pos.x -= m_vec.x;
	m_cnt++;
	printf("SAttack\n");
	if (m_cnt > 30) {
		m_cnt = 120;
		m_sattack_flg = false;

	}
}

void Enemy04::Damage()
{
}

void Enemy04::Alignment_y()
{
	float p = m_distance.y;
	 /*printf("%f\n", p);*/
	 if (p<3.1f&&p>-3.1f)
		 return;
	if (p > 0)
		m_pos.y += 3.0f;
	else
		m_pos.y -= 3.0f;

}

void Enemy04::AttackControl()
{
	if (m_interval_flg)
		return;
	/*if (m_pos.x < 150 || m_pos.x > 1130)
		m_exattack_flg = true;*/
	if (m_distance.x < 400 && m_distance.x>350 || m_distance.x > -400 && m_distance.x < -350)
		m_sattack_flg = true;
	if (m_distance.x < 150 || m_distance.x > -150)
		m_lattack_flg = true;

}

void Enemy04::MoveControl()
{
	Alignment_y();
}

void Enemy04::SetAnim()
{
	if (m_state == m_state_old)
		return;
	switch (m_state)
	{
	case eIdle:
		m_img.ChangeAnimation(Enemy04Anim::eEIdile04);
		break;
	case eMove:
		m_img.ChangeAnimation(Enemy04Anim::eEMove04, false);
		break;
	case eEXAttack:
		break;
	case eLAttack:
		break;
	case eSAttack:
		break;
	case eDamage:
		break;
	case eDeath:
		break;
	default:
		break;
	}
}
