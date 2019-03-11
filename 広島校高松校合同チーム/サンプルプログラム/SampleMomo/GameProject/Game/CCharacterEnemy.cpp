#include "CCharacterEnemy.h"
#include "CCharacterPlayer.h"

CCharacterEnemy::CCharacterEnemy() :CCharacter(eTaskIdEnemy, 0)
{
	ADD_RESOURCE("Enemy_Idle_2", CImage::LoadImage("Enemy_idle2.png"));
	ADD_RESOURCE("Enemy_Idle_3", CImage::LoadImage("Enemy_idle3.png"));
	ADD_RESOURCE("Enemy_Idle_4", CImage::LoadImage("Enemy_idle4.png"));
	ADD_RESOURCE("Enemy_Move_2", CImage::LoadImage("Enemy_move2.png"));
	ADD_RESOURCE("Enemy_Move_3", CImage::LoadImage("Enemy_move3.png"));
	ADD_RESOURCE("Enemy_Move_4", CImage::LoadImage("Enemy_move4.png"));
	ADD_RESOURCE("Enemy_Move_5", CImage::LoadImage("Enemy_move5.png"));
	ADD_RESOURCE("Enemy_Move_6", CImage::LoadImage("Enemy_move6.png"));
	ADD_RESOURCE("Enemy_Move_7", CImage::LoadImage("Enemy_move7.png"));
	ADD_RESOURCE("Enemy_Move_8", CImage::LoadImage("Enemy_move8.png"));
	ADD_RESOURCE("Enemy_Attack_2", CImage::LoadImage("Enemy_attack2.png"));


	m_enemy_state = eEnemyStateIdle;
	m_enemy_hp = 100;

	m_vec = CVector3D(0, 0, 0);
	m_pos = CVector3D(500, -50, 380);  //初期値のy軸は地面に埋まらないように少し浮かせる
	m_rads = CVector3D(10,10,10);
	SetSize(300, 300);

	is_damage = true;
	m_attack_chance = false;
	m_AI_cnt = 0;
	p_pos = CVector3D(0, 0, 0);
	p_vec = CVector2D(0, 0);
	LoadAnimImage();

	SetAnim(eEnemyAnimIdIdle);
	SetIsShowShadow(true);
	SetShadowSize(CVector2D(100, 50));
	SetShadowAdjPos(CVector2D(-8.0, -50.0));
}

CCharacterEnemy::~CCharacterEnemy()
{
	printf("削除されました");
}

void CCharacterEnemy::CharacterUpdate()
{
	m_AI_cnt++;
	CharacterBeforeCollisionCheck();
	switch (m_enemy_state) {
	case eEnemyStateIdle:
		Idle();
		break;
	case eEnemyStateMove:
		Move();
		break;
	case eEnemyStateAttack:
		Attack();
		break;
	case eEnemyStateDamage:
		Damage();
		break;
	default:
		break;
	}
	Gravity();
#ifdef _DEBUG

#endif // _DEBUG
	MovePos();
	
}

void CCharacterEnemy::CharacterDraw()
{	

}

