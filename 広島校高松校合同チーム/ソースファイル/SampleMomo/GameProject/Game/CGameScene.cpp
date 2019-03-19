#include "CGameScene.h"
//#include "CCharacterEnemy.h"
#include "CCharacterPlayer.h"
#include "CObjectImage.h"
#include "CCommonObject.h"
#include "CStoryScene.h"
#include "CTitle.h"
#include "CBar.h"
#include "CGameSceneUI.h"
#include "CCharacterEnemy.h"
#include "CCharacterBoss.h"
#include "CGameOver.h"

/*

�v���C���[�߂肱�݂̌����ɂ���
�����蔻��̏��ԓI�Ƀv���C���[���Ή����鑤�i�������Ă��鎞�Ɉړ����鑤�j�ɂȂ�׃v���C���[���G�Ȃǂ̃I�u�W�F�N�g�ɍ��킹�Ĉړ���߂��Ă���`�ɂȂ邩��

�΍�


�ǂ��Ȃ�������\�ȑ΍�
�v���C���[�̓����蔻�菇�ʂ̒����i��ɒ�������΂悢�Ƃ������ƂɂȂ�B


�ǂ��΍�
�����蔻����������Ƃ𑊎�I�u�W�F�N�g�ɂ��`����d�g��


���{�I����
���s���ŕӂ蔻�肪�ς�闝�R

�`�揇�ԂŃ\�[�g�͍s���Ă��邪�A���̏��Ԃ�Update�Ȃǂ̍X�V�ɂ����p����邩��B

*/

//#include "CDropItem.h"
static CGameScene* s_instance_p = nullptr;

CGameScene::CGameScene() : CObject(0, 0)
{
	Init();
}

CGameScene::~CGameScene()
{
}

void CGameScene::Init()
{
	for (int i = 0; i < GAME_SCENE_OBJECT_MAX; i++) {
		m_game_scene_object_p[i] = nullptr;
	}
}

void CGameScene::Setup()
{
	

	for (int i = 0; i < 6; i++) {
		//������(�����͒P���Ȃ̂ŏ����̌y���ėp�I�u�W�F�N�g�ő�p)
		AddGameSceneObject(new CCommonObject(nullptr, CVector3D(1280.0f * i,10000.0f, 0.0f), CVector2D(0, 0), CVector3D(1280.0f, 1.0f + 10000.0f, 720.0f)));
		AddGameSceneObject(new CObjectImage(GET_RESOURCE("Stage_Background_0", CImage*), CVector3D(1280 * i, 0, 0), CVector2D(1280, 720), -1));
	}

	//AddGameSceneObject(new CCommonObject(nullptr, CVector3D(600, 0, 600), CVector2D(0, 0), CVector3D(50, 50, 50)));

	SetGameSceneLimitPosMin(CVector3D(100.0f, 0.0f, 340.0f));

	SetGameSceneLimitPosMax(CVector3D(1280.0f*6,720.0f,720.0f));

	
	CCharacterPlayer* player_p = new CCharacterPlayer();
	AddGameSceneObject(player_p);
	player_p->SetPos(300, -2500, 500);
	

	//for (int i = 0; i < 1;i++) AddGameSceneObject(new CCharacterEnemy());

	/*
	CDropItem* drop_item_p;
	AddGameSceneObject(drop_item_p = new CDropItem(eItemIdSpear));
	drop_item_p->SetPos(CVector3D(200,200,200));
	drop_item_p->SetSize(CVector2D(200, 200));
	*/


	//�G�̔z�u
	/*for(int i = 0; i < 70;i++) AddGameSceneObject(new CCharacterEnemy(eEnemyIdAxe,CVector3D(1000 +  200 * i,-2500,450 + 100 )));


	for (int i = 0; i < 0; i++) AddGameSceneObject(new CCharacterEnemy(eEnemyIdSpear, CVector3D(2000 + 200 * i, -2500, 450 + 100 * i)));
*/

	AddGameSceneObject(new CCharacterBoss());
	
	AddGameSceneObject(new CGameSceneUI());

	CFPS::Wait();//deltatime���艻�p
}


void CGameScene::AddGameSceneObject(Task * _object)
{
	TaskManager::GetInstance()->AddTask(_object);
	m_game_scene_object_p[m_game_scene_object_num++] = _object;
}

void CGameScene::ClearGameSceneObject()
{
	for (int i = 0; i < m_game_scene_object_num; i++) {
		m_game_scene_object_p[i]->SetIsDelete();
		m_game_scene_object_p[i] = nullptr;
	}
	m_game_scene_object_num = 0;
}

void CGameScene::WaveDone()
{
}

void CGameScene::GameOver()
{
	ClearGameSceneObject();
	TaskManager::GetInstance()->AddTask(new CGameOver());
}

CGameScene * CGameScene::GetInstance()
{
	if (s_instance_p == nullptr) s_instance_p = new CGameScene();
	return s_instance_p;
}
