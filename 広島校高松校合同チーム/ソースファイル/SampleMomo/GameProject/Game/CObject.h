#pragma once
#include "../Task/Task.h"
#include "../stdafx.h"

#include "../Global.h"



enum {
	eReceiveCollisionX,
	eReceiveCollisionY,
	eReceiveCollisionZ,
};


class CObject : public Task {
private:
protected:
	CVector3D m_pos = CVector3D(0,0,0);
	CVector3D m_pos_old = CVector3D(0, 0, 0);
	CVector3D m_vec = CVector3D(0, 0, 0);
	float m_speed = 1.0f;
	CVector2D m_size;
	CVector3D m_rads = CVector3D(0,0,0);
	bool m_is_flip = false;


	//他のオブジェクトに対してアクティブな判定かどうか（他のオブジェクトからして壁になるかどうか)
	bool m_is_collision_others = true;//基本的にはtrue



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

	static const CVector2D& GetScroll();
	static void SetScroll(const CVector2D& _scroll);

	bool CollisionCheck3D(CObject * _ob) { return CollisionCheck3D(m_pos, m_rads, _ob->GetPos(), _ob->GetRads()); };

	void SetIsCollisionOthers(bool _is) { m_is_collision_others = _is; }
	bool GetIsCollisionOthers() { return m_is_collision_others; }


	static bool CollisionCheck3D(const CVector3D& _pos_1, const CVector3D& _rads_1, const CVector3D& _pos_2, const CVector3D& _rads_2) {
		
		//なくてもよさげ
		if (_rads_1.x == 0 && _rads_1.y == 0 && _rads_1.z == 0
			|| _rads_2.x == 0 && _rads_2.y == 0 && _rads_2.z == 0) return false;

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

	

	//ベクトルによる移動を行う
	void MovePos() {
		m_pos += m_vec * CFPS::GetDeltaTime() * GAME_BASE_FPS;
	};
};

/*
2019/03/06 クラス定義。基本機能実装。 by shingai
*/
