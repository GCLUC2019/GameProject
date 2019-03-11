#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

/*
‚±‚±‚ÅCharacterTypeİ’è‚·‚é
*/
enum {
	eEnemy01,
	eEnemy02,
	eEnemy03,
	eEnemy04,
	eEnemy05,
	eBossHead,
};

class EnemyBase : public Task {
private:
protected:
	
	CVector2D m_pos;	//“GˆÊ’u
	CVector2D m_vec;	//“GƒxƒNƒgƒ‹
	CImage m_img;		//“G‰æ‘œ
	int m_type;			//“G¯•Êq
	int m_e_hp;			//“G‘Ì—Í
	float m_ang;		//“G•ûŒü
	
public:
	EnemyBase(int _type);
	virtual void Move();
	virtual void Attack();
	virtual void Update();
	virtual void Draw();

};