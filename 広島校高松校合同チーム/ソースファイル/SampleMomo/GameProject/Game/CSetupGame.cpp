#include "CSetupGame.h"
#include "CCharacterEnemy.h"
#include "CCharacterPlayer.h"
#include "CObjectImage.h"
#include "CCommonObject.h"
#include "CStorySceneOpening.h"
#include "CStorySceneCrear1.h"
#include "CStageCrear.h"
#include "CGameOver.h"

//起動時に呼ばれます。
void CSetupGame::Setup()
{
	/*ADD_RESOURCE("Stage_Background_0", CImage::LoadImage("stage_background_0.png"));

	for (int i = -1; i < 6; i++) {
		TaskManager::GetInstance()->AddTask(new CCommonObject(nullptr, CVector3D(1280*i, 0, 0), CVector2D(0, 0), CVector3D(1280, 1, 720)));
		TaskManager::GetInstance()->AddTask(new CObjectImage(GET_RESOURCE("Stage_Background_0", CImage*), CVector3D(1280*i, 0, 0), CVector2D(1280, 720), -1));
	}
	*/


	/*CCharacterPlayer* player_p = new CCharacterPlayer();
	TaskManager::GetInstance()->AddTask(player_p);*/
	/*CStoryScene* s_scene_p = new CStorySceneOpening();*/
	//CStoryScene* s_scene_p = new CStorySceneCrear1();
	CGameOver* c_over_p = new CGameOver();
	CStageCrear* Crear_p = new CStageCrear();
	TaskManager::GetInstance()->AddTask(c_over_p);


	/*player_p->SetSize(400, 400);
	player_p->SetPos(300, -300,300);
	player_p->SetRads(10, 10, 10);*/

	
}
