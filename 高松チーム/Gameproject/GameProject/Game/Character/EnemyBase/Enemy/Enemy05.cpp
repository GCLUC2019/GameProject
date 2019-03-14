#include "Enemy05.h"
#include "../../Anim/AnimData.h"
#include "../GameProject/Game/Resource/Resource.h"
#include "../../CharacterBase.h"
#include "../../Player.h"
#include "../GameProject/Game/CollitionBase.h"
#include "../GameProject/Game/GameData/GameData.h"
#define MOVE_ 360

#define GRAVITY -4//�d��
#define DEP_N 540//���s�d��
#define JUMP_SPD 50
#define SAIZE_SD 110

Enemy05::Enemy05(CVector2D& _pos) : EnemyBase(eEnemy05),
m_move_cnt(0)
{
	//������
	m_img = COPY_RESOURCE("Enemy05", CAnimImage*);
	m_shadow = COPY_RESOURCE("Shadow", CImage*);
	m_rect = CRect(-IMAGE_SIZE / 2.7f,-IMAGE_SIZE / 4.0f, IMAGE_SIZE / 3.0f, IMAGE_SIZE / 2.3f);
	m_pos = _pos;
	m_vec = CVector2D(0, 0);
	m_hp = 100;
	m_img.SetFlipH(m_flip);
	m_move_cnt = 0;
	m_depth = (m_pos.y - DEP_N) / 3.5;
	m_state = eMove;
}

void Enemy05::Move()
{
	MoveManagement(0);
	m_img.ChangeAnimation(eEMove05);
}

void Enemy05::MoveManagement(int _type)
{
	switch (_type) {
	case 0:
		//���ړ�
		++m_move_cnt;
		if (m_move_cnt <= MOVE_ / 2) {
			m_vec.x = 2.0f;
			//m_pos.y += 0.2f;
			//m_depth = (m_pos.y - DEP_N) / 3.5;
			m_flip = true;
		}
		else if (m_move_cnt >= MOVE_/2) {
			m_vec.x = -2.0f;
			m_flip = false;
		}
		if (m_move_cnt >= MOVE_) {
			m_vec.x = 0;
			m_move_cnt = 0;
			m_state = eAttack;
			
		}
		break;

	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
}

void Enemy05::Attack()
{
	m_img.ChangeAnimation(eEAttack05,false);
	if (m_img.CheckAnimationEnd())
		m_state = eMove;
	
}

void Enemy05::Damage()
{
	m_vec.x = 0;
	if (m_hp <= 0){
		m_img.ChangeAnimation(eEDeath05, false);
		if (m_img.CheckAnimationEnd())
			SetKill();
	}
	else {
		m_img.ChangeAnimation(eEDamage05, false);
		if (m_img.CheckAnimationEnd())
			m_state = eMove;
	}
}

void Enemy05::Update()
{
	switch (m_state) {
	case eMove:
		Move();
		break;
	case eSearch:
		//Search();
		break;
	case eAttack:
		Attack();
		break;
	case eDamage:
		Damage();
		break;
	default:
		break;
	}


	m_pos += m_vec;
	MoveControl();
	m_img.UpdateAnimation();
}

void Enemy05::Draw()
{
	//�T�C�Y�w��ƕ`��
	m_img.SetSize(IMAGE_SIZE, IMAGE_SIZE);
	m_img.SetCenter(IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	m_img.SetPos(m_pos- g_game_data.m_scroll);
	m_img.SetFlipH(m_flip);

	m_shadow.SetSize(SAIZE_SD + m_depth / 5, 50);
	m_shadow.SetCenter((SAIZE_SD + m_depth / 5) / 2, 50 / 2);
	m_shadow.SetPos(CVector2D(m_pos.x- g_game_data.m_scroll.x,m_pos.y + 90 - g_game_data.m_scroll.y));

	m_shadow.Draw();
	m_img.Draw();
	
}

void Enemy05::HitCheck()
{	

	if (CollitionBase::CollisionCheckRect(this, ePEffectShortAttack01)){
		printf("HitAttack");
		m_hp -= 1;
		m_state = eDamage;
	}
	if (CollitionBase::CollisionCheckRect(this, ePEffectShortAttack02)) {
		m_hp -= 1;
		m_state = eDamage;
	}
	if (CollitionBase::CollisionCheckRect(this, ePEffectShortAttack03)) {
		m_hp -= 1;
		m_state = eDamage;
	}
}
