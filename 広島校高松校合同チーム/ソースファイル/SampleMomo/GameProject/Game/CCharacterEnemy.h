#pragma once
#include "CCharacter.h"
#include "../Global.h"



enum {	//アニメーションの種類の番号
	eEnemyAnimIdIdle,
	eEnemyAnimIdMove,
	eEnemyAnimIdAttack,
	eEnemyAnimIdDamage,
	eEnemyAnimIdMax,
};

enum {	//アニメーションの画像を入れる番号
	eEnemyAnimIdle1,
	eEnemyAnimIdle2,
	eEnemyAnimIdle3,
	eEnemyAnimIdle4,
	eEnemyAnimMove1,
	eEnemyAnimMove2,
	eEnemyAnimMove3,
	eEnemyAnimMove4,
	eEnemyAnimMove5,
	eEnemyAnimMove6,
	eEnemyAnimMove7,
	eEnemyAnimMove8,
	eEnemyAnimAttack1,
	eEnemyAnimAttack2,
	eEnemyAnimDamage1,
	eEnemyAnimMax,
};


class CCharacterEnemy : public CCharacter {
private:
	enum {	//エネミーの状態
		eEnemyStateIdle,	//待機状態
		eEnemyStateMove,	//移動状態
		eEnemyStateAttack,	//攻撃状態
		eEnemyStateDamage	//ダメージ状態
	};
	enum {  //エネミーのタイプ
		eEnemyTypeSpear,	//槍
		eEnemyTypeAxe,		//斧
		eEnemyTypeGun		//銃
	};
	int m_enemy_type;        //エネミーのタイプです
	int m_enemy_state;       //エネミーの状態
	int m_old_enemy_state;   //エネミーがダメージを受けた時に記憶する直前の状態
	int m_AI_cnt;            //状態が変化するまでのカウント
	bool m_is_damage;        //エネミーがダメージを受けていいかどうかのフラグ
	int m_damage_chance;     //プレイヤーの攻撃を当てられた回数
	bool m_attack_chance;    //エネミーの攻撃が当たる距離かのフラグ
	CVector2D m_attack_pos;      //適正射程距離
	CVector3D m_player_pos;		 //プレイヤーの座標を記憶
	CVector2D m_player_vec;      //プレイヤー方向へのベクトル

	bool is_attack;          //エネミーの攻撃を当てたかどうかのフラグ

public:
	CCharacterEnemy();
	~CCharacterEnemy();
	void CharacterUpdate();
	void CharacterDraw();
	void ReceiveAttack();
	void CharacterOutHitPoint();

	void LoadAnimImage();
	void Idle();         //待機状態の関数
	void Move();		 //移動状態の関数
	void Attack();		 //攻撃状態の関数
	void Damage();		 //ダメージ状態の関数
	void MovePos();		 //移動処理

	void AiChange(int ai_cnt);				//状態を変更する時の関数
	void CharacterBeforeCollisionCheck();	//プレイヤーとの位置関係を調べる関数
};
/*
2019/03/11 クラス定義。 by 堀川
*/