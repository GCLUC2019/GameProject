#pragma once
#include "../GameProject/Base/Task.h"


class BossFireEffect : public Task {
private:
	CImage m_flip;
	CAnimImage m_img;
	CVector2D m_pos;
public:
	BossFireEffect(const CVector2D& pos);

	void Update();

	void Draw();
};

class BossLazerEffect : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
public:
	BossLazerEffect(const CVector2D& pos);

	void Update();

	void Draw();
};

class BossSlashEffect : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
public:
	BossSlashEffect(const CVector2D& pos);

	void Update();

	void Draw();
};
