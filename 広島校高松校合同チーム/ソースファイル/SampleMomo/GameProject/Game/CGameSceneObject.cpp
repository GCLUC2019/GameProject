#include "CGameSceneObject.h"
#include "../Global.h"
#include "CGameScene.h"
#include "CGameSceneWave.h"
#include "CAnimation.h"

CGameSceneObject::CGameSceneObject(int _task_id, int _draw_priority) : CObject(_task_id, _draw_priority)
{
	m_anim_p = new CAnimation();
	m_shadow_p = GET_RESOURCE("Shadow", CImage*);
}

CGameSceneObject::~CGameSceneObject()
{
}

void CGameSceneObject::BeforeUpdate()
{
	SetPosOld(m_pos);
	GameSceneObjectBeforeUpdate();
}

void CGameSceneObject::Update()
{
	GameSceneObjectUpdate();
	Gravity();
	MovePos();
	MoveLimit();
	CalcScroll();
}

void CGameSceneObject::AfterUpdate()
{
	GameSceneObjectAfterUpdate();

	//アニメーション制御用なのでここにあると都合が良い
	m_anim_p->CheckWillPlayAnim();
	//SetAnim(m_will_play_anim_id);
	m_anim_p->PlayAnim();

	//描画順番の設定
	SetDrawPriority(m_pos.z);
}

void CGameSceneObject::GameSceneObjectUpdate()
{
}



void CGameSceneObject::GameSceneObjectAfterUpdate()
{
}

void CGameSceneObject::Gravity()
{
	if (GetIsReceiveGravity() == false) return;

	//接地しているなら重力を加算しない
	if (m_is_landing == true) {
		return;
	}


	//printf("delta_time %lf", CFPS::GetDeltaTime());
	//加算しているが加算量は1秒間で一律としたいので
	m_vec.y += GRAVITY * CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if (m_vec.y >= GRAVITY_LIMIT) m_vec.y = GRAVITY_LIMIT;

}

void CGameSceneObject::BeforeCollisionCheck()
{
	m_is_landing_old = m_is_landing;
	m_is_landing = false;
	GameSceneObjectBeforeCollisionCheck();
}

void CGameSceneObject::GameSceneObjectBeforeCollisionCheck()
{
	
}



void CGameSceneObject::GameSceneObjectBeforeUpdate()
{
}

void CGameSceneObject::Draw()
{
	DrawShadow();
	DrawAnimImage();
	GameSceneObjectDraw();
}

void CGameSceneObject::DrawShadow()
{
	if (m_shadow_p == nullptr) return;

	register CVector2D draw_pos_shadow = CVector2D(m_pos.x, m_pos.z) - GetScroll();

	register CVector2D shadow_pos_adj = m_shadow_pos_adj;
	if (m_is_flip == true) shadow_pos_adj.x *= -1.0f;

	m_shadow_p->SetFlipH(m_is_flip);
	m_shadow_p->SetSize(m_shadow_size.x, m_shadow_size.y);
	m_shadow_p->SetPos(draw_pos_shadow + shadow_pos_adj);
	m_shadow_p->SetCenter(m_shadow_size.x / 2.0, m_shadow_size.y / 2.0);
	m_shadow_p->Draw();
}

void CGameSceneObject::DrawAnimImage()
{
	CImage* draw_anim_image_p = m_anim_p->GetPlayAnimImage();
	if (draw_anim_image_p == nullptr) return;
	draw_anim_image_p->SetFlipH(m_is_flip);
	draw_anim_image_p->SetSize(m_size.x, m_size.y);
	
	register CVector2D draw_pos = CVector2D(m_pos.x, m_pos.y + m_pos.z) - GetScroll();


	register CVector2D draw_adj = m_draw_adj;
	if (m_is_flip == true) draw_adj.x *= -1.0f;


	//点滅描画
	if (m_is_blind_draw == true) {

		if (m_blind_delay_count-- <= 0) {
			if (m_is_blind_now == false) {
				m_is_blind_now = true;
				m_blind_delay_count = m_blind_delay;
			}
			else {
				m_is_blind_now = false;
				m_blind_delay_count = m_blind_delay;
			}
		}

		if (m_is_blind_now == false) {
			draw_anim_image_p->SetColor(2.55f, 2.55f, 2.55f, m_blind_alpha);
		}
		else {
			draw_anim_image_p->SetColor(2.55f, 2.55f, 2.55f, 2.55f);
		}
	}
	if (m_is_blind_draw == false) {
		m_is_blind_now = false;
		draw_anim_image_p->SetColor(2.55f, 2.55f, 2.55f, 2.55f);
	}
	
	
	draw_anim_image_p->SetPos(draw_pos + draw_adj);
	draw_anim_image_p->SetCenter(m_size.x / 2.0, m_size.y / 2.0);
	draw_anim_image_p->Draw();
}

