#pragma once
#include "CObject.h"
#include "../Global.h"

class CTitle : public CObject {
private:
	CImage m_back;;
public:
	CTitle();
	~CTitle();
	void Update();
	void Draw();
};

