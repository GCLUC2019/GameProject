#include "CBullet.h"
#include "CGameScene.h"
#include "CCharacter.h"



CBullet::CBullet(CImage*_bullet_image, int _target_task_id, CVector3D _pos, CVector2D _offset_pos, CVector2D _size, bool _flip, double _attack_power, CVector3D _bullet_attack_length, CVector3D _destroy_length, double _speed, CImage* _shadow_image, CVector2D _shadow_offset_pos, CVector2D _shadow_size) : CObject()
{
	m_attack_length = _bullet_attack_length;
	m_target_task_id = _target_task_id;
	m_attack_power = _attack_power;
	m_bullet_image_p = _bullet_image;
	m_pos = _pos;
	m_size = _size;
	m_is_flip = _flip;

	m_offset_pos = _offset_pos;

	//CVector3D offset_pos = _offset_pos;
	if (m_is_flip == false) {
		m_vec = CVector3D(1, 0, 0);
	}
	else {
		m_vec = CVector3D(-1, 0, 0);
		//offset_pos.x *= -1.0;
	}
	//m_pos += offset_pos;

	m_vec *= _speed;
	m_bullet_fire_pos = m_pos;
	m_destroy_length = _destroy_length;

	SetShadow(_shadow_image, _shadow_offset_pos, _shadow_size);
}

void CBullet::SetShadow(CImage * _shadow_image, CVector2D _shadow_offset_pos, CVector2D _shadow_size)
{
	m_shadow_image_p = _shadow_image;
	m_shadow_offset_pos = _shadow_offset_pos;
	m_shadow_size = _shadow_size;
}

void CBullet::Update()
{
	MovePos();
	CheckDestroy();
	CheckHitTarget();
	SetDrawPriority(m_pos.z);
}

void CBullet::Draw()
{
	CVector2D offset_pos = m_offset_pos;
	if (m_is_flip == true) offset_pos.x *= -1.0;

	m_bullet_image_p->SetSize(15, 15);
	m_bullet_image_p->SetFlipH(m_is_flip);
	m_bullet_image_p->SetPos(CVector2D(m_pos.x,m_pos.y+m_pos.z) - GetScroll() + offset_pos);
	m_bullet_image_p->Draw();

	if (m_shadow_image_p != nullptr) {
		m_shadow_image_p->SetSize(m_shadow_size);

		CVector2D shadow_offset_pos = m_shadow_offset_pos;

		if (m_is_flip == true) shadow_offset_pos.x *= -1.0;

		m_shadow_image_p->SetPos(CVector2D(m_pos.x, m_pos.y + m_pos.z) + shadow_offset_pos - GetScroll());
		m_shadow_image_p->Draw();
	}
}

void CBullet::CheckDestroy()
{
	CVector3D move_amount = m_pos - m_bullet_fire_pos;
	if (abs(move_amount.x) >= m_destroy_length.x
		|| abs(move_amount.y) >= m_destroy_length.y
		|| abs(move_amount.z) >= m_destroy_length.z) {
		Destroy();
	}
}

void CBullet::CheckHitTarget()
{
	//ローカル変数定義
	register const CVector3D& player_pos = GetPos();//プレイヤーの位置

	register CVector3D length;//距離ベクトル(位置の差)を計算
	register CVector3D length_abs;//絶対距離
	const CVector3D attack_length = m_attack_length;

	//生成されている全てのターゲットのポインタを取得
	register Task** enemy_array = TaskManager::GetInstance()->FindTaskArray(m_target_task_id);

	if (enemy_array != nullptr) {

		register CCharacter* range_attack_enemy_p = nullptr;
		register double range_target_enemy_length;

		//カウンタ
		register int i = 0;

		//敵のポインタ取得用
		CCharacter* enemy_p = nullptr;

		while (true) {
			if (enemy_array[i] == nullptr) {
				break;
			}

			enemy_p = dynamic_cast<CCharacter*>(enemy_array[i]);
			if (enemy_p == nullptr) {
				i++;
				continue;
			}

			//位置関係を取得

			//敵のポジションを取得
			register const CVector3D& enemy_pos = enemy_p->GetPos();//敵の位置

			const CVector3D& enemy_rads = enemy_p->GetRads();


			//距離ベクトル(位置の差)を計算
			length = enemy_pos - player_pos;

			//絶対距離を計算
			length_abs.x = abs(length.x);
			length_abs.y = abs(length.y);
			length_abs.z = abs(length.z);

			//敵が左側にいて自分が左向き
			//もしくは敵が右側にいて、自分が右向きなら
			if (length.x <= 0.0f && m_is_flip == true
				|| length.x >= 0.0f && m_is_flip == false) {
				//攻撃範囲内に敵がいるなら
				if (length_abs.x <= attack_length.x + enemy_rads.x&& length_abs.y <= attack_length.y + enemy_rads.y&&length_abs.z <= attack_length.z + enemy_rads.z) {
					
					double length_enemy = length_abs.x + length_abs.y + length_abs.z;
					if (range_attack_enemy_p == nullptr) {
						range_attack_enemy_p = enemy_p;
						range_target_enemy_length = length_enemy;
					}
					else if (range_attack_enemy_p != nullptr && range_target_enemy_length > length_enemy) {
						range_attack_enemy_p = enemy_p;
						range_target_enemy_length = length_enemy;
					}
				}
			}

			//インクリメント
			i++;
		}

		//ループ終了後(ブロックがわかりにくいのでリファクタリングの余地あり)
		if (range_attack_enemy_p != nullptr) {
			range_attack_enemy_p->ReceiveAttack();
			range_attack_enemy_p->ReceiveKnockBack(m_pos,5.0);
			*range_attack_enemy_p->GetHitPointPointer() -= m_attack_power;
			Destroy();
		}

		free(enemy_array);
	}
}

void CBullet::Destroy()
{
	SetIsDelete();
	CGameScene::GetInstance()->EraseGameSceneObject(this);
}
