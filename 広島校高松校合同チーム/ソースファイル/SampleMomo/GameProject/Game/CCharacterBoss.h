#include "CCharacter.h"
#include "CCharacterPlayer.h"
#include "../Global.h"

//�{�X�̃A�j���[�V�����̎�ޔԍ�
enum {
	eEnemyAnimBossIdIdle = 0,
	eEnemyAnimBossIdRun,
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
		eEnemyBossStateRun,
	};

	CCharacterPlayer* m_player_p;

	int m_boss_state;
	CVector3D m_player_pos = CVector3D(0, 0, 0);
public:
	CCharacterBoss();
	~CCharacterBoss();
	void CharacterUpdate();
	void CharacterDraw();

	void LoadAnimImage();
	void Idle();
	void Run();
	void Move();

	void CharacterBeforeCollisionCheck();
};


