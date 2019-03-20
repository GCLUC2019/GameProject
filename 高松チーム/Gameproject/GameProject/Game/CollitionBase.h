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
	@brief 　			Y軸比較関数
	@param	b1	
	@param	b2			[in]比較する対象の座標
	@param	_length		[in]当たり判定の距離（これより短ければ当たっている負の数は不可）
	*/
	static bool CollitionCheckY(const CVector2D& b1, const CVector2D& b2, const float&  _length);
};