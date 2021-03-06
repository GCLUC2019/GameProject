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
enum PlayerState
{
	eIdle,		//待機
	eMove,		//移動
	eJumpUp,	//ジャンプ
	eJumpDown,	//ジャンプ
	eSquat,		//しゃがみ
	eAttack01,	//近距離攻撃
	eAttack02,	//
	eAttack03,	//
	eAttack04,	//遠距離攻撃
	eDamage,	//ダメージ
	eDeath,		//死亡
	eUp,		//起き上がり
	eSpecial,	//必殺
};

class Player : public CharacterBase {
private:

	int m_HP;				//体力
	int m_special;			//必殺用変数（勾玉のやつ）

	CImage m_shadow;		//影
	CVector2D m_pos_old;	//前座標
	float m_speed;			//移動速度
	int m_state;			// 状態
	int m_state_old;		// 前状態
	float m_jump_vec;			//ジャンプ値
	float m_depth;			//描画奥行き
    float m_before_jump_pos;

	//フラグ
	bool m_flip;			//反転フラグ
	bool m_damage_flg;		//ダメージフラグ
	bool m_jump_flg;		//ジャンプフラグ
    bool m_jump2_flg;       //何かに乗っているときのフラグ
	bool m_squat_flg;		//しゃがみフラグ
	bool m_attack_flg;		//攻撃フラグ
	bool m_special_flg;		//必殺攻撃フラグ
	bool m_death_flg;		//死亡フラグ
	
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
	/*
	@brief 死亡状態制御関数（作るなら演出とか）
	*/
	void Death();
public:
	/*
	@brief 　			ダメージ関数
	@param _damage	[in]与えるダメージ 
	*/
	void Damage(int _damage);
	/*
	@brief 　			アイテム取得関数
	@param _damage	[in]アイテムの種類
	*/
	void ItemGet(int _itemTyp);
	void SpecialPuls(int _puls);

	Player();
	void HitCheck(/*Task* _t*/);
	void Update();
	void Draw();
	int GetHP() {
		return m_HP;
	}
	int GetSpecial() {
		return m_special;
	}
};



class SpecialEvent :public Task{
private:
	int m_cnt;

	CImage m_curtain;
	CImage m_hissathu01;
	CImage m_hissathu02;
	CImage m_cutin;

	CVector2D m_cutin_pos;
	CVector2D m_pos;
	CRect m_rect;
public:
	SpecialEvent();
	~SpecialEvent();
	void Update();
	void Draw();
	CVector2D GetPos() {
		return m_pos;
	}
	 CRect GetRect() {
		 return m_rect;
	}
};

