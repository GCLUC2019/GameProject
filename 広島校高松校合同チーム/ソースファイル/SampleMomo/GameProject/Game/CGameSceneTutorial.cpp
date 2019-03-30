#include "CGameSceneTutorial.h"
#include "CGameScene.h"
#include "CAnimation.h"
#include "CSubWeapon.h"
#include "CBar.h"
#include "CDamageEffect.h"
#include "CItem.h"

static CTutorial* s_tutorial_p = nullptr;
bool CCharacterTutorialEnemy::tutorial_flag = true;

//チュートリアルのテキスト数
#define TUTORIAL_SENTENSE_NUM (eLessonEnd)

//表示する絵を変えるための文章数
#define CHANGE_NUM 50
//次の紙芝居の配列ナンバー
#define NEXT_ARRAY_NUM 5

//成功表示までのウェイトタイム
#define WAIT_TIME_SUCCESS (10)

//次のレッスンまでのウェイトタイム
#define WAIT_TIME (60)

CTutorial::CTutorial() :CStoryScene()
{
	m_skip_tutorial_p = GET_RESOURCE("Skip_Tutorial", CImage*);

	CCharacterTutorialEnemy::tutorial_flag = true;
	s_tutorial_p = this;

	SetDrawPriority(1000);

	m_lesson_num = eLessonMoveLeft;
	for (int i = 0; i < 5; ++i) {
		m_clear_flag[i] = false;
	}

	m_lesson_clear_flag = false;

	//チュートリアル用の死んでも復活するエネミーを用意すれば良いと思います
	//if (TaskManager::GetInstance()->FindTask(eTaskIdEnemy) == nullptr)
	//CGameScene::GetInstance()->AddGameSceneObject(new CCharacterTutorialEnemy(CVector3D(1500, -151, 450 + 100)));
	
	Setchar();
	SetValue();
	SetTextBox();
	SetText(t_name[0]);
	SetIcon();
	SetSubSentense(TUTORIAL_SENTENSE_NUM);
	SetParam();



	m_target_p = CCharacterPlayer::GetInstance();
	m_enemy_damage = false;
	m_is_show_white_screen = false;

	m_setting_wait_time = WAIT_TIME;
	m_wait_time_count = m_setting_wait_time;
	SetIsFadeEffect(false);
}

CTutorial::~CTutorial()
{

}

void CTutorial::Update()
{
	InputSkipTutorial();
	if (m_lesson_clear_flag) LessonClear();
	else switch (m_lesson_num)
	{
	case eLessonMoveLeft:
		LessonMoveLeft();
		break;
	case eLessonMoveLeftClear:
		LessonSuccess();
		break;

	case eLessonMoveRight:
		LessonMoveRight();
		break;
	case eLessonMoveRightClear:
		LessonSuccess();
		break;

	case eLessonMoveUp:
		LessonMoveUp();
		break;
	case eLessonMoveUpClear:
		LessonSuccess();
		break;

	case eLessonMoveDown:
		LessonMoveDown();
		break;
	case eLessonMoveDownClear:
		LessonSuccess();
		break;

	case eLessonMoveJump:
		LessonMoveJump();
		break;
	case eLessonMoveJumpClear:
		LessonSuccess();
		break;

	case eLessonAttack:
		LessonAttack();
		break;
	case eLessonAttackClear:
		LessonSuccess();
		break;

	case eLessonComboAttack:
		LessonComboAttack();
		break;
	case eLessonComboAttackClear:
		LessonSuccess();
		break;

	case eLessonVerticalAttack:
		LessonVerticalAttack();
		break;
	case eLessonVerticalAttackClear:
		LessonSuccess();
		break;

	case eLessonSideAttack:
		LessonSideAttack();
		break;
	case eLessonSideAttackClear:
		LessonSuccess();
		break;

	case eLessonJumpAttack:
		LessonJumpAttack();
		break;
	case eLessonJumpAttackClear:
		LessonSuccess();
		break;

	case eLessonEvasion:
		LessonEvasion();
		break;
	case eLessonEvasionClear:
		LessonSuccess();
		break;

	case eLessonDash:
		LessonDash();
		break;
	case eLessonDashClear:
		LessonSuccess();
		break;

	case eLessonTakeWeapon:
		LessonTakeWeapon();
		break;

	case eLessonTakeWeaponClear :
		LessonSuccess();
		break;

	case eLessonWeaponAttack:
		LessonWeaponAttack();
		break;
	case eLessonWeaponAttackClear:
		LessonSuccess();
		break;

	case eLessonWeaponDestroy:
		LessonWeaponDestroy();
		break;
	case eLessonWeaponDestroyClear:
		LessonSuccess();
		break;

	case eLessonTakeKibidango:
		LessonTakeKibidango();
		break;
	case eLessonTakeKibidangoClear:
		LessonSuccess();
		break;
	case eLessonTutorialEnd:
		LessonTutorialEnd();
		break;
	default:
		break;
	}
	printf("レッスン番号 %d\n", m_lesson_num);

	UpdateTutorialText(CHAR_NUM, sentence_num);
	
	if (m_lesson_num >= eLessonEnd) {
		SetIsDelete();
	}
}

