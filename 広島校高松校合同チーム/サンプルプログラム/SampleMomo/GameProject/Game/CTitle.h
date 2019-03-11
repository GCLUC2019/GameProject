#pragma once
#include "CObject.h"
#include "../Global.h"

class CTitle : public CObject {
private:
public:
	CTitle();
	~CTitle();
	void Update();
	void Draw();
};

