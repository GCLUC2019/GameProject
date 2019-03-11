#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

/*
������CharacterType�ݒ肷��
*/
enum {
	ePlayer,
};

class CharacterBase : public Task {
private:
protected:
	CVector2D m_pos;
	CImage m_img;
	int m_type;

public:
	CharacterBase(int _type);
	virtual void Update();
	virtual void Draw();
    CVector2D GetPos(){
        return m_pos;
    }
};