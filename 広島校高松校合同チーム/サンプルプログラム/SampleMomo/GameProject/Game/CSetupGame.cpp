#include "CSetupGame.h"
#include "CCharacterEnemy.h"
#include "CCharacterPlayer.h"
#include "CObjectImage.h"

//‹N“®Žž‚ÉŒÄ‚Î‚ê‚Ü‚·B
void CSetupGame::Setup()
{
	ADD_RESOURCE("Stage_Background_0", CImage::LoadImage("haikei.png"));
	CObjectImage* stage_p = new CObjectImage(GET_RESOURCE("Stage_Background_0", CImage*));
	stage_p->SetSize(1280,720);

	CCharacterPlayer* player_p = new CCharacterPlayer();
	player_p->SetSize(600, 600);
	player_p->SetPos(300, 0,300);

	/*
	CCharacterEnemy* enemy_p = new CCharacterEnemy();
	enemy_p->SetSize(300, 300);
	*/
}
