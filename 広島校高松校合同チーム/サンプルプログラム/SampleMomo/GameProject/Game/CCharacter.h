#pragma once
#include "CObject.h"

#define ANIMATION_INFO_MAX (100)
#define ANIMATION_IMAGE_MAX (500)


#define DEFAULT_ANIM_DELAY (10)

struct AnimInfo {
	int image_id;
	int image_num = 0;
	int delay;
};

class CCharacter : public CObject {
private:
protected:

	//�e�\���֘A
	CVector2D m_shadow_size;
	CImage * m_shadow_p = nullptr;
	bool m_is_show_shadow = false;

	//�A�j���[�V��������֘A
	AnimInfo m_anim_info[ANIMATION_INFO_MAX];
	int m_play_anim_id = 0;
	int m_play_anim_image = 0;
	int m_will_play_anim_id = 0;
	int m_play_anim_count = 0;
	CImage* m_anim_image_p[ANIMATION_IMAGE_MAX];

	//�\���ʒu�����֘A
	CVector2D m_draw_adj;

	//�t���O�֘A
	bool m_is_landing = false;
	
public:
	CCharacter(int _task_id, int _draw_priority);
	virtual ~CCharacter();
	void Update();
	virtual void CharacterUpdate();
	void AfterUpdate();
	virtual void CharacterAfterUpdate();

	void SetWillPlayAnim(int _anim_id) { m_will_play_anim_id = _anim_id; };
	void SetAnim(int _anim_id);
	void PlayAnim();

	void Gravity();

	void BeforeCollisionCheck();
	virtual void CharacterBeforeCollisionCheck();

	void BeforeUpdate();
	virtual void CharacterBeforeUpdate();

	void Draw();
	void DrawShadow();
	void DrawAnimImage();
	virtual void CharacterDraw();
	void CollisionCheck(Task* _collision_task);
	virtual void CollisionCheckCharacter(Task* _collision_task);

	void SetIsShowShadow(bool _is) { m_is_show_shadow = _is; };
	void SetShadowSize(CVector2D _size) { m_shadow_size = _size; };

	void SetDrawAdjPos(CVector2D _adj_pos) { m_draw_adj = _adj_pos; };
	CVector2D GetDrawAdjPos() { return m_draw_adj; };

	void MoveLimit();
};


/*
2019/03/06 �N���X��`�B��{�@�\�����B by shingai
2019/03/11 �A�j���[�V�����V�X�e���A�e�\���V�X�e���A�����蔻��V�X�e�������B by shingai
*/