void CGameSceneObject::GameSceneObjectDraw()
{

}


//処理順番に関係なく、当たった場合どちらが動くかの設定値によってやるのもあり、
//ソートとアルゴリズム的には似てるものの、順番には関係なく優先度で処理をするので大幅に軽量
//やはりタスク側で当たり判定の優先度と当たり判定をするオブジェクトかどうかの設定はあったほうがいいな。
//(潜在的なバグの発生頻度を考えると仕方なし)
//いやまぁどっちがどくかのフラグだけでもいいけども
//ちゅーかどっちがどくかのフラグだけの場合だとあれだな
//全オブジェクトの組み合わせを被りなしでしてもいいわけだなぁ。(計算の短縮もできるし)

//一旦他にやらないといけないことがあるので優先度ソート式でいく(楽だし)


//優先度型にするとなるとCollisionCheckでそもそも同じオブジェクトの組み合わせをしないようにする必要がある（ループ負荷は減りそうだ）
//このオブジェクトでやるべき内容ではないかも

//タスクシステム側で機能を実装するよりかは軽量な設計な気もするが


void CGameSceneObject::CollisionCheck(Task * _collision_task)
{
	register CObject* ob = dynamic_cast<CObject*>(_collision_task);
	register const CVector3D& ob_pos = ob->GetPos();
	register const CVector3D& ob_pos_old = ob->GetPosOld();
	register const CVector3D& ob_rads = ob->GetRads();

	if (CollisionCheck3D(CVector3D(m_pos.x, m_pos_old.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.x = m_pos_old.x;
	};


	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) { 
		//相手の頭上に自分の足がくる位置計算
		register float ob_head_pos = ob_pos.y - ob_rads.y - m_rads.y;
		m_pos.y = m_pos_old.y;
		if (m_pos.y <= ob_head_pos) {
			m_pos.y = ob_head_pos;
			m_is_landing = true;
		}
	};
	


	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos_old.y, m_pos.z), m_rads, ob_pos, ob_rads)) {
		m_pos.z = m_pos_old.z;
	};

	GameSceneObjectCollisionCheck(_collision_task);


	//軽量化前
	/*
	CObject* ob = dynamic_cast<CObject*>(_collision_task);
	const CVector3D& ob_pos = ob->GetPos();
	const CVector3D& ob_pos_old = ob->GetPosOld();
	const CVector3D& ob_rads = ob->GetRads();


	//相手も動く場合は、処理が複雑かも

	if (CollisionCheck3D(CVector3D(m_pos.x, m_pos_old.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.x = m_pos_old.x;
	};

	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.y = m_pos_old.y;


		//もし戻した座標が自分の頭上より上なら自分の頭上ぴったりに合わせる

		//計算式 敵の頭上ぴったりとなる位置 = 敵のY位置 - 敵のY半径 - 自分のY半径 - 若干浮かせるための補正値


		double ob_head_pos = ob_pos.y - ob_rads.y - m_rads.y - 0.1f;
		if (m_pos.y <= ob_head_pos) m_pos.y = ob_head_pos;


		m_is_landing = true;
	};

	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos_old.y, m_pos.z), m_rads, ob_pos, ob_rads)) {
		m_pos.z = m_pos_old.z;
	};

	GameSceneObjectCollisionCheck(_collision_task);
	*/
}

void CGameSceneObject::GameSceneObjectCollisionCheck(Task * _collision_task)
{

}

