#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

class EnemyBase : public Task {
private:
protected:

	CRect m_rect;			//敵矩形
	CVector2D m_pos;		//敵位置
	CVector2D m_shadow_pos;	//影位置
	CVector2D m_vec;		//敵ベクトル
	CAnimImage m_img;		//敵画像
	CImage m_shadow;		//影
	CVector2D m_pos_old;	//敵前位置
	int m_hp;				//敵体力
	int m_state;			//敵状態
	float m_ang;			//敵方向
	float m_depth;			//奥行き
	bool m_flip;			//反転フラグ
	
public:
	EnemyBase(int _type);
	virtual void Move();
	virtual void Attack();
	virtual void Damage();
	virtual void Update();
	virtual void Draw();
	virtual void HitCheck(Task* _t);
	static bool CollisionCheckRect(EnemyBase* b1, EnemyBase* b2);
	static bool CollitionCheckflip(int fliptype, EnemyBase* b1, EnemyBase*b2);
	/*
	@drief オブジェクトの画面移動を制限する
	*/
	virtual void MoveControl();
	virtual int GetType() { return m_type; }
	virtual CVector2D GetPos() {
		return  m_pos;
	}
	CRect GetRect() {
		return m_rect;
	}
		
};