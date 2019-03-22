#pragma once
#include "../Base/Task.h"

class CollitionBase  {
private:

protected:

public:
	CollitionBase();
	void Update();
	/*
	@brief �@			��`����iY�������t���j
	@param	b1			[in]��r���̃|�C���^
	@param	_type		[in]��r����Ώۂ�type
	@param	_y			[in]Y�����������i������Z����Γ������Ă��镉�̐��͕s�j
	*/
	static bool CollisionCheckRectANDY(Task * b1, const int& _type, const float& _y);
	static bool CollisionCheckRect(Task * b1, const int& _type);
    static bool CollisionCheckPoint(Task* b1, int _type);
	/*
	@brief �@			�|�C���^�擾��`����iY�������t���j
	@param	b1			[in]��r���̃|�C���^
	@param	_type		[in]��r����Ώۂ�type
	@param	_y			[in]Y�����������i������Z����Γ������Ă��镉�̐��͕s�j
	*/
	static Task* GetCollisionCheckRectANDY(Task * b1, const int& _type, const float& _y);
	/*
	@brief �@			�|�C���^�擾��`����
	@param	b1			[in]��r���̃|�C���^
	@param	_type		[in]��r����Ώۂ�type
	*/
	static Task* GetCollisionCheckRect(Task* b1, const int& _type);
	static bool CollitionCheckflip(int fliptype, Task* b1, Task*b2);
	/*
	@brief �@			Y����r�֐�
	@param	b1	
	@param	b2			[in]��r����Ώۂ̍��W
	@param	_length		[in]�����蔻��̋����i������Z����Γ������Ă��镉�̐��͕s�j
	*/
	static bool CollitionCheckY(const CVector2D& b1, const CVector2D& b2, const float&  _length);
};