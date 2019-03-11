#pragma once
#include"../GameProject/stdafx.h"
#include "../System/Task.h"

class Barrett:public Task{
private:
	CVector2D m_pos;
public:
	Barrett(const CVector2D& _pos);
	/*!
	@brief	更新処理
	@param	delta_time			[in] 前回の更新からの経過時間
	**/
	void Update(float delta_time);
	/*!
	@brief	描画処理
	**/
	void Render();
};