#pragma once
/*　担当
	国見　class Enemy05
*/
#include "../EnemyBase.h"

class Enemy05 : public EnemyBase {
private:
	enum {
		eMove,
		eSearch,
		eAttack,
		eDamage,
	};
private:
	int m_move_cnt;	//仮攻撃カウント変数
public:
	Enemy05();
	void Move();
	/*
	@brief　移動管理
	@param　_type	[in]　移動タイプ
	*/
	void MoveManagement(int _type);
	void Attack();
	void Damage();
	void Update();
	void Draw();
	void HitCheck(Task* _t);
	
};