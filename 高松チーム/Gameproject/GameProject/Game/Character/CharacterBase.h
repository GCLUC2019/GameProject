#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

class CharacterBase : public Task {
private:
protected:
	CVector2D m_pos;
	CAnimImage m_img;
	int m_type;
	CRect m_rect;
    float m_depth;
public:
	CharacterBase(int _type);
	virtual void Update();
	virtual void Draw();
	virtual void Damage(int _damage);
	int GetType() { return m_type; }
    CVector2D GetPos(){
        return m_pos;
    }
	CRect GetRect() {
		return m_rect;
	}
    float GetDepth() {
        return m_depth;
    }
};