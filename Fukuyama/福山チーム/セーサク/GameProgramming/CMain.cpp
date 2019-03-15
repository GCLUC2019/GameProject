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
#include "CBoss.h"



#include"CSceneManager.h"

#include"CSpeedEnemy.h"

>>>>>>> 0d547db42de5c4a5a2e178c92dfdc0ed3961ae4b
CTexture Texture;
CRectangle*Explosion;

CScene*mpScene;
CMap*mpMap;

CPlayerTank *Tank;

CEnemyTank*EnemyTank;

CSpeedEnemy*SpeedEnemy = NULL;

CBoss *Boss = NULL;

CEnemy1*Enemy1;           //追加　釜田
CEnemy2*Enemy2;

//CScene::ESceneTag CMain::mSceneTag = CScene::EROOT;

CMap::EScneMap CMain::mSceneMap = CMap::EStat; //変更　前岡
//初めに1回だけ実行する処理の定義
void CMain::Init() {
	mSceneMap = CMap::EStat;
	mpMap = new CMap();
	mpMap->Init();

	/*mSceneTag = CScene::EGAME;
	mpScene = new CSceneGame();
	mpScene->Init();*/
}

//繰り返し実行する処理の定義
void CMain::Update() {

	mpMap->Update();
	if (mpMap->mScneMap != mSceneMap){
		delete mpMap;
		mpMap = 0;
		switch (mSceneMap){
		case CMap::EMap1:
			mpMap = new CMap1();
			mpMap->Init();
			break;
		case CMap::EMap2:
			mpMap = new CMap2();
			mpMap->Init();
			break;
		case CMap::EMap3:
			mpMap = new CMap3();
			mpMap->Init();
			break;
		}
		
	}

	/*mpScene->Update();
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
	}*/
}

