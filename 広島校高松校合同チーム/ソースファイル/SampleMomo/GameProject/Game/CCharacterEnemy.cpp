#include "CCharacterEnemy.h"
#include "CAnimation.h"
#include "CCharacterPlayer.h"
#include "CGameScene.h"
#include "CSubWeapon.h"

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
	//アイテムドロップ
	int drop_weapon_id = 0;

	switch (m_enemy_id) {
	case eEnemyIdSpear:
		drop_weapon_id = eWeaponSpear;
		break;
	case eEnemyIdAxe:
		drop_weapon_id = eWeaponAxe;
		break;
	case eEnemyIdGun:
		drop_weapon_id = eWeaponGun;
		break;
	}

	CGameScene::GetInstance()->AddGameSceneObject(new CSubWeaponItem(m_pos,drop_weapon_id));
}

void CCharacterEnemy::LoadAnimImage()
{

	//敵の種類に応じて読み込むアニメーションデータを変える。

	switch (m_enemy_id) {
	case eEnemyIdSpear:
		m_is_range = false;
		m_receive_damage_frame = ENEMY_SPEAR_RECEIVE_DAMAGE_FRAME;
		m_attack_power = ENEMY_SPEAR_ATTACK_POWER;
		m_attacking_hit_start_frame = ENEMY_SPEAR_ATTACK_HIT_START_FRAME;
		m_attacking_hit_end_frame = ENEMY_SPEAR_ATTACK_HIT_END_FRAME;
		m_attack_frame = ENEMY_SPEAR_ATTACK_FRAME;
		m_attack_length = ENEMY_SPEAR_ATTACK_LENGTH;
		m_find_length = ENEMY_SPEAR_FIND_LENGTH;
		m_move_end_length = ENEMY_SPEAR_MOVE_END_LENGTH;
		m_space_length = ENEMY_SPEAR_SPACE_LENGTH;
		m_anim_p->ReadAnimDataFile("EnemyAnim/Spear/ENEMY_SPEAR_ANIM_DATA.anim");
		break;
	case eEnemyIdAxe:
		m_is_range = false;
		m_receive_damage_frame = ENEMY_AXE_RECEIVE_DAMAGE_FRAME;
		m_attack_power = ENEMY_AXE_ATTACK_POWER;
		m_attacking_hit_start_frame = ENEMY_AXE_ATTACK_HIT_START_FRAME;
		m_attacking_hit_end_frame = ENEMY_AXE_ATTACK_HIT_END_FRAME;
		m_attack_frame = ENEMY_AXE_ATTACK_FRAME;
		m_attack_length = ENEMY_AXE_ATTACK_LENGTH;
		m_find_length = ENEMY_AXE_FIND_LENGTH;
		m_move_end_length = ENEMY_AXE_MOVE_END_LENGTH;
		m_space_length = ENEMY_AXE_SPACE_LENGTH;
		m_anim_p->ReadAnimDataFile("EnemyAnim/Axe/ENEMY_AXE_ANIM_DATA.anim");
		break;
	case eEnemyIdGun:
		m_is_range = true;
		m_receive_damage_frame = ENEMY_GUN_RECEIVE_DAMAGE_FRAME;
		m_attack_power = ENEMY_GUN_ATTACK_POWER;
		m_attacking_hit_start_frame = ENEMY_GUN_ATTACK_HIT_START_FRAME;
		m_attacking_hit_end_frame = ENEMY_GUN_ATTACK_HIT_END_FRAME;
		m_attack_frame = ENEMY_GUN_ATTACK_FRAME;
		m_attack_length = ENEMY_GUN_ATTACK_LENGTH;
		m_find_length = ENEMY_GUN_FIND_LENGTH;
		m_move_end_length = ENEMY_GUN_MOVE_END_LENGTH;
		m_space_length = ENEMY_GUN_SPACE_LENGTH;
		m_anim_p->ReadAnimDataFile("EnemyAnim/Gun/ENEMY_GUN_ANIM_DATA.anim");
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

	EnemyAttack();
	EnemyMoving();
	

	

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

	//既定の距離より離れてるなら、視認できないとして移動しない
	if (target_length > m_find_length) return;

	//もし既定の距離まで近づいていてなおかつ攻撃可能な範囲なら移動を完了する
	if (target_vec.x <= m_move_end_length.x && target_vec.y <= m_move_end_length.y && target_vec.z <= m_move_end_length.z
		&& abs(target_vec.x) <= m_attack_length.x && abs(target_vec.y) <= m_attack_length.y && abs(target_vec.z) <= m_attack_length.z) {
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
	//float target_length = sqrt(target_vec.x * target_vec.x + target_vec.y * target_vec.y + target_vec.z * target_vec.z);

	printf("abs(target_vec.x) %lf abs(target_vec.y) %lf abs(target_vec.z) %lf \n", abs(target_vec.x), abs(target_vec.y), abs(target_vec.z));
	if (abs(target_vec.x) <= m_attack_length.x && abs(target_vec.y) <= m_attack_length.y && abs(target_vec.z) <= m_attack_length.z) {
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
		//float target_length = sqrt(target_vec.x * target_vec.x + target_vec.y * target_vec.y + target_vec.z * target_vec.z);

		//printf("攻撃判定フレーム\n");

		//もし攻撃範囲内なら
		if (abs(target_vec.x) <= m_attack_length.x && abs(target_vec.y) <= m_attack_length.y && abs(target_vec.z) <= m_attack_length.z && m_is_hit_attack == false) {
			//printf("ダメージを与えた\n");
			m_is_hit_attack = true;

			//ダメージを与える
			m_target_p->HitPointGainValue(-m_attack_power);

			//攻撃が当たったことを伝える
			m_target_p->ReceiveAttack();
		}
	}



	m_anim_p->SetWillPlayAnim(eEnemyAnimIdAttack);

	//もし遠距離かつ攻撃完了しているなら発射モーション再生
	if (m_is_range == true && m_is_hit_attack == true) {
		m_anim_p->SetWillPlayAnim(eEnemyAnimIdShot);
	}
	
}

void CCharacterEnemy::AdjAnim()
{

	switch (m_enemy_id) {
	case eEnemyIdSpear:
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
		break;
	case eEnemyIdAxe:
		switch (m_anim_p->GetWillPlayAnim()) {
		case eEnemyAnimIdAttack:
			SetSize(400, 500);
			SetShadowSize(CVector2D(160, 50));
			SetDrawAdjPos(CVector2D(0, 0.0f));
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
		break;
	case eEnemyIdGun:
		switch (m_anim_p->GetWillPlayAnim()) {
		case eEnemyAnimIdAttack:
			SetSize(400, 400);
			SetShadowSize(CVector2D(160, 50));
			SetDrawAdjPos(CVector2D(-35, 0.0f));
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
		break;
	}
	

	//モーションのフレームに応じて影とかの見え方変える必要もでてきそうだ
	
}
