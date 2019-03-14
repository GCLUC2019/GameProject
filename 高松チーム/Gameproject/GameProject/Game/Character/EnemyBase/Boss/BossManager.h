#pragma once
#include "../GameProject/Base/Task.h"


/*
   作成者　番條
   マネージャーで待機状態を管理する
*/
class BossManager : public Task {
private:
	enum {
		eIdle,
		eUp,
		eAttackDown,
		eAttackDown2,
		eDeath,
		eNothing,
	};

	CAnimImage m_img; //頭

	CVector2D m_pos; //頭の座標
	CVector2D m_player_pos;//プレイヤーの座標を取得して格納

	int m_state;//ボスの状態
	int m_boss_attack_type;//ボスの攻撃する種類を番号で振り分ける
	int m_boss_hp;//ボスの体力
	int m_idle_cnt;//待機状態でいる時間

	bool m_death_flag;

public:

	BossManager();

	void Nothing();

	void Idle();

	void Attack();

	void Death();

	void Update();

	void Draw();
};
