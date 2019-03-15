#pragma once
#include "../GameProject/Base/Task.h"

class UI : public Task {
public:
	enum UIData {
		ePlayerLogoUI,
		eSpecialGageUI,
		eGageBaseUI,
		ePlayerGageUI,
	};
private:
protected:
	CVector2D m_pos;
	CAnimImage m_img;

public:
	UI();
	UI(int _type);
	void Update();
	void Draw();
	virtual void HitCheck();

};

class PlayerLogoUI : public UI{
private:
public:
	PlayerLogoUI();
	void Update();
	void Draw();
};

class SpecialGageUI : public UI {
private:
	int m_state;
	int m_special_gage;
public:
	SpecialGageUI();
	void Update();
	void Draw();
};

class GageBaseUI : public UI {
private:
public:
	GageBaseUI();
	void Update();
	void Draw();
};

class PlayerGageUI : public UI {
private:
	float m_player_hp_now;
	float m_player_hp_max;
	float hp_width;
public:
	PlayerGageUI();
	void Update();
	void Draw();
};