#include "CCharacter.h"
#include "CCharacterPlayer.h"
#include "../Global.h"

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

//速度
#define DEF_SPEED 1.5
#define RUN_SPEED 4.5

//攻撃範囲
#define ATTACK1_RANGE_X 1.5
#define RUN_SPEED 4.5


//ボスのアニメーションの種類番号
enum {
	eEnemyAnimBossIdIdle = 0,
	eEnemyAnimBossIdRun,
	eEnemyAnimBossIdWalk,
	eEnemyAnimBossIdBark,
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
	};

	boss_mode_counts s_boss_mode;

	CCharacterPlayer* m_player_p;

	int m_boss_state = eEnemyBossStateIdle;
	int m_befor_state = m_boss_state;
	int m_just_dist = DEF_JUST_DIST;
	bool m_is_attack = true;
	bool m_is_hit = false;
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
	//vecの加算
	void Move();
	void MoveLimit();
	//距離の精査
	void CheckDist();

	void CharacterBeforeCollisionCheck();
};


