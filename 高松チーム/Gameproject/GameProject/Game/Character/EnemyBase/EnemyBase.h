#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

/*
ここでCharacterType設定する
*/
enum {
	eEnemy01,
	eEnemy02,
	eEnemy03,
	eEnemy04,
	eEnemy05,
	eBossHead,
};

class EnemyBase : public Task {
private:
protected:
	
	CVector2D m_pos;	//敵位置
	CVector2D m_vec;	//敵ベクトル
	CAnimImage m_img;	//敵画像
	CVector2D m_pos_old;//敵前位置
	int m_type;			//敵識別子
	int m_e_hp;			//敵体力
	int m_state;		//敵状態
	float m_ang;		//敵方向
	
public:
	EnemyBase(int _type);
	virtual void Move();
	virtual void Attack();
	virtual void Update();
	virtual void Draw();
	/*
	@drief オブジェクトの画面移動を制限する
	*/
	virtual void MoveControl();

};