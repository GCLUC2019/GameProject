#pragma once
#include "../stdafx.h"
#include "../System/Task.h"
class Ball : public Task {
private:
	CVector2D m_pos;		//ボールの位置
	CVector2D m_vec;		//ボールの移動量
public:
	/*!
		@brief	コンストラクタ
		@param	pos			[in] 出現位置
	**/
	Ball(const CVector2D& pos);
	/*!
		@brief	デフォルトコンストラクタ
	**/
	Ball();
	~Ball();
	/*!
		@brief	更新処理
		@param	delta_time			[in] 前回の更新からの経過時間
	**/
	/*!
	@brief	\コンストラクタ
	**/
	
	void Update(float delta_time);
	/*!
		@brief	描画処理
	**/
	void Render();
};