#include "CCharacterEnemy.h"
#include "CCharacterPlayer.h"

CCharacterEnemy::CCharacterEnemy() :CCharacter(eTaskIdEnemy, 0)
{
	ADD_RESOURCE("SpearEnemy_Idle_1", CImage::LoadImage("Enemy_Spear_idle1.png"));
	ADD_RESOURCE("SpearEnemy_Idle_2", CImage::LoadImage("Enemy_Spear_idle2.png"));
	ADD_RESOURCE("SpearEnemy_Idle_3", CImage::LoadImage("Enemy_Spear_idle3.png"));
	ADD_RESOURCE("SpearEnemy_Idle_4", CImage::LoadImage("Enemy_Spear_idle4.png"));
	ADD_RESOURCE("AxeEnemy_Idle_1", CImage::LoadImage("Enemy_Axe_idle1.png"));
	ADD_RESOURCE("AxeEnemy_Idle_2", CImage::LoadImage("Enemy_Axe_idle2.png"));
	ADD_RESOURCE("AxeEnemy_Idle_3", CImage::LoadImage("Enemy_Axe_idle3.png"));
	ADD_RESOURCE("AxeEnemy_Idle_4", CImage::LoadImage("Enemy_Axe_idle4.png"));
	ADD_RESOURCE("Enemy_Move_2", CImage::LoadImage("Enemy_move2.png"));
	ADD_RESOURCE("Enemy_Move_3", CImage::LoadImage("Enemy_move3.png"));
	ADD_RESOURCE("Enemy_Move_4", CImage::LoadImage("Enemy_move4.png"));
	ADD_RESOURCE("Enemy_Move_5", CImage::LoadImage("Enemy_move5.png"));
	ADD_RESOURCE("Enemy_Move_6", CImage::LoadImage("Enemy_move6.png"));
	ADD_RESOURCE("Enemy_Move_7", CImage::LoadImage("Enemy_move7.png"));
	ADD_RESOURCE("Enemy_Move_8", CImage::LoadImage("Enemy_move8.png"));
	ADD_RESOURCE("Enemy_Attack_2", CImage::LoadImage("Enemy_attack2.png"));

	t = 1;
	m_enemy_state = eEnemyStateIdle;

	m_vec = CVector3D(0, 0, 0);
	m_pos = CVector3D(1000, -160, 500);  //初期値のy軸は地面に埋まらないように少し浮かせる
	m_rads = CVector3D(75,150,10);
	SetSize(300, 300);
	m_is_flip = false;

	m_is_damage = true;
	m_damage_chance = 0;
	m_attack_chance = false;
	m_attack_pos = CVector2D(300, 100);
	m_AI_cnt = 0;
	m_player_pos = CVector3D(0, 0, 0);
	m_player_vec = CVector2D(0, 0);
	LoadAnimImage();

	is_attack = true;

	SetAnim(eEnemyAnimIdIdle);
	SetIsShowShadow(true);
	SetShadowSize(CVector2D(100, 50));
	SetDrawAdjPos(CVector2D(5.0, 50.0));

	m_hit_point = 100.0f;
	m_hit_point_max = 100.0f;
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
	//printf("%f", m_pos.x);
#endif // _DEBUG
	MovePos();
	
}

void CCharacterEnemy::CharacterDraw()
{	

}

void CCharacterEnemy::ReceiveAttack()
{
	/*if (m_is_damage)*/ m_enemy_state = eEnemyStateDamage;
	m_AI_cnt = 0;
	printf("エネミー 攻撃があたった!\n");
}

void CCharacterEnemy::LoadAnimImage()
{
	if (t == 1) {
		m_anim_image_p[eEnemyAnimIdle1] = GET_RESOURCE("SpearEnemy_Idle_1", CImage*);
		m_anim_image_p[eEnemyAnimIdle2] = GET_RESOURCE("SpearEnemy_Idle_2", CImage*);
		m_anim_image_p[eEnemyAnimIdle3] = GET_RESOURCE("SpearEnemy_Idle_3", CImage*);
		m_anim_image_p[eEnemyAnimIdle4] = GET_RESOURCE("SpearEnemy_Idle_4", CImage*);
	}
	else {
		m_anim_image_p[eEnemyAnimIdle1] = GET_RESOURCE("AxeEnemy_Idle_1", CImage*);
		m_anim_image_p[eEnemyAnimIdle2] = GET_RESOURCE("AxeEnemy_Idle_2", CImage*);
		m_anim_image_p[eEnemyAnimIdle3] = GET_RESOURCE("AxeEnemy_Idle_3", CImage*);
		m_anim_image_p[eEnemyAnimIdle4] = GET_RESOURCE("AxeEnemy_Idle_4", CImage*);
	}
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
	m_anim_info[eEnemyAnimIdAttack].delay = 50;

	m_anim_info[eEnemyAnimIdDamage].image_num = 1;
	m_anim_info[eEnemyAnimIdDamage].image_id = eEnemyAnimDamage1;
	m_anim_info[eEnemyAnimIdDamage].delay = 30;
}

