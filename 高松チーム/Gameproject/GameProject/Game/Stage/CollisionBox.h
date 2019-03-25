#pragma once
#include "../../Base/Task.h"
#include "../CollitionBase.h"
/*
�S��
�c��  class CollisionBox�@
*/
//�����蔻����������邾���̃N���X
class CollisionBox :public Task {
protected:
    CVector2D m_pos;
	CVector2D m_pos_org;
    CRect m_rect;
public:
    CollisionBox(const CVector2D &_pos, const CRect &_rect);
    void Update();
    void Draw();
    void HitCheck();

    int GetType() { return m_type; }
    float GetDepth() { return m_depth; }

    CVector2D GetPos() {
        return  m_pos;
    }
    CRect GetRect() {
        return m_rect;
    }
	void Scroll(const CVector2D& _vec) {
		m_pos += _vec;
	}
};