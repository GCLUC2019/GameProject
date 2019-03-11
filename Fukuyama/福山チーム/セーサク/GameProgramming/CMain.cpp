//ヘッダファイルのインクルード
#include "CMain.h"
#include "glut.h"
#include "CVector2.h"
#include "CMatrix33.h"
#include "CRectangle.h"
#include "windows.h"
#include "CPlayerTank.h"
#include "CBullet.h"
#include "CEnemyTank.h"
#include "CTexture.h"
#include "CSceneGame.h"

CTexture Texture;
CRectangle*Explosion;

CScene*mpScene;

CPlayerTank *Tank;

CEnemyTank*EnemyTank;

CScene::ESceneTag CMain::mSceneTag = CScene::EROOT;

//初めに1回だけ実行する処理の定義
void CMain::Init() {
	mSceneTag = CScene::EGAME;
	mpScene = new CSceneGame();
	mpScene->Init();
}

//繰り返し実行する処理の定義
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

