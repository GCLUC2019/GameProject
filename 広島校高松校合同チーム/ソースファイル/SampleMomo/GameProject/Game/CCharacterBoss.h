#include "CCharacter.h"
#include "CCharacterPlayer.h"
#include "../Global.h"

//�{�X�̏����\���ʒu
#define DEF_BOSS_POS CVector3D(1000, -2060, 500);
#define DEF_BOSS_VEC CVector3D(0, 0, 0);
#define DEF_SAHDOW_POS CVector2D(-30.0, -90.0);

//�{�X�̃T�C�Y
#define BOSS_SIZE CVector2D(500,500)
#define BOSS_SHADOW_SIZE CVector2D(300, 50)

//�{�X��HP
#define BOSS_HP 50.0f

//�N���덷
#define RANGE (150)

//�U���̓K�������̏����l
#define DEF_JUST_DIST 350
#define JUST_DIST_Z 25

//���̓K������
#define NEXT_JUST_DIST1 400
#define NEXT_JUST_DIST2 100

//�v���C���[�Ƃ̋���
#define PLAYER_DIST�QFAR 600
#define AWAY_DIST 500

//�e��Ԃ̌��E����
#define IDLE_LIMIT 120
#define WALK_LIMIT 180
#define RUN_LIMIT  75
#define AWAY_LIMIT  75

//���x
#define DEF_SPEED 1.5
#define RUN_SPEED 4.5

//�U���͈�
#define ATTACK1_RANGE_BITE 400
#define ATTACK1_RANGE_BARK 500

//�U������
#define BITE_TIME 30.0
#define BARK_TIME 50.0

//������
#define JUMP_POWER 40
#define JUMP_POWER_X 10

//�����W��
#define FLICTION 0.7

//�ő呬�x
#define MAX_SPEED 8.0f

//�{�X�̃A�j���[�V�����̎�ޔԍ�
enum {
	eEnemyAnimBossIdIdle = 0,
	eEnemyAnimBossIdRun,
	eEnemyAnimBossIdWalk,
	eEnemyAnimBossIdJump,
	eEnemyAnimBossIdBark,
	eEnemyAnimBossIdBite,
	eEnmeyAnimBossIdMax,
};

//�{�X�̉摜������ԍ�
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
	//�G�l�~�[�̏�Ԃ��J�E���g����֐�
	void ModeCount();
	//�G�l�~�[�̈ړ�������ύX
	void ChangeDist();
	//�G�l�~�[�̏�Ԃ�ύX
	void ChangeState();
	void ChengeStateIdleOrAway();
	void ChangeAttackState(int _state, int attack_time);
	//�ȉ��A�G�l�~�[�̍s�����
	//�ړ��n
	void Idle();
	void Run();
	void Walk();
	void Away();
	void CloseToPlayer();
	//�U���n
	void Attack1();
	void Attack2();
	void AttackHub();
	//�ړ��̌��E�l
	void MoveLimit();
	//�����̐���
	void CheckDist();
	float CheckAttackRange();

	//��_���[�W����
	void ReceiveAttack();

	//������
	void DefalutSet();

	void CharacterBeforeCollisionCheck();
};


