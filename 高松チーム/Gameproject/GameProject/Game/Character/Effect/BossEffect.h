#pragma once
#include "../GameProject/Base/Task.h"


class BossFireEffect : public Task {
private:
	CImage m_flip;
	CAnimImage m_img;
	CVector2D m_pos;

	CRect m_rect;
public:
	BossFireEffect(const CVector2D& pos);

	void Update();

	void HitCheck();

	void Draw();

	CVector2D GetPos() {
		return m_pos;
	}
	CRect GetRect() {
		return m_rect;
	}
};

class BossLazerEffect : public Task {
private:
	CImage m_img;
	CAnimImage m_img2;//矩形移動の座標確認用の画像
	CVector2D m_pos;
	CVector2D m_pos2;//矩形移動用の座標

	CRect m_rect;

	int m_rect_pos;//矩形移動させるため
public:
	BossLazerEffect(const CVector2D& pos);

	void Update();

	void HitCheck();

	void Draw();

	CVector2D GetPos() {
		return m_pos;
	}
	CRect GetRect() {
		return m_rect;
	}
};

class BossSlashEffect : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_player_pos;
	CRect m_rect;

	bool m_flip;
public:
	BossSlashEffect(const CVector2D &pos);

	void Update();

	void HitCheck();

	void Draw();

	CVector2D GetPos() {
		return m_pos;
	}
	CRect GetRect() {
		return m_rect;
	}
};
