#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

/*
������CharacterType�ݒ肷��
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
	
	CVector2D m_pos;	//�G�ʒu
	CVector2D m_vec;	//�G�x�N�g��
	CImage m_img;		//�G�摜
	int m_type;			//�G���ʎq
	int m_e_hp;			//�G�̗�
	float m_ang;		//�G����
	
public:
	EnemyBase(int _type);
	virtual void Move();
	virtual void Attack();
	virtual void Update();
	virtual void Draw();

};