#pragma once
#include "../System/Task.h"
#include "../stdafx.h"

class CObject : public Task {
private:
protected:
	CVector3D m_pos;
	CVector3D m_vec;
public:
	CObject(int _id, int _up, int _rd);
	virtual ~CObject();
	virtual void Update(float delta_time);
	virtual void Render();
	void SetPos(CVector3D _pos) { m_pos = _pos; };
	void SetVec(CVector3D _vec) { m_pos = _vec; };
	CVector3D GetPos() { return m_pos; };
	CVector3D GetVec() { return m_vec; };
};