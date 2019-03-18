#pragma once
#include "../GameProject/Base/Task.h"
#include "../GameProject/stdafx.h"

class EnemyBase : public Task {
private:
protected:

	CRect m_rect;			//“G‹éŒ`
	CVector2D m_pos;		//“GˆÊ’u
	CVector2D m_shadow_pos;	//‰eˆÊ’u
	CVector2D m_vec;		//“GƒxƒNƒgƒ‹
	CAnimImage m_img;		//“G‰æ‘œ
	CImage m_shadow;		//‰e
	CVector2D m_pos_old;	//“G‘OˆÊ’u
	int m_hp;				//“G‘Ì—Í
	int m_state;			//“Gó‘Ô
	float m_ang;			//“G•ûŒü
	float m_depth;			//‰œs‚«
	bool m_flip;			//”½“]ƒtƒ‰ƒO
	
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
	@drief ƒIƒuƒWƒFƒNƒg‚Ì‰æ–ÊˆÚ“®‚ğ§ŒÀ‚·‚é
	*/
	virtual void MoveControl();
	virtual int GetType() { return m_type; }
	virtual CVector2D GetPos() {
		return  m_pos;
	}
	CRect GetRect() {
		return m_rect;
	}
    float GetDepth() {
        return m_depth;
    }
};