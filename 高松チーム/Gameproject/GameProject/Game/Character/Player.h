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
	CImage m_shadow;		//

	CVector2D m_pos_old;	//前座標
	float m_speed;			//移動速度
	int m_state;			// 状態
	int m_state_old;		// 前状態
	int m_jump_vec;			//ジャンプ値
	float m_depth;			//描画奥行き
	bool m_flip;			//反転フラグ
	bool m_jump_flg;		//ジャンプフラグ
	bool m_squat_flg;		//しゃがみフラグ
	bool m_attack_flg;		//攻撃フラグ
	bool m_special_flg;		//必殺攻撃フラグ
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
	/*
	@brief 攻撃制御関数
	*/
	void Attack();
	/*
	@brief 必殺攻撃関数
	*/
	void Special();
	/*
	@brief アニメーション設定関数
	*/
	void SetAnim();


	void Update();
	void Draw();
};