#pragma once
#include "../GameProject/Base/Task.h"

class GameScene : public Task {
private:
	CVector2D m_player_pos_x;
	bool m_go_flg;
	float mp_fadeout;
public:
	GameScene();
	~GameScene();
	void Update();
};
