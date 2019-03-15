#include "CGameSceneObject.h"
#include "../Global.h"
#include "CGameScene.h"
#include "CGameSceneWave.h"

CGameSceneObject::CGameSceneObject(int _task_id, int _draw_priority) : CObject(_task_id, _draw_priority)
{
	m_shadow_p = GET_RESOURCE("Shadow", CImage*);
}

CGameSceneObject::~CGameSceneObject()
{
}

void CGameSceneObject::Update()
{
	GameSceneObjectUpdate();
}

void CGameSceneObject::GameSceneObjectUpdate()
{
}

void CGameSceneObject::AfterUpdate()
{
	GameSceneObjectAfterUpdate();

	//ƒAƒjƒ[ƒVƒ‡ƒ“§Œä—p‚È‚Ì‚Å‚±‚±‚É‚ ‚é‚Æ“s‡‚ª—Ç‚¢
	SetAnim(m_will_play_anim_id);
	PlayAnim();

	//•`‰æ‡”Ô‚Ìİ’è
	SetDrawPriority(m_pos.z);
}

void CGameSceneObject::GameSceneObjectAfterUpdate()
{
}

void CGameSceneObject::Gravity()
{
	//Ú’n‚µ‚Ä‚¢‚é‚È‚çd—Í‚ğ‰ÁZ‚µ‚È‚¢
	if (m_is_landing == true) {
		return;
	}

	m_vec.y += GRAVITY * CFPS::GetDeltaTime();
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

void CGameSceneObject::BeforeUpdate()
{
	SetPosOld(m_pos);
	GameSceneObjectBeforeUpdate();
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

	CVector2D draw_pos_shadow = CVector2D(m_pos.x, m_pos.z) - GetScroll();

	CVector2D shadow_pos_adj = m_shadow_pos_adj;

	if (m_is_flip == true) shadow_pos_adj.x *= -1.0f;

	m_shadow_p->SetFlipH(m_is_flip);
	m_shadow_p->SetSize(m_shadow_size.x, m_shadow_size.y);
	m_shadow_p->SetPos(draw_pos_shadow + shadow_pos_adj);
	m_shadow_p->SetCenter(m_shadow_size.x / 2.0, m_shadow_size.y / 2.0);
	m_shadow_p->Draw();
}

void CGameSceneObject::DrawAnimImage()
{
	if (m_anim_image_p[m_play_anim_image] == nullptr) return;
	m_anim_image_p[m_play_anim_image]->SetFlipH(m_is_flip);
	m_anim_image_p[m_play_anim_image]->SetSize(m_size.x, m_size.y);
	CVector2D draw_pos = CVector2D(m_pos.x, m_pos.y + m_pos.z) - GetScroll();


	CVector2D draw_adj = m_draw_adj;
	if (m_is_flip == true) draw_adj.x *= -1.0f;


	//“_–Å•`‰æ
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
			m_anim_image_p[m_play_anim_image]->SetColor(2.55f, 2.55f, 2.55f, m_blind_alpha);
		}
		else {
			m_anim_image_p[m_play_anim_image]->SetColor(2.55f, 2.55f, 2.55f, 2.55f);
		}
	}
	if (m_is_blind_draw == false) {
		m_is_blind_now = false;
		m_anim_image_p[m_play_anim_image]->SetColor(2.55f, 2.55f, 2.55f, 2.55f);
	}
	
	
	m_anim_image_p[m_play_anim_image]->SetPos(draw_pos + draw_adj);
	m_anim_image_p[m_play_anim_image]->SetCenter(m_size.x / 2.0, m_size.y / 2.0);
	m_anim_image_p[m_play_anim_image]->Draw();
}

void CGameSceneObject::GameSceneObjectDraw()
{

}

