#pragma once
#include "CObject.h"
#include "../Global.h"

class CBar: public CObject {
private:
public:
	CBar();
	~CBar();
	void Update();
	void Draw();
};