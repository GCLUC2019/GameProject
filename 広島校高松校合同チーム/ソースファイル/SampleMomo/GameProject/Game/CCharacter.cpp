#include "CCharacter.h"
#include "../Global.h"
#include "CGameScene.h"
#include "CGameSceneWave.h"

CCharacter::CCharacter(int _task_id, int _draw_priority) : CObject(_task_id, _draw_priority)
{
	m_shadow_p = GET_RESOURCE("Shadow", CImage*);
}

CCharacter::~CCharacter()
{

}

void CCharacter::Update()
{
	CheckHitPoint();
	CharacterUpdate();
}

void CCharacter::CharacterUpdate()
{
	
}

void CCharacter::AfterUpdate()
{
	CharacterAfterUpdate();

	//�A�j���[�V��������p�Ȃ̂ł����ɂ���Ɠs�����ǂ�
	SetAnim(m_will_play_anim_id);
	PlayAnim();

	//�`�揇�Ԃ̐ݒ�
	SetDrawPriority(m_pos.z);
	//SetDrawPriority(GetShadowPos().z);
}

void CCharacter::CharacterAfterUpdate()
{
}

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

void CCharacter::Gravity()
{
	//�ڒn���Ă���Ȃ�d�͂����Z���Ȃ�
	if (m_is_landing == true) {
		//printf("m_vec.y %lf\n", m_vec.y);
		return;
	}

	//�x�N�g�����傫���ۂɓG�ɂ��܂����Ⴄ�ꍇ����

	m_vec.y += GRAVITY * CFPS::GetDeltaTime();
	if (m_vec.y >= GRAVITY_LIMIT) m_vec.y = GRAVITY_LIMIT;

	//if (m_vec.y >= 3.0) m_vec.y = 3.0;
}

void CCharacter::BeforeCollisionCheck()
{
	m_is_landing_old = m_is_landing;
	m_is_landing = false;
}

void CCharacter::CharacterBeforeCollisionCheck()
{
}

void CCharacter::BeforeUpdate()
{
	CharacterBeforeUpdate();
}

void CCharacter::CharacterBeforeUpdate()
{
}

void CCharacter::HitPointGainValue(double _value)
{
	m_hit_point += _value;
	if (m_hit_point > m_hit_point_max) m_hit_point = m_hit_point_max;
}

void CCharacter::ReceiveAttack()
{
}

void CCharacter::SendDeadMeForFromWave()
{
	if (m_from_wave_p == nullptr) return;
	m_from_wave_p->DeadEnemy(m_wave_character_id);
}

void CCharacter::CheckHitPoint()
{
	if (m_hit_point < 0.0f) {
		SetIsDelete();
		SendDeadMeForFromWave();//�E�F�[�u�V�X�e���Ɏ������|���ꂽ���Ƃ�`����
	}
}

void CCharacter::Draw()
{
	DrawShadow();
	DrawAnimImage();
	CharacterDraw();
}

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

void CCharacter::CharacterDraw()
{
}

void CCharacter::CollisionCheck(Task * _collision_task)
{
	CObject* ob = dynamic_cast<CObject*>(_collision_task);
	CVector3D ob_pos = ob->GetPos();
	CVector3D ob_pos_old = ob->GetPosOld();
	CVector3D ob_rads = ob->GetRads();


	//����������ꍇ�́A���������G����

	if (CollisionCheck3D(CVector3D(m_pos.x,m_pos_old.y,m_pos_old.z),m_rads,ob_pos,ob_rads)) {
		m_pos.x = m_pos_old.x;
	};

	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.y = m_pos_old.y;
		
		
		//�����߂������W�������̓������Ȃ玩���̓���҂�����ɍ��킹��

		//�v�Z�� �G�̓���҂�����ƂȂ�ʒu = �G��Y�ʒu - �G��Y���a - ������Y���a - �኱�������邽�߂̕␳�l


		double ob_head_pos = ob_pos.y - ob_rads.y - m_rads.y - 0.1f;
		if(m_pos.y <= ob_head_pos) m_pos.y = ob_head_pos;


		m_is_landing = true;
	};

	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos_old.y, m_pos.z), m_rads, ob_pos, ob_rads)) {
		m_pos.z = m_pos_old.z;
	};

	/*
	if (CollisionCheck3D(m_pos, m_rads, ob_pos, ob_rads)) {
		//printf("�Ԃ����� ob_pos.y %lf ob_rads.y %lf\n",ob_pos.y,ob_rads.y);
		//m_pos = m_pos_old;
	};
	*/

	


	CollisionCheckCharacter(_collision_task);
}

void CCharacter::CollisionCheckCharacter(Task * _collision_task)
{
}

void CCharacter::MoveLimit()
{
	CVector3D limit_pos_max = CGameScene::GetInstance()->GetGameSceneLimitPosMax();
	CVector3D limit_pos_min = CGameScene::GetInstance()->GetGameSceneLimitPosMin();

	if (m_pos.x < limit_pos_min.x + m_rads.x / 2.0) m_pos.x = limit_pos_min.x + m_rads.x / 2.0;
	if (m_pos.x > limit_pos_max.x) m_pos.x = limit_pos_max.x;

	if (m_pos.z < limit_pos_min.z + m_rads.y / 2.0) m_pos.z = limit_pos_min.z + m_rads.y / 2.0;
	if (m_pos.z > limit_pos_max.z) m_pos.z = limit_pos_max.z;
}
