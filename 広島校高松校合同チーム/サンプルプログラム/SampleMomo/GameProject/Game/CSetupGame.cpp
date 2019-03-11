#include "CSetupGame.h"
#include "CCharacterEnemy.h"
#include "CCharacterPlayer.h"
#include "CObjectImage.h"
#include "CCommonObject.h"

//ãNìÆéûÇ…åƒÇŒÇÍÇ‹Ç∑ÅB
void CSetupGame::Setup()
{
	LoadResorce();
	

	for (int i = -1; i < 6; i++) {
		TaskManager::GetInstance()->AddTask(new CCommonObject(nullptr, CVector3D(1280*i, 0, 0), CVector2D(0, 0), CVector3D(1280, 1, 720)));
		TaskManager::GetInstance()->AddTask(new CObjectImage(GET_RESOURCE("Stage_Background_0", CImage*), CVector3D(1280*i, 0, 0), CVector2D(1280, 720), -1));
	}
	


	CCharacterPlayer* player_p = new CCharacterPlayer();
	TaskManager::GetInstance()->AddTask(player_p);

	player_p->SetSize(400, 400);
	player_p->SetPos(300, -300,300);
	player_p->SetRads(10, 10, 10);

	
}

void CSetupGame::LoadResorce()
{
	ADD_RESOURCE("Stage_Background_0", CImage::LoadImage("stage_background_0.png"));

	ADD_RESOURCE("Shadow", CImage::LoadImage("shadow.png"));

	ADD_RESOURCE("Player_Idle_Anim_0", CImage::LoadImage("momotaro_idle_anim_0.png"));
	ADD_RESOURCE("Player_Idle_Anim_1", CImage::LoadImage("momotaro_idle_anim_1.png"));
	ADD_RESOURCE("Player_Idle_Anim_2", CImage::LoadImage("momotaro_idle_anim_2.png"));
	ADD_RESOURCE("Player_Move_Anim_0", CImage::LoadImage("momotaro_move_anim_0.png"));
	ADD_RESOURCE("Player_Move_Anim_1", CImage::LoadImage("momotaro_move_anim_1.png"));
	ADD_RESOURCE("Player_Move_Anim_2", CImage::LoadImage("momotaro_move_anim_2.png"));
	ADD_RESOURCE("Player_Move_Anim_3", CImage::LoadImage("momotaro_move_anim_3.png"));
	ADD_RESOURCE("Player_Move_Anim_4", CImage::LoadImage("momotaro_move_anim_4.png"));
	ADD_RESOURCE("Player_Move_Anim_5", CImage::LoadImage("momotaro_move_anim_5.png"));
	ADD_RESOURCE("Player_Move_Anim_6", CImage::LoadImage("momotaro_move_anim_6.png"));
	ADD_RESOURCE("Player_Move_Anim_7", CImage::LoadImage("momotaro_move_anim_7.png"));
}
