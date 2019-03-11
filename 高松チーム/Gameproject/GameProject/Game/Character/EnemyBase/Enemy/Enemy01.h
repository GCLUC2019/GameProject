#pragma once
#include "../EnemyBase.h"

class Enemy: public EnemyBase{
private:
public:
	Enemy();
	void Update();
	void Draw();
};