#pragma once
#include "CObject.h"
class CAnimation;

enum {
	eEffectDamage = 0,
	eEffectSlashX,
	eEffectSlashY,
	eEffectSlashFinish,
	eEffectBark,
	eEffectBite,
	eEffectRash,
	eEffectJump,
};

class  CDamageEffect :public CObject
{
private:
	CAnimation * m_anim_p = nullptr;
	CVector3D* m_pos_p;
	CVector2D m_offset_pos;

	//回転によって変わるオフセット値
	CVector2D m_flip_offset_pos;
	double m_delete_cnt = 0;
	int m_effect_id = 0;
public:
	CDamageEffect(CVector3D * _pos_p,CVector2D _offset_pos = CVector2D(0,0), CVector2D _size = CVector2D(100,100),double _count = 60.0,int _effect_id=0,bool _is_flip = false,CVector2D _flip_offset_pos = CVector2D(0, 0));

	~CDamageEffect();
	void Update();
	void Draw();
	void LoadAnimImage();
	void ChangeAnim(int _anim_id);
};

