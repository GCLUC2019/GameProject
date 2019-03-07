#pragma once
#include "../Task/Task.h"
#include "../stdafx.h"

class CObject : public Task {
private:
protected:
	CVector3D m_pos;
	CVector3D m_vec;
	float m_speed;
	CVector2D m_size;
	bool m_is_flip = false;
public:
	CObject(int _task_manager_id,int _task_id, int _update_priority, int _draw_priority);
	virtual ~CObject();
	virtual void Update(float delta_time);
	virtual void Draw();

	void SetSpeed(float _speed) { m_speed = _speed; };

	void SetPos(CVector3D _pos) { m_pos = _pos; };
	void SetPos(float _x,float _y,float _z) { m_pos = CVector3D(_x,_y,_z); };

	void SetVec(CVector3D _vec) { m_pos = _vec; };
	void SetVec(float _x, float _y, float _z) { m_vec = CVector3D(_x, _y, _z); };

	void SetSize(CVector2D _size) { m_size = _size; };
	void SetSize(float _x, float _y) { m_size = CVector2D(_x, _y); };

	void SetIsFlip(bool _is) { m_is_flip = _is; };
	bool GetIsFlip() { return m_is_flip; };

	float GetSpeed() {return m_speed; };
	CVector3D GetPos() { return m_pos; };
	CVector3D GetVec() { return m_vec; };
	CVector2D GetSize() { return m_size; };
};