void CCharacterEnemy::Idle()
{
	SetWillPlayAnim(eEnemyAnimIdIdle);
	is_attack = true;
	m_is_damage = true;
	m_player_vec = CVector2D(m_player_pos.x - m_pos.x, m_player_pos.z - m_pos.z);
	m_player_vec = m_player_vec/ m_player_vec.Length();
	m_vec = CVector3D(0, m_vec.y, 0);
	AiChange(200);
}

void CCharacterEnemy::Move()
{
	SetWillPlayAnim(eEnemyAnimIdMove);
	m_is_damage = true;
	if (m_damage_chance > 3) {
		m_vec = CVector3D(-m_player_vec.x * 2, m_vec.y, -m_player_vec.y * 2);
	}
	else m_vec = CVector3D(m_player_vec.x, m_vec.y, m_player_vec.y);
	if (m_vec.x > 0) m_is_flip = true;
	else m_is_flip = false;
	if (m_attack_chance) m_AI_cnt += 200;
	AiChange(200);
}

void CCharacterEnemy::Attack()
{
	SetWillPlayAnim(eEnemyAnimIdAttack);
	m_is_damage = true;
	m_vec = CVector3D(0, m_vec.y, 0);
	if (m_player_vec.x > 0) m_is_flip = true;
	else m_is_flip = false;

	CCharacterPlayer* p = dynamic_cast<CCharacterPlayer*>(TaskManager::GetInstance()->FindTask(eTaskIdPlayer));
	CVector3D player_pos = p->GetPos();
	if (abs(m_pos.z - player_pos.z) < 500 && abs(player_pos.x - m_pos.x) <200 && is_attack) {
		is_attack = false;
		if(p == NULL) printf("プレイヤーがいません\n");
		printf("Hit!!\n");
		p->ReceiveAttack();
		p->HitPointGainValue(-3.0);
	}

	AiChange(140);
}

void CCharacterEnemy::Damage()
{
	SetWillPlayAnim(eEnemyAnimIdDamage);
	m_vec = CVector3D(0, m_vec.y, 0);
	//if (m_is_damage) {
		m_damage_chance++;
		m_is_damage = false;
		m_hit_point -= 10.0f;
	//}
	if (m_hit_point < 0)SetIsDelete();
	AiChange(30);
}

void CCharacterEnemy::MovePos()
{
	m_pos_old = m_pos;
	
	m_pos += m_vec;
	//とりあえずテスト用なので
	if (m_pos.z <= 430.0f) m_pos.z = 430.0f;
	if (m_pos.z >= 720.0f) m_pos.z = 720.0f;
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
			m_damage_chance = 0;
			m_AI_cnt = rand() % 50;
			if (m_attack_chance)m_enemy_state = eEnemyStateAttack;
			else m_enemy_state = eEnemyStateIdle;
			break;
		case eEnemyStateAttack:
			m_AI_cnt = 0;
			if (m_attack_chance)m_enemy_state = eEnemyStateIdle;
			else m_enemy_state = eEnemyStateMove;
			break;
		case eEnemyStateDamage:
			m_AI_cnt = rand() % 50;
			if (m_damage_chance > 3)m_enemy_state = eEnemyStateMove;
			else m_enemy_state = eEnemyStateIdle;
			break;
		default:
			break;
		}
	}
	
}

void CCharacterEnemy::CharacterBeforeCollisionCheck()
{
	CCharacterPlayer* p = dynamic_cast<CCharacterPlayer*>(TaskManager::GetInstance()->FindTask(eTaskIdPlayer));
	m_player_pos = p->GetPos();
	CVector2D l_vec = CVector2D(m_player_pos.x - m_pos.x, m_player_pos.z - m_pos.z);
	/*l_vec.Length() < 200*/
	if (abs(l_vec.x) < m_attack_pos.x && abs(l_vec.y) < m_attack_pos.y) {
		m_attack_chance = true;
	}
	else m_attack_chance = false;

	/*float* h = p->GetHitPointPointer();
	float hp = *h;
	printf("%f\n", hp);*/
	/*printf("エネミーのZ%f", m_pos.z);
	printf("プレイヤーのZ%f\n", m_player_pos.z);*/
}
