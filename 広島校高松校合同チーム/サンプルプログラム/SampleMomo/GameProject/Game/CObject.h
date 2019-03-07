#pragma once
#include "../System/Task.h"
#include "../stdafx.h"

class CObject : public Task {
private:
protected:
	CVector3D m_pos;
	CVector3D m_vec;
	CVector2D m_size;
public:
	CObject(int _id, int _up, int _rd);
	virtual ~CObject();
	virtual void Update(float delta_time);
	virtual void Render();

	void SetPos(CVector3D _pos) { m_pos = _pos; };
	void SetPos(float _x,float _y,float _z) { m_pos = CVector3D(_x,_y,_z); };

	void SetVec(CVector3D _vec) { m_pos = _vec; };
	void SetVec(float _x, float _y, float _z) { m_vec = CVector3D(_x, _y, _z); };

	void SetSize(CVector2D _size) { m_size = _size; };
	void SetSize(float _x, float _y) { m_size = CVector2D(_x, _y); };


	CVector3D GetPos() { return m_pos; };
	CVector3D GetVec() { return m_vec; };
	CVector2D GetSize() { return m_size; };
};