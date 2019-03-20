#pragma once
#include "../Base/Task.h"

class CollitionBase  {
private:

protected:

public:
	CollitionBase();
	void Update();
	static bool CollisionCheckRect(Task* b1, int _type);
    static bool CollisionCheckPoint(Task* b1, int _type);
	static Task* GetCollisionCheckRect(Task* b1, int _type);
	static bool CollitionCheckflip(int fliptype, Task* b1, Task*b2);
	/*
	@brief �@			Y����r�֐�
	@param	b1	
	@param	b2			[in]��r����Ώۂ̍��W
	@param	_length		[in]�����蔻��̋����i������Z����Γ������Ă��镉�̐��͕s�j
	*/
	static bool CollitionCheckY(const CVector2D& b1, const CVector2D& b2, const float&  _length);
};