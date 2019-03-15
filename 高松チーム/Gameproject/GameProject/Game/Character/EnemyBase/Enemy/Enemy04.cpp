#include "Enemy04.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Global.h"
#include "../GameProject/Game/GameData/GameData.h"
#define DEP_N 1200
Enemy04::Enemy04() : EnemyBase(CharacterData::eEnemy04),
m_hight(0.0f),
m_search_flg(false)
{
	m_img = COPY_RESOURCE("Enemy04", CAnimImage*);
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_img.ChangeAnimation(Enemy04Anim::eEIdile04);
}

Enemy04::Enemy04(CVector2D _pos) : EnemyBase(CharacterData::eEnemy04),
m_hight(0.0f),
m_search_flg(false)
{
	m_img = COPY_RESOURCE("Enemy04", CAnimImage*);
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_img.ChangeAnimation(Enemy04Anim::eEDeath04);
	m_shadow = COPY_RESOURCE("Shadow", CImage*);
	m_pos = _pos;
	m_vec = CVector2D(0, 0);
	m_dir = CVector2D(0, 0);
	m_state = eSearch;
	m_depth = m_pos.y / DEP_N;

}

void Enemy04::Update()
{
}

void Enemy04::Draw()
{
	m_img.UpdateAnimation();
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_img.SetPos(m_pos);//(CVector2D(m_pos.x - g_game_data.m_scroll.x, m_pos.y + m_hight - g_game_data.m_scroll.y / 3));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}

void Enemy04::Move()
{
}

void Enemy04::Search()
{
}

void Enemy04::Attack()
{
}

void Enemy04::Damage()
{
}

void Enemy04::MoveControl()
{
}
