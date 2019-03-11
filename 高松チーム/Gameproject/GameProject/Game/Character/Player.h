#pragma once
#include "CharacterBase.h"
/*
作成　中尾	
　操作　暫定
 十字　	:移動
 zキー	:しゃがみ	（画像が逆さ）
 xキー	:攻撃　　	（画像が横）
 cキー	:ジャンプ
*/
class Player : public CharacterBase {
private:
	CImage m_Shadow;		//
	CVector2D m_pos_old;	//前座標
	float m_Spd;			//移動速度
	int m_State;			// 状態
	int m_Jumpvec;			//ジャンプ値
	float m_Depth;			//描画奥行き
	bool m_Jump_flg;		//ジャンプフラグ
	bool m_Squat_flg;		//しゃがみフラグ
	bool m_Attack_flg;		//攻撃
public:
	Player();
	/*
	@brief 移動制御関数
	*/
	void Move();
	/*
	@brief ジャンプ制御関数
	*/
	void Jump();
	void Attack();
	void Update();
	void Draw();
};