void CGameSceneObject::CollisionCheck(Task * _collision_task)
{
	register CObject* ob = dynamic_cast<CObject*>(_collision_task);
	register const CVector3D& ob_pos = ob->GetPos();
	register const CVector3D& ob_pos_old = ob->GetPosOld();
	register const CVector3D& ob_rads = ob->GetRads();
	register double ob_head_pos;

	//‘Šè‚à“®‚­ê‡‚ÍAˆ—‚ª•¡G‚©‚à

	if (CollisionCheck3D(CVector3D(m_pos.x, m_pos_old.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.x = m_pos_old.x;
	};

	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.y = m_pos_old.y;


		//‚à‚µ–ß‚µ‚½À•W‚ª©•ª‚Ì“ªã‚æ‚èã‚È‚ç©•ª‚Ì“ªã‚Ò‚Á‚½‚è‚É‡‚í‚¹‚é

		//ŒvZ® “G‚Ì“ªã‚Ò‚Á‚½‚è‚Æ‚È‚éˆÊ’u = “G‚ÌYˆÊ’u - “G‚ÌY”¼Œa - ©•ª‚ÌY”¼Œa - áŠ±•‚‚©‚¹‚é‚½‚ß‚Ì•â³’l


		ob_head_pos = ob_pos.y - ob_rads.y - m_rads.y - 0.1f;
		if (m_pos.y <= ob_head_pos) m_pos.y = ob_head_pos;


		m_is_landing = true;
	};

	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos_old.y, m_pos.z), m_rads, ob_pos, ob_rads)) {
		m_pos.z = m_pos_old.z;
	};

	GameSceneObjectCollisionCheck(_collision_task);

	//Œy—Ê‰»‘O
	/*
	CObject* ob = dynamic_cast<CObject*>(_collision_task);
	const CVector3D& ob_pos = ob->GetPos();
	const CVector3D& ob_pos_old = ob->GetPosOld();
	const CVector3D& ob_rads = ob->GetRads();


	//‘Šè‚à“®‚­ê‡‚ÍAˆ—‚ª•¡G‚©‚à

	if (CollisionCheck3D(CVector3D(m_pos.x, m_pos_old.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.x = m_pos_old.x;
	};

	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.y = m_pos_old.y;


		//‚à‚µ–ß‚µ‚½À•W‚ª©•ª‚Ì“ªã‚æ‚èã‚È‚ç©•ª‚Ì“ªã‚Ò‚Á‚½‚è‚É‡‚í‚¹‚é

		//ŒvZ® “G‚Ì“ªã‚Ò‚Á‚½‚è‚Æ‚È‚éˆÊ’u = “G‚ÌYˆÊ’u - “G‚ÌY”¼Œa - ©•ª‚ÌY”¼Œa - áŠ±•‚‚©‚¹‚é‚½‚ß‚Ì•â³’l


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
	const CVector3D& limit_pos_max = CGameScene::GetInstance()->GetGameSceneLimitPosMax();
	const CVector3D& limit_pos_min = CGameScene::GetInstance()->GetGameSceneLimitPosMin();

	if (m_pos.x < limit_pos_min.x + m_rads.x / 2.0) m_pos.x = limit_pos_min.x + m_rads.x / 2.0;
	if (m_pos.x > limit_pos_max.x) m_pos.x = limit_pos_max.x;

	if (m_pos.z < limit_pos_min.z + m_rads.y / 2.0) m_pos.z = limit_pos_min.z + m_rads.y / 2.0;
	if (m_pos.z > limit_pos_max.z) m_pos.z = limit_pos_max.z;
}

void CGameSceneObject::SetAnim(int _anim_id)
{
	if (m_play_anim_id == _anim_id) return;
	m_play_anim_id = _anim_id;
	m_play_anim_image = m_anim_info[_anim_id].image_id;
	m_play_anim_count = m_anim_info[_anim_id].delay;
}

void CGameSceneObject::PlayAnim()
{
	if (m_play_anim_count-- <= 0) {

		m_play_anim_image++;
		if (m_play_anim_image >= m_anim_info[m_play_anim_id].image_id + m_anim_info[m_play_anim_id].image_num) {
			m_play_anim_image = m_anim_info[m_play_anim_id].image_id;
		}
		m_play_anim_count = m_anim_info[m_play_anim_id].delay;
	}
}
