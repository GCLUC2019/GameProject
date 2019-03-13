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
}

void CGameSceneObject::GameSceneObjectAfterUpdate()
{
}

void CGameSceneObject::Gravity()
{
	//Ú’n‚µ‚Ä‚¢‚é‚È‚çd—Í‚ð‰ÁŽZ‚µ‚È‚¢
	if (m_is_landing == true) {
		return;
	}

	m_vec.y += GRAVITY * CFPS::GetDeltaTime();
	if (m_vec.y >= GRAVITY_LIMIT) m_vec.y = GRAVITY_LIMIT;

}

void CGameSceneObject::BeforeCollisionCheck()
{
	GameSceneObjectBeforeCollisionCheck();
}

void CGameSceneObject::GameSceneObjectBeforeCollisionCheck()
{
}

void CGameSceneObject::BeforeUpdate()
{
	GameSceneObjectBeforeUpdate();
}

void CGameSceneObject::GameSceneObjectBeforeUpdate()
{
}

void CGameSceneObject::Draw()
{
	DrawShadow();
	GameSceneObjectDraw();
}

void CGameSceneObject::DrawShadow()
{
}

void CGameSceneObject::GameSceneObjectDraw()
{
}

void CGameSceneObject::CollisionCheck(Task * _collision_task)
{
	GameSceneObjectCollisionCheck(_collision_task);
}

void CGameSceneObject::GameSceneObjectCollisionCheck(Task * _collision_task)
{

}

void CGameSceneObject::MoveLimit()
{
	CVector3D limit_pos_max = CGameScene::GetInstance()->GetGameSceneLimitPosMax();
	CVector3D limit_pos_min = CGameScene::GetInstance()->GetGameSceneLimitPosMin();

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
