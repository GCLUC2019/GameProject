﻿#include "CCharacterEnemy.h"
#include "CAnimation.h"
#include "CCharacterPlayer.h"
#include "CGameScene.h"
#include "CSubWeapon.h"
#include "CBar.h"
#include "CDamageEffect.h"
#include "CBullet.h"
#include "CItem.h"

CCharacterEnemy::CCharacterEnemy(int _enemy_id, CVector3D _enemy_pos, CGameSceneWave* _from_wave) :CCharacter(eTaskIdEnemy, 0)
{
	m_enemy_id = _enemy_id;
	SetPos(_enemy_pos);
	SetPosOld(_enemy_pos);

	m_speed = 1.0f;

	m_knock_back_frame = ENEMY_KNOCK_BACK_FRAME;

	SetIsShowShadow(true);
	SetRads(75, 110, 10);

	m_hit_point = 7.5f;
	m_hit_point_max = 7.5f;


	LoadAnimImage();

	//当たり判定の優先度
	SetCollisionPriority(5);

	//敵はプレイヤーを設定（ここを変えれば味方のトランプ兵も作れるかも）
	m_target_p = CCharacterPlayer::GetInstance();
	
	m_from_wave_p = _from_wave;

	m_hit_point_bar_p = new CBar(GET_RESOURCE("HP_Bar", CImage*),&m_hit_point,m_hit_point_max,m_pos,CVector2D(195,15),true);
	m_hp_frame_image_p = GET_RESOURCE("Enemy_HP_Bar_Frame", CImage*);
}

CCharacterEnemy::~CCharacterEnemy()
{
	if (m_hit_point_bar_p != nullptr) delete m_hit_point_bar_p;
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
	
	DoingKnockBack();
	
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
	m_hp_frame_image_p->SetSize(CVector2D(200,20));
	m_hp_frame_image_p->SetPos(CVector2D(m_pos.x,m_pos.y + m_pos.z) + CVector2D(-100,-170) - GetScroll());
	m_hp_frame_image_p->Draw();

	m_hit_point_bar_p->SetPos(m_pos + CVector3D(-100 + 2.5, 0, -170 + 2.5));
	m_hit_point_bar_p->Update();
	m_hit_point_bar_p->Draw();
}

void CCharacterEnemy::CharacterOutHitPoint()
{
	DropItem();
	CGameScene::GetInstance()->EraseGameSceneObject(this);
	SetIsDelete();
}

