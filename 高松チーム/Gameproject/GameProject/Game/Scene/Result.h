#pragma once
/*Å@íSìñ
	çëå©Å@class GameClear
*/
#include "../../Base/Task.h"
#include "../GameProject/Game/Resource/Resource.h"Å@

class GameClear : public Task {
private:
	CImage m_gameclear_img;
	CVector2D m_gameclear_pos;

public:
	GameClear();
	void Update();
	void Draw();

};