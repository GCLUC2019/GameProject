#pragma once
#include "../System/Task.h"
#include "../stdafx.h"

class Bullet : public Task {
private:
	CVector2D m_pos;
public:
	Bullet(const CVector2D& pos);
	void Update(float delta_time);
	void Render();

};