void CCharacterEnemy::ReceiveAttack()
{
	m_receive_damage_count = m_receive_damage_frame;
	m_is_receive_damage_now = true;
	m_anim_p->SetWillPlayAnim(eEnemyAnimIdDamage);
	m_is_attacking = false;
	m_is_moving = false;
	CSound::GetInstance()->GetSound("SE_Damage")->Play();
	CGameScene::GetInstance()->AddGameSceneObject(new CDamageEffect(&m_pos,CVector2D(-200,-210),CVector2D(400,400),30));
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

void CCharacterEnemy::ReceiveKnockBack(CVector3D _from_pos, double _power)
{
	if (m_is_knock_back == true) return;
	if (m_is_invincible == true) return;

	SetKnockBack(_from_pos,_power);

	//動作中断
	m_is_attacking = false;
}


void CCharacterEnemy::EnemyMoving()
{
	if (m_target_p == nullptr) return;
	if (m_is_knock_back == true) return;
	
	const CVector3D& target_pos = m_target_p->GetPos();
	CVector3D target_vec = target_pos - m_pos;
	float target_length = sqrt(target_vec.x * target_vec.x + target_vec.y * target_vec.y + target_vec.z * target_vec.z);
	
	//ベクトル初期化
	m_vec.x = 0.0f;
	m_vec.z = 0.0f;


	//ダメージ中ならなにもしない
	if (m_is_receive_damage_now == true) return;

	//敵のいる方向に向く
	if (target_vec.x > 0.0f) m_is_flip = false;
	else if (target_vec.x < 0.0f) m_is_flip = true;


	//攻撃中でも距離をとるのが必要な場合距離を取る

	
	//もし距離が十分とれていて攻撃中なら移動しない
	if (m_is_attacking == true &&
		abs(target_vec.x) >= m_space_length.x &&
		abs(target_vec.y) >= m_space_length.y &&
		abs(target_vec.z) >= m_space_length.z) return;
	

	//既定の距離より離れてるなら、視認できないとして移動しない
	if (target_length > m_find_length) return;

	//もし既定の距離まで近づいていてなおかつ攻撃可能な範囲なら移動を完了する
	//ただし距離が近すぎる場合は逆に離れる
	if (target_vec.x <= m_move_end_length.x && target_vec.y <= m_move_end_length.y && target_vec.z <= m_move_end_length.z
		&& abs(target_vec.x) <= m_attack_length.x && abs(target_vec.y) <= m_attack_length.y && abs(target_vec.z) <= m_attack_length.z
		&& abs(target_vec.x) > m_space_length.x && abs(target_vec.y) > m_space_length.y && abs(target_vec.z) > m_space_length.z){
		m_is_moving = false;
		return;
	}
	

	
	CVector3D target_dir = target_vec / target_length;
	CVector3D move_vec = target_dir * m_speed;
	
	//もし既定の距離よりも近づいていた場合離れる
	if (abs(target_vec.x) <= m_space_length.x && abs(target_vec.z) <= m_space_length.z) {
		move_vec.x *= -1.0;
		move_vec.z *= -1.0;
	}
	
	m_is_moving = true;

	//とりあえずY軸移動はいない(ジャンプ実装したら必要な場合にさせる)
	m_vec.x = move_vec.x;
	m_vec.z = move_vec.z;



	//もし攻撃中でないならアニメーションを再生する
	if(m_is_attacking == false ) m_anim_p->SetWillPlayAnim(eEnemyAnimIdMove);
}

void CCharacterEnemy::EnemyAttack()
{
	if (m_target_p == nullptr) return;
	if (m_is_attacking == true) return;
	if (m_is_knock_back == true) return;

	const CVector3D& target_pos = m_target_p->GetPos();
	CVector3D target_vec = target_pos - m_pos;
	float target_length = sqrt(target_vec.x * target_vec.x + target_vec.y * target_vec.y + target_vec.z * target_vec.z);

	//もし移動中でなおかつ距離をとっていないなら攻撃できない
	//(近づきながら攻撃はできないが、離れながら攻撃は可能）
	if (m_is_moving == true 
		&& abs(target_vec.x) > m_space_length.x && abs(target_vec.y) > m_space_length.y && abs(target_vec.z) > m_space_length.z) return;
	
	if (m_is_receive_damage_now == true) return;

	//もし画面外なら攻撃しない
	if (m_is_in_screen == false) return;

	//敵のいる方向に向く
	if (target_vec.x > 0.0f) m_is_flip = false;
	else if (target_vec.x < 0.0f) m_is_flip = true;

	if (abs(target_vec.x) <= m_attack_length.x && abs(target_vec.y) <= m_attack_length.y && abs(target_vec.z) <= m_attack_length.z) {
		m_is_attacking = true;
		m_is_hit_attack = false;
		m_attacking_count = m_attack_frame;
		m_anim_p->SetWillPlayAnim(eEnemyAnimIdAttack);
		
		
		if (m_is_range == true) {
			CGameScene::GetInstance()->AddGameSceneObject(new CBullet(GET_RESOURCE("Bullet", CImage*), eTaskIdPlayer, m_pos, CVector2D(200, -49), CVector2D(15, 15), m_is_flip, m_attack_power, ENEMY_BULLET_ATTACK_LENGTH, ENEMY_GUN_BULLET_DESTROY_LENGTH, 20.0, GET_RESOURCE("Shadow", CImage*), CVector2D(-20, 140), CVector2D(30, 30)));
			CSound::GetInstance()->GetSound("SE_Shot1")->Play();
		}
	}


	switch (m_enemy_id) {
	case eEnemyIdAxe:
		CSound::GetInstance()->GetSound("SE_Slash1")->Play();
		break;
	case eEnemyIdSpear:
		CSound::GetInstance()->GetSound("SE_Slash1")->Play();
		break;
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


	//ターゲットが無敵か取得
	bool enemy_invincible = m_target_p->GetInvincible();
	//printf("enemy_invincible %d\n", enemy_invincible);

	//もし攻撃判定フレームなら
	if (m_attacking_count <= m_attack_frame - m_attacking_hit_start_frame && m_attacking_count >= m_attack_frame - m_attacking_hit_end_frame
		&& m_is_range == false) {//遠距離攻撃なら弾の方で攻撃判定は行うのでなにもしない


		


		//距離計算
		const CVector3D& target_pos = m_target_p->GetPos();
		CVector3D target_vec = target_pos - m_pos;
		const CVector3D& target_rads = m_target_p->GetRads();
		//float target_length = sqrt(target_vec.x * target_vec.x + target_vec.y * target_vec.y + target_vec.z * target_vec.z);

		
		//もし攻撃範囲内なら
		if (abs(target_vec.x) <= m_attack_length.x + target_rads.x && abs(target_vec.y) <= m_attack_length.y + target_rads.y && abs(target_vec.z) <= m_attack_length.z + target_rads.z && m_is_hit_attack == false) {
			//printf("ダメージを与えた\n");
			m_is_hit_attack = true;

			//ダメージを与える
			m_target_p->HitPointGainValue(-m_attack_power);

			//ノックバックを与える
			m_target_p->ReceiveKnockBack(m_pos, 5.0);

			//攻撃が当たったことを伝える
			m_target_p->ReceiveAttack();
		}
	}



	m_anim_p->SetWillPlayAnim(eEnemyAnimIdAttack);

	//相手が無敵でなく、もし遠距離かつ攻撃完了しているなら発射モーション再生
	if (m_is_range == true && m_is_hit_attack == true) {
		m_anim_p->SetWillPlayAnim(eEnemyAnimIdShot);
		
	}
	
}

void CCharacterEnemy::DropItem()
{
	//出現率3分の1
	int rand = Utility::Rand(0,3);
	if (rand != 0) return;


	//出現するアイテムの種類(0:持っている武器 1:アイテム)
	rand = Utility::Rand(0, 2);

	
	//テスト用
	CGameScene::GetInstance()->AddGameSceneObject(new CItem(m_pos + CVector3D(0, 100, 0), eItemFlag));
	return;

	switch (rand) {
	case 0: {
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
		CGameScene::GetInstance()->AddGameSceneObject(new CSubWeaponItem(m_pos + CVector3D(0, 100, 0), drop_weapon_id));
		break;
	}
	case 1: {
		//出現するアイテムを決定
		rand = Utility::Rand(0, 4);
		int drop_item_id;
		switch (rand) {
		case 0:
		case 1:
		case 2:
			drop_item_id = eItemPeach;
			break;
		case 3:
			drop_item_id = eItemFlag;
			break;
		}
		CGameScene::GetInstance()->AddGameSceneObject(new CItem(m_pos + CVector3D(0, 100, 0), drop_item_id));
		break;
	}
	}
	
	

	
}

void CCharacterEnemy::AdjAnim()
{

	switch (m_enemy_id) {
	case eEnemyIdSpear:
		switch (m_anim_p->GetWillPlayAnim()) {
		case eEnemyAnimIdAttack:
			SetSize(400, 300);
			SetShadowSize(CVector2D(160, 50));
			SetDrawAdjPos(CVector2D(60, 0.0f));
			break;
		case eEnemyAnimIdMove:
			SetSize(300, 300);
			SetShadowSize(CVector2D(100, 50));
			SetDrawAdjPos(CVector2D(0, 0.0f));
			break;
		case eEnemyAnimIdIdle:
			SetSize(300, 300);
			SetShadowSize(CVector2D(100, 50));
			SetDrawAdjPos(CVector2D(-10, 0.0f));
			break;
		default:
			SetSize(300, 300);
			SetShadowSize(CVector2D(100, 50));
			SetDrawAdjPos(CVector2D(-10, 0.0f));
			break;
		}
		break;
	case eEnemyIdAxe:
		switch (m_anim_p->GetWillPlayAnim()) {
		case eEnemyAnimIdAttack:
			SetSize(300, 400);
			SetShadowSize(CVector2D(160, 50));
			SetDrawAdjPos(CVector2D(0, 0.0f));
			break;
		case eEnemyAnimIdMove:
			SetSize(300, 300);
			SetShadowSize(CVector2D(100, 50));
			SetDrawAdjPos(CVector2D(0, 0.0f));
			break;
		case eEnemyAnimIdIdle:
			SetSize(300, 300);
			SetShadowSize(CVector2D(100, 50));
			SetDrawAdjPos(CVector2D(-10, 0.0f));
			break;
		default:
			SetSize(300, 300);
			SetShadowSize(CVector2D(100, 50));
			SetDrawAdjPos(CVector2D(-10, 0.0f));
			break;
		}
		break;
	case eEnemyIdGun:
		switch (m_anim_p->GetWillPlayAnim()) {
		case eEnemyAnimIdAttack:
			SetSize(300, 300);
			SetShadowSize(CVector2D(160, 50));
			SetDrawAdjPos(CVector2D(35, 0.0f));
			break;
		case eEnemyAnimIdMove:
			SetSize(300, 300);
			SetShadowSize(CVector2D(100, 50));
			SetDrawAdjPos(CVector2D(0, 0.0f));
			break;
		case eEnemyAnimIdIdle:
			SetSize(300, 300);
			SetShadowSize(CVector2D(100, 50));
			SetDrawAdjPos(CVector2D(-10, 0.0f));
			break;
		default:
			SetSize(300, 300);
			SetShadowSize(CVector2D(100, 50));
			SetDrawAdjPos(CVector2D(-10, 0.0f));
			break;
		}
		break;
	}
	

	//モーションのフレームに応じて影とかの見え方変える必要もでてきそうだ
	
}
