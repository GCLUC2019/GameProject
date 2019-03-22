#pragma once
#include "../GameProject/Base/Task.h"

class UI : public Task {
public:
	enum UIData {
		ePlayerLogoUI,
		eSpecialGageUI,
		eGageBaseUI,
		ePlayerGageUI,
		eGuidanceUI,
		eBossHpUI,
		eBossGageBaseUI,
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
	CAnimImage m_special_gage_img;
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

class GuidanceUI : public UI {
private:
public:
	GuidanceUI();
	void Update();
	void Draw();
};

class FadeOut : public Task {
private:
	CFont m_font;
	CVector2D m_pos;
	CVector2D m_pos_ohuda;
	CVector2D m_pos_rogo;

	CImage m_img;
	CImage m_img_ohuda;
	CImage m_img_rogo;

	float m_fadeout;
	float m_ohuda_ang;
public:
	FadeOut();
	void Update();
	void Draw();
	float GetFadeOut() {
		return m_fadeout;
	}
};