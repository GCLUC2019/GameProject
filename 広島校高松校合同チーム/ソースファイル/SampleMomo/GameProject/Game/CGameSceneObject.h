#pragma once
#include "CObject.h"

/*
ゲームシーン(ゲームのメインとなるゲームシーン)で使われるオブジェクトのベース。
キャラクタークラスなどに派生する。
アニメーション再生機能もほしいな……。
*/

#define ANIMATION_INFO_MAX (100)
#define ANIMATION_IMAGE_MAX (500)

#define DEFAULT_BLIND_DELAY (5)
#define DEFAULT_BLIND_ALPHA (0.75f)

struct AnimInfo {
	int image_id;
	int image_num = 0;
	int delay;
};

class CGameSceneObject : public CObject {
private:
protected:
	//影表示関連
	CVector2D m_shadow_size;
	CImage * m_shadow_p = nullptr;
	bool m_is_show_shadow = false;

	//表示位置調整関連
	CVector2D m_draw_adj;

	CVector2D m_shadow_pos_adj = CVector2D(0, 0);

	//フラグ関連
	bool m_is_landing = false;
	bool m_is_landing_old = false;
	//CImage * m_static_image_p = nullptr;

	//アニメーション関連(アニメーションクラスに分離したほうがよいかも)
	AnimInfo m_anim_info[ANIMATION_INFO_MAX];
	int m_play_anim_id = 0;
	int m_play_anim_image = 0;
	int m_will_play_anim_id = 0;
	int m_play_anim_count = 0;
	CImage* m_anim_image_p[ANIMATION_IMAGE_MAX];

	bool m_is_blind_draw = false;
	bool m_is_blind_now = false;
	int m_blind_delay = DEFAULT_BLIND_DELAY;
	int m_blind_delay_count = 0;
	float m_blind_alpha = DEFAULT_BLIND_ALPHA;


public:
	CGameSceneObject(int _task_id = 0, int _draw_priority = 0);
	virtual ~CGameSceneObject();

	void Update();
	virtual void GameSceneObjectUpdate();

	void AfterUpdate();
	virtual void GameSceneObjectAfterUpdate();

	void Gravity();

	void BeforeCollisionCheck();
	virtual void GameSceneObjectBeforeCollisionCheck();

	void BeforeUpdate();
	virtual void GameSceneObjectBeforeUpdate();

	void Draw();
	
	void DrawShadow();

	void DrawAnimImage();

	virtual void GameSceneObjectDraw();

	void CollisionCheck(Task* _collision_task);
	virtual void  GameSceneObjectCollisionCheck(Task* _collision_task);

	void SetIsShowShadow(bool _is) { m_is_show_shadow = _is; };
	void SetShadowSize(CVector2D _size) { m_shadow_size = _size; };

	//影の位置が変わりすぎると当たり判定との差異が起こるので注意すること(X軸にずらすとかその程度にする)
	void SetShadowPosAdj(CVector2D _pos) { m_shadow_pos_adj = _pos; };

	void SetDrawAdjPos(CVector2D _adj_pos) { m_draw_adj = _adj_pos; };
	CVector2D GetDrawAdjPos() { return m_draw_adj; };

	void MoveLimit();

	void SetIsBlindDraw(bool _is,int _delay = DEFAULT_BLIND_DELAY,double _blind_alpha = DEFAULT_BLIND_ALPHA) { 
		m_is_blind_draw = _is;
		m_blind_delay = _delay;
		m_blind_delay_count = 0;
		m_blind_alpha = _blind_alpha;
	};

	//アニメーション再生関連
	void SetWillPlayAnim(int _anim_id) { m_will_play_anim_id = _anim_id; };
	void SetAnim(int _anim_id);
	void PlayAnim();
};


/*
2019/03/13 クラス定義。基本機能実装。キャラクタークラスから機能分離  by shingai
*/

