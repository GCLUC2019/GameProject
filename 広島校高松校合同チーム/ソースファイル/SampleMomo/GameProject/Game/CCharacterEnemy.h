#pragma once
#include "CCharacter.h"
#include "../Global.h"



enum {
	eEnemyAnimIdIdle,
	eEnemyAnimIdMove,
	eEnemyAnimIdAttack,
	eEnemyAnimIdDamage,
	eEnemyAnimIdMax,
};

enum {
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
	enum {
		eEnemyStateIdle,
		eEnemyStateMove,
		eEnemyStateAttack,
		eEnemyStateDamage
	};
	int t;   //仮のタイプ
	int m_enemy_state;
	int m_old_enemy_state;   //ダメージを受けた時に記憶する直前の状態
	int m_AI_cnt;            //状態が変化するまでのカウント
	bool m_is_damage;          //ダメージを受けていいかどうかのフラグ
	int m_damage_chance;    //攻撃を当てられた状態
	bool m_attack_chance;    //攻撃が当たる距離かのフラグ
	CVector2D m_attack_pos;         //プレイヤー方向へのベクトル
	CVector3D m_player_pos;		 //プレイヤーの座標を記憶
	CVector2D m_player_vec;         //プレイヤー方向へのベクトル
public:
	CCharacterEnemy();
	~CCharacterEnemy();
	void CharacterUpdate();
	void CharacterDraw();
	void ReceiveAttack();

	void LoadAnimImage();
	void Idle();
	void Move();
	void Attack();
	void Damage();
	void MovePos();

	void AiChange(int ai_cnt);
	void CharacterBeforeCollisionCheck();
};
/*
2019/03/06 クラス定義。 by shingai
2019/03/11 クラス定義。 by 堀川
*/