void CGameSceneObject::MoveLimit()
{
	if (GetIsLimitMovePos() == false) return;

	const CVector3D& limit_pos_max = CGameScene::GetInstance()->GetGameSceneLimitPosMax();
	const CVector3D& limit_pos_min = CGameScene::GetInstance()->GetGameSceneLimitPosMin();

	if (m_pos.x < limit_pos_min.x + m_rads.x / 2.0) m_pos.x = limit_pos_min.x + m_rads.x / 2.0;
	if (m_pos.x > limit_pos_max.x) m_pos.x = limit_pos_max.x;

	if (m_pos.z < limit_pos_min.z + m_rads.y / 2.0) m_pos.z = limit_pos_min.z + m_rads.y / 2.0;
	if (m_pos.z > limit_pos_max.z) m_pos.z = limit_pos_max.z;
}

void CGameSceneObject::CalcScroll()
{
	if (GetIsCalcScrollBaseObject() == false) return;

	//if (GetTaskId() == eTaskIdPlayer) printf("プレイヤーのcalcpos\n");

	//printf("スクロール計算\n");
	//画面上の座標

	const CVector2D& scroll_pos = GetScroll();
	//printf("scroll_pos x%lf scroll_pos y%lf \n", scroll_pos.x, scroll_pos.y);

	CVector2D calc_scroll_pos = scroll_pos;

	register const float offset_x = -350.0f;
	register const float offset_y = -200.0f;

	//スクロール限界値を設定
	register const double max_x = CGameScene::GetInstance()->GetGameSceneLimitPosMax().x - 1280.0f;
	register const double min_x = CGameScene::GetInstance()->GetGameSceneLimitPosMin().x;

	//キャラ描画位置
	register double draw_pos_y = m_pos.y + m_pos.z;


	if (m_pos.x >= scroll_pos.x + 1280.0f + offset_x) {
		calc_scroll_pos.x = m_pos.x - 1280.0f - offset_x;
	}

	else if (m_pos.x <= scroll_pos.x - offset_x) {
		calc_scroll_pos.x = m_pos.x + offset_x;
	}


	if (calc_scroll_pos.x >= CGameScene::GetInstance()->GetGameSceneLimitPosMax().x + offset_x) {
		calc_scroll_pos.x = CGameScene::GetInstance()->GetGameSceneLimitPosMax().x - offset_x;
	}


	if (calc_scroll_pos.x > max_x) calc_scroll_pos.x = max_x;
	if (calc_scroll_pos.x < min_x) calc_scroll_pos.x = min_x;

	if (draw_pos_y <= scroll_pos.y - offset_y) {
		calc_scroll_pos.y = draw_pos_y + offset_y;
	}
	else if (scroll_pos.y < 0) {
		calc_scroll_pos.y = draw_pos_y + offset_y;
	}

	if (calc_scroll_pos.y > 0.0f) calc_scroll_pos.y = 0.0f;

	//printf("m_pos.x %f m_pos.y %f m_pos.z %f\n", m_pos.x, m_pos.y,m_pos.z);
	//printf("calc_scroll_pos.x %f calc_scroll_pos.y %f\n", calc_scroll_pos.x, calc_scroll_pos.y);
	SetScroll(calc_scroll_pos);
}

/*
void CGameSceneObject::SetAnim(int _anim_id)
{
	if (m_play_anim_id == _anim_id) return;
	m_play_anim_id = _anim_id;
	m_play_anim_image = m_anim_info[_anim_id].image_id;
	m_play_anim_count = m_anim_info[_anim_id].delay[0];
}

void CGameSceneObject::PlayAnim()
{
	if (m_play_anim_count <= 0.0) {
		m_play_anim_image++;
		if (m_play_anim_image >= m_anim_info[m_play_anim_id].image_id + m_anim_info[m_play_anim_id].image_num) {
			m_play_anim_image = m_anim_info[m_play_anim_id].image_id;
		}
		m_play_anim_count = m_anim_info[m_play_anim_id].delay[m_play_anim_image - m_anim_info[m_play_anim_id].image_id];
	}
	else {
		m_play_anim_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
	}

}

*/

