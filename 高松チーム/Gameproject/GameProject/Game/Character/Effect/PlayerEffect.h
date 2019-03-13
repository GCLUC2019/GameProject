#pragma once
#include "../GameProject/Base/Task.h"

class PlayerEffectLongAttack : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_vec;

public:
	PlayerEffectLongAttack(const CVector2D& pos);
	void Update();
	void Draw();

};

class PlayerEffectShortAttack01 : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_vec;

public:
	PlayerEffectShortAttack01(const CVector2D& pos);
	void Update();
	void Draw();
};

class PlayerEffectShortAttack02 : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_vec;

public:
	PlayerEffectShortAttack02(const CVector2D& pos);
	void Update();
	void Draw();
};

class PlayerEffectShortAttack03 : public Task {
private:
	CAnimImage m_img;
	CVector2D m_pos;
	CVector2D m_vec;

public:
	PlayerEffectShortAttack03(const CVector2D& pos);
	void Update();
	void Draw();
};

class PlayerEffectSpecialAttack : public Task {
private:
	CAnimImage m_img;
	CImage m_img2;
	CVector2D m_pos;
	CVector2D m_vec;
	CVector2D m_scale;

public:
	PlayerEffectSpecialAttack(const CVector2D& pos);
	void Update();
	void Draw();
};