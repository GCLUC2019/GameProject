#pragma once
#include "../GameProject/Base/Task.h"

class BossManager : public Task {
private:
	enum {
		eNothing,
		eIdle,
		eAttack,
	};

	CAnimImage m_img; //“ª
	CImage m_img2;//‰Eè‹Ê‚ª‚ ‚é‚Ù‚¤
	CImage m_img3;//¶è
	CAnimImage m_img4;//K”ö

	CVector2D m_pos; //“ª‚ÌÀ•W
	CVector2D m_pos2;//‰Eè‚ÌÀ•W
	CVector2D m_pos3;//¶è‚ÌÀ•W
	CVector2D m_pos4;//K”ö‚ÌÀ•W
	CVector2D m_center;
	CVector2D m_center2;

	int m_state;

	float m_rot;//‰~ü—¦
	float m_rot2;//‰~ü—¦
	float m_r;  //”¼Œa

	bool Idle_flag;
	bool Attack_flag;

public:

	BossManager();

	void Update();

	void Draw();
};
