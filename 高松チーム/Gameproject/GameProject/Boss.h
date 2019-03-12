#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
担当
番條　Boss.cppp,h
*/
class BossHead :public EnemyBase {
private:
	CVector2D m_center;

	float m_rot;//円周率
	float m_r;  //半径

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

	float m_rot;
	float m_r;
protected:


public:
	BossHand();

	void Update();

	void Draw();

};

