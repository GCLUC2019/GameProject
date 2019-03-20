#pragma once
#include "../GameProject/Base/Task.h"
class E2Effect :public Task {
private:
    CAnimImage m_img;
    CVector2D m_pos;
    CRect m_rect;
public:
    E2Effect(const CVector2D&pos);
    void Update();
    void Draw();
    void HitCheck();
    CVector2D GetPos() {
        return m_pos;
    }
    CRect GetRect() {
        return m_rect;
    }
};

class E4EffectEXAttack :public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CRect m_rect;
public:
	E4EffectEXAttack(const CVector2D&pos);
	void Update();
	void Draw();
	void HitCheck();
	CVector2D GetPos() {
		return m_pos;
	}
	CRect GetRect() {
		return m_rect;
	}
};