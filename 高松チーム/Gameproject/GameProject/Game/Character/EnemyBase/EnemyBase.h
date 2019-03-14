#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

class EnemyBase : public Task {
private:
protected:

	CRect m_rect;			//�G��`
	CVector2D m_pos;		//�G�ʒu
	CVector2D m_shadow_pos;	//�e�ʒu
	CVector2D m_vec;		//�G�x�N�g��
	CAnimImage m_img;		//�G�摜
	CImage m_shadow;		//�e
	CVector2D m_pos_old;	//�G�O�ʒu
	int m_hp;				//�G�̗�
	int m_state;			//�G���
	float m_ang;			//�G����
	float m_depth;			//���s��
	bool m_flip;			//���]�t���O
	
public:
	EnemyBase(int _type);
	virtual void Move();
	virtual void Attack();
	virtual void Damage();
	virtual void Update();
	virtual void Draw();
	virtual void HitCheck(Task* _t);
	static bool CollisionCheckRect(EnemyBase* b1, EnemyBase* b2);
	static bool CollitionCheckflip(int fliptype, EnemyBase* b1, EnemyBase*b2);
	/*
	@drief �I�u�W�F�N�g�̉�ʈړ��𐧌�����
	*/
	virtual void MoveControl();
	virtual int GetType() { return m_type; }
	virtual CVector2D GetPos() {
		return  m_pos;
	}
	CRect GetRect() {
		return m_rect;
	}
		
};