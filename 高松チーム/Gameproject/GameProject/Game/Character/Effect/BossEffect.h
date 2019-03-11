#pragma once
#include "../GameProject/Base/Task.h"


class BossEffect : public Task {
private:
	CImage m_img;
	CVector2D m_pos;
public:
	BossEffect(CVector2D& pos);

	void Update();

	void Draw();
};
