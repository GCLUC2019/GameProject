#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
担当
番條　Boss.cppp,h
*/
class BossHead :public EnemyBase {
private:

	bool m_anim_flag;//アニメーションフラグ
	bool m_move_flag;//移動フラグ
protected:


public:
	BossHead();

	void Update();

	void Draw();

};


class BossHand :public EnemyBase {
private:

	CVector2D m_center;

	int m_cnt;//エフェクト用に使ってます

	bool m_anim_flag;//アニメーションフラグ
	bool m_move_flag;//移動フラグ

protected:


public:
	BossHand();

	void Update();

	void Draw();

};

