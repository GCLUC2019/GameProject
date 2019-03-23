#pragma once
#include "CObject.h"

/*
弾オブジェクト
銃の弾を表示するようにしたのでオブジェクト化
斬撃とかにも同じように仕える
*/

#define BULLET_SPEED (20.0)
class CBullet : public  CObject {
private:
	int m_target_task_id;
	CImage * m_bullet_image_p = nullptr;
	CImage * m_shadow_image_p = nullptr;
	double m_attack_power;
	CVector3D m_attack_length;

	CVector2D m_offset_pos;

	//弾が指定地点まで動いたら削除する
	CVector3D m_destroy_length;

	//弾が発射された地点(初期位置)
	CVector3D m_bullet_fire_pos;

	CVector2D m_shadow_offset_pos;
	CVector2D m_shadow_size;
public:
	CBullet(CImage*_bullet_image,int _target_task_id,CVector3D _pos, CVector2D _offset_pos,CVector2D _size,bool _flip,double _attack_power,CVector3D _bullet_attack_length, CVector3D _destroy_length,double _speed = BULLET_SPEED, CImage* _shadow_image = nullptr, CVector2D _shadow_offset_pos = CVector2D(0,0), CVector2D _shadow_size = CVector2D(0,0));
	void SetShadow(CImage* _shadow_image, CVector2D _shadow_offset_pos, CVector2D _shadow_size);
	void Update();
	void Draw();
	void CheckDestroy();
	void CheckHitTarget();
	void Destroy();
};

/*
20190320 by shingai
*/