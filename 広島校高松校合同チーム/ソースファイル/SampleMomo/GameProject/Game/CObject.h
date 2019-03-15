#pragma once
#include "../Task/Task.h"
#include "../stdafx.h"

static CVector2D s_scroll = CVector2D(0, 0);

class CObject : public Task {
private:
protected:
	CVector3D m_pos = CVector3D(0,0,0);
	CVector3D m_pos_old;
	CVector3D m_vec;
	float m_speed;
	CVector2D m_size;
	CVector3D m_rads;
	bool m_is_flip = false;
public:
	CObject(int _task_id = 0, int _draw_priority = 0);
	virtual ~CObject();
	virtual void BeforeUpdate();
	virtual void BeforeCollisionCheck();
	virtual void Update();
	virtual void AfterUpdate();
	virtual void Draw();

	void SetSpeed(float _speed) { m_speed = _speed; };

	void SetPos(const CVector3D& _pos) { m_pos = _pos; };
	void SetPos(float _x,float _y,float _z) { m_pos = CVector3D(_x,_y,_z); };
	void SetPosOld(const CVector3D& _pos) { m_pos_old = _pos; };

	void SetRads(const CVector3D& _rads) { m_rads = _rads; };
	void SetRads(float _x, float _y, float _z) { m_rads = CVector3D(_x, _y, _z); };


	void SetVec(const CVector3D& _vec) { m_vec = _vec; };
	void SetVec(float _x, float _y, float _z) { m_vec = CVector3D(_x, _y, _z); };

	void SetSize(const CVector2D& _size) { m_size = _size; };
	void SetSize(float _x, float _y) { m_size = CVector2D(_x, _y); };

	void SetIsFlip(bool _is) { m_is_flip = _is; };
	bool GetIsFlip() { return m_is_flip; };

	float GetSpeed() {return m_speed; };
	
	const CVector3D& GetPos() { return m_pos; };
	const CVector3D& GetPosOld() { return m_pos_old; };


	const CVector3D& GetVec() { return m_vec; };
	const CVector3D& GetRads() { return m_rads; };
	const CVector2D& GetSize() { return m_size; };

	static const CVector2D& GetScroll() { return s_scroll; };
	static void SetScroll(const CVector2D& _scroll) { s_scroll = _scroll; };

	bool CollisionCheck3D(CObject * _ob) { return CollisionCheck3D(m_pos, m_rads, _ob->GetPos(), _ob->GetRads()); };

	static bool CollisionCheck3D(const CVector3D& _pos_1, const CVector3D& _rads_1, const CVector3D& _pos_2, const CVector3D& _rads_2) {
		//軽量化
		if (abs(_pos_1.x - _pos_2.x) < _rads_1.x + _rads_2.x &&
			abs(_pos_1.y - _pos_2.y) < _rads_1.y + _rads_2.y &&
			abs(_pos_1.z - _pos_2.z) < _rads_1.z + _rads_2.z) {
			return true;
		}
		return false;

		/*
		//軽量化
		if (abs(_pos_1.x - _pos_2.x) < _rads_1.x + _rads_2.x) {
			if (abs(_pos_1.y - _pos_2.y) < _rads_1.y + _rads_2.y) {
				if (abs(_pos_1.z - _pos_2.z) < _rads_1.z + _rads_2.z) {
					return true;
				}
			}
		}
		return false;
		*/
	};
};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
*/
