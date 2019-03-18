#include "CCharacter.h"
#include "CCharacterPlayer.h"
#include "../Global.h"

//ボスの初期表示位置
#define DEF_BOSS_POS CVector3D(1000, -2060, 500);
#define DEF_BOSS_VEC CVector3D(0, 0, 0);
#define DEF_SAHDOW_POS CVector2D(-30.0, -90.0);

//ボスのサイズ
#define BOSS_SIZE CVector2D(500,500)
#define BOSS_SHADOW_SIZE CVector2D(300, 50)

//ボスのHP
#define BOSS_HP 50.0f

//起動誤差
#define RANGE (150)

//攻撃の適正距離の初期値
#define DEF_JUST_DIST 350
#define JUST_DIST_Z 25

//次の適正距離
#define NEXT_JUST_DIST1 400
#define NEXT_JUST_DIST2 100

//プレイヤーとの距離
#define PLAYER_DIST＿FAR 600
#define AWAY_DIST 500

//各状態の限界時間
#define IDLE_LIMIT 120
#define WALK_LIMIT 180
#define RUN_LIMIT  75
#define AWAY_LIMIT  75

//速度
#define DEF_SPEED 1.5
#define RUN_SPEED 4.5

//攻撃範囲
#define ATTACK1_RANGE_BITE 400
#define ATTACK1_RANGE_BARK 500

//攻撃時間
#define BITE_TIME 30.0
#define BARK_TIME 50.0

//跳躍力
#define JUMP_POWER 40
#define JUMP_POWER_X 10

//減速係数
#define FLICTION 0.7

//最大速度
#define MAX_SPEED 8.0f

//ボスのアニメーションの種類番号
enum {
	eEnemyAnimBossIdIdle = 0,
	eEnemyAnimBossIdRun,
	eEnemyAnimBossIdWalk,
	eEnemyAnimBossIdJump,
	eEnemyAnimBossIdBark,
	eEnemyAnimBossIdBite,
	eEnmeyAnimBossIdMax,
};

//ボスの画像を入れる番号
enum {
	eEnemyAnimBossIdle1=0,
	eEnemyAnimBossIdle2,
	eEnemyAnimBossRun1,
	eEnemyAnimBossRun2,
	eEnemyAnimBossRun3,
	eEnemyAnimBossRun4,
	eEnemyAnimBossRun5,
	eEnemyAnimBossRun6,
	eEnemyAnimBossRun7,
	eEnemyAnimBossRun8,
	eEnmeyAnimBossMax,
};

class CCharacterBoss :public CCharacter
{
private:
	enum {
		eEnemyBossStateIdle=0,
		eEnemyBossStateWalk,
		eEnemyBossStateRun,
		eEnemyBossStateAttack,
		eEnemyBossStateAway,
	};

	struct boss_mode_counts {
		double boss_idle = 0.0;
		double boss_walk = 0.0;
		double boss_run = 0.0;
		double boss_attack = 0.0;
		double boss_away = 0.0;
	};

	boss_mode_counts s_boss_mode;

	CCharacterPlayer* m_player_p;

	double m_attack_complete = 0.0;

	int m_boss_state = eEnemyBossStateIdle;
	int m_befor_state = m_boss_state;
	int m_just_dist = DEF_JUST_DIST;
	bool m_is_attack = true;
	bool m_is_hit = false;
	bool m_away_flg = false;
	CVector3D m_player_pos = CVector3D(0, 0, 0);
public:
	CCharacterBoss();
	~CCharacterBoss();
	void CharacterUpdate();
	void CharacterDraw();

	void LoadAnimImage();
	void ChangeFlip();
	//エネミーの状態をカウントする関数
	void ModeCount();
	//エネミーの移動距離を変更
	void ChangeDist();
	//エネミーの状態を変更
	void ChangeState();
	void ChengeStateIdleOrAway();
	void ChangeAttackState(int _state, int attack_time);
	//以下、エネミーの行動状態
	//移動系
	void Idle();
	void Run();
	void Walk();
	void Away();
	void CloseToPlayer();
	//攻撃系
	void Attack1();
	void Attack2();
	void AttackHub();
	//移動の限界値
	void MoveLimit();
	//距離の精査
	void CheckDist();
	float CheckAttackRange();

	//被ダメージ処理
	void ReceiveAttack();

	//初期化
	void DefalutSet();

	void CharacterBeforeCollisionCheck();
};


