#include "CSetupGame.h"
#include "CCharacterEnemy.h"
#include "CCharacterPlayer.h"
#include "CObjectImage.h"

//�N�����ɌĂ΂�܂��B
void CSetupGame::Setup()
{
	ADD_RESOURCE("Stage_Background_0", CImage::LoadImage("stage_background_0.png"));
	new CObjectImage(GET_RESOURCE("Stage_Background_0", CImage*));
	new CCharacterPlayer();
}
