#pragma once
#include "../GameProject/Base/Task.h"

class BossManager : public Task {
private:
	enum {
		eNothing,
		eIdle,
		eAttack,
		eDeath,
	};

	CAnimImage m_img; //頭
	CImage m_img2;//右手玉があるほう
	CImage m_img3;//左手
	CAnimImage m_img4;//尻尾

	CImage m_img5;//やられたときの画像

	CVector2D m_pos; //頭の座標
	CVector2D m_pos2;//右手の座標
	CVector2D m_pos3;//左手の座標
	CVector2D m_pos4;//尻尾の座標
	CVector2D m_pos5;//尻尾の座標
	CVector2D m_center;
	CVector2D m_center2;

	int m_state;//ボスの状態
	int m_boss_hp;//ボスの体力

	float m_rot;//円周率
	float m_rot2;//円周率
	float m_r;  //半径

	bool m_idle_flag;
	bool m_attack_flag;
	bool m_death_flag;

public:

	BossManager();

	void Idle();

	void Attack();

	void Death();

	void Update();

	void Draw();
};
