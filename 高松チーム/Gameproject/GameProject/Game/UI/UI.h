#pragma once
#include "../GameProject/Base/Task.h"

class UI : public Task {
public:
	enum UIData {
		ePlayerLogoUI,
		eSpecialGageUI,
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
public:
	SpecialGageUI();
	void Update();
	void Draw();
};