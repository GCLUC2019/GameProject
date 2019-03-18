#include "CCharacterEnemy.h"
#include "CAnimation.h"
#include "CCharacterPlayer.h"


CCharacterEnemy::CCharacterEnemy(int _enemy_id, CVector3D _enemy_pos) :CCharacter(eTaskIdEnemy, 0)
{
	m_enemy_id = _enemy_id;
	SetPos(_enemy_pos);

	m_speed = 1.0f;

	SetIsShowShadow(true);
	SetRads(75, 150, 10);

	m_hit_point = 10.0f;
	m_hit_point_max = 10.0f;


	LoadAnimImage();

	//当たり判定の優先度
	SetCollisionPriority(5);

	//敵はプレイヤーを設定（ここを変えれば味方のトランプ兵も作れるかも）
	m_target_p = CCharacterPlayer::GetInstance();
	
}

CCharacterEnemy::~CCharacterEnemy()
{
}

void CCharacterEnemy::LoadAnimImage()
{

	//敵の種類に応じて読み込むアニメーションデータを変える。

	switch (m_enemy_id) {
	case eEnemyIdSpear:
		m_receive_damage_frame = ENEMY_RECEIVE_DAMAGE_FRAME;
		m_attack_power = ENEMY_ATTACK_POWER;
		m_attacking_hit_start_frame = ENEMY_ATTACK_HIT_START_FRAME;
		m_attacking_hit_end_frame = ENEMY_ATTACK_HIT_END_FRAME;
		m_attack_frame = ENEMY_ATTACK_FRAME;
		m_attack_length = ENEMY_ATTACK_LENGTH;
		m_move_start_length = ENEMY_MOVE_START_LENGTH;
		m_move_end_length = ENEMY_MOVE_END_LENGTH;
		m_anim_p->ReadAnimDataFile("EnemyAnim/ENEMY_ANIM_DATA.anim");
		break;
	}
	
}

void CCharacterEnemy::CharacterBeforeUpdate()
{
}

void CCharacterEnemy::CharacterUpdate()
{
	m_anim_p->SetWillPlayAnim(eEnemyAnimIdIdle);
	
	Attacking();
	ReceiveDamageNow();

	EnemyMoving();
	EnemyAttack();

	

	AdjAnim();
}

void CCharacterEnemy::CharacterBeforeCollisionCheck()
{
}

void CCharacterEnemy::CollisionCheckCharacter(Task * _collision_task)
{
}

void CCharacterEnemy::CharacterDraw()
{
}

void CCharacterEnemy::CharacterOutHitPoint()
{
	SetIsDelete();
}

void CCharacterEnemy::ReceiveAttack()
{
	m_receive_damage_count = m_receive_damage_frame;
	m_is_receive_damage_now = true;
	m_anim_p->SetWillPlayAnim(eEnemyAnimIdDamage);
	m_is_attacking = false;
	m_is_moving = false;
}

void CCharacterEnemy::ReceiveDamageNow()
{
	if (m_is_receive_damage_now == false) return;
	m_receive_damage_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if (m_receive_damage_count <= 0.0) {
		m_is_receive_damage_now = false;
		return;
	}
	m_anim_p->SetWillPlayAnim(eEnemyAnimIdDamage);
}


