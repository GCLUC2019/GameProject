#pragma once
#include "../GameProject/Base/Task.h"


/*
   作成者　番條
   マネージャーで待機状態を管理する
*/
class BossManager : public Task {
private:
	enum Manager{
		eIdle,
		eAttackDown = 2,
		eAttackDown2,
		eDeath,
		eNothing,
		eUp,
	};

	CImage m_img; //やられたときの画像
	CImage m_img2;
	CVector2D m_pos; //やられたときの座標
	CVector2D m_player_pos;//プレイヤーの座標を取得して格納
	CVector2D m_pos2;

	int m_state;//ボスの状態
	int m_boss_attack_type;//ボスの攻撃する種類を番号で振り分ける
	int m_boss_hp;//ボスの体力
	int m_idle_cnt;//待機状態でいる時間
	int m_cnt;

	bool m_death_flag;
	bool m_idle_flag;

public:

	BossManager();

	~BossManager();

	void Nothing();

	void Idle();

	void Attack();

	void Death();

	void Update();

	void Draw();

	friend class BossHand;
};
