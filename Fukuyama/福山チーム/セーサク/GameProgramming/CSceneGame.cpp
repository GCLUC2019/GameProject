#include "CSceneGame.h"
#include "CMain.h"
#include "Windows.h"
#include"CBoss.h"
#include"CSpeedEnemy.h"
extern CRectangle BackImage;
extern CTexture MapTexture;

#define ENEMYINTERVER 120
#define ENEMYLIMIT 0

void CSceneGame::Init(){
	Tank = new CPlayerTank();
	EnemyTank = new CEnemyTank();
	SpeedEnemy = new CSpeedEnemy();
	Boss = new CBoss();

	Tank->Init();
	EnemyTank->Init();
	EnemyTank->mPosition = CVector2(-400.0f, 250.0f);
	EnemyTank->mRotation = 270.0f;
	SpeedEnemy->Init();
	SpeedEnemy->mPosition = CVector2(400.0f, -200.0f);
	SpeedEnemy->mRotation = 90.0f;


	Boss->Init();
	Boss->mPosition = CVector2(400.0f, -150.0f);
	Boss->mRotation = 90.0f;

	CTaskManager::Get()->Add(Tank);
	//CTaskManager::Get()->Add(EnemyTank);
	CTaskManager::Get()->Add(Boss);
	CTaskManager::Get()->Add(SpeedEnemy);
	MapTexture.Load("1eria.tga");
	Texture.Load("exp.tga");

	mEnemyIntervar = ENEMYINTERVER;
	mEnemyLimit = ENEMYLIMIT;
}

void CSceneGame::Update(){
	if (mEnemyIntervar>0&&mEnemyLimit<1){
		mEnemyIntervar--;
	}

	BackImage.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	BackImage.Draw(MapTexture, 0, 1000, 0, 750);
	BackImage.x = 0;
	BackImage.y = 0;
	BackImage.h = 300;
	BackImage.w = 400;
	CTaskManager::Get()->Update();
	CTaskManager::Get()->Render();
	CCollisionManager::Get()->Remove();
	CTaskManager::Get()->Remove();

	if (mEnemyIntervar <= 0 && mEnemyLimit < 1){          //小川
		mEnemyIntervar = ENEMYINTERVER;
		mEnemyLimit += 1;

		Enemy1 = new CEnemy1();               //追加　釜田
		Enemy2 = new CEnemy2();

		Enemy1->Init();                       //追加　釜田
		Enemy1->mPosition = CVector2(200.0f, -40.0f);
		Enemy1->mRotation = 270.0f;

		Enemy2->Init();                       //追加　釜田
		Enemy2->mPosition = CVector2(360.0f, -80.0f);
		Enemy2->mRotation = 270.0f;

		CTaskManager::Get()->Add(Enemy1);      //追加　釜田
		CTaskManager::Get()->Add(Enemy2);
	}
}

void CSceneWin::Init(){
	mTexture.Load("Result.tga");
	mWin.SetVertex(-200, 200, -100, 100);
	mWin.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mWin.SetTexture(&mTexture, 0, 358, 142, 0);
}

void CSceneWin::Update(){
	mWin.Update();
	mWin.Render();
	if (GetKeyState(VK_RETURN) & 0x8000){
		CMain::mSceneTag = CScene::ETITLE;
	}
}

void CSceneLose::Init(){
	mTexture.Load("game-over.tga");
	mLose.SetVertex(-400, 400, -300, 300);
	mLose.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mLose.SetTexture(&mTexture, 0, 800, 0, 600);
}

void CSceneLose::Update(){
	mLose.Update();
	mLose.Render();
	if (GetKeyState(VK_RETURN) & 0x8000){
		CMain::mSceneTag = CScene::ETITLE;
	}
}

void CSceneTitle::Init(){
	mTexture.Load("title.tga");//タイトル画像
	mTitle.SetVertex(-300, 300, -100, 100);
	mTitle.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mTitle.SetTexture(&mTexture,0, 766, 0, 151);

	mEnterTex.Load("Enter.tga");//タイトル追加
}

void CSceneTitle::Update(){
	BackImage.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	BackImage.Draw(MapTexture, 0, 1000, 0, 750);
	BackImage.x = 0;
	BackImage.y = 0;
	BackImage.h = 300;
	BackImage.w = 400;

	mEnter.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mEnter.Draw(mEnterTex, 0, 355, 0, 21);
	mEnter.x = 0;
	mEnter.y = -300;
	mEnter.h = 10;
	mEnter.w =150;
	mTitle.Update();
	mTitle.Render();
	mEnter.Update();
	mEnter.Render();
	mEnter.y -= -150;
	if (GetKeyState(VK_RETURN) & 0x8000){
		CMain::mSceneTag = CScene::EGAME;
	}
}