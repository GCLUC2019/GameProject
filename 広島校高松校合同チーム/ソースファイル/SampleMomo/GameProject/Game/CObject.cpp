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


//�C�����C���W�J���܂��B

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


//�C�����C���W�J���܂�
//bool CObject::CollisionCheck3D(CObject * _ob)
//{
//	return CollisionCheck3D(m_pos,m_rads,_ob->GetPos(),_ob->GetRads());
//}


//�C�����C���W�J���܂�


//
//bool CObject::CollisionCheck3D(const CVector3D& _pos_1, const CVector3D& _rads_1, const CVector3D& _pos_2, const CVector3D& _rads_2)
//{
//	//�y�ʉ�
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
//	//�y�ʉ��O(���肵������)
//	//�����ǂ��炩����̓����蔻�肪�ݒ肳��ĂȂ��Ȃ瓖���蔻����s��Ȃ�
//	if (_rads_1.x == 0 && _rads_1.y == 0 && _rads_1.z == 0 || _rads_2.x == 0 && _rads_2.y == 0 && _rads_2.z == 0) return false;
//
//	//���W�ƍ��W�̋��������߂�B(�ǂꂾ������Ă��邩)
//	double v = _pos_2.x - _pos_1.x;
//
//	//���̐��̏ꍇ�t���ɂ���B
//	if (v < 0) {
//		v *= -1.0f;
//	}
//	//�����̓����蔻��œ������Ă����璆�����s
//	if (v <= _rads_1.x + _rads_2.x) {
//		//�c���̓����蔻�菈���J�n
//
//		//���W�ƍ��W�̋��������߂�B(�ǂꂾ������Ă��邩)
//		v = _pos_1.y - _pos_2.y;
//
//		//���̐��̏ꍇ�t���ɂ���B
//		if (v < 0) {
//			v *= -1.0f;
//		}
//
//		//�c���̓����蔻��œ������Ă����璆�����s
//		if (v <= _rads_1.y + _rads_2.y) {
//			//���W�ƍ��W�̋��������߂�B(�ǂꂾ������Ă��邩)
//			v = _pos_1.z - _pos_2.z;
//
//			//���̐��̏ꍇ�t���ɂ���B
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