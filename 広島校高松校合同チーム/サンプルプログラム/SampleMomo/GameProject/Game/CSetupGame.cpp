#include "CSetupGame.h"
#include "CCharacterEnemy.h"
#include "CCharacterPlayer.h"
#include "CObjectImage.h"

//‹N“®‚ÉŒÄ‚Î‚ê‚Ü‚·B
void CSetupGame::Setup()
{
	ADD_RESOURCE("Stage_Background_0", CImage::LoadImage("haikei.png"));
	new CObjectImage(GET_RESOURCE("Stage_Background_0", CImage*));
	new CCharacterPlayer();
	new CCharacterEnemy();
}
