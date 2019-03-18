#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
担当
番條　Boss.cppp,h
*/


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////お頭クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossHead :public EnemyBase {
private:
	enum Head{
		eIdle,
		eUp,
		eFireAttackDown,
		eHeadAttackDown,
		eFireAttack,
		eHeadAttack,
	};
	CImage m_img2;//攻撃時
	CAnimImage m_img3;//ボスの待機状態のアニメーション
	CImage m_img4;//影
	
	CVector2D m_pos2;
	CVector2D m_player_pos; //プレイヤーの座標を格納する
	CVector2D m_shadow_pos;//影の座標

	CRect m_rect2;//待機時の矩形

	bool m_anim_flag;//アニメーションフラグ
	bool m_move_flag;//移動フラグ
	bool m_draw_flag;
	bool m_idle_flag;
	bool m_approach_flag; //助走フラグ
	bool m_shadow_flag;//影を出すか消すか

	int m_state;
	int m_anim_cnt;//アニメーションカウント
	int m_idle_cnt;//待機状態でいる時間
	int m_boss_hp;
	int m_shadow_size;


protected:


public:
	BossHead(const CVector2D &player_pos,const int state);

	~BossHead();

	void Idle();

	void FireAttack();

	void HeadAttack();

	void UpMove();

	void FireDownMove();

	void HeadDownMove();

	void Update();

	void Draw();

	friend class BossManager;
};

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////お手クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossHand :public EnemyBase {
private:
	enum Hand{
		eIdle,
		eUp,
		eDownAttack,
		eDownHandAttack,
		eLazerAttack,
		eHandAttack,

	};

	CImage m_img2;//右手玉があるほう
	CImage m_img3;//左手
	CImage m_img4;//攻撃時の左手

	CVector2D m_pos2;//右手の座標
	CVector2D m_pos3;//左手の座標
	CVector2D m_player_pos; //プレイヤーの座標を格納する

	CVector2D m_center;
	CVector2D m_center2;

	int m_cnt;//エフェクト用に使ってます
	int m_state;
	int m_idle_cnt;//待機状態でいる時間
	
	float m_ang;
	float m_rot;//円周率
	float m_rot2;//円周率
	float m_r;  //半径

	bool m_anim_flag;//アニメーションフラグ
	bool m_move_flag;//移動フラグ
	bool m_idle_flag;
	bool m_draw_flag;
	bool m_attack_flag;
	bool m_hand_flag;//下に下がるときのやつ
	bool m_slash_flag;//攻撃時

protected:


public:

	BossHand(const CVector2D &player_pos, const int state);

	~BossHand();

	void Idle();

	void Attack();

	void HandAttack();

	void UpMove();

	void DownMove();

	void DownHandAttack();

	void Update();

	void Draw();
	friend class BossManager;
};


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////尻尾クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossTail :public EnemyBase{
private:
	enum  Tail{
		eIdle,
		eUp,
		eDown,
		eTailAttack,
	};

	CAnimImage m_img2;//ボスの攻撃するときの画像
	CImage m_img3;//ボスの攻撃するまでの画像

	CVector2D m_pos2;//攻撃するときのざひょう

	CVector2D m_player_pos; //攻撃するときに使うプレイヤーの座標を格納する

	int m_state;
	int m_idle_cnt;//待機状態でいる時間
	int m_anim_cnt;

	bool m_draw_flag;
	bool m_idle_flag;
	bool m_anim_flag;

public:

	BossTail(const CVector2D &player_pos, const int state);

	~BossTail();

	void Update();

	void Idle();

	void TailAttack();

	void UpMove();

	void DownMove();

	void HitCheck(Task*_t);

	void Draw();
	friend class BossManager;
};

