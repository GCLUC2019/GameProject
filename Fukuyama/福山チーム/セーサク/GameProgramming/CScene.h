#ifndef CSCENE_H
#define CSCENE_H

#include "CPlayerTank.h"
#include "CEnemyTank.h"
#include "CTexture.h"
#include"CEnemy1.h"
#include"CEnemy2.h"

extern CPlayerTank*Tank;
extern CTexture Texture;
extern CEnemyTank*EnemyTank;
extern CEnemy1*Enemy1;        //í«â¡Å@äòìc
extern CEnemy2*Enemy2;

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