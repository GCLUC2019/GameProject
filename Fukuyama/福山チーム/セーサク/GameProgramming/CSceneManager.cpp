//§ì‘O‰ª

#include"CSceneManager.h"



void CMap1::Init(){
	TextureMap1.Load("1eria.tga");
	mMap1.SetVertex(200, -200, 100, -100);
	mMap1.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mMap1.SetTexture(&TextureMap1, 0, 358, 142, 0);
}

void CMap1::Update(){
	mMap1.Update();
	mMap1.Render();
}

void CMap2::Init(){
	TextureMap2.Load("Bosbeamae.tga");
	mMap2.SetVertex(200, -200, 100, -100);
	mMap2.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mMap2.SetTexture(&TextureMap2, 0, 358, 142, 0);
}

void CMap2::Update(){
	mMap2.Update();
	mMap2.Update();
}

void CMap3::Init(){
	TextureMap3.Load("Bosbea.tga");
	mMap3.SetVertex(200, -200, 100, -100);
	mMap3.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
	mMap3.SetTexture(&TextureMap3, 0, 358, 142, 0);
}

void CMap3::Update(){
	mMap3.Update();
	mMap3.Update();
}