void CTutorial::Draw()
{
	m_skip_tutorial_p->SetSize(500,25);
	m_skip_tutorial_p->SetPos(800,0);
	m_skip_tutorial_p->Draw();
	AllDraw();
}

void CTutorial::AddRAll()
{

}

void CTutorial::Setchar()
{
	char name_array2[][MAX_SENTENSE_SIZE] = {	"TutorialText-MoveLeft","TutorialText-Success",
		"TutorialText-MoveRight","TutorialText-Success",
		"TutorialText-MoveUp","TutorialText-Success",
		"TutorialText-MoveDown","TutorialText-Success",
		"TutorialText-Jump","TutorialText-Success",
		"TutorialText-Attack","TutorialText-Success",
		"TutorialText-ComboAttack","TutorialText-Success",
		"TutorialText-VerticalAttack","TutorialText-Success",
		"TutorialText-SideAttack","TutorialText-Success",
		"TutorialText-JumpAttack","TutorialText-Success",
		"TutorialText-Evasion","TutorialText-Success",
		"TutorialText-Dash","TutorialText-Success",
		"TutorialText-TakeWeapon","TutorialText-Success",
		"TutorialText-WeaponAttack","TutorialText-Success",
		"TutorialText-WeaponDestory","TutorialText-Success",
		"TutorialText-TakeKibidango","TutorialText-End",
		"TutorialText-1" ,"TutorialText-2"
		,"TutorialText-3","TutorialText-4" };

	SetSentense(TUTORIAL_SENTENSE_NUM, t_name, name_array2);
}

void CTutorial::SetValue()
{

}

void CTutorial::BeforeUpdate()
{
}

void CTutorial::ResetPos()
{
	m_target_p->SetPos(CVector3D(300, m_target_p->GetPos().y, 550));
	m_target_p->SetIsFlip(false);
}

void CTutorial::LessonSuccess()
{
	CSound::GetInstance()->GetSound("SE_Success")->Play();
	m_lesson_clear_flag = true;
	m_lesson_num++;
	SetIsFadeEffect(true);
	m_setting_wait_time = WAIT_TIME_SUCCESS;
	m_is_reset_pos = true;
}

