#pragma once
#include "../Task/Task.h"
#include "../stdafx.h"



class CObject : public Task {
private:
protected:
	CVector3D m_pos;
	CVector3D m_pos_old;
	CVector3D m_vec;
	float m_speed;
	CVector2D m_size;
	CVector3D m_rads;
	bool m_is_flip = false;
public:
	CObject(int _task_id, int _draw_priority);
	virtual ~CObject();
	virtual void BeforeUpdate();
	virtual void BeforeCollisionCheck();
	virtual void Update();
	virtual void AfterUpdate();
	virtual void Draw();

	void SetSpeed(float _speed) { m_speed = _speed; };

	void SetPos(CVector3D _pos) { m_pos = _pos; };
	void SetPos(float _x,float _y,float _z) { m_pos = CVector3D(_x,_y,_z); };

	void SetRads(CVector3D _rads) { m_rads = _rads; };
	void SetRads(float _x, float _y, float _z) { m_rads = CVector3D(_x, _y, _z); };


	void SetVec(CVector3D _vec) { m_vec = _vec; };
	void SetVec(float _x, float _y, float _z) { m_vec = CVector3D(_x, _y, _z); };

	void SetSize(CVector2D _size) { m_size = _size; };
	void SetSize(float _x, float _y) { m_size = CVector2D(_x, _y); };

	void SetIsFlip(bool _is) { m_is_flip = _is; };
	bool GetIsFlip() { return m_is_flip; };

	float GetSpeed() {return m_speed; };
	CVector3D GetPos() { return m_pos; };
	CVector3D GetPosOld() { return m_pos_old; };

	CVector3D GetVec() { return m_vec; };
	CVector3D GetRads() { return m_rads; };
	CVector2D GetSize() { return m_size; };

	static CVector2D GetScroll();
	static void SetScroll(CVector2D _scroll);

	bool CollisionCheck3D(CObject * _ob);
	static bool CollisionCheck3D(CVector3D _pos_1, CVector3D _rads_1, CVector3D _pos_2, CVector3D _rads_2);
};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
*/
