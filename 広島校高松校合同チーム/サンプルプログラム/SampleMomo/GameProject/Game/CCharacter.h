#pragma once
#include "CObject.h"

#define ANIMATION_INFO_MAX (100)
#define ANIMATION_IMAGE_MAX (500)


#define DEFAULT_ANIM_DELAY (10)
#define PLAYER_ANIM_RUN_DELAY (5)

struct AnimInfo {
	int image_id;
	int image_num = 0;
	int delay;
};

class CCharacter : public CObject {
private:
protected:

	//影表示関連
	CVector2D m_shadow_size;
	CImage * m_shadow_p = nullptr;
	bool m_is_show_shadow = false;

	//アニメーション制御関連
	AnimInfo m_anim_info[ANIMATION_INFO_MAX];
	int m_play_anim_id = 0;
	int m_play_anim_image = 0;
	int m_will_play_anim_id = 0;
	int m_play_anim_count = 0;
	CImage* m_anim_image_p[ANIMATION_IMAGE_MAX];

	//表示位置調整関連
	CVector2D m_draw_adj;

	CVector2D m_shadow_pos_adj = CVector2D(0,0);

	//フラグ関連
	bool m_is_landing = false;


	//近くに存在するエネミーオブジェクト
	//CCharacterEnemy* m_near_enemy_p;
	
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


	//影の位置が変わりすぎると当たり判定との差異が起こるので注意すること(X軸にずらすとかその程度にする)
	void SetShadowPosAdj(CVector2D _pos) { m_shadow_pos_adj = _pos; };

	void SetDrawAdjPos(CVector2D _adj_pos) { m_draw_adj = _adj_pos; };
	CVector2D GetDrawAdjPos() { return m_draw_adj; };

	void MoveLimit();
};


/*
2019/03/06 クラス定義。基本機能実装。 by shingai
2019/03/11 アニメーションシステム、影表示システム、当たり判定システム実装。 by shingai
*/

