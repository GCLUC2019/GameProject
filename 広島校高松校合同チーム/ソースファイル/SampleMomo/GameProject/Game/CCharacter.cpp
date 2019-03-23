#include "CCharacter.h"
#include "../Global.h"
#include "CGameScene.h"
#include "CGameSceneWave.h"

CCharacter::CCharacter(int _task_id, int _draw_priority) : CGameSceneObject(_task_id, _draw_priority)
{
	/*
	m_shadow_p = GET_RESOURCE("Shadow", CImage*);
	*/
}

CCharacter::~CCharacter()
{

}

void CCharacter::GameSceneObjectUpdate()
{
	CheckHitPoint();
	CharacterUpdate();
}

void CCharacter::CharacterUpdate()
{
	
}

void CCharacter::GameSceneObjectAfterUpdate()
{
	CharacterAfterUpdate();

	/*
	//アニメーション制御用なのでここにあると都合が良い
	SetAnim(m_will_play_anim_id);
	PlayAnim();

	//描画順番の設定
	SetDrawPriority(m_pos.z);
	//SetDrawPriority(GetShadowPos().z);
	*/

	
}

void CCharacter::CharacterAfterUpdate()
{
}

void CCharacter::CharacterOutHitPoint()
{
}

/*
void CCharacter::SetAnim(int _anim_id)
{
	if (m_play_anim_id == _anim_id) return;
	m_play_anim_id = _anim_id;
	m_play_anim_image = m_anim_info[_anim_id].image_id;
	m_play_anim_count = m_anim_info[_anim_id].delay;
}

void CCharacter::PlayAnim()
{
	if (m_play_anim_count-- <= 0) {

		m_play_anim_image++;
		if (m_play_anim_image >= m_anim_info[m_play_anim_id].image_id + m_anim_info[m_play_anim_id].image_num) {
			m_play_anim_image = m_anim_info[m_play_anim_id].image_id;
		}
		m_play_anim_count = m_anim_info[m_play_anim_id].delay;
	}
}
*/

/*
void CCharacter::Gravity()
{
	//接地しているなら重力を加算しない
	if (m_is_landing == true) {
		//printf("m_vec.y %lf\n", m_vec.y);
		return;
	}

	//ベクトルが大きい際に敵にうまっちゃう場合あり

	m_vec.y += GRAVITY * CFPS::GetDeltaTime();
	if (m_vec.y >= GRAVITY_LIMIT) m_vec.y = GRAVITY_LIMIT;

	//if (m_vec.y >= 3.0) m_vec.y = 3.0;
}
*/

void CCharacter::GameSceneObjectBeforeCollisionCheck()
{
	/*
	m_is_landing_old = m_is_landing;
	m_is_landing = false;
	*/
	CharacterBeforeCollisionCheck();
}

void CCharacter::CharacterBeforeCollisionCheck()
{
}

void CCharacter::GameSceneObjectBeforeUpdate()
{
	CharacterBeforeUpdate();
}

void CCharacter::CharacterBeforeUpdate()
{
}

void CCharacter::HitPointGainValue(double _value)
{
	//無敵なら何もしない
	if (GetInvincible() == true) {
		//printf("無敵です\n");
		return;
	}



	m_hit_point += _value;
	if (m_hit_point > m_hit_point_max) m_hit_point = m_hit_point_max;
}

void CCharacter::ReceiveAttack()
{
}

void CCharacter::DoingKnockBack()
{
	if (m_is_knock_back == false) return;

	m_knock_back_count -= CFPS::GetDeltaTime()  * GAME_BASE_FPS;
	m_vec.x = m_knock_back_vec.x;
	m_vec.z = m_knock_back_vec.z;

	if (m_knock_back_count <= 0.0) {
		m_is_knock_back = false;
		m_vec.x = 0.0;
		m_vec.z = 0.0;
	}
}

void CCharacter::ReceiveKnockBack(CVector3D _from_pos, double _power)
{
}

void CCharacter::SetKnockBack(CVector3D _from_pos, double _power)
{
	//ノックバック
	m_is_knock_back = true;
	m_knock_back_count = m_knock_back_frame;
	CVector3D vec = _from_pos - m_pos;
	m_knock_back_vec = vec.GetNormalize() * -1.0 * _power;
}

void CCharacter::SendDeadMeForFromWave()
{
	if (m_from_wave_p == nullptr) return;
	m_from_wave_p->DeadEnemy(m_wave_character_id);
}

void CCharacter::CheckHitPoint()
{
	if (m_hit_point <= 0.0f) {
		//printf("hp 0 \n");
		//SetIsDelete();
		CharacterOutHitPoint();
		SendDeadMeForFromWave();//ウェーブシステムに自分が倒されたことを伝える
	}
}


void CCharacter::GameSceneObjectDraw()
{
	/*
	DrawShadow();
	DrawAnimImage();
	*/
	CharacterDraw();
}

