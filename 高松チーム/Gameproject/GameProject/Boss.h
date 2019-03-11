#pragma once
#include "../GameProject/Game/Character/EnemyBase/EnemyBase.h"

/*
担当
  番條　Boss.cppp,h 
*/
class BossHead :public EnemyBase{
protected:
	CImage m_img2; //横ブレス攻撃img
	CVector2D m_pos2; //横ブレスpos 1枚1280,960サイズ

	float m_rot;
protected:


public:
	BossHead();

	void Update();

	void Draw();

};
