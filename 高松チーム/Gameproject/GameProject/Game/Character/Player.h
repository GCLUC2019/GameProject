#pragma once
#include "CharacterBase.h"
/*
作成　中尾	
　操作　暫定
 十字　		:移動
 SHIFTキー	:しゃがみ	
 Zキー		:近距離攻撃　　	
 SPACEキー	:ジャンプ
 Xキー		:遠距離攻撃
 Qキー		:必殺攻撃
*/
class Player : public CharacterBase {
private:

	int m_HP;				//体力
	int m_special;			//必殺用変数（勾玉のやつ）

	CImage m_shadow;		//
	CVector2D m_pos_old;	//前座標
	float m_speed;			//移動速度
	int m_state;			// 状態
	int m_state_old;		// 前状態
	int m_jump_vec;			//ジャンプ値
	float m_depth;			//描画奥行き


	//フラグ
	bool m_flip;			//反転フラグ
	bool m_damage_flg;		//ダメージフラグ
	bool m_jump_flg;		//ジャンプフラグ
	bool m_squat_flg;		//しゃがみフラグ
	bool m_attack_flg;		//攻撃フラグ
	bool m_special_flg;		//必殺攻撃フラグ

	
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
	/*
	@brief ダメージ状態制御関数（無敵とか死亡への移行とか）
	*/
	void DamageState();
public:
	/*
	@brief 　			ダメージ関数
	@param _damage	[in]与えるダメージ 
	*/
	void Damage(int _damage);
	Player();
	void Update();
	void Draw();
	int GetHP() {
		return m_HP;
	}
};