#pragma once
#include "CStoryScene.h"
#include "CCharacter.h"
#include "CCharacterPlayer.h"
#include "CCharacterEnemy.h"

class CCharacterTutorialEnemy;

enum {
	eLessonMoveLeft,
	eLessonMoveLeftClear,
	eLessonMoveRight,
	eLessonMoveRightClear,
	eLessonMoveUp,
	eLessonMoveUpClear ,
	eLessonMoveDown,
	eLessonMoveDownClear,
	eLessonMoveJump,
	eLessonMoveJumpClear,
	eLessonAttack,
	eLessonAttackClear,
	eLessonComboAttack,
	eLessonComboAttackClear,
	eLessonVerticalAttack,
	eLessonVerticalAttackClear,
	eLessonSideAttack,
	eLessonSideAttackClear,
	eLessonJumpAttack,
	eLessonJumpAttackClear,
	eLessonEvasion,
	eLessonEvasionClear,
	eLessonDash,
	eLessonDashClear,
	eLessonTakeWeapon,
	eLessonTakeWeaponClear,
	eLessonWeaponAttack,
	eLessonWeaponAttackClear,
	eLessonWeaponDestroy,
	eLessonWeaponDestroyClear,
	eLessonTakeKibidango,
	eLessonTakeKibidangoClear,
	eLessonTutorialEnd,
	eLessonEnd
};


class CTutorial : public CStoryScene {
private:
	int m_lesson_num;
	bool m_clear_flag[5];
	bool m_lesson_clear_flag;
	bool m_enemy_damage;
	CCharacterPlayer* m_target_p = nullptr;//ターゲット 単純な話キャラならばいいので同士討ちも設定次第では可能か
	CCharacterTutorialEnemy* m_enemy_p = nullptr;

	CImage* m_skip_tutorial_p = nullptr;

	double m_wait_time_count = 0.0;

	double m_setting_wait_time;

	int m_lesson_flag_count = 0;

	bool m_is_reset_pos = false;
public:
	CTutorial();
	~CTutorial();

	void Update();
	void Draw();
	void AddRAll();
	void Setchar();
	void SetValue();


	void BeforeUpdate();

	void ResetPos();
	void LessonSuccess();

	void LessonMoveLeft();
	void LessonMoveRight();
	void LessonMoveUp();
	void LessonMoveDown();
	void LessonMoveJump();
	void LessonEvasion();

	void LessonAttack();
	void LessonComboAttack();

	void LessonVerticalAttack();

	void LessonSideAttack();

	void LessonJumpAttack();

	void LessonDash();

	void LessonTakeWeapon();

	void LessonWeaponAttack();

	void LessonWeaponDestroy();

	void LessonTakeKibidango();

	void LessonTutorialEnd();

	//void Lesson1();
	void Lesson2();
	void Lesson3();
	void Lesson4();
	void LessonClear();

	void InputSkipTutorial();

	void EnemyDamage() {
		m_enemy_damage = true;
	}

	static CTutorial* GetInstance(); 

	void UpdateTutorialText(int word, int limit);
};



//チュートリアルエネミー

class CCharacterTutorialEnemy : public CCharacter {
public:
	static bool tutorial_flag;
private:
	CCharacter* m_target_p = nullptr;//ターゲット 単純な話キャラならばいいので同士討ちも設定次第では可能か

	bool m_is_moving = false;

	//HPバー
	CBar* m_hit_point_bar_p = nullptr;
	CImage * m_hp_frame_image_p = nullptr;

	CVector3D m_attack_length;

	double m_attack_power = 0.0;
	double m_attacking_count = 0;
	double m_attack_frame = 0;
	double m_attacking_hit_start_frame = 0.0;
	double m_attacking_hit_end_frame = 0.0;


	bool m_is_range = false;

	bool m_is_attacking = false;

	bool m_is_hit_attack = false;

	bool m_is_receive_damage_now = false;
	double m_receive_damage_frame;
	double m_receive_damage_count;

	enum {	//エネミーの状態
		eEnemyStateIdle,	//待機状態
		eEnemyStateMove,	//移動状態
		eEnemyStateAttack,	//攻撃状態
		eEnemyStateDamage	//ダメージ状態
	};

		int m_enemy_state;       //エネミーの状態
		int m_old_enemy_state;   //エネミーがダメージを受けた時に記憶する直前の状態
		double m_AI_cnt;            //状態が変化するまでのカウント
		int m_damage_chance;     //プレイヤーの攻撃を当てられた回数
		bool m_attack_chance;    //エネミーの攻撃が当たる距離かのフラグ
		CVector3D m_player_pos;		 //プレイヤーの座標を記憶
		CVector2D m_player_vec;      //プレイヤー方向へのベクトル
		bool is_attack;          //エネミーが攻撃しようとするかどうかのフラグ

public:
	CCharacterTutorialEnemy(CVector3D _enemy_pos);
	~CCharacterTutorialEnemy();

	void LoadAnimImage();
	void CharacterBeforeUpdate();
	void CharacterUpdate();
	void CharacterBeforeCollisionCheck();
	void CollisionCheckCharacter(Task* _collision_task);
	void CharacterDraw();
	void CharacterOutHitPoint();
	void ReceiveAttack();

	void ReceiveDamageNow();

	void ReceiveKnockBack(CVector3D _from_pos, double _power);

	void EnemyMoving();
	void EnemyAttack();
	void EnemyIdle();         //待機状態の関数
	void AiChange(int ai_cnt);				//状態を変更する時の関数

	void DropItem();

	void AdjAnim();

	void CheckTutorial() {
		if (CCharacterTutorialEnemy::tutorial_flag == false) SetIsDelete();
	}
};

