#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

class CharacterBase : public Task {
private:
protected:
	CVector2D m_pos;
	CAnimImage m_img;
	int m_type;

public:
	CharacterBase(int _type);
	virtual void Update();
	virtual void Draw();
	virtual void Damage(int _damage);
    CVector2D GetPos(){
        return m_pos;
    }
};