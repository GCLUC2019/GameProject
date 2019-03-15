//§ì‘O‰ª

#include"CSceneManager.h"

void CStat::Init(){

	Texture.Load("1eria.tga");
	mStat.SetVertex(200, -200, 100, -100);
	mStat.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mStat.SetTexture(&Texture, 0, 358, 142, 0);
}

void CStat::Update(){
	mStat.Update();
	mStat.Render();
}