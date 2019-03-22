#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"


/*
担当
番條　Boss.cppp,h
*/


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////頭クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossHead :public EnemyBase {
private:
	enum Head {
		eIdle,
		eUp,
		eFireAttackDown,
		eHeadAttackDown,
		eFireAttack,
		eHeadAttack,
		eDeath,
	};
	CImage m_shadow;//影

	CVector2D m_player_pos; //プレイヤーの座標を格納する

	CRect m_rect2;//待機時の矩形

	bool m_anim_flag;//アニメーションフラグ
	bool m_draw_flag;
	bool m_approach_flag; //助走フラグ
	bool m_shadow_flag;//影を出すか消すか

	int m_state;
	int m_anim_cnt;//アニメーションカウント
	int m_idle_cnt;//待機状態でいる時間
	int m_shadow_size;

	float m_shadow_y;//影のy座標
	float m_shadow_x;

	float m_hp;




protected:


public:
	BossHead(const CVector2D &player_pos, const int state);

	~BossHead();

	void Idle();

	void FireAttack();

	void HeadAttack();

	void UpMove();

	void HitCheck();

	void FireDownMove();

	void HeadDownMove();

	void Update();

	void Draw();

	

	friend class BossManager;
};

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////手クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossRightHand :public EnemyBase {
private:
	enum RightHand {
		eIdle,
		eUp,
		eDownAttack,
		eLazerAttack,

	};
	CImage m_shadow;//影

	CVector2D m_player_pos; //プレイヤーの座標を格納する

	CVector2D m_center;
	//CVector2D m_center2;

	int m_cnt;//エフェクト用に使ってます
	int m_state;
	int m_idle_cnt;//待機状態でいる時間

	float m_ang;
	float m_rot;//円周率
	float m_rot2;//円周率
	float m_r;  //半径

	int m_shadow_size;
	float m_shadow_y;//影のy座標
	float m_shadow_x;

	bool m_anim_flag;//アニメーションフラグ
	bool m_move_flag;//移動フラグ
	bool m_idle_flag;

protected:


public:

	BossRightHand(const CVector2D &player_pos, const int state);

	~BossRightHand();

	void Idle();

	void Attack();

	void UpMove();

	void DownMove();

	void Update();

	void Draw();
	friend class BossManager;
};

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////手クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossLeftHand :public EnemyBase {
private:
	enum LeftHand {
		eIdle,
		eUp,
		eDownAttack,
		eHandAttack,

	};
	CImage m_shadow;//影

	CVector2D m_center;
	CVector2D m_player_pos; //プレイヤーの座標を格納する


	int m_cnt;//エフェクト用に使ってます
	int m_state;
	int m_idle_cnt;//待機状態でいる時間

	float m_ang;
	float m_rot;//円周率
	float m_rot2;//円周率
	float m_r;  //半径
	int m_shadow_size;
	float m_shadow_y;//影のy座標
	float m_shadow_x;

	bool m_slash_flag;//攻撃時

public:
	BossLeftHand(const CVector2D &player_pos, const int state);

	~BossLeftHand();

	void Idle();

	void Attack();

	void UpMove();

	void DownMove();

	void Update();

	void Draw();
	friend class BossManager;
};

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////尻尾クラス/////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class BossTail :public EnemyBase {
private:
	enum  Tail {
		eIdle,
		eUp,
		eDown,
		eTailAttack,
	};
	CVector2D m_player_pos; //攻撃するときに使うプレイヤーの座標を格納する
	CImage m_shadow;//影

	int m_state;
	int m_anim_cnt;
	int m_shadow_size;

	bool m_attack_flag;
	bool m_idle_flag;

	float m_shadow_y;//影のy座標
	float m_shadow_x;

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

class BossDeath :public EnemyBase {
private:
	
	CImage m_img; //やられたときの画像
	CAnimImage m_img2;//やられたときエフェクト
	CAnimImage m_img3;//やられたときエフェクト　その２

	CVector2D m_pos; //やられたときの座標
	CVector2D m_player_pos;//プレイヤーの座標を取得して格納
	CVector2D m_pos2;//えふぇくと座標
	CVector2D m_pos3;//エフェクト座標　その２
	CVector2D m_rect_pos;//矩形移動のぽす

	int m_state;//ボスの状態
	int m_boss_attack_type;//ボスの攻撃する種類を番号で振り分ける
	int m_boss_hp;//ボスの体力
	int m_idle_cnt;//待機状態でいる時間
	int m_cnt;

	bool m_idle_flag;

public:

	BossDeath();

	~BossDeath();

	void Update();

	void Draw();
	friend class BossManager;


};

