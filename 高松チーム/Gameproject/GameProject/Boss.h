#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
�S��
  �Ԟ��@Boss.cppp,h 
*/
class BossHead :public EnemyBase{
protected:
	CImage m_img2; //���u���X�U��img
	CVector2D m_pos2; //���u���Xpos 1��1280,960�T�C�Y

	float m_rot;
protected:


public:
	BossHead();

	void Update();

	void Draw();

};
