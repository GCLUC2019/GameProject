#ifndef CSCENE_H
#define CSCENE_H

#include "CPlayerTank.h"
#include "CEnemyTank.h"
#include "CTexture.h"

extern CPlayerTank*Tank;
extern CTexture Texture;
extern CEnemyTank*EnemyTank;

class CScene{
public:
	enum ESceneTag{
		EROOT,
		EGAME,
		EWIN,
		ELOSE,
	};
	ESceneTag mSceneTag;
	virtual ~CScene(){}
	virtual void Init(){}
	virtual void Update(){}
};

#endif