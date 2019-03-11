#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

/*
Ç±Ç±Ç≈CharacterTypeê›íËÇ∑ÇÈ
*/
enum {
	eEnemy01,
};

class EnemyBase : public Task {
private:
protected:
	
	CVector2D m_pos;
	CImage m_img;
	int m_type;
	
public:
	EnemyBase(int _type);
	virtual void Update();
	virtual void Draw();

};