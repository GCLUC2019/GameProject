#pragma once
#include "../GameProject/Base/Task.h"

class Ground : public Task {
private:
	CImage m_img;
	CVector2D m_pos;

public:
	Ground();
	void Update();
	void Draw();

};

class Bamboo : public Task {
private:
	CImage m_img;
	CVector2D m_pos;
public:
	Bamboo();
	void Update();
	void Draw();
};