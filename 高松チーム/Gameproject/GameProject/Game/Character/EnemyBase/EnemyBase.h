#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

/*
������CharacterType�ݒ肷��
*/
enum {
	eEnemy01 = 1,
	eEnemy02,
	eEnemy03,
	eEnemy04,
	eEnemy05,
	eBossHead,
	eBossHund
};

class EnemyBase : public Task {
private:
protected:
	
	CVector2D m_pos;	//�G�ʒu
	CVector2D m_vec;	//�G�x�N�g��
	CAnimImage m_img;	//�G�摜
	CVector2D m_pos_old;//�G�O�ʒu
	int m_hp;			//�G�̗�
	int m_state;		//�G���
	float m_ang;		//�G����
	float m_depth;		//���s��
	bool m_flip;		//���]�t���O
	
public:
	EnemyBase(int _type);
	virtual void Move();
	virtual void Attack();
	virtual void Damage();
	virtual void Update();
	virtual void Draw();
	virtual void HitCheck(Task* _t);
	/*
	@drief �I�u�W�F�N�g�̉�ʈړ��𐧌�����
	*/
	virtual void MoveControl();


};