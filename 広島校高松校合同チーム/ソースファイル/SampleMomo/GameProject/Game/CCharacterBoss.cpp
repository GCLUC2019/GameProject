#include "CCharacterBoss.h"
#include "CCharacterPlayer.h"

//起動誤差
#define RANGE (300)


CCharacterBoss::CCharacterBoss():CCharacter(eTaskIdEnemy,0)
{
	ADD_RESOURCE("Idle1", CImage::LoadImage("DogIdle1.png"));
	ADD_RESOURCE("Idle2", CImage::LoadImage("DogIdle2.png"));
	ADD_RESOURCE("Run1", CImage::LoadImage("DogRun1.png"));
	ADD_RESOURCE("Run2", CImage::LoadImage("DogRun2.png"));
	ADD_RESOURCE("Run3", CImage::LoadImage("DogRun3.png"));
	ADD_RESOURCE("Run4", CImage::LoadImage("DogRun4.png"));
	ADD_RESOURCE("Run5", CImage::LoadImage("DogRun5.png"));
	ADD_RESOURCE("Run6", CImage::LoadImage("DogRun6.png"));
	ADD_RESOURCE("Run7", CImage::LoadImage("DogRun7.png"));
	ADD_RESOURCE("Run8", CImage::LoadImage("DogRun8.png"));

	m_player_p  = dynamic_cast<CCharacterPlayer*>(TaskManager::GetInstance()->FindTask(eTaskIdPlayer));
	m_boss_state = eEnemyBossStateIdle;

	m_vec = CVector3D(0, 0, 0);
	//初期値のy軸は地面に埋まらないように少し浮かせる
	m_pos = CVector3D(1000, -160, 500);  

	m_rads = CVector3D(75, 120, 10);
	SetSize(500, 500);
	m_is_flip = false;

	LoadAnimImage();

	SetAnim(eEnemyAnimBossIdIdle);
	SetIsShowShadow(true);
	SetShadowSize(CVector2D(300, 50));
	SetDrawAdjPos(CVector2D(-30.0, -90.0));
}

CCharacterBoss::~CCharacterBoss()
{
}

void CCharacterBoss::CharacterUpdate()
{
	m_player_pos = m_player_p->GetPos();
	Idle();
	Run();
	Move();
	Gravity();
}

void CCharacterBoss::CharacterDraw()
{
	printf("x:%f y:%f", m_pos.x, m_pos.y);
}

void CCharacterBoss::LoadAnimImage()
{
	//待機アニメーションの読み込み
	m_anim_image_p[eEnemyAnimBossIdle1] = GET_RESOURCE("Idle1", CImage*);
	m_anim_image_p[eEnemyAnimBossIdle2] = GET_RESOURCE("Idle2", CImage*);

	//走るアニメーションの読み込み
	m_anim_image_p[eEnemyAnimBossRun1] = GET_RESOURCE("Run1", CImage*);
	m_anim_image_p[eEnemyAnimBossRun2] = GET_RESOURCE("Run2", CImage*);
	m_anim_image_p[eEnemyAnimBossRun3] = GET_RESOURCE("Run3", CImage*);
	m_anim_image_p[eEnemyAnimBossRun4] = GET_RESOURCE("Run4", CImage*);
	m_anim_image_p[eEnemyAnimBossRun5] = GET_RESOURCE("Run5", CImage*);
	m_anim_image_p[eEnemyAnimBossRun6] = GET_RESOURCE("Run6", CImage*);
	m_anim_image_p[eEnemyAnimBossRun7] = GET_RESOURCE("Run7", CImage*);
	m_anim_image_p[eEnemyAnimBossRun8] = GET_RESOURCE("Run8", CImage*);

	//アニメーションデータの設定
	m_anim_info[eEnemyAnimBossIdIdle].image_num = 2;
	m_anim_info[eEnemyAnimBossIdIdle].image_id = eEnemyAnimBossIdle1;
	m_anim_info[eEnemyAnimBossIdIdle].delay = DEFAULT_ANIM_DELAY;

	m_anim_info[eEnemyAnimBossIdRun].image_num = 8;
	m_anim_info[eEnemyAnimBossIdRun].image_id = eEnemyAnimBossRun1;
	m_anim_info[eEnemyAnimBossIdRun].delay = DEFAULT_ANIM_DELAY;


}

void CCharacterBoss::Idle()
{
	if (m_boss_state == eEnemyBossStateIdle) {
		SetWillPlayAnim(eEnemyAnimBossIdIdle);
		m_vec.x = 0;
		if (m_player_pos.x > m_pos.x + RANGE)m_is_flip = false;
		if (m_player_pos.x < m_pos.x - RANGE) m_is_flip = true;
		if (abs(m_pos.x - m_player_pos.x) >= 500)m_boss_state = eEnemyBossStateRun;
	}
}

void CCharacterBoss::Run()
{
	if (m_boss_state == eEnemyBossStateRun) {
		SetWillPlayAnim(eEnemyAnimBossIdRun);
		if (m_player_pos.x > m_pos.x + RANGE)m_vec.x+=3;
		if (m_player_pos.x < m_pos.x - RANGE) m_vec.x -= 3;
		if (abs(m_pos.x - m_player_pos.x) >= 200)m_boss_state = eEnemyBossStateIdle;
	}
}

void CCharacterBoss::Move()
{
	m_pos += m_vec;
}

void CCharacterBoss::CharacterBeforeCollisionCheck()
{
	
}