void CCharacterEnemy::EnemyMoving()
{
	if (m_target_p == nullptr) return;
	
	const CVector3D& target_pos = m_target_p->GetPos();
	CVector3D target_vec = target_pos - m_pos;
	float target_length = sqrt(target_vec.x * target_vec.x + target_vec.y * target_vec.y + target_vec.z * target_vec.z);
	
	//ベクトル初期化
	m_vec.x = 0.0f;
	m_vec.z = 0.0f;


	//ダメージ中ならなにもしない
	if (m_is_receive_damage_now == true) return;

	//敵のいる方向に向く
	if (target_vec.x > 0.0f) m_is_flip = true;
	else if (target_vec.x < 0.0f) m_is_flip = false;

	//もし攻撃中なら移動しない
	if (m_is_attacking == true) return;

	//もし移動中でなくて既定の距離以下なら移動しない
	if (m_is_moving == false && target_length <= m_move_start_length) return;

	//もし既定の距離まで近づいているなら移動をやめる
	if (target_length <= m_move_end_length) {
		m_is_moving = false;
		return;
	}
	

	
	CVector3D target_dir = target_vec / target_length;
	CVector3D move_vec = target_dir * m_speed;
	

	
	m_is_moving = true;

	//とりあえずY軸移動はいない(ジャンプ実装したら必要な場合にさせる)
	m_vec.x = move_vec.x;
	m_vec.z = move_vec.z;

	m_anim_p->SetWillPlayAnim(eEnemyAnimIdMove);
}

void CCharacterEnemy::EnemyAttack()
{
	if (m_target_p == nullptr) return;
	if (m_is_attacking == true) return;
	if (m_is_moving == true) return;//もし移動中なら攻撃しない
	if (m_is_receive_damage_now == true) return;

	const CVector3D& target_pos = m_target_p->GetPos();
	CVector3D target_vec = target_pos - m_pos;
	float target_length = sqrt(target_vec.x * target_vec.x + target_vec.y * target_vec.y + target_vec.z * target_vec.z);

	if (target_length <= m_attack_length) {
		m_is_attacking = true;
		m_is_hit_attack = false;
		m_attacking_count = m_attack_frame;
		m_anim_p->SetWillPlayAnim(eEnemyAnimIdAttack);
	}
	
}

void CCharacterEnemy::Attacking()
{
	if (m_target_p == nullptr) return;
	if (m_is_attacking == false) return;
	if (m_is_receive_damage_now == true) return;

	m_attacking_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if (m_attacking_count <= 0) {
		m_is_attacking = false;
		return;
	}

	//もし攻撃判定フレームなら
	if (m_attacking_count <= m_attack_frame - m_attacking_hit_start_frame && m_attacking_count >= m_attack_frame - m_attacking_hit_end_frame) {

		//距離計算
		const CVector3D& target_pos = m_target_p->GetPos();
		CVector3D target_vec = target_pos - m_pos;
		float target_length = sqrt(target_vec.x * target_vec.x + target_vec.y * target_vec.y + target_vec.z * target_vec.z);

		//printf("攻撃判定フレーム\n");

		//もし攻撃範囲内なら
		if (target_length <= m_attack_length && m_is_hit_attack == false) {
			//printf("ダメージを与えた\n");
			m_is_hit_attack = true;

			//ダメージを与える
			m_target_p->HitPointGainValue(-m_attack_power);

			//攻撃が当たったことを伝える
			m_target_p->ReceiveAttack();
		}
	}



	m_anim_p->SetWillPlayAnim(eEnemyAnimIdAttack);
}

void CCharacterEnemy::AdjAnim()
{
	switch (m_anim_p->GetWillPlayAnim()) {
	case eEnemyAnimIdAttack:
		SetSize(500, 400);
		SetShadowSize(CVector2D(160, 50));
		SetDrawAdjPos(CVector2D(-60, 0.0f));
		break;
	case eEnemyAnimIdMove:
		SetSize(400, 400);
		SetShadowSize(CVector2D(100, 50));
		SetDrawAdjPos(CVector2D(0, 0.0f));
		break;
	case eEnemyAnimIdIdle:
		SetSize(400, 400);
		SetShadowSize(CVector2D(100, 50));
		SetDrawAdjPos(CVector2D(10, 0.0f));
		break;
	default:
		SetSize(400, 400);
		SetShadowSize(CVector2D(100, 50));
		SetDrawAdjPos(CVector2D(10, 0.0f));
		break;
	}


	//モーションのフレームに応じて影とかの見え方変える必要もでてきそうだ
	
}
