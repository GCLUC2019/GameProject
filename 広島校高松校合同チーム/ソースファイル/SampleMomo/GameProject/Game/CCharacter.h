#pragma once
#include "CGameSceneObject.h"

/*
#define ANIMATION_INFO_MAX (100)
#define ANIMATION_IMAGE_MAX (500)
*/


//#define DEFAULT_ANIM_DELAY (10)

#define PLAYER_ANIM_IDLE (8)
#define DEFAULT_ANIM_DELAY (5)
#define PLAYER_ANIM_RUN_DELAY (3)

//#define PLAYER_ANIM_RUN_DELAY (5)

class CGameSceneWave;

#define DEFAULT_HIT_POINT (10.0f)

/*
struct AnimInfo {
	int image_id;
	int image_num = 0;
	int delay;
};
*/

class CCharacter : public CGameSceneObject {
private:
protected:

	float m_hit_point = DEFAULT_HIT_POINT;
	float m_hit_point_max = DEFAULT_HIT_POINT;


	/*
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
	bool m_is_landing_old = false;
	*/

	//無敵状態の可否
	bool m_is_invincible = false;
	

	CGameSceneWave* m_from_wave_p = nullptr;
	int m_wave_character_id = 0;
	
public:
	CCharacter(int _task_id, int _draw_priority);
	
	virtual ~CCharacter();

	void GameSceneObjectUpdate();
	virtual void CharacterUpdate();
	
	void GameSceneObjectAfterUpdate();
	virtual void CharacterAfterUpdate();


	void SetInvincible(bool _is) { m_is_invincible = _is; };
	bool GetInvincible() { return m_is_invincible; };


	//HPが尽きた時に呼ばれる
	virtual void CharacterOutHitPoint();
	
	/*
	void SetWillPlayAnim(int _anim_id) { m_will_play_anim_id = _anim_id; };
	void SetAnim(int _anim_id);
	void PlayAnim();

	void Gravity();
	*/

	void GameSceneObjectBeforeCollisionCheck();
	virtual void CharacterBeforeCollisionCheck();

	void GameSceneObjectBeforeUpdate();
	virtual void CharacterBeforeUpdate();

	float* GetHitPointPointer() { return &m_hit_point; };
	float GetHitPointMax() { return m_hit_point_max; };

	void HitPointGainValue(double _value);

	virtual void ReceiveAttack();


	void SetFromWave(CGameSceneWave* _wave) { m_from_wave_p = _wave; };
	void SetCharacterWaveId(int _id) { m_wave_character_id = _id; };
	int GetCharacterWaveId() { return m_wave_character_id; };

	void SendDeadMeForFromWave();

	void CheckHitPoint();

	void GameSceneObjectDraw();
	
	/*
	void DrawShadow();
	void DrawAnimImage();
	*/

	virtual void CharacterDraw();
	
	void GameSceneObjectCollisionCheck(Task* _collision_task);
	virtual void CollisionCheckCharacter(Task* _collision_task);

	/*
	void SetIsShowShadow(bool _is) { m_is_show_shadow = _is; };
	void SetShadowSize(CVector2D _size) { m_shadow_size = _size; };
	

	//影の位置が変わりすぎると当たり判定との差異が起こるので注意すること(X軸にずらすとかその程度にする)
	void SetShadowPosAdj(CVector2D _pos) { m_shadow_pos_adj = _pos; };

	void SetDrawAdjPos(CVector2D _adj_pos) { m_draw_adj = _adj_pos; };
	CVector2D GetDrawAdjPos() { return m_draw_adj; };


	void MoveLimit();
	*/
};


/*
2019/03/06 クラス定義。基本機能実装。 by shingai
2019/03/11 アニメーションシステム、影表示システム、当たり判定システム実装。 by shingai
～2019/03/17 色々な機能を実装 by shingai
*/

