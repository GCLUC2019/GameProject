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

	//�A�j���[�V��������p�Ȃ̂ł����ɂ���Ɠs�����ǂ�
	m_anim_p->CheckWillPlayAnim();
	//SetAnim(m_will_play_anim_id);
	m_anim_p->PlayAnim();

	//�`�揇�Ԃ̐ݒ�
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

	//�ڒn���Ă���Ȃ�d�͂����Z���Ȃ�
	if (m_is_landing == true) {
		return;
	}


	//printf("delta_time %lf", CFPS::GetDeltaTime());
	//���Z���Ă��邪���Z�ʂ�1�b�Ԃňꗥ�Ƃ������̂�
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


	//�_�ŕ`��
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


//�������ԂɊ֌W�Ȃ��A���������ꍇ�ǂ��炪�������̐ݒ�l�ɂ���Ă��̂�����A
//�\�[�g�ƃA���S���Y���I�ɂ͎��Ă���̂́A���Ԃɂ͊֌W�Ȃ��D��x�ŏ���������̂ő啝�Ɍy��
//��͂�^�X�N���œ����蔻��̗D��x�Ɠ����蔻�������I�u�W�F�N�g���ǂ����̐ݒ�͂������ق��������ȁB
//(���ݓI�ȃo�O�̔����p�x���l����Ǝd���Ȃ�)
//����܂��ǂ������ǂ����̃t���O�����ł��������ǂ�
//����[���ǂ������ǂ����̃t���O�����̏ꍇ���Ƃ��ꂾ��
//�S�I�u�W�F�N�g�̑g�ݍ��킹����Ȃ��ł��Ă������킯���Ȃ��B(�v�Z�̒Z�k���ł��邵)

//��U���ɂ��Ȃ��Ƃ����Ȃ����Ƃ�����̂ŗD��x�\�[�g���ł���(�y����)


//�D��x�^�ɂ���ƂȂ��CollisionCheck�ł������������I�u�W�F�N�g�̑g�ݍ��킹�����Ȃ��悤�ɂ���K�v������i���[�v���ׂ͌��肻�����j
//���̃I�u�W�F�N�g�ł��ׂ����e�ł͂Ȃ�����

//�^�X�N�V�X�e�����ŋ@�\�����������肩�͌y�ʂȐ݌v�ȋC�����邪


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
		//����̓���Ɏ����̑�������ʒu�v�Z
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


	//�y�ʉ��O
	/*
	CObject* ob = dynamic_cast<CObject*>(_collision_task);
	const CVector3D& ob_pos = ob->GetPos();
	const CVector3D& ob_pos_old = ob->GetPosOld();
	const CVector3D& ob_rads = ob->GetRads();


	//����������ꍇ�́A���������G����

	if (CollisionCheck3D(CVector3D(m_pos.x, m_pos_old.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.x = m_pos_old.x;
	};

	if (CollisionCheck3D(CVector3D(m_pos_old.x, m_pos.y, m_pos_old.z), m_rads, ob_pos, ob_rads)) {
		m_pos.y = m_pos_old.y;


		//�����߂������W�������̓������Ȃ玩���̓���҂�����ɍ��킹��

		//�v�Z�� �G�̓���҂�����ƂȂ�ʒu = �G��Y�ʒu - �G��Y���a - ������Y���a - �኱�������邽�߂̕␳�l


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

	//if (GetTaskId() == eTaskIdPlayer) printf("�v���C���[��calcpos\n");

	//printf("�X�N���[���v�Z\n");
	//��ʏ�̍��W

	const CVector2D& scroll_pos = GetScroll();
	//printf("scroll_pos x%lf scroll_pos y%lf \n", scroll_pos.x, scroll_pos.y);

	CVector2D calc_scroll_pos = scroll_pos;

	register const float offset_x = -350.0f;
	register const float offset_y = -200.0f;

	//�X�N���[�����E�l��ݒ�
	register const double max_x = CGameScene::GetInstance()->GetGameSceneLimitPosMax().x - 1280.0f;
	register const double min_x = CGameScene::GetInstance()->GetGameSceneLimitPosMin().x;

	//�L�����`��ʒu
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

