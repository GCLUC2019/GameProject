#pragma once
#include "CObject.h"
#include "../Global.h"

class  CStageCrear:public CObject
{
private:
	CImage m_crear;
	int m_draw_cnt = 0;
	int m_change_cnt = 0;
public:
	CStageCrear();
	~CStageCrear();
	void Update();
	void Draw();
};

 