#include "CObject.h"



CObject::CObject(int _task_id, int _draw_priority) : Task(_task_id,_draw_priority)
{
}

CObject::~CObject()
{
}

void CObject::BeforeUpdate()
{
}

void CObject::BeforeCollisionCheck()
{
}

void CObject::Update()
{
}

void CObject::AfterUpdate()
{
}

void CObject::Draw()
{
}


//インライン展開します。

/*
const CVector2D& CObject::GetScroll()
{
	return s_scroll;
}
*/

/*
void CObject::SetScroll(const CVector2D& _scroll)
{
	s_scroll = _scroll;
}
*/


//インライン展開します
//bool CObject::CollisionCheck3D(CObject * _ob)
//{
//	return CollisionCheck3D(m_pos,m_rads,_ob->GetPos(),_ob->GetRads());
//}


//インライン展開します


//
//bool CObject::CollisionCheck3D(const CVector3D& _pos_1, const CVector3D& _rads_1, const CVector3D& _pos_2, const CVector3D& _rads_2)
//{
//	//軽量化
//	if (abs(_pos_1.x - _pos_2.x) < _rads_1.x + _rads_2.x) {
//		if (abs(_pos_1.y - _pos_2.y) < _rads_1.y + _rads_2.y) {
//			if (abs(_pos_1.z - _pos_2.z) < _rads_1.z + _rads_2.z) {
//				return true;
//			}
//		}
//	}
//	return false;
//
//	/*
//	//軽量化前(安定した動作)
//	//もしどちらか一方の当たり判定が設定されてないなら当たり判定を行わない
//	if (_rads_1.x == 0 && _rads_1.y == 0 && _rads_1.z == 0 || _rads_2.x == 0 && _rads_2.y == 0 && _rads_2.z == 0) return false;
//
//	//座標と座標の距離を求める。(どれだけ離れているか)
//	double v = _pos_2.x - _pos_1.x;
//
//	//負の数の場合逆数にする。
//	if (v < 0) {
//		v *= -1.0f;
//	}
//	//横軸の当たり判定で当たっていたら中を実行
//	if (v <= _rads_1.x + _rads_2.x) {
//		//縦軸の当たり判定処理開始
//
//		//座標と座標の距離を求める。(どれだけ離れているか)
//		v = _pos_1.y - _pos_2.y;
//
//		//負の数の場合逆数にする。
//		if (v < 0) {
//			v *= -1.0f;
//		}
//
//		//縦軸の当たり判定で当たっていたら中を実行
//		if (v <= _rads_1.y + _rads_2.y) {
//			//座標と座標の距離を求める。(どれだけ離れているか)
//			v = _pos_1.z - _pos_2.z;
//
//			//負の数の場合逆数にする。
//			if (v < 0) {
//				v *= -1.0f;
//			}
//
//			if (v <= _rads_1.z + _rads_2.z) {
//				return true;
//			}
//
//		}
//	}
//	return false;
//	*/
//}