#pragma once
/*Å@íSìñ
	çëå©Å@class GameClear
*/
#include "../../Base/Task.h"
#include "../../Game/Resource/Resource.h"

class GameClear : public Task {
private:
	CImage m_gameclear_img;
	CVector2D m_gameclear_pos;

public:
	GameClear();
	~GameClear();
	void Update();
	void Draw();
	CVector2D GetPos() {
		return  CVector2D(0, 800);
	}
};