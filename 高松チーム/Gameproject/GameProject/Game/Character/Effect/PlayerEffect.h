#pragma once
#include "../GameProject/Base/Task.h"

class PlayerEffectLongAttack : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_vec;
	CRect m_rect;
	float m_depth;
	bool m_flip;

public:
	PlayerEffectLongAttack(const CVector2D& pos, bool _flip);
	void Update();
	void Draw();
	void MoveControl();

};

class PlayerEffectShortAttack01 : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_vec;
	CRect m_rect;
	bool m_flip;

public:
	PlayerEffectShortAttack01(const CVector2D& pos, bool _flip);
	void Update();
	void Draw();
	CVector2D GetPos() { return m_pos; }
	CRect GetRect() { return m_rect; }
};

class PlayerEffectShortAttack02 : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_vec;
	CRect m_rect;
	bool m_flip;

public:
	PlayerEffectShortAttack02(const CVector2D& pos, bool _flip);
	void Update();
	void Draw();
	CVector2D GetPos() { return m_pos; }
	CRect GetRect() { return m_rect; }
};

class PlayerEffectShortAttack03 : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_vec;
	CRect m_rect;
	bool m_flip;

public:
	PlayerEffectShortAttack03(const CVector2D& pos, bool _flip);
	void Update();
	void Draw();
	CVector2D GetPos() { return m_pos; }
	CRect GetRect(){ return m_rect; }
};

class PlayerEffectSpecialAttack : public Task {
private:
	CAnimImage m_img;
	CImage m_img2;
	CVector2D m_pos;
	CVector2D m_vec;
	CVector2D m_scale;
	int m_cnt;

public:
	PlayerEffectSpecialAttack(const CVector2D& pos);
	void Update();
	void Draw();
};

class PlayerEffectGetDamage : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_vec;

public:
	PlayerEffectGetDamage(const CVector2D & pos);
	void Update();
	void Draw();
};