#include "Enemy05.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Game/Resource/Resource.h"

Enemy05::Enemy05() : EnemyBase(eEnemy05)
{
	m_pos = CVector2D(100, 100);
	m_img = COPY_RESOURCE("Enemy05", CAnimImage*);
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_pos = CVector2D(200, 200);
	m_vec = CVector2D(0, 0);
}

void Enemy05::Move()
{
}

void Enemy05::Attack()
{
}

void Enemy05::Update()
{
}

void Enemy05::Draw()
{

}
