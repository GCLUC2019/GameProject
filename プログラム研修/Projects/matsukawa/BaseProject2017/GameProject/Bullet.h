#pragma once
#include "stdafx.h"
#include "System\Task.h"

class Bullet:public Task
{
private:
	CVector2D m_pos;
public:
	Bullet(const CVector2D& pos);
	void Update();
	void Render();
};