void CTutorial::LessonMoveLeft()
{
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft) && m_target_p->GetIsMoving()) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonMoveRight()
{
	if (CInput::GetState(0, CInput::eHold, CInput::eRight) && m_target_p->GetIsMoving()) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonMoveUp()
{
	if (CInput::GetState(0, CInput::eHold, CInput::eUp) && m_target_p->GetIsMoving()) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonMoveDown()
{
	if (CInput::GetState(0, CInput::eHold, CInput::eDown) && m_target_p->GetIsMoving()) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonMoveJump()
{
	if (m_target_p->GetIsJumping()) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonEvasion()
{
	if (m_target_p->GetIsEvasion()) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonAttack()
{
	
	if (m_target_p->GetIsAttacking()) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonComboAttack()
{
	if (m_target_p->GetIsAttacking() && m_target_p->GetComboCount() >= 1) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonVerticalAttack()
{
	//printf("%d\n", m_target_p->GetComboCount());
	if (m_target_p->GetComboCount() == 0 && 
		(CInput::GetState(0, CInput::eHold, CInput::eLeft) || CInput::GetState(0, CInput::eHold, CInput::eRight)) &&
		m_target_p->GetIsAfterAttackFrame()) {
		m_lesson_flag_count++;

		if (m_lesson_flag_count >= 2) {
			m_lesson_flag_count = 0;
			SetIsFadeEffect(false);
			m_lesson_clear_flag = true;
			m_lesson_num++;
			m_setting_wait_time = WAIT_TIME;
		}
		
	}
}

void CTutorial::LessonSideAttack()
{
	if (m_target_p->GetComboCount() == 1 &&
		(CInput::GetState(0, CInput::eHold, CInput::eUp) || CInput::GetState(0, CInput::eHold, CInput::eDown)) &&
		m_target_p->GetIsAfterAttackFrame()) {
		m_lesson_flag_count++;

		if (m_lesson_flag_count >= 2) {
			m_lesson_flag_count = 0;
			SetIsFadeEffect(false);
			m_lesson_clear_flag = true;
			m_lesson_num++;
			m_setting_wait_time = WAIT_TIME;
		}

	}
}

void CTutorial::LessonJumpAttack()
{
	if (m_target_p->GetComboCount() == 2 && m_target_p->GetIsLanding() == false &&
		m_target_p->GetIsAttacking()) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
	
}

void CTutorial::LessonDash()
{
	if (m_target_p->GetIsDashing() && m_target_p->GetIsMoving()) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonTakeWeapon()
{
	if (m_lesson_flag_count == 0) {
		CGameScene::GetInstance()->AddGameSceneObject(new CSubWeaponItem(CVector3D(500, 0, 550), 0));
		m_lesson_flag_count++;
	}
	if (CSubWeaponItem::GetIsTakeItemNow()) {
		m_lesson_flag_count = 0;
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonWeaponAttack()
{
	if (m_target_p->GetIsWeaponAttacking() || m_target_p->GetPlayerEquipWeaponId() == -1) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonWeaponDestroy()
{
	if (m_target_p->GetPlayerEquipWeaponId() == -1) {
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME;
	}
}

void CTutorial::LessonTakeKibidango()
{
	if (m_lesson_flag_count == 0) {
		m_target_p->HitPointGainValue(-7.5f);
		CGameScene::GetInstance()->AddGameSceneObject(new CItem(CVector3D(500, 0, 550), eItemPeach));
		m_lesson_flag_count++;
	}
	if (CItem::GetIsTakeItemNow()) {
		m_lesson_flag_count = 0;
		SetIsFadeEffect(false);
		m_lesson_clear_flag = true;
		m_lesson_num++;
		m_setting_wait_time = WAIT_TIME + 30;
	}
}

void CTutorial::LessonTutorialEnd()
{
	SetIsDelete();
	CGameScene::GetInstance()->DeletePlayer();
	CGameScene::GetInstance()->PopPlayer();
	CGameScene::GetInstance()->ChangeScene(eStage1);
}

/*
//移動とジャンプを確認
void CTutorial::Lesson1()
{
	if (CInput::GetState(0, CInput::eHold, CInput::eRight) && m_target_p->GetIsMoving()) {
		m_clear_flag[0] = true;
		
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eLeft) && m_target_p->GetIsMoving()) {
		m_clear_flag[1] = true;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eUp) && m_target_p->GetIsMoving()) {
		m_clear_flag[2] = true;
	}
	if (CInput::GetState(0, CInput::eHold, CInput::eDown) && m_target_p->GetIsMoving()) {
		m_clear_flag[3] = true;
		
	}

	if (m_target_p->GetIsJumping()) {
		m_clear_flag[4] = true;
	}


	bool is_clear = false;
	for (int i = 0; m_clear_flag[i]; ++i) {
		if (m_clear_flag[i] == false) {
			break;
		}
		if (i == 4) {
			is_clear = true;
		}
	}

	if (is_clear == true) {
		for (int i = 0; i < 5; ++i) {
			m_clear_flag[i] = false;
		}
		m_lesson_clear_flag = true;
		m_lesson_num++;
	}
	
}
*/

//通常攻撃を確認
void CTutorial::Lesson2()
{
	if (m_target_p->GetIsAttacking()) {
		m_clear_flag[0] = true;
	}
	if (m_clear_flag[0]) {
		m_enemy_damage = false;
		m_clear_flag[0] = false;
		m_lesson_clear_flag = true;
		m_lesson_num++;
	}
}

//回避とダッシュを確認
void CTutorial::Lesson3()	//回避の確認はプレイヤー側から何かフラグを貰ってください
{
	if (m_target_p->GetIsEvasion()) {
		m_clear_flag[0] = true;
	}
	if (m_target_p->GetIsDashing()) {
		m_clear_flag[1] = true;
	}

	if (m_clear_flag[0] && m_clear_flag[1]) {
		m_clear_flag[0] = false;
		m_clear_flag[1] = false;
		m_lesson_clear_flag = true;
		m_lesson_num++;
		
	}
	
}

//サブ武器攻撃を確認
void CTutorial::Lesson4()	//サブ武器攻撃もエネミーからもらった方が良いかもしれません
{
	if (m_target_p->GetIsWeaponAttacking() && m_enemy_damage) {
		//m_lesson_clear_flag = true;
		m_enemy_damage = false;
		m_lesson_num++;
	}
}

void CTutorial::LessonClear()
{
	
}

void CTutorial::InputSkipTutorial()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eButton10)) {
		LessonTutorialEnd();
	}
	
}


CTutorial * CTutorial::GetInstance()
{
	return s_tutorial_p;
}

//void CTutorial::GetEnemyP(CCharacterTutorialEnemy enemy)
//{
//	m_enemy_p = &enemy;
//}

void CTutorial::UpdateTutorialText(int word, int limit)
{
	//文字出力完了していないなら、
	if (complete_flg == false) {
		if (dis_cnt >= 4 && rect_cnt <= lim * word) {
			RectUp();
			rect_cnt += RECTSIZE_X;
			dis_cnt = 0;
		}
		//lesson完了で文字を出力完了に
		if (m_lesson_clear_flag) {
			rect_cnt = lim * word;
			RectUp();
			complete_flg = true;
			dis_cnt = 0;
		}
		//指定した文字を出力を終えた場合
		if (rect_cnt >= lim * word) {
			complete_flg = true;
			dis_cnt = 0;
		}
	}

	//文章を表示し終えた後lesson完了で次の文章へ
	if (subscript<sentence_num - 1 && dis_cnt >= 15 && complete_flg == true) {
		if (m_lesson_clear_flag) {


			m_wait_time_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
			if (m_wait_time_count <= 0.0) {
				if (m_is_reset_pos == true) {
					ResetPos();
					m_is_reset_pos = false;
				}
				m_wait_time_count = m_setting_wait_time;
				subscript++;
				NextText(t_name);
				m_lesson_clear_flag = false;
			}
			
		}
	}

	dis_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
}





CCharacterTutorialEnemy::CCharacterTutorialEnemy(CVector3D _enemy_pos) :CCharacter(eTaskIdEnemy, 0)
{
	SetPos(_enemy_pos);
	SetPosOld(_enemy_pos);

	m_speed = 1.0f;

	m_knock_back_frame = ENEMY_KNOCK_BACK_FRAME;

	SetIsShowShadow(true);
	SetRads(75, 150, 10);

	m_hit_point = 7.5f;
	m_hit_point_max = 7.5f;

	m_enemy_state = eEnemyStateIdle;       
	m_AI_cnt = 0;
	m_damage_chance = 0;
	m_attack_chance = false;
	is_attack = false;


	LoadAnimImage();

	//当たり判定の優先度
	SetCollisionPriority(5);

	//敵はプレイヤーを設定（ここを変えれば味方のトランプ兵も作れるかも）
	m_target_p = CCharacterPlayer::GetInstance();

	m_hit_point_bar_p = new CBar(GET_RESOURCE("HP_Bar", CImage*), &m_hit_point, m_hit_point_max, m_pos, CVector2D(195, 15), true);
	m_hp_frame_image_p = GET_RESOURCE("Enemy_HP_Bar_Frame", CImage*);
}

CCharacterTutorialEnemy::~CCharacterTutorialEnemy()
{
	if (m_hit_point_bar_p != nullptr) delete m_hit_point_bar_p;
	if (tutorial_flag)CGameScene::GetInstance()->AddGameSceneObject(new CCharacterTutorialEnemy(m_player_pos + CVector3D(500, -510, 0)));
}

void CCharacterTutorialEnemy::LoadAnimImage()
{
	m_is_range = false;
	m_receive_damage_frame = ENEMY_SPEAR_RECEIVE_DAMAGE_FRAME;
	m_attack_power = ENEMY_SPEAR_ATTACK_POWER;
	m_attacking_hit_start_frame = ENEMY_SPEAR_ATTACK_HIT_START_FRAME;
	m_attacking_hit_end_frame = ENEMY_SPEAR_ATTACK_HIT_END_FRAME;
	m_attack_frame = ENEMY_SPEAR_ATTACK_FRAME;
	m_attack_length = ENEMY_SPEAR_ATTACK_LENGTH;
	m_anim_p->ReadAnimDataFile("EnemyAnim/Spear/ENEMY_SPEAR_ANIM_DATA.anim");
}

void CCharacterTutorialEnemy::CharacterBeforeUpdate()
{
	CVector2D l_vec = CVector2D(m_player_pos.x - m_pos.x, m_player_pos.z - m_pos.z);
	if (abs(l_vec.x) < m_attack_length.x && abs(l_vec.y) < m_attack_length.z) {
		m_attack_chance = true;
	}
	else m_attack_chance = false;
}

void CCharacterTutorialEnemy::CharacterUpdate()
{

	m_anim_p->SetWillPlayAnim(eEnemyAnimIdIdle);

	m_player_pos = m_target_p->GetPos();
	if (m_pos.x - m_player_pos.x > 0) m_is_flip = true;   //LRの追加か、マイナス値を付与する
	else m_is_flip = false;
	m_AI_cnt += CFPS::GetDeltaTime() * GAME_BASE_FPS;
	switch (m_enemy_state) {
	case eEnemyStateIdle:
		EnemyIdle();			
		break;
	case eEnemyStateMove:
		EnemyMoving();			
		break;
	case eEnemyStateAttack:
		EnemyAttack();
		break;
	default:
		break;
	}
	DoingKnockBack();
	ReceiveDamageNow();
	CheckTutorial();
	//printf("%f %f %f\n", m_pos.x, m_pos.y, m_pos.z);
	AdjAnim();
}

void CCharacterTutorialEnemy::CharacterBeforeCollisionCheck()
{
	
}

void CCharacterTutorialEnemy::CollisionCheckCharacter(Task * _collision_task)
{

}

void CCharacterTutorialEnemy::CharacterDraw()
{
	m_hp_frame_image_p->SetSize(CVector2D(200, 20));
	m_hp_frame_image_p->SetPos(CVector2D(m_pos.x, m_pos.y + m_pos.z) + CVector2D(-100, -170) - GetScroll());
	m_hp_frame_image_p->Draw();

	m_hit_point_bar_p->SetPos(m_pos + CVector3D(-100 + 2.5, 0, -170 + 2.5));
	m_hit_point_bar_p->Update();
	m_hit_point_bar_p->Draw();
}

void CCharacterTutorialEnemy::CharacterOutHitPoint()
{
	DropItem();
	CGameScene::GetInstance()->EraseGameSceneObject(this);
	SetIsDelete();
}

void CCharacterTutorialEnemy::ReceiveAttack()
{
	m_receive_damage_count = m_receive_damage_frame;
	m_is_receive_damage_now = true;
	m_anim_p->SetWillPlayAnim(eEnemyAnimIdDamage);
	m_is_attacking = false;
	m_is_moving = false;
	CSound::GetInstance()->GetSound("SE_Damage")->Play();
	CGameScene::GetInstance()->AddGameSceneObject(new CDamageEffect(&m_pos, CVector2D(-200, -210), CVector2D(400, 400), 30));
	CTutorial::GetInstance()->EnemyDamage();
}

void CCharacterTutorialEnemy::ReceiveDamageNow()
{
	
	if (m_is_receive_damage_now == false) return;
	m_AI_cnt = 0;
	m_receive_damage_count -= CFPS::GetDeltaTime() * GAME_BASE_FPS;
	if (m_receive_damage_count <= 0.0) {
		m_is_receive_damage_now = false;
		AiChange(-1);
		return;
	}
	m_anim_p->SetWillPlayAnim(eEnemyAnimIdDamage);
}

void CCharacterTutorialEnemy::ReceiveKnockBack(CVector3D _from_pos, double _power)
{
	if (m_is_knock_back == true) return;
	if (m_is_invincible == true) return;

	SetKnockBack(_from_pos, _power);

	//動作中断
	m_is_attacking = false;
}

void CCharacterTutorialEnemy::EnemyMoving()
{
	m_is_attacking = false;
	if (m_target_p == nullptr) return;
	if (m_is_knock_back == true) return;
	m_anim_p->SetWillPlayAnim(eEnemyAnimIdMove);
	m_is_moving = true;
	//m_is_damage = true;
	if (m_damage_chance > 3) {
		m_vec = CVector3D(-m_player_vec.x * 2, m_vec.y, -m_player_vec.y * 2);
	}
	else m_vec = CVector3D(m_player_vec.x, m_vec.y, m_player_vec.y);
	if (m_vec.x > 0) m_is_flip = false;
	else m_is_flip = true;
	if (m_attack_chance && m_damage_chance < 3) m_AI_cnt += 100;
	AiChange(200);
}

void CCharacterTutorialEnemy::EnemyAttack()
{
	if (m_target_p == nullptr) return;
	if (m_is_knock_back == true) return;
	if (is_attack == false) {
		AiChange(0);
		return;
	}

	m_anim_p->SetWillPlayAnim(eEnemyAnimIdAttack);
	//m_is_damage = true;
	//m_vec = CVector3D(0, m_vec.y, 0);
	

	//if (m_is_receive_damage_now == true) m_enemy_state = eEnemyStateIdle;

	CVector3D target_vec = m_pos - m_player_pos;
	
	if (m_AI_cnt > ENEMY_SPEAR_ATTACK_HIT_START_FRAME && m_AI_cnt <= ENEMY_SPEAR_ATTACK_HIT_END_FRAME && abs(target_vec.x) <= m_attack_length.x && abs(target_vec.y) <= m_attack_length.y && abs(target_vec.z) <= m_attack_length.z && is_attack) {
		m_is_attacking = true;
		if (m_target_p == NULL) printf("プレイヤーがいません\n");
		printf("Hit!!\n");
		//ダメージを与える
		m_target_p->HitPointGainValue(-m_attack_power);

		//ノックバックを与える
		m_target_p->ReceiveKnockBack(m_pos, 5.0);

		//攻撃が当たったことを伝える
		m_target_p->ReceiveAttack();
	}
	if (m_is_attacking == true) {
		/*m_is_attacking = false;*/
		CSound::GetInstance()->GetSound("SE_Slash1")->Play();
	}
	AiChange(40);
}


void CCharacterTutorialEnemy::EnemyIdle()
{
	m_is_attacking = false;
	m_anim_p->SetWillPlayAnim(eEnemyAnimIdIdle);
	m_is_moving = false;
	/*is_attack = true;
	m_is_damage = true;*/
	m_player_vec = CVector2D(m_player_pos.x - m_pos.x, m_player_pos.z - m_pos.z);
	float x = m_player_vec.x;
	if (m_attack_length.x > abs(x)) m_player_vec.x = 0;
	m_player_vec = m_player_vec / m_player_vec.Length();
	m_vec = CVector3D(0, m_vec.y, 0);
	AiChange(100);
}

void CCharacterTutorialEnemy::AiChange(int ai_cnt)
{
	if (m_AI_cnt > ai_cnt) {
		switch (m_enemy_state)
		{
		case eEnemyStateIdle:
			m_AI_cnt = 0;
			m_enemy_state = eEnemyStateMove;
			/*if ((rand() % 100) % 2) */is_attack = true;
			break;
		case eEnemyStateMove:
			m_damage_chance = 0;
			m_AI_cnt = 0;
			if (m_attack_chance)m_enemy_state = eEnemyStateAttack;
			else {
				m_AI_cnt += rand() % 100;
				m_enemy_state = eEnemyStateIdle;
			}
			break;
		case eEnemyStateAttack:
			m_AI_cnt = 50;
			is_attack = false;
			if (m_attack_chance)m_enemy_state = eEnemyStateIdle;
			else m_enemy_state = eEnemyStateMove;
			break;
		case eEnemyStateDamage:
			m_AI_cnt = 0;
			if (m_damage_chance > 3)m_enemy_state = eEnemyStateMove;
			else m_enemy_state = eEnemyStateIdle;
			break;
		default:
			break;
		}
	}
}

void CCharacterTutorialEnemy::DropItem()
{
	//出現率3分の1
	int rand = Utility::Rand(0, 2);
	if (rand != 0) return;

	//アイテムドロップ
	int drop_weapon_id = 0;


	CGameScene::GetInstance()->AddGameSceneObject(new CSubWeaponItem(m_pos + CVector3D(0, 140, 0), drop_weapon_id));
}


void CCharacterTutorialEnemy::AdjAnim()
{
	switch (m_anim_p->GetWillPlayAnim()) {
	case eEnemyAnimIdAttack:
		SetSize(500, 400);
		SetShadowSize(CVector2D(160, 50));
		SetDrawAdjPos(CVector2D(-60, 0.0f));
		break;
	case eEnemyAnimIdMove:
		SetSize(400, 400);
		SetShadowSize(CVector2D(100, 50));
		SetDrawAdjPos(CVector2D(0, 0.0f));
		break;
	case eEnemyAnimIdIdle:
		SetSize(400, 400);
		SetShadowSize(CVector2D(100, 50));
		SetDrawAdjPos(CVector2D(10, 0.0f));
		break;
	case eEnemyAnimIdDamage:
		SetSize(400, 400);
		SetShadowSize(CVector2D(100, 50));
		SetDrawAdjPos(CVector2D(10, 0.0f));
		break;
	}
}


