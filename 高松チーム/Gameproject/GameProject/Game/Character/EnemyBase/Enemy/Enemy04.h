#pragma once
/*
	担当		
	中尾	Enemy04
*/

#include"../EnemyBase.h"
class Enemy04 : public EnemyBase {
private:
	enum Enemy04State {
		eMove,
		eSearch,
		eAttack,
		eDamage,
	};
	CVector2D m_dir;
	float m_hight;//高さ
	bool m_search_flg;//プレイヤーを見つけたかどうかのフラグ

	int cnt;
	void Update();
	void Draw();
	void Move();//プレイヤー発見時の動き
	void Search();//探索中の動き
	void Attack();//攻撃
	void Damage();//ダメージ
	void MoveControl();
public:
	Enemy04();
	Enemy04(CVector2D _pos);

};