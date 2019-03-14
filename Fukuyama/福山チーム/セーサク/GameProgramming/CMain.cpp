//�w�b�_�t�@�C���̃C���N���[�h
#include "CMain.h"
//#include "glut.h"
#include "CVector2.h"
#include "CMatrix33.h"
#include "CRectangle.h"
#include "windows.h"
#include "CPlayerTank.h"
#include "CBullet.h"
#include "CEnemyTank.h"
#include "CSceneGame.h"
#include "CBoss.h"
#include "CTexture.h"

CTexture Texture;
CRectangle*Explosion;

CScene*mpScene;

CPlayerTank *Tank;

CEnemyTank*EnemyTank;

CBoss *Boss = NULL;

CEnemy1*Enemy1;           //�ǉ��@���c
CEnemy2*Enemy2;

CScene::ESceneTag CMain::mSceneTag = CScene::EROOT;

//���߂�1�񂾂����s���鏈���̒�`
void CMain::Init() {
	mSceneTag = CScene::EGAME;
	mpScene = new CSceneGame();
	mpScene->Init();
}

//�J��Ԃ����s���鏈���̒�`
void CMain::Update() {
	mpScene->Update();
	if (mpScene->mSceneTag != mSceneTag){
		delete mpScene;
		mpScene = 0;
		switch (mSceneTag){
		case CScene::EWIN:
			mpScene = new CSceneWin();
			mpScene->Init();
			break;
		case CScene::EGAME:
			mpScene = new CSceneGame();
			mpScene->Init();
			break;
		case CScene::ELOSE:
			mpScene = new CSceneLose();
			mpScene->Init();
			break;
		}
	}
}

