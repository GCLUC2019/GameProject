#pragma once
#include "../Base/Task.h"

class CollitionBase  {
private:

protected:

public:
	CollitionBase();
	void Update();
	/*
	@brief 　			矩形判定（Y軸制限付き）
	@param	b1			[in]比較元のポインタ
	@param	_type		[in]比較する対象のtype
	@param	_y			[in]Y軸制限距離（これより短ければ当たっている負の数は不可）
	*/
	static bool CollisionCheckRectANDY(Task * b1, const int& _type, const float& _y);
	static bool CollisionCheckRect(Task * b1, const int& _type);
    static bool CollisionCheckPoint(Task* b1, int _type);
	/*
	@brief 　			ポインタ取得矩形判定（Y軸制限付き）
	@param	b1			[in]比較元のポインタ
	@param	_type		[in]比較する対象のtype
	@param	_y			[in]Y軸制限距離（これより短ければ当たっている負の数は不可）
	*/
	static Task* GetCollisionCheckRectANDY(Task * b1, const int& _type, const float& _y);
	/*
	@brief 　			ポインタ取得矩形判定
	@param	b1			[in]比較元のポインタ
	@param	_type		[in]比較する対象のtype
	*/
	static Task* GetCollisionCheckRect(Task* b1, const int& _type);
	static bool CollitionCheckflip(int fliptype, Task* b1, Task*b2);
	/*
	@brief 　			Y軸比較関数
	@param	b1	
	@param	b2			[in]比較する対象の座標
	@param	_length		[in]当たり判定の距離（これより短ければ当たっている負の数は不可）
	*/
	static bool CollitionCheckY(const CVector2D& b1, const CVector2D& b2, const float&  _length);
};