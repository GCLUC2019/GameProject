//§ì‘O‰ª

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
	CTexture Texture;
	CRectangle mMap1;
	void Init();
	void Update();
};

class CMap2 :public CMap{
public:
	CMap2(){
		mScneMap = EMap2;
	}
	CTexture Texture;
	CRectangle mMap2;
	void Init();
	void Update();
};

class CMap3 :public CMap{
public:
	CMap3(){
		mScneMap = EMap3;
	}
	CTexture Texture;
	CRectangle mMap3;
	void Init();
	void Update();
};