void CCharacterEnemy::LoadAnimImage()
{
	m_anim_image_p[eEnemyAnimIdle1] = GET_RESOURCE("Enemy_Idle_0", CImage*);
	m_anim_image_p[eEnemyAnimIdle2] = GET_RESOURCE("Enemy_Idle_2", CImage*);
	m_anim_image_p[eEnemyAnimIdle3] = GET_RESOURCE("Enemy_Idle_3", CImage*);
	m_anim_image_p[eEnemyAnimIdle4] = GET_RESOURCE("Enemy_Idle_4", CImage*);
	m_anim_image_p[eEnemyAnimMove1] = GET_RESOURCE("Enemy_Move_0", CImage*);
	m_anim_image_p[eEnemyAnimMove2] = GET_RESOURCE("Enemy_Move_2", CImage*);
	m_anim_image_p[eEnemyAnimMove3] = GET_RESOURCE("Enemy_Move_3", CImage*);
	m_anim_image_p[eEnemyAnimMove4] = GET_RESOURCE("Enemy_Move_4", CImage*);
	m_anim_image_p[eEnemyAnimMove5] = GET_RESOURCE("Enemy_Move_5", CImage*);
	m_anim_image_p[eEnemyAnimMove6] = GET_RESOURCE("Enemy_Move_6", CImage*);
	m_anim_image_p[eEnemyAnimMove7] = GET_RESOURCE("Enemy_Move_7", CImage*);
	m_anim_image_p[eEnemyAnimMove8] = GET_RESOURCE("Enemy_Move_8", CImage*);
	m_anim_image_p[eEnemyAnimAttack1] = GET_RESOURCE("Enemy_Attack_0", CImage*);
	m_anim_image_p[eEnemyAnimAttack2] = GET_RESOURCE("Enemy_Attack_2", CImage*);
	m_anim_image_p[eEnemyAnimDamage1] = GET_RESOURCE("Enemy_Damage_0", CImage*);

	//アニメーションデータの設定
	m_anim_info[eEnemyAnimIdIdle].image_num = 4;
	m_anim_info[eEnemyAnimIdIdle].image_id = eEnemyAnimIdle1;
	m_anim_info[eEnemyAnimIdIdle].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[eEnemyAnimIdMove].image_num = 8;
	m_anim_info[eEnemyAnimIdMove].image_id = eEnemyAnimMove1;
	m_anim_info[eEnemyAnimIdMove].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[eEnemyAnimIdAttack].image_num = 2;
	m_anim_info[eEnemyAnimIdAttack].image_id = eEnemyAnimAttack1;
	m_anim_info[eEnemyAnimIdAttack].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[eEnemyAnimIdDamage].image_num = 1;
	m_anim_info[eEnemyAnimIdDamage].image_id = eEnemyAnimDamage1;
	m_anim_info[eEnemyAnimIdDamage].delay = 100;
}

void CCharacterEnemy::Idle()
{
	SetWillPlayAnim(eEnemyAnimIdIdle);
	is_damage = true;
	p_vec = CVector2D(p_pos.x - m_pos.x, p_pos.z - m_pos.z);
	p_vec = p_vec/p_vec.Length();
	m_vec = CVector3D(0, m_vec.y, 0);
	AiChange(200);
}

void CCharacterEnemy::Move()
{
	SetWillPlayAnim(eEnemyAnimIdMove);
	is_damage = true;
	m_vec = CVector3D(p_vec.x, m_vec.y, p_vec.y);
	AiChange(200);
}

void CCharacterEnemy::Attack()
{
	SetWillPlayAnim(eEnemyAnimIdAttack);
	is_damage = true;
	m_vec = CVector3D(0, m_vec.y, 0);
	AiChange(0);
}

void CCharacterEnemy::Damage()
{
	SetWillPlayAnim(eEnemyAnimIdDamage);
	m_vec = CVector3D(0, m_vec.y, 0);
	if (is_damage) {
		m_enemy_hp -= 30;
		is_damage = false;
	}
	if (m_enemy_hp < 0)SetIsDelete();
}

void CCharacterEnemy::MovePos()
{
	m_pos_old = m_pos;
	m_pos += m_vec;
	//とりあえずテスト用なので
	if (m_pos.z <= 280.0f) m_pos.z = 280.0f;
	if (m_pos.z >= 580.0f) m_pos.z = 580.0f;
}

void CCharacterEnemy::AiChange(int ai_cnt)
{
	if (m_AI_cnt > ai_cnt) {
		switch (m_enemy_state)
		{
		case eEnemyStateIdle:
			m_AI_cnt = rand() % 50;
			if(m_attack_chance)m_enemy_state = eEnemyStateAttack;
			else m_enemy_state = eEnemyStateMove;
			break;
		case eEnemyStateMove:
			m_AI_cnt = rand() % 50;
			if (m_attack_chance)m_enemy_state = eEnemyStateAttack;
			else m_enemy_state = eEnemyStateIdle;
			break;
		case eEnemyStateAttack:
			m_AI_cnt = rand() % 50;
			if (m_attack_chance)m_enemy_state = eEnemyStateIdle;
			else m_enemy_state = eEnemyStateMove;
			break;
		default:
			break;
		}
	}
	
}

void CCharacterEnemy::CharacterBeforeCollisionCheck()
{
	CCharacterPlayer* p = dynamic_cast<CCharacterPlayer*>(TaskManager::GetInstance()->FindTask(eTaskIdPlayer));
	p_pos = p->GetPos();
	CVector2D l_vec = CVector2D(p_pos.x - m_pos.x, p_pos.z - m_pos.z);
	if (l_vec.Length() < 10) {
		m_attack_chance = true;
	}
	else m_attack_chance = false;
}