/*
void CCharacter::DrawShadow()
{
	if (m_shadow_p == nullptr) return;
	
	//CVector2D shadow_adj_pos = m_shadow_adj_pos;
	//if (m_is_flip == true) shadow_adj_pos.x *= -1.0f;
	//CVector2D draw_pos_shadow = CVector2D(m_pos.x, m_pos.z + (m_size.y / 2.0)) - GetScroll() + shadow_adj_pos;

	CVector2D draw_pos_shadow = CVector2D(m_pos.x, m_pos.z ) - GetScroll();

	CVector2D shadow_pos_adj = m_shadow_pos_adj;

	if (m_is_flip == true) shadow_pos_adj.x *= -1.0f;

	m_shadow_p->SetFlipH(m_is_flip);
	m_shadow_p->SetSize(m_shadow_size.x, m_shadow_size.y);
	m_shadow_p->SetPos(draw_pos_shadow + shadow_pos_adj);
	m_shadow_p->SetCenter(m_shadow_size.x / 2.0, m_shadow_size.y / 2.0);
	m_shadow_p->Draw();
}
*/


/*
void CCharacter::DrawAnimImage()
{
	if (m_anim_image_p[m_play_anim_image] == nullptr) return;
	m_anim_image_p[m_play_anim_image]->SetFlipH(m_is_flip);
	m_anim_image_p[m_play_anim_image]->SetSize(m_size.x, m_size.y);
	CVector2D draw_pos = CVector2D(m_pos.x, m_pos.y + m_pos.z) - GetScroll();


	CVector2D draw_adj = m_draw_adj;
	if (m_is_flip == true) draw_adj.x *= -1.0f;

	m_anim_image_p[m_play_anim_image]->SetPos(draw_pos + draw_adj);
	m_anim_image_p[m_play_anim_image]->SetCenter(m_size.x / 2.0, m_size.y / 2.0);
	m_anim_image_p[m_play_anim_image]->Draw();
}
*/

void CCharacter::CharacterDraw()
{
}

//
//void CCharacter::CollisionCheck(Task * _collision_task)
//{
//	CObject* ob = dynamic_cast<CObject*>(_collision_task);
//	CVector3D ob_pos = ob->GetPos();
//	CVector3D ob_pos_old = ob->GetPosOld();
//	CVector3D ob_rads = ob->GetRads();
//
//
//	//相手も動く場合は、処理が複雑かも
//
//	if (CollisionCheck3D(CVector3D(m_pos.x,m_pos_old.y,m_pos_old.z),m_rads,ob_pos,ob_rads)) {
//		m_pos.x = m_pos_old.x;
//	};
//
//	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
//		m_pos.y = m_pos_old.y;
//		
//		
//		//もし戻した座標が自分の頭上より上なら自分の頭上ぴったりに合わせる
//
//		//計算式 敵の頭上ぴったりとなる位置 = 敵のY位置 - 敵のY半径 - 自分のY半径 - 若干浮かせるための補正値
//
//
//		double ob_head_pos = ob_pos.y - ob_rads.y - m_rads.y - 0.1f;
//		if(m_pos.y <= ob_head_pos) m_pos.y = ob_head_pos;
//
//
//		m_is_landing = true;
//	};
//
//	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos_old.y, m_pos.z), m_rads, ob_pos, ob_rads)) {
//		m_pos.z = m_pos_old.z;
//	};
//
//	/*
//	if (CollisionCheck3D(m_pos, m_rads, ob_pos, ob_rads)) {
//		//printf("ぶつかった ob_pos.y %lf ob_rads.y %lf\n",ob_pos.y,ob_rads.y);
//		//m_pos = m_pos_old;
//	};
//	*/
//
//	
//
//
//	CollisionCheckCharacter(_collision_task);
//}

void CCharacter::GameSceneObjectCollisionCheck(Task * _collision_task)
{
	CollisionCheckCharacter(_collision_task);
}

void CCharacter::CollisionCheckCharacter(Task * _collision_task)
{
}

/*
void CCharacter::MoveLimit()
{
	CVector3D limit_pos_max = CGameScene::GetInstance()->GetGameSceneLimitPosMax();
	CVector3D limit_pos_min = CGameScene::GetInstance()->GetGameSceneLimitPosMin();

	if (m_pos.x < limit_pos_min.x + m_rads.x / 2.0) m_pos.x = limit_pos_min.x + m_rads.x / 2.0;
	if (m_pos.x > limit_pos_max.x) m_pos.x = limit_pos_max.x;

	if (m_pos.z < limit_pos_min.z + m_rads.y / 2.0) m_pos.z = limit_pos_min.z + m_rads.y / 2.0;
	if (m_pos.z > limit_pos_max.z) m_pos.z = limit_pos_max.z;
}
*/