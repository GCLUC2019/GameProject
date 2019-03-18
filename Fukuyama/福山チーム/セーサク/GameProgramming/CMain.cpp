//ヘッダファイルのインクルード
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



//#include"CSceneManager.h"  //前岡

#include"CSpeedEnemy.h"

CRectangle BackImage;
CTexture Texture;
CTexture MapTexture;
CRectangle*Explosion;

CScene*mpScene;
CMap*mpMap;

CPlayerTank *Tank;

CEnemyTank*EnemyTank;

CSpeedEnemy*SpeedEnemy = NULL;

CBoss *Boss = NULL;

CEnemy1*Enemy1;           //追加　釜田
CEnemy2*Enemy2;

CScene::ESceneTag CMain::mSceneTag = CScene::EROOT;

//CMap::EScneMap CMain::mMapTag = CMap::EMap1; //変更　前岡
//初めに1回だけ実行する処理の定義
void CMain::Init() {
	/*mMapTag = CMap::EStat;  //前岡
	mpMap = new CMap();
	mpMap->Init();*/
	MapTexture.Load("1eria.tga");

	mSceneTag = CScene::EGAME;
	mpScene = new CSceneGame();
	mpScene->Init();
}

//繰り返し実行する処理の定義
void CMain::Update() {
	BackImage.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	BackImage.Draw(MapTexture, 0, 1000, 0, 750);
	BackImage.x = 0;
	BackImage.y = 0;
	BackImage.h = 300;
	BackImage.w = 400;
	/*mpMap->Update();  //前岡
	if (mpMap->mScneMap != mMapTag){
	delete mpMap;
	mpMap = 0;
	switch (mMapTag){
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

	}*/

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
			//前岡
			/*case CMap::EMap1:
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
			break;*/
		}
	}


}

