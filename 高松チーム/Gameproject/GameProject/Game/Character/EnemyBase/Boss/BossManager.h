#pragma once
#include "../GameProject/Base/Task.h"

class BossManager : public Task {
private:
	CAnimImage m_img; //頭
	CImage m_img2;//右手玉があるほう
	CImage m_img3;//左手
	CAnimImage m_img4;//尻尾

	CVector2D m_pos; //頭の座標
	CVector2D m_pos2;//右手の座標
	CVector2D m_pos3;//左手の座標
	CVector2D m_pos4;//尻尾の座標

	int m_state;
public:

	BossManager();

	void Update();

	void Draw();
};
