//êßçÏëOâ™

#ifndef CSCENEMANAGER_H
#define CSCENEMANAGER_H

#include"CMap.h"
#include"CCollider.h"
#include"CRectangle.h"


class CStat:public CMap{
public:
	CStat(){
		mScneMap = EStat;
	}
	CTexture Texture;
	CRectangle mStat;
	void Init();
	void Update();
};

class CMap1 :public CMap{
public:
	CMap1(){
		mScneMap = EMap1;
	}
	CTexture TextureMap1;
	CRectangle mMap1;
	void Init();
	void Update();
};

class CMap2 :public CMap{
public:
	CMap2(){
		mScneMap = EMap2;
	}
	CTexture TextureMap2;
	CRectangle mMap2;
	void Init();
	void Update();
};

class CMap3 :public CMap{
public:
	CMap3(){
		mScneMap = EMap3;
	}
	CTexture TextureMap3;
	CRectangle mMap3;
	void Init();
	void Update();
};

#endif